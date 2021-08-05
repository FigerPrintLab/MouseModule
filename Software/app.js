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

/*
app.post("/", (req, res) => {
    res.send("communication succeeded");
    // console.log(req.body);
    if (req.body.type === "mousedown") {
        if (req.body.buttons === 1) {
            //console.log("trigger pulse requested");
            trigger();
        } else if (req.body.buttons === 2) {
            //console.log("gate on requested");
            gate(true);
        }
    } else if (req.body.type === "mouseup" && req.body.buttons === 2) {
        //console.log("gate off requested");
        gate(false);
    } else if (req.body.type === "mousemove") {
        // console.log("mouse moved to X: " + req.body.clientX + ", Y: " + req.body.clientY);
        move(req.body.clientX, req.body.clientY);
    }
});
*/

app.post('/mousedown1', (req, res, next) => { raspberry.trigger(); res.send(); });
app.post('/mousedown2', (req, res, next) => { raspberry.gate(true); res.send(); });
app.post('/mouseup2', (req, res, next) => { raspberry.gate(false); res.send(); });
app.post('/mousemove', (req, res, next) => { raspberry.move(req.body.clientX, req.body.clientY); res.send(); });

module.exports = app;
