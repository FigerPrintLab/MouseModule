/*
 * This is a demo of the pigpio library. Make sure
 * to install it by running:
 * # apt install -y pigpio
 *
 * Then you must compile with flags:
 * $ gcc -Wall -pthread -o testGPIO testGPIO.c -lpigpio -lrt
 * 
 * You need to run the executable as root user.
 */

#include <stdio.h>
#include <time.h>
#include <pigpio.h>

#define PWM_GPIO 18
#define DIG_GPIO 17

int gpioToggle(unsigned gpio);
int pwmSwipe(unsigned gpio);

int main() {
    if (gpioInitialise() < 0) return -1;
    // gpioToggle(DIG_GPIO);
    // pwmSwipe(PWM_GPIO);
    gpioTerminate();
    return 0;
}

int gpioToggle(unsigned gpio) {
    if (gpioSetMode(gpio, PI_OUTPUT) != 0) return -1;
    
    unsigned i;
    unsigned state = 1;
    for (i = 0; i < 8; i++) {
        if (gpioWrite(gpio, state) != 0) {
            printf("ERROR: Could not write gpio\n");
            return -1;
        }
        sleep(1);
        state == 0 ? (state = 1) : (state = 0);
    }
    return 0;
}

int pwmSwipe(unsigned gpio) {
    printf("Starting PWM...\n");
    unsigned freq = PI_HW_PWM_MAX_FREQ/100000;
    float d = 1.0;

    while (d > 0.0) {
        gpioHardwarePWM(gpio, freq, d*PI_HW_PWM_RANGE);
        d -= 0.01;
        clock_t start = clock();
        while (clock() - start < 0.03*CLOCKS_PER_SEC) {
        }
    }

    printf("Stop PWM.\n");
    gpioHardwarePWM(gpio, 0, 0);
    return 1;
}
