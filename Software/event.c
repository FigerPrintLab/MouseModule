/*
 * This program captures some significant mouse events
 * and displays them in a human readable format. The 
 * strings are taken from the definitions in "linux/input.h"
 * Missing: VALUE field in myEvent
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/time.h>
#include <linux/input.h>

/*
 * Uncomment these lines to skip some events or some infos
 */
#define NO_INDEX
//#define NO_TIME
#define NO_OTHER
#define NO_SYN
//#define NO_BTN
//#define NO_REL
//#define NO_ABS

/* 
 * Human readable event struct
 */
struct str_event {
    long double timestamp;
    const char* type;
    const char* code;
    unsigned int value;
};

/*
 * Print the raw event
 */
void printRaw(unsigned int i, const struct input_event* event) {
    printf("%d.\nsec: %ld, usec: %ld type: 0x%x, code: 0x%x, value: %d\n",
    i, event->time.tv_sec, event->time.tv_usec, event->type, event->code, event->value);
}

/* 
 * Transform CODE field in a string value based 
 * on the TYPE field
 */
const char* getCode(const char* type, const unsigned short c) {
    //printf("B) TYPE: %s, CODE: 0x%x\n", type, c);
    if (strcmp(type,"EV_SYN") == 0) {
        switch(c) {
            case SYN_REPORT:
                return "SYN_REPORT";
                break;
            case SYN_CONFIG:
                return "SYN_CONFIG";
                break;
            case SYN_MT_REPORT:
                return "SYN_MT_REPORT";
                break;
            case SYN_DROPPED:
                return "SYN_DROPPED";
                break;
            case SYN_MAX:
                return "SYN_MAX";
                break;
            case SYN_CNT:
                return "SYN_CNT";
                break;
            default:
                return "SYN_NOT_KNOWN";
                break;
        }
    } else if (strcmp(type,"EV_KEY") == 0) {
        switch(c) {
            case BTN_LEFT:
                return "BTN_LEFT";
                break;
            case BTN_RIGHT:
                return "BTN_RIGHT";
                break;
            case BTN_MIDDLE:
                return "BTN_MIDDLE";
                break;
            case BTN_SIDE:
                return "BTN_SIDE";
                break;
            case BTN_EXTRA:
                return "BTN_EXTRA";
                break;
            case BTN_FORWARD:
                return "BTN_FORWARD";
                break;
            case BTN_BACK:
                return "BTN_BACK";
                break;
            case BTN_TASK:
                return "BTN_TASK";
                break;
            default:
                return "BTN_OTHER";
                break;
        }
    } else if (strcmp(type, "EV_REL") == 0) {
        switch(c) {
            case REL_X:
                return "REL_X";
                break;
            case REL_Y:
                return "REL_Y";
                break;
            case REL_RX:
                return "REL_RX";
                break;
            case REL_RY:
                return "REL_RY";
                break;
            case REL_HWHEEL:
                return "REL_HWHEEL";
                break;
            case REL_WHEEL:
                return "REL_WHEEL";
                break;
            default:
                return "REL_OTHER";
                break;
        }
    } else if (strcmp(type,"EV_ABS") == 0) {
        switch(c) {
            case ABS_X:
                return "ABS_X";
                break;
            case ABS_Y:
                return "ABS_Y";
                break;
            case ABS_RX:
                return "ABS_RX";
                break;
            case ABS_RY:
                return "ABS_RY";
                break;
            case ABS_WHEEL:
                return "ABS_WHEEL";
                break;
            default:
                return "ABS_OTHER";
                break;
        }
    } else {
        return "CODE_OTHER";
    }
}

/*
 * Set the human readable event from the raw event
 */
void setStrEvent(const struct input_event* systemEvent, struct str_event* event) {
    if (systemEvent->type == EV_SYN) {
        event->type = "EV_SYN";
    } else if (systemEvent->type == EV_KEY) {
        event->type = "EV_KEY";
    } else if (systemEvent->type == EV_REL) {
        event->type = "EV_REL";
    } else if (systemEvent->type == EV_ABS) {
        event->type = "EV_ABS";
    } else {
        event->type = "TYPE_OTHER";
    }

    event->timestamp = (double) systemEvent->time.tv_sec + 0.000001 * (double) systemEvent->time.tv_usec;
    event->value = systemEvent->value;
    event->code = getCode(event->type, systemEvent->code);
}

/*
 * Print the human readable event
 */
void printHuman(unsigned int i, const struct str_event* event) {
    #ifdef NO_OTHER
	if(strcmp(event->type, "TYPE_OTHER") == 0) return;
    #endif

    #ifdef NO_SYN
        if (strcmp(event->type,"EV_SYN") == 0) return;
    #endif
    
    #ifdef NO_BTN
        if (strcmp(event->type,"EV_KEY") == 0) return;
    #endif
    
    #ifdef NO_REL
        if (strcmp(event->type,"EV_REL") == 0) return;
    #endif

    #ifdef NO_ABS
        if (strcmp(event->type,"EV_ABS") == 0) return;
    #endif
    
    #ifdef NO_TIME
        #ifdef NO_INDEX 
            printf("Type: %s, Code: %s, Value: %d\n",
            event->type, event->code, event->value);
	#else
            printf("%d.\nType: %s, Code: %s, Value: %d\n",
            i, event->type, event->code, event->value);
	#endif
    #else
	#ifdef NO_INDEX
            printf("Time: %Lf, Type: %s, Code: %s, Value: %d\n",
            event->timestamp, event->type, event->code, event->value);
	#else
            printf("%d.\nTime: %Lf, Type: %s, Code: %s, Value: %d\n",
            i, event->timestamp, event->type, event->code, event->value);
        #endif
    #endif
}

void printFunctional(const struct str_event* event, bool* rec, bool* mode) {
    if (strcmp(event->type, "TYPE_OTHER") == 0) return;
    else if (strcmp(event->type, "EV_SYN") == 0) return;
#ifndef NO_BTN
    else if (strcmp(event->type, "EV_KEY") == 0) {
	if ((strcmp(event->code, "BTN_LEFT") == 0) && event->value == 1)
	    printf("TRIGGER PULSE _|_\n");
	else if (strcmp(event->code, "BTN_RIGHT") == 0) {
	    if ((event->value) == 0)
		printf("GATE OFF\n");
	    else
		printf("GATE ON\n");
        }
	else if ((strcmp(event->code, "BTN_MIDDLE") == 0) && event->value == 1) {
	    *mode = !(*mode);
	    if (!(*mode))
		printf("Change mode to ATTENUATION\n");
	    else
		printf("Change mode to OFFSET\n");
	}
	else if ((strcmp(event->code, "BTN_SIDE") == 0) && event->value == 1)
	    printf("ERASE\n");
	else if ((strcmp(event->code, "BTN_EXTRA") == 0) && event->value == 1) {
	    *rec = !(*rec);
	    if (!(*rec))
	        printf("Stop recording. Start playback\n");
	    else
		printf("Start recording\n");
	}
#endif
#ifndef NO_REL
    } else if (strcmp(event->type, "EV_REL") == 0) {
	if (strcmp(event->code, "REL_X") == 0)
            printf("X: %d\n", event->value);
	else if (strcmp(event->code, "REL_Y") == 0)
	    printf("Y: %d\n", event->value);
        else if (strcmp(event->code, "REL_WHEEL") == 0)
	    printf("WHEEL: %d\n", event->value);
#endif
#ifndef NO_ABS
    } else if (strcmp(event->type, "EV_ABS") == 0) {
        if (strcmp(event->code, "ABS_X") == 0)
            printf("X: %d\n", event->value);
	else if (strcmp(event->code, "ABS_Y") == 0)
	    printf("Y: %d\n", event->value);
	else if (strcmp(event->code, "ABS_WHEEL") == 0)
            printf("WHEEL: %d\n", event->value);
    }
#endif
}

int main(int argc, char** argv) {
    // Check arguments
    if (argc == 1) {
        printf("USAGE: ./event <event-number>\n");
        return EXIT_FAILURE;
    }
    
    FILE *mouse;
    struct input_event systemEvent;
    struct str_event myEvent;
    char filePath[18] = "/dev/input/event";
    strcat(filePath, argv[1]);
    
    bool rec = false;
    bool mode = false; // false: attenuation | true: offset
    //unsigned int attenuation = 0;
    //int offset = 0;

    // Open the file
    mouse = fopen(filePath, "r");
    if(mouse == NULL) {
        printf("ERROR Opening %s\n", filePath);
        return EXIT_FAILURE;
    }

    unsigned int i = 0;
    while(1) {
        size_t bytes = fread(&systemEvent, sizeof(struct input_event), 1, mouse);

        // If we managed to read some bytes, print the relative events
        if (bytes > 0) {
            //printRaw(i, &systemEvent);
            setStrEvent(&systemEvent, &myEvent);
            //printHuman(i, &myEvent);
	    printFunctional(&myEvent, &rec, &mode);
            i++;
        }
    }
    return EXIT_SUCCESS;
}
