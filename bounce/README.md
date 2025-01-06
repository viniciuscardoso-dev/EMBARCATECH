# Bounce e Debounce no Arduino

Este repositório contém dois códigos que demonstram o fenômeno de **bounce** em botões mecânicos e como solucioná-lo utilizando a técnica de **debounce** no Arduino.

## O que é Bounce?

Quando pressionamos ou soltamos um botão mecânico, o seu estado (ligado/desligado) não muda de forma instantânea. Em vez disso, o botão pode oscilar rapidamente entre **ALTO** e **BAIXO** por um curto período de tempo (geralmente alguns milissegundos).

Esse efeito é chamado de **bounce** e pode gerar problemas em circuitos eletrônicos, tais como:
- Oscilações indesejadas no estado de componentes (ex: LEDs).
- Leituras imprecisas ou instáveis no Arduino.

## O que é Debounce?

**Debounce** é uma técnica para "filtrar" o efeito de bounce, garantindo que o estado do botão seja considerado como estável apenas após um pequeno intervalo de tempo. Isso evita que múltiplas oscilações rápidas sejam interpretadas como comandos válidos pelo Arduino.

## Códigos Disponíveis

### 1. `bounce.ino`
Este código demonstra o comportamento do bounce sem a aplicação de nenhuma técnica de debounce. Ele detecta e exibe as rápidas oscilações no estado do botão, mostrando no Monitor Serial sempre que o estado do botão muda.

- **Problema:** Você observará mudanças rápidas entre "ALTO" e "BAIXO" ao pressionar ou soltar o botão, mesmo que o botão esteja sendo pressionado de forma constante.
- **Objetivo:** Permite observar o efeito do bounce de forma clara.

### 2. `debounce.ino`
Este código implementa a técnica de debounce para eliminar as oscilações causadas pelo bounce. Ele espera um intervalo de 50ms após detectar uma mudança no botão antes de considerar o novo estado como estável.

- **Solução:** As oscilações rápidas no estado do botão são ignoradas, e o LED reflete apenas o estado estável do botão.
- **Como funciona:**
  - Ao detectar uma mudança no estado do botão, o código registra o tempo da mudança utilizando a função `millis()`.
  - Antes de atualizar o estado do botão, ele verifica se se passaram pelo menos 50ms desde a última mudança.
  - Apenas mudanças persistentes por mais de 50ms são consideradas válidas.

## Como Usar os Códigos

1. Faça o upload do arquivo `bounce.ino` para o Arduino para observar o efeito do bounce.
2. Faça o upload do arquivo `debounce.ino` para ver como o problema do bounce é resolvido via software.

### Passos para Carregar o Código:

1. Abra o arquivo `.ino` no Arduino IDE.
2. Conecte o Arduino ao computador.
3. Selecione a placa e a porta corretas.
4. Faça o upload do código.
5. Abra o **Monitor Serial** para observar as saídas.

## Benefícios do Debounce

- Garante leituras estáveis do botão.
- Melhora a confiabilidade do circuito.
- Proporciona uma experiência mais consistente ao interagir com o botão.

---

Com este material, você pode entender e corrigir o efeito de bounce em projetos que utilizam botões mecânicos, tornando suas interações mais confiáveis e precisas! 😊
