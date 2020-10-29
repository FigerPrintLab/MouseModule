import asyncio
import evdev
from evdev import InputDevice, categorize, ecodes

def showCoord(x, y, time=0):
    if time == 0:
        print (str(x), str(y))
    else:
        print (str(x), str(y), str(time))

def record(t):
    if rec:
        print("Start recording")
        # Record using timestamps
        
    else:
        print("Stop recording")
        # Stop record
        
def playback():
    if pb:
        print("Start playback")
        # Playback from recorder signal
        
    else:
        print("Stop playback")

def gate():
    if gt:
        print("Start gate signal")
        # Start gate
        
    else:
        print("Stop gate signal")
        # Stop gate

def trigger():
    print("Trigger pulse")
    # Send pulse

def wheel(plus):
    if os:
        if plus:
            print("Increase offset")
        else:
            print("Decrease offset")
    else:
        if plus:
            print("Increase range")
        else:
            print("Decrease range")

rec = False
pb = False
gt = False
os = False
device = evdev.InputDevice("/dev/input/event2")


async def helper(device):
    async for event in device.async_read_loop():

        time = event.timestamp()

        if event.type == ecodes.EV_ABS: 
            absX = float((device.absinfo(ecodes.ABS_X)).value) / float((device.absinfo(ecodes.ABS_X)).max)
            absY = float((device.absinfo(ecodes.ABS_Y)).value) / float((device.absinfo(ecodes.ABS_Y)).max)
            #showCoord(absX, absY)

        elif event.type == ecodes.EV_KEY:
            keyEvent = categorize(event)
            if isinstance(keyEvent.keycode, list):
                keyCode = keyEvent.keycode[0]
                keyState = keyEvent.keystate
            else:
                keyCode = keyEvent.keycode
                keyState = keyEvent.keystate
            
            global pb
            global rec
            global gt
            global os
         
            if keyCode == "BTN_EXTRA" and keyState == 1:
                if pb:
                    pb = False
                    playback()
                    
                rec = not rec
                record(time)
                
            elif keyCode == "BTN_SIDE" and keyState == 1:
                if rec:
                    rec = False
                    record(time)
                    
                pb = not pb
                playback()
                
            elif keyCode == "BTN_LEFT" and keyState == 1:
                trigger()
                
            elif keyCode == "BTN_RIGHT":
                if keyState == 1:
                    gt = True
                    gate()
                else:
                    gt = False
                    gate()
                    
            elif keyCode == "BTN_MIDDLE" and keyState == 1:
                if os:
                    print("Attenuator mode")
                    os = False
                else:
                    print("Offset mode")
                    os = True
                
        elif event.type == ecodes.EV_REL:
            relEvent = categorize(event)
            if relEvent.event.value == -1:
                wheel(True)
            else:
                wheel(False)
            

loop = asyncio.get_event_loop()
loop.run_until_complete(helper(device))