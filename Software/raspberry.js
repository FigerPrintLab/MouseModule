"use strict";

const PIN_REC = 7;
const PIN_PB = 11;
const PIN_PWM_X = 12;
const PIN_GATE = 29;
const PIN_TRIG = 31;
const PIN_PWM_Y = 33;
const range = 1024;
const clockdiv = 8;
const rpio = require("rpio");

rpio.open(PIN_PWM_X, rpio.PWM);
rpio.open(PIN_PWM_Y, rpio.PWM);
rpio.pwmSetClockDivider(clockdiv);
rpio.pwmSetRange(PIN_PWM_X, range);
rpio.pwmSetRange(PIN_PWM_Y, range);

rpio.open(PIN_REC,  rpio.OUTPUT, rpio.LOW);
rpio.open(PIN_PB,   rpio.OUTPUT, rpio.LOW);
rpio.open(PIN_GATE, rpio.OUTPUT, rpio.HIGH);
rpio.open(PIN_TRIG, rpio.OUTPUT, rpio.LOW);

exports.getRange = () => {
    return range;
}

exports.trigger = () => {
    rpio.write(PIN_TRIG, rpio.HIGH);
    rpio.usleep(10000);
    rpio.write(PIN_TRIG, rpio.LOW);
    return;
}

exports.gate = (on) => {
    rpio.write(PIN_GATE, on ? rpio.LOW : rpio.HIGH);
    return;
}

exports.rec_pb = (rec, pb) => {
    rpio.write(PIN_REC, rec ? rpio.HIGH: rpio.LOW);
    rpio.write(PIN_PB, pb ? rpio.HIGH: rpio.LOW);
    return;
}

exports.move = (clientX, clientY) => {
    // const x = Math.round((clientX + 0.5) * range);
    // const y = Math.round((clientY + 0.5) * range);
    rpio.pwmSetData(PIN_PWM_X, clientX);
    rpio.pwmSetData(PIN_PWM_Y, clientY);
    return;
}
