/*
 * This file contains all the functions used to capture
 * some significant mouse events and turn them into analog
 * signals.
 * For more info about the event catalogation in linux check
 * "linux/input.h" 
 * The pigpio library is used to generate hw signals.
 * 
 * TODO:
 *  - Implement the movement constraining logic based on 
 *    attenuation and offset
 *  - Add the ending event to the recording array list in 
 *    order end the playback correctly
 */

#include <pigpio.h>
#include "event.h"

/*
 * Get the file name corresponding to the mouse
 */
bool getFileName(FILE* fp, char* name) {
    char* out = NULL;
    size_t line_buf_size = 0;
	char* token;

	regex_t regex;
	int value;

	while(getline(&out, &line_buf_size, fp) > 0) {
		if(strstr(out, "mouse")) {
			token = strtok(out, " ");
			value = regcomp(&regex, "event[0-9]", 0);
			value = regexec(&regex, token, 0, NULL, 0);
            while(value != 0) {
                token = strtok(NULL, " ");
                value = regcomp(&regex, "event[0-9]", 0);
                value = regexec(&regex, token, 0, NULL, 0);
            }
		    strcpy(name, token);
            return true; 
		}
	}
	return false;
}

/*
 * Print the raw event
 */
void printRaw(unsigned long i, const struct input_event* event) {
    printf("%lu.\nsec: %ld, usec: %ld type: 0x%x, code: 0x%x, value: %d\n",
    i, event->time.tv_sec, event->time.tv_usec, event->type, event->code, event->value);
}

/* 
 * Transform CODE field in a string value based 
 * on the TYPE field
 */
const char* getCode(const char* type, const unsigned short c) {
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
    event->code = getCode(event->type, systemEvent->code);
    event->value = systemEvent->value;
}

/*
 * Print the human readable event
 */
void printHuman(unsigned long i, const struct str_event* event) {
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
            printf("%lu.\nType: %s, Code: %s, Value: %d\n",
                i, event->type, event->code, event->value);
        #endif
    #else
        #ifdef NO_INDEX
            printf("Time: %Lf, Type: %s, Code: %s, Value: %d\n",
            event->timestamp, event->type, event->code, event->value);
        #else
            printf("%lu.\nTime: %Lf, Type: %s, Code: %s, Value: %d\n",
                i, event->timestamp, event->type, event->code, event->value);
        #endif
    #endif
}

/*
 * Print the operation that each event should trigger
 */
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
                printf("REL X: %d\n", event->value);
        else if (strcmp(event->code, "REL_Y") == 0)
            printf("REL Y: %d\n", event->value);
        else if (strcmp(event->code, "REL_WHEEL") == 0)
            printf("REL WHEEL: %d\n", event->value);
#endif
#ifndef NO_ABS
    } else if (strcmp(event->type, "EV_ABS") == 0) {
        if (strcmp(event->code, "ABS_X") == 0)
            printf("ABS X: %d\n", event->value);
        else if (strcmp(event->code, "ABS_Y") == 0)
            printf("ABS Y: %d\n", event->value);
        else if (strcmp(event->code, "ABS_WHEEL") == 0)
                printf("ABS WHEEL: %d\n", event->value);
    }
#endif
}

/*
 * Add events to a dynamic allocated array to record them
 */
void pushEvent(Thread* thread, const struct input_event* event) {
    thread->list.array = (struct input_event*) realloc(thread->list.array, sizeof(*event) * (thread->list.length + 1));
    thread->list.array[thread->list.length] = *event;
    thread->list.length += 1;
}

/*
 * Erase the event list and stop the thread
 */
void stopThread(Thread* thread) {
    free(thread->list.array);
    thread->list.length = 0;
    //thread->stop = false;
    pthread_join(thread->id, NULL);
}

/*
 * Event handlers
 */
void trigger(const long double t, const struct input_event* event) {
    gpioWrite(TRIG, 1);
    clock_t start = clock();
    while (clock() - start < 0.00005*CLOCKS_PER_SEC) {
    }
    gpioWrite(TRIG, 0);
    printf("TRIGGER PULSE\n");
}

void gate(const long double t, const struct input_event* event) {
    if (event->value == 1) {
        gpioWrite(GATE, 1);
        printf("GATE ON\n");
    } else if (event->value == 0) {
            gpioWrite(GATE, 0);
        printf("GATE OFF\n");
    }
}

void changeMode(const long double t, const struct input_event* event, bool* mode) {
    *mode = !(*mode);
    if (*mode) {
        printf("OFFSET MODE\n");
    } else {
        printf("ATTENUATION MODE\n");
    }
}

void* handlePlayback(void* arg) {
    Thread* thread = (Thread*)arg;
    clock_t start, end;
    double elapsed;

    while(1) {
        printf("START\n");
        /*
         * Reset the current status to the initial one
         *
         * I would have used the following form:
         * *(Status*)thread->status = (Status)thread->start
         * It actually works but it gives a warning related to 
         * casting nonscalar variables (Status structure in this case)
         */
        *(Status*)thread->status = *(Status*)&thread->start;

        /* Replay all the recorded events */
        for (unsigned int i = 0; i < thread->list.length-1; i++) {
            /* Calculate interval between subsequent events */
            long double time1 = (long double)thread->list.array[i].time.tv_sec + 0.000001 * (long double)thread->list.array[i].time.tv_usec;
            long double time2 = (long double)thread->list.array[i+1].time.tv_sec + 0.000001 * (long double)thread->list.array[i+1].time.tv_usec;
            double interval = time2 - time1;
            
            /* Wait the interval unless the playback is stopped */
            start = clock();
            do {
                end = clock();
                elapsed = ((double) (end - start))/CLOCKS_PER_SEC;
                if (*thread->stop) {
                    printf("EXIT THREAD\n");
                    pthread_exit(NULL);
                    return NULL;
                }
            } while(elapsed < interval);
            //printf("PLAYBACK | TIME: %Lf, TYPE: %hu, CODE: %hu\n", time2, thread->list.array[i+1].type, thread->list.array[i+1].code);
            handle(&thread->list.array[i+1]);
        }
        printf("END\n");
    }
    pthread_exit(NULL);
    return NULL;
}

void playback(bool* pb, Thread* thread) {
    *pb = !(*pb);
    if (*pb) {
        gpioWrite(PB, 1);
	    printf("START PLAYBACK, registered %d events\n", thread->list.length);

        int error = pthread_create(&thread->id, NULL, &handlePlayback, (void*)thread);
        if (error != 0) printf("ERROR: Unable to create thread: %s\n", strerror(error));
    } else {
        gpioWrite(PB, 0);
	    printf("STOP PLAYBACK\n");
    }
}

void erase(bool* pb, Thread* thread, bool* stop) {
    if (*pb) {
	    playback(pb, thread);
    }
    printf("ERASE\n");
    *stop = true;
    stopThread(thread);
    *stop = false;
}

void record(const long double t, const struct input_event* event, bool* rec, bool* pb, Status* status, Thread* thread) {
    *rec = !(*rec);
    if (*rec) {
        if (*pb) {
            playback(pb, thread);
        }
        /* Alloc 0 memory to reinitialize the event array */
        thread->list.array = (struct input_event*) malloc(0);
        /* Save current status to restore it on every new playback cycle */
        thread->start = *status;
        gpioWrite(REC, 1);
        printf("START RECORDING\n");
    } else {
        gpioWrite(REC, 0);
        printf("STOP RECORDING\n");
	    playback(pb, thread);
    }
}

void printStatus(const Status* s) {
    printf("STATUS: x = %d\ty = %d\tattenuation = %d\toffset = %d\tmode = %s\n", s->x, s->y, s->attenuation, s->offset, s->mode ? "true" : "false");
}

void move(const long double t, const struct input_event* event, const bool axis, int* val) {
    if (axis) {
        *val += event->value;
    } else {
        *val -= event->value;
    }
    
    // int max = MAX_POS / ATTENUATION_RANGE * (*attenuation);
    if (*val > MAX_POS) {
        *val = MAX_POS;
    }
    else if (*val < MIN_POS) {
        *val = MIN_POS;
    }

    unsigned d = ((float)*val+1000)*CONST;
    if (axis) {
        gpioHardwarePWM(PWM_0, FREQ, d);
        printf("X: %d\n", *val);
    } else {
        gpioHardwarePWM(PWM_1, FREQ, d);
        printf("Y: %d\n", *val);
    }
}

void wheel(int* attenuation, int* offset, const long double t, const struct input_event* event, const bool* mode) {
    if (event->value < 0) {
        if (!(*mode)) {
            if (*attenuation > (-ATTENUATION_RANGE)) {
                --(*attenuation);
            }
            printf("ATTENUATION: %d\n", *attenuation);
        } else {
            if (*offset > *attenuation) {
                --(*offset);
            }
            printf("OFFSET: %d\n", *offset);
        }
    } else {
        if (!(*mode)) {
            if (*attenuation < -(abs(*offset))) {
                ++(*attenuation);
            }
            printf("ATTENUATION: %d\n", *attenuation);
        } else {
            if (*offset < -(*attenuation)) {
                ++(*offset);
            }
            printf("OFFSET: %d\n", *offset);
        }
    }
}

/* Update current position when it's out of range (because of a new attenuation or offset event) */
void updatePosition(int* x, int* y, const int* attenuation, const int* offset) {
    float border = 0.5 + (*attenuation / (ATTENUATION_RANGE * 2));
    int max = (int)(border + (*offset / (ATTENUATION_RANGE * 2)));
    int min = (int)(-border + (*offset / (ATTENUATION_RANGE * 2)));

    if (*x > max)
        *x = max;
    else if (*x < min)
        *x = min;

    if (*y > max)
        *y = max;
    else if (*y < min)
        *y = min;
}

/* 
 * Main handling function
 */
void handle(const struct input_event* event) {
    static Status status = { 0, 0, 0, 0, false };
    static bool rec = false; // recording state
    static bool pb = false; // playback state
    const long double timestamp = (long double) event->time.tv_sec +
	                    0.000001 * (long double) event->time.tv_usec;
    bool relevant = false;
    static bool stop = false;
    static Thread thread = {0, {NULL, 0}, { 0 , 0, 0, 0, false }, &status, &stop};
    
    /* If we're if playback mode and this function is called
     * by the main thread, allow the handling only if it's
     * an ERASE event.
     */
    if (pb && thread.id != pthread_self()) {
        //printf("MAIN\n");
        if (event->code == BTN_SIDE && event->value == 1) {
            erase(&pb, &thread, &stop);
        }
        return;
    } else {
        //printf("THREAD\n");
    }

    /* Call the appropriate function based on the event type */
    if (event->type == EV_KEY) {
        if (event->code == BTN_LEFT && event->value == 1) {
            trigger(timestamp, event);
	        relevant = true;
        } else if (event->code == BTN_RIGHT) {
            gate(timestamp, event);
	        relevant = true;
        } else if (event->code == BTN_MIDDLE && event->value == 1) {
            changeMode(timestamp, event, &status.mode);
            // record(timestamp, event, &rec, &pb, &status, &thread);
	        relevant = true;
        } else if (event->code == BTN_SIDE && event->value == 1) {
            if (rec) {
                printf("ERASE WHILE IN RECORD MODE\n");
                record(timestamp, event, &rec, &pb, &status, &thread);
                erase(&pb, &thread, &stop);
            }
            if (pb) {
                printf("ERASE WHILE IN PLAYBACK MODE\n");
                erase(&pb, &thread, &stop);
            }
        } else if (event->code == BTN_EXTRA && event->value == 1) {
            record(timestamp, event, &rec, &pb, &status, &thread);
	        relevant = true;
        }
    } else if (event->type == EV_REL/* && !pb*/) {
        if (event->code == REL_X) {
            move(timestamp, event, true, &status.x);
	        relevant = true;
        } else if (event->code == REL_Y) {
            move(timestamp, event, false, &status.y);
	        relevant = true;
        } else if (event->code == REL_WHEEL) {
            wheel(&status.attenuation, &status.offset, timestamp, event, &status.mode);
            updatePosition(&status.x, &status.y, &status.attenuation, &status.offset);
	        relevant = true;
        }
    } else if (event->type == EV_ABS/* && !pb*/) {
        if (event->code == ABS_X) {
            move(timestamp, event, true, &status.x);
	        relevant = true;
        } else if (event->code == ABS_Y) {
            move(timestamp, event, false, &status.y);
	        relevant = true;
        } else if (event->code == ABS_WHEEL) {
            wheel(&status.attenuation, &status.offset, timestamp, event, &status.mode);
            updatePosition(&status.x, &status.y, &status.attenuation, &status.offset);
	        relevant = true;
        }
    }
    
    /* Save the event in the recording array if it's a relevant event */
    if (relevant && rec) {
	    pushEvent(&thread, event);
    }
}

