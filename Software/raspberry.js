"use strict";

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
rpio.open(PIN_GATE, rpio.OUTPUT, rpio.HIGH);
rpio.open(PIN_TRIG, rpio.OUTPUT, rpio.HIGH);

exports.getRange = () => {
    return range;
}

exports.trigger = () => {
    rpio.write(PIN_TRIG, rpio.LOW);
    rpio.usleep(500);
    rpio.write(PIN_TRIG, rpio.HIGH);
    return;
}

exports.gate = (on) => {
    rpio.write(PIN_GATE, on ? rpio.LOW : rpio.HIGH);
    return;
}

exports.move = (clientX, clientY) => {
    // const x = Math.round((clientX + 0.5) * range);
    // const y = Math.round((clientY + 0.5) * range);
    rpio.pwmSetData(PIN_PWM_X, clientX);
    rpio.pwmSetData(PIN_PWM_Y, clientY);
    return;
}
