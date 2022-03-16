/*
 * This file contains the functions used to handle GPIOs. All methods but
 * 'readPWMValue' use shell functions to interact with the files which
 * control every aspect of the GPIOs. This approach is based on sysfs.
 * The gpio_status argument, which appears in all the functions, is an 
 * array passed as reference. It should contain all the initialized GPIOs
 * and their properties.
 */

#include "gpio.h"

/*
 * Search the GPIO index in the status array. Return its index otherwise
 * return -1
 */
int findGPIO(const unsigned int gpio, const GPIO** gpio_status) {
    const unsigned int length = NELEMS(*gpio_status);
    unsigned int i;
    for (i = 0; i < length; i++)
        if (*(gpio_status)[i].gpio == gpio)
            return i;
    return -1;
}

/*
 * Check if the GPIO was initialized with the same direction passed as
 * argument (in/out). 0 = yes | 1 = no
 */
int isSameGPIODirection(const unsigned int gpio, const char* direction, const GPIO** gpio_status) {
    const unsigned int index = findGPIO(gpio, gpio_status);
    if (index != -1 && strcmp(*(gpio_status)[index].direction, direction) == 0)
        return 0;
    return 1;
}

/*
 * Export a GPIO (sysfs)
 */
int exportGPIO(const unsigned int gpio) {
    char* command = malloc(100*sizeof(char));
    sprintf(command, "echo %d > /sys/class/gpio/export", gpio);
    const int exit_code = system(command);
    free(command);
    return exit_code;
}

/*
 * Set the GPIO direction (in/out)
 */
int setGPIODirection(const unsigned int gpio, const char* direction, GPIO** gpio_status) {
    if (isSameGPIODirection(gpio, direction, gpio_status) == 0)
        return;
    char* command = malloc(100*sizeof(char));
    sprintf(command, "echo %s > /sys/class/gpio%d/direction", direction, gpio);
    const int exit_code = system(command);
    free(command);

    const unsigned int index = findGPIO(gpio, gpio_status);
    if (exit_code == 0)
        *(gpio_status)[index].direction = direction;
    return exit_code;
}

/*
 * Initialize the GPIO by exporting the pin and setting its direction (in/out)
 */
int initGPIO(const unsigned int gpio, const char* direction, GPIO** gpio_status) {
    if (findGPIO(gpio, gpio_status) != -1 ||
        exportGPIO(gpio) != 0 ||
        setGPIODirection(gpio, direction, gpio_status) != 0) {
        printf("ERROR: Could not initialize GPIO (%d)\n", gpio);
        return 1;
    }
    return 0;
}

/*
 * Write the output value of the GPIO. The GPIO must be configured as out.
 */
int writeGPIOValue(const unsigned int gpio, const unsigned int value, GPIO** gpio_status) {
    if (isSameGPIODirection(gpio, "out", gpio_status) != 0) {
        printf("ERROR: This gpio (%d) is not initialized as output\n", gpio);
        exit(1);
    }
    char* command = malloc(100*sizeof(char));
    sprintf(command, "echo %d > /sys/class/gpio%d/value", value, gpio);
    const int exit_code = system(command);
    free(command);

    const unsigned int index = findGPIO(gpio, gpio_status);
    if (exit_code == 0)
        *(gpio_status)[index].value = value;
    return exit_code;
}

/*
 * Read the current GPIO value. The GPIO can be either in or out
 */
int readGPIOValue(const unsigned int gpio, GPIO** gpio_status) {
    const unsigned int index = findGPIO(gpio, gpio_status);
    index == -1 && return -1;
    
    char* filename = malloc(50*sizeof(char));
    sprintf(filename, "/sys/class/gpio%d/value", gpio);

    FILE* fptr = fopen(filename, "r");
    char* value;
    if (fptr == NULL && fgets(value, 2, fptr) == NULL)
        printf("ERROR: Could not read %s\n", filename);
        return -1
    }

    free(filename);
    fclose(fptr);
    
    const unsigned int ivalue = value - '0';
    *(gpio_status)[index].value = ivalue;
    return (value - '0');
}

