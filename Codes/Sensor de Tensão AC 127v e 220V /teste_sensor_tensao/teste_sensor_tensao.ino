/*
* MASTERWALKER SHOP 2015
* SENSOR DE TENSÃO AC 127V/220V
*/

int portaAnalog = A2; // PORTA ANALÓGICA UTILIZADA PELO SENSOR DE TENSÃO

float valor; // DECLARAÇÃO DE VARIÁVEL QUE RECEBE O VALOR LIDO NA PORTA ANALÓGICA A2
float valFinal = 0.00; // DECLARAÇÃO DE VARIÁVEL QUE RECEBE O VALOR FINAL CONVERTIDO
String rede; // DECLARAÇÃO DE VARIÁVEL QUE RECEBE A STRING 127V OU 220V DE ACORDO COM A REDE

void setup(){
  Serial.begin(9600); // INICIALIZA A PORTA SERIAL
  pinMode(portaAnalog, INPUT); // DECLARA QUE A PORTA ANALÓGICA É UMA ENTRADA
}

void loop() {

  valFinal = 0;
  rede = "0V";
  
  valor = analogRead(portaAnalog); // LEITURA DO VALOR NA PORTA ANALÓGICA(VARIA DE 0 ATÉ 1024)
  
  if ((valor > 100) & (valor < 483)) { // SE VARIÁVEL FOR MAIOR QUE 100 E MENOR QUE 483 FAZ
     valFinal = ((valor*5)/1024)*66.8; // VARIÁVEL RECEBE O VALOR GERADO PELA CONTA(O VALOR 66.6 PODE SER ALTERADO PARA FINS DE AJUSTE DO VALOR DE TENSÃO)
     rede = "127V"; // VARIÁVEL RECEBE A STRING 127V QUE INDICA A QUAL REDE O SENSOR ESTÁ LIGADO
  }
  if ((valor > 665) & (valor < 1023)) { // SE VARIÁVEL FOR MAIOR QUE 665 E MENOR QUE 1023 FAZ
     valFinal = ((valor*5)/1024)*49.7; // VARIÁVEL RECEBE O VALOR GERADO PELA CONTA(O VALOR 49.7 PODE SER ALTERADO PARA FINS DE AJUSTE DO VALOR DE TENSÃO)
     rede = "220V"; // VARIÁVEL RECEBE A STRING 220V QUE INDICA A QUAL REDE O SENSOR ESTÁ LIGADO
  }
  
  //SAÍDA NA JANELA COM INFORMAÇÕES DA PORTA SERIAL
  Serial.print("LEITURA DE: ");
  Serial.print(valFinal);
  Serial.print(" VOLTS / ");
  Serial.print(" LIGADO A REDE DE ");
  Serial.println(rede);
  
  delay(500); // TEMPO DE INTERVALO ENTRE UMA LEITURA E OUTRA
}
