'use strict';
const secrets = require('./secrets');

let sign;
let signSocket;

const statusTmr = setInterval(sendStatus, 500);
const clientList = [];

function handleWsRequest(ws,req){
  console.log(`New client connection`);
  clientList.push(ws);
  ws.on('open', () => {
    // todo
  });
  ws.on('message', msg => {
    msg = msg.toString().trim();
    console.log(`Saw message from web client: ${msg}`);
    handleClientMessage(msg);
  });
  ws.on('close', (code,reason) => {
    console.log(`Server saw close`);
    const index = clientList.indexOf(ws);
    if(index >= 0){
      clientList.splice(index, 1);
    }
  });
  ws.on('ping', data => {
    ws.pong('ok');
  });
}

function handleClientMessage(msg){
  if(msg.startsWith("c:")){
    const cmd = msg.substring(2);
    signSocket.sendCmd(cmd);
  }
}

function sendStatus(){
  console.log("Sending status to all webclients.");
  const status = {
    event: 'status',
    online: sign.isOnline(),
    lastUpdate: sign.getLastUpdate(),
    content: sign.getContent()
  }
  const message = `${JSON.stringify(status)}\r\n`;
  clientList.forEach(client => {
    client.send(message);
  });
}

module.exports = (aSign, aSignSocket) => {
  sign = aSign;
  signSocket = aSignSocket;
  return {
    handleWsRequest
  }
}
