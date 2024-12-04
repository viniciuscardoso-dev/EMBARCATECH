// Configuração inicial
void setup() {
    // Configuração dos pinos das lâmpadas (A0 a A3)
    for (int i = 0; i < 4; i++) {
        pinMode(A0 + i, OUTPUT);
    }

    // Configuração dos pinos do display de sete segmentos (13 a 7)
    for (int i = 7; i <= 13; i++) {
        pinMode(i, OUTPUT);
    }

    // Configuração do pino do interruptor (D2)
    pinMode(2, INPUT);
}

// Função para desligar todas as lâmpadas
void desligar() {
    for (int i = 0; i < 4; i++) {
        digitalWrite(A0 + i, LOW);
    }

    // Desligar todos os segmentos do display
    for (int i = 7; i <= 13; i++) {
        digitalWrite(i, LOW);
    }
}

// Função para converter binário para decimal
int binario_para_decimal(int valor[4]) {
    return valor[0] * 8 + valor[1] * 4 + valor[2] * 2 + valor[3];
}

// Função para converter Gray para decimal
int gray_para_decimal(int valor[4]) {
    int bin[4];
    bin[0] = valor[0];  // O primeiro bit de Gray é o mesmo no binário
    // Os bits seguintes são calculados por XOR entre o bit Gray e o bit anterior do binário
    for (int i = 1; i < 4; i++) {
        bin[i] = bin[i - 1] ^ valor[i];
    }

    // Agora convertemos o valor binário resultante para decimal
    return binario_para_decimal(bin);
}

// Função para exibir um número no display de sete segmentos
void exibir_no_display(int valor[4], bool modo_gray) {
    int numero;

    if (modo_gray) {
        numero = gray_para_decimal(valor); // Converte Gray para decimal
    } else {
        numero = binario_para_decimal(valor); // Converte Binário para decimal
    }

    // Mapeamento dos segmentos (a-g) para cada dígito de 1 a 8
    int segmentos[8][7] = {
        {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},  // 1
        {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},  // 2
        {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},  // 3
        {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},   // 4
        {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},  // 5
        {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH}, // 6
        {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},    // 7
        {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH} // 8
    };

    // Pinos do display correspondentes aos segmentos (a-g)
    int pinos_display[7] = {13, 12, 11, 10, 9, 8, 7};

    // Ativa os segmentos necessários para o número
    if (numero > 0 && numero <= 8) {
        for (int i = 0; i < 7; i++) {
            digitalWrite(pinos_display[i], segmentos[numero - 1][i]); // Mostra valores entre 1 e 8
        }
    }
}

// Função para exibir valores em um determinado modo (bin ou gray)
void exibir_modo(int modo[8][4], bool modo_gray) {
    for (int i = 0; i < 8; i++) { // Itera pelas linhas do array (1 a 8)
        // Atualiza as lâmpadas (A0 a A3)
        for (int j = 0; j < 4; j++) {
            digitalWrite(A0 + j, modo[i][j]);
        }

        // Atualiza o display com o mesmo valor
        exibir_no_display(modo[i], modo_gray);

        delay(1000); // Aguarda 1 segundo antes de mudar para o próximo valor
    }
}

void loop() {
    // Define os arrays binário e Gray (1 a 8)
    int bin[8][4] = {
        {0, 0, 0, 1}, // 1
        {0, 0, 1, 0}, // 2
        {0, 0, 1, 1}, // 3
        {0, 1, 0, 0}, // 4
        {0, 1, 0, 1}, // 5
        {0, 1, 1, 0}, // 6
        {0, 1, 1, 1}, // 7
        {1, 0, 0, 0}  // 8
    };

    int gray[8][4] = {
        {0, 0, 0, 1}, // 1
        {0, 0, 1, 1}, // 2
        {0, 0, 1, 0}, // 3
        {0, 1, 1, 0}, // 4
        {0, 1, 1, 1}, // 5
        {0, 1, 0, 1}, // 6
        {0, 1, 0, 0}, // 7
        {1, 1, 0, 0}  // 8
    };

    // Variável para armazenar o estado anterior do interruptor
    static int estado_anterior = LOW;

    // Lê o estado do interruptor
    int estado_atual = digitalRead(2);

    // Verifica se houve uma mudança no estado do interruptor
    if (estado_atual != estado_anterior) {
        // Desliga todas as lâmpadas e o display
        desligar();
        delay(500); // Pausa para estabilidade

        // Alterna entre os modos com base no estado do interruptor
        if (estado_atual == HIGH) {
            exibir_modo(gray, true); // Ativa o modo Gray
        } else {
            exibir_modo(bin, false); // Ativa o modo binário
        }

        // Atualiza o estado anterior
        estado_anterior = estado_atual;
    }
}
