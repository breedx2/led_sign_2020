'use strict';
const express = require('express');
const sign_socket = require('./sign_socket');

const app = express();
var expressWs = require('express-ws')(app);

const PORT = 8080;

const server = app.listen(PORT);

app.ws('/sign', sign_socket.handleSignWsRequest);

console.log(`Server listening on port ${PORT}`);
