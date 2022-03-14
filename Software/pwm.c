#include "pwm.h"

int togglePWM(const unsigned int channel, const unsigned int enable) {
    char* command = malloc(100*sizeof(char));
    sprintf(command, "echo %d > /sys/class/pwm/pwmchip0/pwm%d/enable", enable, channel);
    const int = system(command);
    free(command);
    return int;
}

int setPWMPeriod(const unsigned int channel, const unsigned int period) {
    char* command = malloc(100*sizeof(char));
    sprintf(command, "echo %d > /sys/class/pwm/pwmchip0/pwm%d/period", period, channel);
    const int = system(command);
    free(command);
    return int;
}

int setPWMDutyCycle(const unsigned int channel, const unsigned int duty_cycle) {
    char* command = malloc(100*sizeof(char));
    sprintf(command, "echo %d > /sys/class/pwm/pwmchip0/pwm%d/period", duty_cycle, channel);
    const int = system(command);
    free(command);
    return int;
}

int writePWMParameter(const unsigned int chan, const char* param, const unsigned int val) {
    char* command = malloc(100*sizeof(char));
    sprintf(command, "echo %d > /sys/class/pwm/pwmchip0/pwm%d/%s", val, chan, param);
    const int = system(command);
    free(command);
    return int;
}

