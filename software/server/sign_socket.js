'use strict';
const secrets = require('./secrets');

let signSocket;
let pending = {};
let dumpTimer;

function handleSignWsRequest(ws,req){
  ws.on('open', () => {
    const tmr = setTimeout(() => {
      console.log("Auth timed out. Closing.");
      signSocket = null;
      clearInterval(dumpTimer);
      dumpTimer = null;
      ws.close();
    }, 5000);
    pending[ws] = tmr;
  });
  ws.on('message', msg => {
    msg = msg.toString().trim();
    console.log(`Server got message ${msg}`);
    if(msg.startsWith("id:")){
      handleAuthLine(ws, msg);
    }
  });
  ws.on('close', (code,reason) => {
    console.log(`Server saw close`);
    if(ws === signSocket){
      signSocket = null;
      console.log('Sign has disconnected.');
    }
  });
  ws.on('ping', data => {
    if(ws === signSocket){
      console.log(`Sign sent ping.`);
      ws.pong('ok');
    }
  });
}

function handleAuthLine(ws, msg){
  console.log(`Checking this auth line: '${msg}'`);
  if(signSocket){ // already have an authed sign
    return ws.close();
  }
  if(secrets.token === msg.substr(3)){
      console.log("The sign has connected.");
      if(pending[ws]){
        clearTimeout(pending[ws]);
        delete pending[ws];
      }
      signSocket = ws;
      dumpTimer = setInterval(() => {
        console.log("Asking for a dump");
        signSocket.send("dump\r\n");
      }, 5000);
      return ws.send('ACK\r\n');
  }
  ws.close(); // invalid auth
}

module.exports = {
  handleSignWsRequest
}
