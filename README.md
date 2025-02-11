# 📌 Controle de Servomotor por PWM no Raspberry Pi Pico W
## 📖 Descrição do Projeto
Este projeto tem como objetivo a simulação do controle de um servomotor utilizando o módulo PWM (Pulse Width Modulation) presente no microcontrolador RP2040.
A simulação será conduzida no simulador de eletrônica online Wokwi, permitindo o ajuste da posição do servomotor por meio da variação do ciclo de trabalho do PWM.

## 🎯 Objetivos do Projeto

- Configurar a GPIO 22 para gerar um sinal PWM com frequência de aproximadamente 50 Hz (período de 20 ms);

- Definir ciclos ativos específicos para posicionar o servomotor nos ângulos 0°, 90° e 180°;

- Criar uma rotina para movimentação suave do servo entre os ângulos 0° e 180°, ajustando o ciclo ativo em incrementos de ±5 µs a cada 10 ms;

- Integrar um LED RGB no GPIO 12 para visualizar a movimentação do servo utilizando a ferramenta educacional BitDogLab.
## 🖥️ Requisitos

- Raspberry Pi Pico W (ou simulação no Wokwi);

- VS Code com as extensões Raspberry Pi Pico e Wokwi instaladas;

- SDK do Raspberry Pi Pico configurado;

- CMake para compilação do projeto;


## 🔧 Funcionalidades Implementadas

- 1️⃣ Configuração do PWM na GPIO 22

  - ✅ Frequência ajustada para 50 Hz (período de 20 ms);

- 2️⃣ Posicionamento do Servomotor

  - ✅ 180° (ciclo ativo de 2400 µs) - Aguarda 5s;

  - ✅ 90° (ciclo ativo de 1470 µs) - Aguarda 5s;

  - ✅ 0° (ciclo ativo de 500 µs) - Aguarda 5s;

- 3️⃣ Movimentação Suave do Servo

  - ✅ Variando o ciclo ativo em incrementos de ±5 µs a cada 10 ms;

- 4️⃣ Interação com LED RGB (GPIO 12)

  - ✅ Integração com BitDogLab para visualizar a movimentação do servo via LED RGB;

  - ✅ Observação do comportamento da iluminação do LED conforme a movimentação do servo.

## 🚀 Como Executar o Projeto
1. Clone este repositório:
   
```bash
   git clone https://github.com/lucaasifx/uart-task.git
```


2. Abra o projeto no VS Code.

3. Certifique-se de que as extensões **Raspberry Pi Pico** e **Wokwi** estão instaladas e configuradas corretamente.
4. Clique no ícone da extensão da Pico:<br>
  ![image](https://github.com/user-attachments/assets/28cdb91b-16e2-4687-a6a1-950f219ddf34)
5. Selecione importar projeto para que a pasta build seja gerada automaticamente:<br>
![image](https://github.com/user-attachments/assets/b0dc78cd-f619-4648-9b5b-d509c65800d7)
  - Selecione o caminho do projeto e clique em Import:<br>
![image](https://github.com/user-attachments/assets/c83813b1-d472-414f-8285-1c85ebf73e1b)


6. Navegue até a opção Compilar Projeto:<br>
![image](https://github.com/user-attachments/assets/366a506d-171c-4c30-9577-e61d1575da33)
7. Abra o arquivo ```diagram.json``` e inicie a simulação:<br>
![image](https://github.com/user-attachments/assets/6f068166-32a4-40fb-b1bc-dbc9e86e956e)

## 🎥 Demonstração

📌 Um vídeo de demonstração foi gravado, apresentando:

- ✅ Explicação das funcionalidades;

- ✅ Execução do código na placa Raspberry Pi Pico W;

- ✅ Interação com LED RGB e movimentação do servo;
- 🔗 [Acesse o vídeo de demonstração](https://www.youtube.com/)
##
