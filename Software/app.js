#! /usr/bin/env node
'use strict';

const path = require('path');
const express = require('express');
const bodyParser = require('body-parser');
const raspberry = require('./raspberry');

const app = express();

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use(express.static(path.join(__dirname, 'client')));

app.get('/', function(req, res) {
    res.sendFile(path.join(__dirname, 'index.html'));
    return;
});

app.get('/favicon.ico', function(req, res) {
    res.sendFile(path.join(__dirname, 'favicon.ico'));
    return;
});

app.post('/mousedown1', (req, res, next) => { raspberry.trigger(); res.send(); });
app.post('/mousedown2', (req, res, next) => { raspberry.gate(true); res.send(); });
app.post('/mouseup2',   (req, res, next) => { raspberry.gate(false); res.send(); });
app.post('/record',     (req, res, next) => { raspberry.rec_pb(req.body.rec_state, req.body.pb_state); res.send(); });
app.post('/mousemove',  (req, res, next) => { raspberry.move(req.body.clientX, req.body.clientY); res.send(); });

module.exports = app;
