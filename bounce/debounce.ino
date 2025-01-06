const byte LED = 13;       // LED conectado ao pino 13
const byte BOTAO = 12;     // Botão conectado ao pino 12
byte estadoBotaoAtual;     // Estado atual do botão
byte estadoBotaoAnterior = LOW; // Estado anterior do botão
unsigned long ultimaMudanca = 0; // Armazena o tempo da última mudança
const unsigned long debounceDelay = 50; // Tempo para o debounce (50ms)

void setup() {
  pinMode(LED, OUTPUT);     // Configura o LED como saída
  pinMode(BOTAO, INPUT);    // Configura o botão como entrada
  Serial.begin(9600);       // Inicializa a comunicação serial
}

void loop() {
  // Lê o estado atual do botão
  byte leituraBotao = digitalRead(BOTAO);

  // Verifica se o estado do botão mudou
  if (leituraBotao != estadoBotaoAnterior) {
    ultimaMudanca = millis(); // Atualiza o tempo da mudança
  }

  // Verifica se o tempo de debounce passou
  if ((millis() - ultimaMudanca) > debounceDelay) {
    // Se o estado estabilizou, atualiza o estado atual do botão
    if (leituraBotao != estadoBotaoAtual) {
      estadoBotaoAtual = leituraBotao;

      // Atualiza o LED e imprime o estado no Monitor Serial
      if (estadoBotaoAtual == HIGH) {
        Serial.println("LED LIGADO");
        digitalWrite(LED, HIGH);
      } else {
        Serial.println("LED DESLIGADO");
        digitalWrite(LED, LOW);
      }
    }
  }

  // Atualiza o estado anterior do botão para a próxima leitura
  estadoBotaoAnterior = leituraBotao;
}
