Projeto Arduino com Integração WhatsApp
Este projeto consiste na integração entre um dispositivo Arduino e o aplicativo WhatsApp, permitindo o envio de mensagens automáticas quando determinada condição é atendida. O Arduino monitora um sensor de gás MQ-2 e, quando o nível de gás ultrapassa um limite predefinido, uma mensagem é enviada para um número de telefone específico no WhatsApp.

Pré-requisitos
Antes de executar o projeto, certifique-se de ter o seguinte:

Arduino Uno (ou outro modelo compatível)
Sensor de gás MQ-2
Computador com Node.js instalado
Conta do WhatsApp
Instalação
Clone este repositório em sua máquina local usando o comando:

bash
Copy code
git clone https://github.com/brunocardsx/gas-Detector.git
No diretório do projeto, execute o seguinte comando para instalar as dependências do Node.js:


```shell
npm install
```
Conecte o Arduino ao computador e verifique em qual porta serial ele está sendo reconhecido.

Abra o arquivo index.js e altere a propriedade path na linha const port = new SerialPort({ path: 'COM3', baudRate: 9600 }) para corresponder à porta serial do seu Arduino.

Inicie o programa executando o comando:

```shell
node .
```
O programa agora está em execução e pronto para enviar mensagens quando o nível de gás exceder o limite especificado.

Personalização
Para personalizar a mensagem enviada pelo WhatsApp, altere o valor da variável botText na função start() em index.js.

Para ajustar o limite de gás que aciona o envio da mensagem, altere o valor da variável leitura_sensor no código do Arduino.

Contribuição
Contribuições são bem-vindas! Se você encontrar algum problema ou tiver sugestões de melhorias, sinta-se à vontade para abrir uma issue ou enviar um pull request.

Licença
Este projeto está licenciado sob a licença MIT. Consulte o arquivo LICENSE para obter mais informações.

Autores
Bruno Cardoso Montero 
Sammuel Gusmão Martins
José Carlos Neto Soares Dantas
Caio Chaves Lima
Rafael Rodrigues Souza



Agradecimentos
Agradecemos ao  Higor Viana, autor do venom-bot por fornecer a biblioteca/utilitário/inspiração que tornou este projeto possível.

Sinta-se à vontade para personalizar o conteúdo de acordo com o seu projeto, adicionando seções adicionais ou ajustando as informações conforme necessário. O objetivo principal do arquivo README.md é fornecer uma visão geral do projeto, instruções de instalação e uso, e informações sobre como contribuir ou entrar em contato com o autor.

Lembre-se de substituir as seções com informações relevantes para o seu projeto, como pré-requisitos específicos, instruções de instalação personalizadas e detalhes sobre a integração com o WhatsApp.
