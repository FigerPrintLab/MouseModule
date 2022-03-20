/*
 * Event header file
 */

#ifndef EVENT_H
    #define EVENT_H
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <pthread.h>
#include <linux/input.h>
#include <regex.h>
#include <pigpio.h>

/* GPIO & PWM parameters */
#define PWM_0 18
#define PWM_1 13
#define GATE   5
#define TRIG   6
#define REC    4
#define PB    17
#define FREQ  PI_HW_PWM_MAX_FREQ / 100000
#define CONST PI_HW_PWM_RANGE / (2 * MAX_POS)

/*
 * Uncomment these lines to skip some events or some infos
 * from being printed
 */
#define NO_INDEX
//#define NO_TIME
//#define NO_OTHER
#define NO_SYN
//#define NO_BTN
//#define NO_REL
//#define NO_ABS

/*
 * Maximum & minimum mouse position & attenuation
 */
#define MAX_POS 1000
#define MIN_POS -MAX_POS
#define MAX_ATT 10

/* 
 * Human readable event struct
 */
struct str_event {
    long double timestamp;
    const char* type;
    const char* code;
    int value;
};

/*
 * Dynamically allocated event array
 */
typedef struct {
    struct input_event* array;
    unsigned int length;
} List;

/*
 * Object to store the current status
 */
typedef struct {
    int x, y, max, min, offset, attenuation;
    bool mode;
} Status;

/*
 * Thread data
 */
typedef struct {
    pthread_t id;
    List list;
    Status start;
    Status* status;
    bool* stop;
} Thread;

/*
 * Function declarations
 */
bool getFileName(FILE* fp, char* name);
void printRaw(unsigned long i, const struct input_event* event);
const char* getCode(const char* type, const unsigned short c);
void setStrEvent(const struct input_event* systemEvent, struct str_event* event);
void printHuman(unsigned long i, const struct str_event* event);
void printFunctional(const struct str_event* event, bool* rec, bool* mode);
void pushEvent(Thread* thread, const struct input_event* event);
void stopThread(Thread* thread);
void trigger(const long double t, const struct input_event* event);
void gate(const long double t, const struct input_event* event);
void changeMode(const long double t, const struct input_event* event, bool* mode);
void* handlePlayback(void* arg);
void playback(bool* pb, Thread* thread);
void erase(bool* pb, Thread* thread, bool* stop);
void record(const long double t, const struct input_event* event, bool* rec, bool* pb, Status* status, Thread* thread);
void printStatus(const Status* s);
void move(const long double t, const struct input_event* event, const bool axis, int* val, int* max, int* min);
void wheel(int* attenuation, int* offset, const long double t, const struct input_event* event, const bool* mode);
void updatePosition(int* x, int* y, int* max, int* min, const int* attenuation, const int* offset);
void handle(const struct input_event* event);

