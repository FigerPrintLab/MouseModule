/*
 * This program read some significant mouse events and use
 * them to generate analog signals through the Raspberry PI
 * GPIOs.
 *
 * TODO:
 *  - Handle interrupt signal
 *  - Pass argument as pointer (more efficient than copying the whole struct)
 *  - Should we implement a mutex for the thread variables which are handles also in erase()?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pigpio.h>
#include "event.h"

int main(int argc, char** argv)
{
    FILE *devices, *mouse;
    struct input_event systemEvent;
    struct str_event myEvent;

    /* Open the devices file */
    devices = fopen("/proc/bus/input/devices", "r");
    if (devices == NULL) {
        printf("ERROR: Unable to read /proc/bus/input/devices\n");
    }

    /* Get the file path corresponding to the mouse */
    char filePath[18] = "/dev/input/";
    char name[10];
    if (getFileName(devices, name))
        strcat(filePath, name);
    else
        printf("ERROR: Unable to find the mouse file\n");

    /* Open the mouse file */
    mouse = fopen(filePath, "r");
    if(mouse == NULL) {
        printf("ERROR: Unable to read %s\n", filePath);
        return EXIT_FAILURE;
    } else {
        printf("OPENINIG %s\n", filePath);
    }

    /* Initialize the gpios */
    if (gpioInitialise() < 0) return EXIT_FAILURE;
    gpioHardwarePWM(PWM_0, 0, 0);
    gpioHardwarePWM(PWM_1, 0, 0);
    if (gpioSetMode(GATE, PI_OUTPUT) != 0) return EXIT_FAILURE;
    if (gpioSetMode(TRIG, PI_OUTPUT) != 0) return EXIT_FAILURE;
    if (gpioSetMode(REC,  PI_OUTPUT) != 0) return EXIT_FAILURE;
    if (gpioSetMode(PB,   PI_OUTPUT) != 0) return EXIT_FAILURE;

    /* Event polling loop */
    // unsigned long i = 0;
    while(1) {
        /* Read from the mouse file */
        size_t bytes = fread(&systemEvent, sizeof(struct input_event), 1, mouse);

        /* If we managed to read some bytes, print the relative events */
        if (bytes > 0) {
            // printRaw(i, &systemEvent);
            setStrEvent(&systemEvent, &myEvent);
            // printHuman(i, &myEvent);
            // printFunctional(&myEvent, &rec, &mode);
            handle(&systemEvent);
            /* Uncomment to get the incremental number of events */
            // i++;
        }
    }
    gpioTerminate();
    return EXIT_SUCCESS;
}
