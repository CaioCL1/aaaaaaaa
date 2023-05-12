import { create } from 'venom-bot'; // Importa a função 'create' do pacote 'venom-bot'
import { SerialPort } from 'serialport'; // Importa a classe 'SerialPort' do pacote 'serialport'
import { ReadlineParser } from '@serialport/parser-readline'; // Importa a classe 'ReadlineParser' do pacote 'serialport/parser-readline'

// Cria uma instância de 'SerialPort' para se comunicar com a porta serial COM3
const port = new SerialPort({ path: 'COM3', baudRate: 9600 });

// Cria uma instância de 'ReadlineParser' para fazer a leitura das linhas recebidas da porta serial
const parser = port.pipe(new ReadlineParser({ delimiter: '\r\n' }));

// Configura um evento para imprimir no console as mensagens recebidas pela porta serial
parser.on('data', console.log);

// Cria uma sessão no WhatsApp usando o pacote 'venom-bot'
create({
  session: 'chat-gpt',
  multidevice: true,
})
  .then((client) => start(client)) // Inicia o cliente quando a sessão é criada com sucesso
  .catch((erro) => {
    console.log(erro); // Exibe no console caso ocorra algum erro na criação da sessão
  });

// Função assíncrona para iniciar o cliente do WhatsApp
async function start(client) {
  const botText = "🤖 world 🌎"; // Mensagem a ser enviada

  // Configura um evento para verificar se a mensagem recebida é "Ativar" e enviar uma mensagem de resposta
  parser.on('data', (mensagem) => {
    if (mensagem.trim() === 'Ativar') {
      // Envia a mensagem para o número de telefone
      client
        .sendText(PHONE_NUMBER, botText)
        .then((result) => {
          console.log('Result: ', result); // Exibe no console o resultado do envio da mensagem
        })
        .catch((error) => {
          console.error('Error when sending: ', error); // Exibe no console caso ocorra um erro no envio da mensagem
        });
    }
  });
}