# Tank 32

Tank 32 é um projeto de robô com controle via Wi-Fi, construído com dois servomotores 9g e, inicialmente, um ESP32-C3 Super Mini. A ideia é, futuramente, migrar para um ESP32-CAM para permitir captura de vídeo e visualização em tempo real enquanto o robô é controlado.

## Visão Geral

O chassi do robô foi modelado para otimizar a disposição dos componentes e garantir estabilidade e mobilidade. A estrutura permite que os servos movimentem as rodas do robô, proporcionando controle direcional.

O ESP32 cria uma rede Wi-Fi à qual eu me conecto para acessar uma página web. Através desta página, é possível controlar o robô remotamente, aproveitando os benefícios de um sistema de controle independente, sem a necessidade de uma conexão à Internet.

## Funcionalidades

- **Controle por Wi-Fi:** O ESP32 cria uma rede Wi-Fi para a qual o usuário pode se conectar.
- **Interface Web:** Através do IP do ESP32, uma página web é acessada para visualizar e controlar o robô.
- **Futuro Upgrade:** Implementação do ESP32-CAM para captura de vídeo ao vivo, aprimorando a experiência de controle.

## Componentes Utilizados

- **ESP32-C3 Super Mini** (atualmente, com possível migração para o ESP32-CAM no futuro)
- **Servomotores 9g** (2 unidades)
- **Chassi 3D Modelado** para acomodar todos os componentes

## Modelagem e Design

O chassi foi projetado para ser leve e resistente, proporcionando uma base sólida para os servos e o ESP32. Abaixo estão algumas imagens 3D do projeto:

<p float="left">
  <img src="/3D/images/1.png" width="250" />

  <img src="/3D/images/2.png" width="250" />

  <img src="/3D/images/3.png" width="250" />
  <p float="left">
  <img src="/3D/images/5.png" width="250" />
  <img src="/3D/images/4.png" width="250" />

  

## Instalação e Uso

1. **Conecte-se ao Wi-Fi do ESP32:** O dispositivo criará uma rede Wi-Fi com o nome `Tank32`.
2. **Acesse a página de controle:** Abra um navegador e digite o endereço IP fornecido pelo ESP32 para visualizar a interface de controle do robô.
3. **Controle o robô:** Use os controles disponíveis na página para movimentar o robô e explorar o ambiente.

## Futuras Implementações

- **Migração para ESP32-CAM:** Integração de vídeo ao vivo para melhorar a experiência de controle remoto.
- **Novas funcionalidades na página web:** Controles adicionais para movimentação e, possivelmente, outros sensores e funcionalidades.

---

Sinta-se à vontade para contribuir, relatar problemas ou sugerir melhorias! Este é um projeto em constante desenvolvimento e toda ajuda é bem-vinda.

