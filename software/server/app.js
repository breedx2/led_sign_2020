const express = require('express');
const ws = require('ws');

const app = express();

const PORT = 8080;

const wsServer = new ws.Server({ noServer: true });
wsServer.on('connection', socket => {
  socket.on('message', message => {
    console.log(`Server sees message: ${message}`);
  })
});

const server = app.listen(PORT);

server.on('upgrade', (request, socket, head) => {
  wsServer.handleUpgrade(request, socket, head, socket => {
    wsServer.emit('connection', socket, request);
  });
});

console.log(`Server listening on port ${PORT}`);
