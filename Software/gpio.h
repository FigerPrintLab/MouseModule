/*
 * GPIO header file
 */

#ifndef GPIO_H
    #define GPIO_H
#endif

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const unsigned int gpio;
    char direction[3];
    unsigned int value;
} GPIO;

int findGPIO(const unsigned int gpio, const GPIO** gpio_status);                                   // -1 = not found
int isSameGPIODirection(const unsigned int gpio, const char* direction, const GPIO** gpio_status); // 0 = yes | 1 = no
int exportGPIO(const unsigned int gpio);                                                           // exit_code
int setGPIODirection(const unsigned int gpio, const char* direction, GPIO** gpio_status);          // exit_code
int initGPIO(const unsigned int gpio, const char* direction, GPIO** gpio_status);                  // 0 = ok | 1 = error
int writeGPIOValue(const unsigned int gpio, const unsigned int value, GPIO** gpio_status);         // exit_code
int readGPIOValue(const unsigned int gpio, GPIO** gpio_status);                                    // -1 = error | value 

