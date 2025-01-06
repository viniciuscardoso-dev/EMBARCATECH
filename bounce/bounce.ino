const byte LED = 13;       // LED conectado ao pino 13
const byte BOTAO = 12;     // Botão conectado ao pino 12
byte valorBotaoAtual;
byte valorBotaoAnterior = LOW; // Estado anterior do botão

void setup() {
  pinMode(LED, OUTPUT);     // Configura o LED como saída
  pinMode(BOTAO, INPUT);    // Configura o botão como entrada
  Serial.begin(9600);       // Inicializa a comunicação serial
}

void loop() {
  valorBotaoAtual = digitalRead(BOTAO);  // Lê o estado atual do botão

  // Se o estado do botão mudar, exibe no monitor serial
  if (valorBotaoAtual != valorBotaoAnterior) {
    Serial.print("Mudança detectada! Novo estado: ");
    Serial.println(valorBotaoAtual == HIGH ? "ALTO" : "BAIXO");

    // Atualiza o LED com o novo estado
    digitalWrite(LED, valorBotaoAtual);

    // Atualiza o estado anterior do botão
    valorBotaoAnterior = valorBotaoAtual;
  }

  // Sem delay para observar mudanças rápidas
}

