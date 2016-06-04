#include <SPI.h>
#include <Ethernet.h>

//Configurações do Ethernet Shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//Essa parte eu sei que é preciso modificar de acordo com a minha rede..
IPAddress ip(192,168,0,172); // Configure um IP válido
byte gateway[] = {192,168,0,172 }; //Entre com o IP do Computador onde a Câmera esta instalada
byte subnet[] = {255,255,255,0 }; //Entre com a Máskara de Subrede
EthernetServer server(80); //Inicializa a biblioteca EthernetServer com os valores de IP acima citados e configura a porta de acesso(80)
// String que representa o estado dos dispositivos
char Luz[7] = "0000L#";

// String onde é guardada as msgs recebidas
char msg[7] = "0000L#";

void setup() {
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}

void loop() {
  EthernetClient client = server.available();
  // SE receber um caracter...
  if (client) {
    // guarda o caracter na string 'msg'
    msg[1] = msg[2]; msg[2] = msg[3]; msg[3] = msg[4]; msg[4] = msg[5]; msg[5] = msg[6];
    msg[6] = client.read();

    if (msg[6] == '#') {
      switch (msg[5]) {
        case 'R':
          // Se receber o comando 'R#' envia de volta o status dos
          // dispositivos. (Que é a string 'Luz')
          client.write(Luz);
          break;
        case 'P':
          // Caso P#, aciona o pino do portão pequeno por 1s.
          digitalWrite(A4, HIGH);
          delay(1000);
          digitalWrite(A4, LOW);
          break;
        case 'G':
          // Caso G#, aciona o pino do portão pequeno por 1s.
          digitalWrite(A5, HIGH);
          delay(1000);
          digitalWrite(A5, LOW);
          break;
        case 'L':
          // Caso L#, ele copia os 4 bytes anteriores p/ a
          // string 'Luz' e cada byte representa um
          // dispositivo, onde '1'=ON e '0'=OFF
          Luz[0] = msg[1];
          Luz[1] = msg[2];
          Luz[2] = msg[3];
          Luz[3] = msg[4];
          if (Luz[0] == '1') digitalWrite(A0, HIGH); else digitalWrite(A0, LOW);
          if (Luz[1] == '1') digitalWrite(A1, HIGH); else digitalWrite(A1, LOW);
          if (Luz[2] == '1') digitalWrite(A2, HIGH); else digitalWrite(A2, LOW);
          if (Luz[3] == '1') digitalWrite(A3, HIGH); else digitalWrite(A3, LOW);
          break;

      }
    }
  }
}
