int Pinbuzzer = 8; // PINO UTILIZADO PELO BUZZER
int PinA0 = A0;   // PINO UTILIZADO PELO SENSOR DE GÁS MQ-2
int PinLed = 7;
int leitura_sensor = 200;    // DEFININDO UM VALOR LIMITE (NÍVEL DE GÁS NORMAL)
unsigned long ultimoEnvio = 0; // Variável para controlar o tempo do último envio
unsigned long intervaloEnvio = 10000; // Intervalo de tempo mínimo entre os envios (em milissegundos)

void setup() {
  pinMode(PinA0, INPUT);       // DEFINE O PINO COMO ENTRADA
  pinMode(Pinbuzzer, OUTPUT);  // DEFINE O PINO COMO SAÍDA
  Serial.begin(9600);          // INICIALIZA A COMUNICAÇÃO SERIAL
  pinMode(PinLed, OUTPUT);     // INICIALIZA O LED COMO SAÍDA
}

void loop() {
  int valor_analogico = analogRead(PinA0); // VARIÁVEL RECEBE O VALOR LIDO NO PINO ANALÓGICO
  Serial.print("Leitura: ");                // EXIBE O TEXTO NA PORTA SERIAL
  Serial.println(valor_analogico);          // MOSTRA NA PORTA SERIAL O VALOR LIDO DO PINO ANALÓGICO
  String mensagem = "Ativar";
  
  if (valor_analogico > leitura_sensor) {  // SE VALOR LIDO NO PINO ANALÓGICO FOR MAIOR QUE O VALOR LIMITE, FAZ
    digitalWrite(PinLed, HIGH);
    digitalWrite(Pinbuzzer, HIGH);         // ATIVA O BUZZER E O MESMO EMITE O SINAL SONORO
    unsigned long tempoAtual = millis();    // Obter o tempo atual
    if (tempoAtual - ultimoEnvio >= intervaloEnvio) {  // Verificar se o intervalo mínimo foi atingido
      Serial.println(mensagem);               // ENVIA A STRING PELA PORTA SERIAL
      ultimoEnvio = tempoAtual;               // Atualizar o tempo do último envio
    }
  } else {                                 // SENÃO, FAZ
    digitalWrite(Pinbuzzer, LOW);          // BUZZER DESLIGADO
    digitalWrite(PinLed, LOW);
  }
  delay(100);                              // INTERVALO DE 100 MILISSEGUNDOS
}
