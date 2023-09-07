// Nokia5110LCD.c

#include "Nokia5110LCD.h"
#include <pigpio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/** the memory buffer for the LCD */
char pcd8544_buffer[LCDWIDTH * LCDHEIGHT / 8] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFC, 0xFE, 0xFF, 0xFC, 0xE0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8,
    0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0x80, 0xC0,
    0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xC7, 0xC7, 0x87, 0x8F, 0x9F,
    0x9F, 0xFF, 0xFF, 0xFF, 0xC1, 0xC0, 0xE0, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFC, 0xFC, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0xF8,
    0xF0, 0xE0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0,
    0xF1, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x0F, 0x0F, 0x87,
    0xE7, 0xFF, 0xFF, 0xFF, 0x1F, 0x1F, 0x3F, 0xF9, 0xF8, 0xF8, 0xF8, 0xF8,
    0xF8, 0xF8, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x7F, 0x3F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFE, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7E, 0x3F, 0x3F, 0x0F,
    0x1F, 0xFF, 0xFF, 0xFF, 0xFC, 0xF0, 0xE0, 0xF1, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFC, 0xF0, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
    0x7F, 0x7F, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

int begin(DisplayInfo* d)
{
    int spiHandle = spiOpen(SPI_CHANNEL, SPI_CLK, 0);
    if (spiHandle < 0) return 1;
    d->_spiHandle = spiHandle;

    // Set common pin outputs.
    d->_rstpin = RST;
    d->_dcpin = DC;
    if (gpioSetMode(d->_rstpin, PI_OUTPUT) < 0) return 1;
    if (gpioSetPullUpDown(d->_rstpin, PI_PUD_UP) < 0) return 1;
    if (gpioSetMode(d->_dcpin, PI_OUTPUT) < 0) return 1;

    d->_bias = BIAS;
    d->_contrast = CONTRAST;
    d->_reinit_interval = 0;
    d->_display_count = 0;

    initDisplay(d);

    // initial display line
    // set page address
    // set column address
    // write display data

    // set up a bounding box for screen updates

    // updateBoundingBox(d, 0, 0, LCDWIDTH - 1, LCDHEIGHT - 1);
    // Push out pcd8544_buffer to the Display (will show the AFI logo)
    // display(d);

    return 0;
}

void initDisplay(DisplayInfo* d)
{
    // toggle RST low to reset
    if (d->_rstpin >= 0) {
        gpioWrite(d->_rstpin, LOW);
        gpioSleep(PI_TIME_RELATIVE, 0, 1000); // 1 ns minimum
        gpioWrite(d->_rstpin, HIGH);
    }

    setBias(d, BIAS);
    setContrast(d, CONTRAST);

    // normal mode
    command(d, PCD8544_FUNCTIONSET);

    // Set display to Normal
    command(d, PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);
}

void setBias(DisplayInfo* d, char val)
{
    if (val > 0x07) {
        val = 0x07;
    }
    d->_bias = val;
    command(d, PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION);
    command(d, PCD8544_SETBIAS | val);
    command(d, PCD8544_FUNCTIONSET);
}

void setContrast(DisplayInfo* d, char val)
{
    if (val > 0x7f) {
        val = 0x7f;
    }
    d->_contrast = val;
    command(d, PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION);
    command(d, PCD8544_SETVOP | val);
    command(d, PCD8544_FUNCTIONSET);
}

void setReinitInterval(DisplayInfo* d, char val)
{
    d->_reinit_interval = val;
}

void command(DisplayInfo* d, char c)
{
    gpioWrite(d->_dcpin, LOW);
    spiWrite(d->_spiHandle, &c, 1);
}

void data(DisplayInfo* d, char c)
{
    gpioWrite(d->_dcpin, HIGH);
    spiWrite(d->_spiHandle, &c, 1);
}

void updateBoundingBox(DisplayInfo* d,
                       char xmin, char ymin,
                       char xmax, char ymax)
{
    d->xUpdateMin = min(d->xUpdateMin, xmin);
    d->xUpdateMax = max(d->xUpdateMax, xmax);
    d->yUpdateMin = min(d->yUpdateMin, ymin);
    d->yUpdateMax = max(d->yUpdateMax, ymax);
}

char min(const char a, const char b)
{
    return (a < b ? a : b);
}

char max(const char a, const char b)
{
    return (a > b ? a : b);
}

void drawPixel(int16_t x, int16_t y, uint16_t color)
{
    setPixel(x, y, color, pcd8544_buffer);
}

void setAddress(DisplayInfo* d, bool x, char address)
{
    if (x) {
        if (address < 0 || address > 83) return;
        gpioWrite(d->_dcpin, LOW);
        char c = PCD8544_SETXADDR | address;
        spiWrite(d->_spiHandle, &c, 1);
    } else { //y
        if (address < 0 || address > 5) return;
        gpioWrite(d->_dcpin, LOW);
        char c = PCD8544_SETYADDR | address;
        spiWrite(d->_spiHandle, &c, 1);
    }
}

void setBothAddresses(DisplayInfo* d, char x, char y)
{
    if (x < 0 || x > 83 || y < 0 || y > 5) return;
    gpioWrite(d->_dcpin, LOW);
    char c[2] = { PCD8544_SETYADDR | y, PCD8544_SETXADDR | x };
    spiWrite(d->_spiHandle, c, 2);
    // c = PCD8544_SETXADDR | x;
    // spiWrite(d->_spiHandle, &c, 1);

}

void setPixel(int16_t x, int16_t y, bool color, char *buffer)
{
    /*
     * TODO: What's _width/_height?
     */
    // if ((x < 0) || (x >= display->_width) || (y < 0) || (y >= display->_height))
    if ((x < 0) || (x >= LCDWIDTH) || (y < 0) || (y >= LCDHEIGHT))
        return;

    int16_t t;
    /*
     * TODO: What's rotation?
     */
    char rotation = 2;
    switch (rotation) {
    case 1:
        t = x;
        x = y;
        y = LCDHEIGHT - 1 - t;
        break;
    case 2:
        x = LCDWIDTH - 1 - x;
        y = LCDHEIGHT - 1 - y;
        break;
    case 3:
        t = x;
        x = LCDWIDTH - 1 - y;
        y = t;
        break;
    }
    // updateBoundingBox(d, x, y, x, y);

    // x is which column
    if (color)
        buffer[x + (y / 8) * LCDWIDTH] |= 1 << (y % 8);
    else
        buffer[x + (y / 8) * LCDWIDTH] &= ~(1 << (y % 8));
}

void clearDisplay(DisplayInfo* d)
{
    memset(pcd8544_buffer, 0, LCDWIDTH * LCDHEIGHT / 8);
    updateBoundingBox(d, 0, 0, LCDWIDTH - 1, LCDHEIGHT - 1);
    gpioWrite(d->_dcpin, HIGH);
    spiWrite(d->_spiHandle,
             pcd8544_buffer,
             LCDWIDTH * LCDHEIGHT / 8);
    /*
     * TODO: What's cursor_x/cursor_y?
     */
    // cursor_y = cursor_x = 0;
}

void invertDisplay(DisplayInfo* d, bool i)
{
    command(d, PCD8544_FUNCTIONSET);
    command(d, PCD8544_DISPLAYCONTROL |
            (i ? PCD8544_DISPLAYINVERTED : PCD8544_DISPLAYNORMAL));
}

void display(DisplayInfo* d)
{
    // if (d->_reinit_interval) {
    //     d->_display_count++;
    //     if (d->_display_count >= d->_reinit_interval) {
    //         d->_display_count = 0;
    //         initDisplay(d);
    //     }
    // }

    // for (char page = (d->yUpdateMin / 8);
    //      page < (d->yUpdateMax / 8) + 1;
    //      page++) {
    //     command(d, PCD8544_SETYADDR | page);

    //     char startcol = d->xUpdateMin;
    //     char endcol = d->xUpdateMax;

    //     command(d, PCD8544_SETXADDR | startcol);

    //     // char buf[LCDWIDTH * LCDHEIGHT / 8] =
    //     //     pcd8544_buffer + (LCDWIDTH * page) + startcol;
    //     gpioWrite(d->_dcpin, HIGH);
    //     spiWrite(d->_spiHandle,
    //              pcd8544_buffer,
    //              LCDWIDTH * LCDHEIGHT / 8);
    // }

    gpioWrite(d->_dcpin, HIGH);
    spiWrite(d->_spiHandle,
             pcd8544_buffer,
             LCDWIDTH * LCDHEIGHT / 8);

    command(d, PCD8544_SETYADDR); // no idea why this is necessary but it is to
    // finish the last byte?

    // d->xUpdateMin = LCDWIDTH - 1;
    // d->xUpdateMax = 0;
    // d->yUpdateMin = LCDHEIGHT - 1;
    // d->yUpdateMax = 0;
}

char getBias(const DisplayInfo* d)
{
    return d->_bias;
}

char getContrast(const DisplayInfo* d)
{
    return d->_contrast;
}

char getReinitInterval(const DisplayInfo* d)
{
    return d->_reinit_interval;
}

void drawBorder(DisplayInfo* d, const int attenuation, const int offset)
{
    /*
     * TODO: Handle attenuation and offset
     */
    char buf[LCDWIDTH];
    memset(buf, 0x00, LCDWIDTH);
    memset(buf+18, 0x01, LCDWIDTH-36);
    buf[17] = 0xFF;
    buf[LCDWIDTH - 1 - 36] = 0xFF;
    gpioWrite(d->_dcpin, HIGH);
    spiWrite(d->_spiHandle, buf, LCDWIDTH);

    memset(buf+19, 0x00, LCDWIDTH-38);
    spiWrite(d->_spiHandle, buf, LCDWIDTH);
    spiWrite(d->_spiHandle, buf, LCDWIDTH);
    spiWrite(d->_spiHandle, buf, LCDWIDTH);
    spiWrite(d->_spiHandle, buf, LCDWIDTH);

    memset(buf+19, 0x80, LCDWIDTH-38);
    spiWrite(d->_spiHandle, buf, LCDWIDTH);
    command(d, PCD8544_SETYADDR); // no idea why this is necessary but it is to
}

void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
    drawHLine(x, y, w, color);
    drawHLine(x, y + h - 1, w, color);
    drawVLine(x, y, h, color);
    drawVLine(x + w - 1, y, h, color);
}

void drawHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
{
    drawLine(x, y, x + w - 1, y, color);
}

void drawVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
{
    drawLine(x, y, x, y + h - 1, color);
}

void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
{
    int16_t steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep) {
        swap(&x0, &y0);
        swap(&x1, &y1);
    }

    if (x0 > x1) {
        swap(&x0, &x1);
        swap(&y0, &y1);
    }

    int16_t dx, dy;
    dx = x1 - x0;
    dy = abs(y1 - y0);

    int16_t err = dx / 2;
    int16_t ystep;

    if (y0 < y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }

    for (; x0 <= x1; x0++) {
        if (steep) {
            drawPixel(y0, x0, color);
        } else {
            drawPixel(x0, y0, color);
        }
        err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
}

int16_t abs_int16(int16_t a)
{
    return a > 0 ? a : (-a);
}

void swap(int16_t* a, int16_t* b)
{
    int16_t t = *a;
    *a = *b;
    *b = t;
}

void drawPoint(DisplayInfo* d, int x, int y, uint16_t color)
{
    // if (x < 0 || x > 84 || y < 0 || y > 48) return;
    if (x < 1) x = 1;
    else if (x > 82) x = 82;
    if (y < 1) y = 1;
    else if (y > 46) y = 46;

    char row = y / 8;
    char pixel = color == WHITE ? 0 : 1 << (y % 8);
    if (row == 0) pixel |= 1;
    else if (row == 5) pixel |= 128;
    // if (color == BLACK) {
    //     pixel = 1 << (y % 8);
    // }
    // printf("Writing pixel %d on row %d and column %d\n", y % 8, row, x);
    setBothAddresses(d, x, row);
    data(d, pixel);
}
