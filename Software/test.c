#include <stdio.h>
#include "pwm.h"

int main() {
    printf("Starting PWM...\n");
    int exit_code;
    if (exit_code = writePWMParameter(0, "period",     2000000) != 0)
        exit(exit_code);
    if (exit_code = writePWMParameter(0, "duty_cycle", 1000000) != 0)
        exit(exit_code);
    if (exit_code = writePWMParameter(0, "enable",     1)       != 0)
        exit(exit_code);
    
    sleep(2);
    printf("PWM\tenable: %d\tperiod: %d\tduty_cycle: %d\n",
            readPWMParameter(0, "enable"),
            readPWMParameter(0, "period"),
            readPWMParameter(0, "duty_cycle"));
    sleep(2);
    printf("Stopping PWM\n");
    if (exit_code = writePWMParameter(0, "enable",     0) != 0)
        exit(exit_code);
    return 0;
}

