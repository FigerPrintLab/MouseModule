#include <stdio.h>
#include <stdlib.h>

void testFile(const FILE* ptr, const char* filename);
void loop(FILE* fptr, unsigned int* duty, const unsigned int period);

int main (int argc, char** argv) {
    FILE* pwm0_period = fopen("/sys/class/pwm/pwmchip0/pwm0/period", "w");
    FILE* pwm0_duty   = fopen("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", "w");
    FILE* pwm0_enable = fopen("/sys/class/pwm/pwmchip0/pwm0/enable", "w");
    testFile(pwm0_period, "period");
    testFile(pwm0_duty,   "duty_cycle");
    testFile(pwm0_enable, "enable");

    unsigned int period = 2000000;
    unsigned int duty   = 1000000;

    // fprintf(pwm0_period, "%d", period);
    // fprintf(pwm0_duty, "%d", duty);
    // fprintf(pwm0_enable, "%d", 1);

    if (system("echo 2000000 > /sys/class/pwm/pwmchip0/pwm0/period") != 0) {
        printf("ERROR: Could not set period\n");
        exit(1);
    }
    if (system("echo 1000000 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle") != 0) {
        printf("ERROR: Could not set duty cycle\n");
        exit(1);
    }
    if (system("echo 1 > /sys/class/pwm/pwmchip0/pwm0/enable") != 0) {
        printf("ERROR: Could not enable pwm\n");
        exit(1);
    }
    sleep(10);

    if (system("echo 0 > /sys/class/pwm/pwmchip0/pwm0/enable") != 0) {
        printf("ERROR: Could not disable pwm\n");
        exit(1);
    }
    // fprintf(pwm0_enable, "%d", 0);
    fclose(pwm0_period);
    fclose(pwm0_duty);
    fclose(pwm0_enable);
    return 0;
}

void testFile(const FILE* fptr, const char* filename) {
    if (fptr == NULL) {
        printf("ERROR: unable to open %s", filename);
        exit(1);
    }
}

void loop(FILE* fptr, unsigned int* duty, const unsigned int period) {
    const unsigned int increment = 100000;
    unsigned int i;
    for (i = 0; i < 10; i++) {
        printf("i = %d\n", i);
        *duty = 100000;
        while (*duty < period) {
            sleep(1);
            printf("\tDuty cycle: %d\n", duty);
            fprintf(fptr, "%d", duty);
            duty += increment;
        }
    }
}
