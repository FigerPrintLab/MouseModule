# MouseModule

This is an eurorack module that processes mouse events through the [Raspberry Pi Zero](https://www.raspberrypi.org/documentation/hardware/raspberrypi/spi/README.md) and generates 2 CV signals (for the X and Y coordinates) a GATE signal (controlled by the left button) and a TRIGGER signal (controlled by the right button). It has also recording and playback capabilities with more complex mice.  

## Functions

The software is written in javascript and mainly contains the following functions:

- `move`: mouse movements change the `Vx` and `Vy` values.
- `record`: record all events.
- `erase`: erase recording.
- `gate`: start/stop `GATE` signal.
- `trigger`: send `TRIGGER` pulse.
- `changeMode`: change the scroll wheel behavior between attenuation and offset.
- `wheel`: increase/decrease attenuation or offset

