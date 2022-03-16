/*
 * This file contains the function that handles any PWM parameter
 * (writePWMParameter) and some more specific utilities which may
 * turn useful.
 * All methods but 'readPWMParameter' use shell functions to write 
 * files that control every aspect of the PWM signals. This approach 
 * is based on sysfs.
 */

#include "pwm.h"

int togglePWM(const unsigned int channel, const unsigned int enable) {
    char* command = malloc(100*sizeof(char));
    sprintf(command, "echo %d > /sys/class/pwm/pwmchip0/pwm%d/enable", enable, channel);
    const int exit_code = system(command);
    free(command);
    return exit_code;
}

int setPWMPeriod(const unsigned int channel, const unsigned int period) {
    char* command = malloc(100*sizeof(char));
    sprintf(command, "echo %d > /sys/class/pwm/pwmchip0/pwm%d/period", period, channel);
    const int exit_code = system(command);
    free(command);
    return exit_code;
}

int setPWMDutyCycle(const unsigned int channel, const unsigned int duty_cycle) {
    char* command = malloc(100*sizeof(char));
    sprintf(command, "echo %d > /sys/class/pwm/pwmchip0/pwm%d/period", duty_cycle, channel);
    const int exit_code = system(command);
    free(command);
    return exit_code;
}

int writePWMParameter(const unsigned int chan, const char* param, const unsigned int val) {
    char* command = malloc(100*sizeof(char));
    sprintf(command, "echo %d > /sys/class/pwm/pwmchip0/pwm%d/%s", val, chan, param);
    const int exit_code = system(command);
    free(command);
    return exit_code;
}

int readPWMParameter(const unsigned int chan, const char* param) {
    char* filename = malloc(50*sizeof(char));
    sprintf(filename, "/sys/class/pwm/pwmchip0/pwm%d/%s", chan, param);

    FILE* fptr = fopen(filename, "r");
    if (fptr == NULL)
        printf("ERROR: Could not open %s\n", filename);
        return -1
    }

    unsigned int value
    fscanf(fptr, "%d", &value);

    free(filename);
    fclose(fptr);
    return value;
}
