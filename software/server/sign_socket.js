'use strict';
const secrets = require('./secrets');

let sign;
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
  ws.on('message', msg => handleMessage(ws, msg));

  ws.on('close', (code,reason) => {
    console.log(`Server saw close`);
    if(ws === signSocket){
      signSocket = null;
      console.log('Sign has disconnected.');
      sign.setOnline(false);
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
  console.log(`Checking this auth line`);
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
      sign.setOnline(true);
      dumpTimer = setInterval(() => {
        if(!signSocket) return;
        // console.log("Asking for a dump");
        signSocket.send("dump\r\n");
      }, 500);
      return ws.send('ACK\r\n');
  }
  ws.close(); // invalid auth
}

function handleMessage(ws, msg){
  msg = msg.toString().trim();
  if(msg.startsWith("id:")){
    handleAuthLine(ws, msg);
  }
  else if(msg.startsWith("dump:")){
    handleDumpReply(msg);
  }
  else {
    console.log(`Server got message ${msg}`);
  }
}

function handleDumpReply(msg){
  // printDumpToConsole(msg);
  // dispatchUpdateToClients(msg); xxxxxxx
  sign.setLastUpdate(new Date());
  sign.setContent(msg.substr(5));
}

function printDumpToConsole(msg){
  const buff = Buffer.from(msg.substr(5), 'base64');
  for(let row=0; row < 7; row++){
    for(let rowbyte=0; rowbyte < 19; rowbyte++){
      const b = buff[(19*row) + rowbyte];
      for(let bp = 0; bp < 8; bp++){
        if((rowbyte == 0) && (bp < 8)) continue;
        if(b & (1 << bp)){
          process.stdout.write('*');
        }
        else{
          process.stdout.write(' ');
        }
      }
    }
    process.stdout.write('\r\n');
  }
}

module.exports = theSign => {
  sign = theSign;
  return {
    handleSignWsRequest
  }
}
