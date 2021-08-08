const express = require('express');
// const ws = require('express-ws');

const app = express();
var expressWs = require('express-ws')(app);

const PORT = 8080;

const server = app.listen(PORT);

app.ws('/sign', (ws,req) => {
  ws.on('message', msg => {
    console.log(`Server got message ${msg.toString()}`);
    ws.send('ACK\r\n');
    // ws.send(`Server saw: ${msg.toString()}\r\n`);
  });
  ws.on('close', (code,reason) => {
    console.log(`Server saw close`)
  });
  ws.on('ping', data => {
    console.log(`Server got ping`);
    ws.pong('ok');
  });
});
//
// const wsServer = new ws.Server({ server: server, path: '/ws' });
// wsServer.on('connection', socket => {
//   console.log('Got a new connection.');
//   socket.on('message', message => {
//     console.log(`Server sees message: ${message}`);
//   })
// });
//
//
// server.on('upgrade', (request, socket, head) => {
//   wsServer.handleUpgrade(request, socket, head, socket => {
//     wsServer.emit('connection', socket, request);
//   });
// });
//
console.log(`Server listening on port ${PORT}`);
