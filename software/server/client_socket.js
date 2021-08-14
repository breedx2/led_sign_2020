'use strict';
const secrets = require('./secrets');

let sign;

function handleWsRequest(ws,req){
  ws.on('open', () => {
  });
  ws.on('message', msg => {
    msg = msg.toString().trim();
  });
  ws.on('close', (code,reason) => {
    console.log(`Server saw close`);
  });
  ws.on('ping', data => {
    ws.pong('ok');
  });
}

module.exports = theSign => {
  sign = theSign;
  return {
    handleWsRequest
  }
}
