'use strict';

const express = require('express');
const sign_socket = require('./sign_socket');
const client_socket = require('./client_socket');
const Sign = require('./sign.js');

const sign = new Sign();
const signWsHandler = sign_socket(sign).handleSignWsRequest

const clientWsHandler = client_socket(sign).handleWsRequest

const app = express();
var expressWs = require('express-ws')(app);
app.use(express.static('static'));

const PORT = 8080;

const server = app.listen(PORT);

app.ws('/sign', signWsHandler);
app.ws('/client', clientWsHandler);

console.log(`Server listening on port ${PORT}`);
