# 💣 The Last Defuse – Bomba Interativa com Acessibilidade

**The Last Defuse** é uma recriação física inspirada no jogo cooperativo *Keep Talking and Nobody Explodes*, desenvolvida com **Arduino** e adaptada especialmente para promover **acessibilidade a pessoas autistas**. A proposta é criar uma experiência cooperativa real, onde um jogador interage com a bomba enquanto outros guiam o desarme por meio de um manual.

## 🎮 Funcionalidades

- **Plataforma Física com Arduino**: Estrutura construída com botões, LEDs,display LCD e outros componentes físicos.
- **Módulos Interativos**: Cada módulo da bomba apresenta desafios distintos, como sequências de luzes, senha,texturas  e fios.
- **Temporizador Real**: A bomba possui contagem progressiva para não colocar pressão nas pessoas do espectro autista.
- **Adaptação Sensorial**: Projeto pensado para minimizar estímulos visuais ou sonoros excessivos, facilitando a interação para autistas.
- **Manual do Especialista**: Um documento guia, externo à bomba, que os outros jogadores usam para ajudar no desarme.

## 🧠 Foco em Acessibilidade

- Estímulos sonoros e visuais controlados.
- Comunicação Ativa
- Feedbacks claros e previsíveis.
- Interface física intuitiva.
- Possibilidade de ajustar tempo e dificuldade.

## 🛠️ Tecnologias e Componentes

- **Microcontrolador**: Arduino Uno (ou equivalente)
- **Linguagem**: C/C++ com Arduino IDE
- **Principais Componentes**:
  - Botões táteis com texturas
  - Botão Arcade
  - LEDs indicadores
  - Display LCD 16x2 (com ou sem I2C)
  - Resistores, fios e protoboard

## 🚀 Como Usar

1. Monte o circuito conforme o esquema na pasta `/circuito/`.
2. Abra o arquivo `.ino` no Arduino IDE.
3. Conecte o Arduino via USB e envie o código para a placa.
4. Inicie o jogo com pelo menos dois participantes: um desarmador e um ou mais especialistas com o manual.

## 📸 Imagens do Projeto

Adicione imagens na pasta `imagens/` e use o seguinte código para exibir no README:

```markdown
![Foto da Bomba Montada](imagens/bomba_montada.jpg)
