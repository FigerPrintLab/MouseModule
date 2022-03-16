/*
 * PWM header file
 */

#ifndef PWM_H
    #define PWM_H
#endif

#include <stdio.h>
#include <stdlib.h>

/* The following functions return the exit code of the shell functions they call */
int togglePWM(const unsigned int channel, const unsigned int enable);
int setPWMPeriod(const unsigned int channel, const unsigned int period);
int setPWMDutyCycle(const unsigned int channel, const unsigned int duty_cycle);
int writePWMParameter(const unsigned int chan, const char* param, const unsigned int val);

/* This function returns the value requested otherwise -1 */
int readPWMParameter(const unsigned int chan, const char* param);

