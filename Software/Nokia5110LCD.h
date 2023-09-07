// Nokia5110LCD.h

#include <stdbool.h>

#ifndef NOKIA5110LCD_H
#define NOKIA5110LCD_H

#define KILO 1000
#define MEGA 1000000

#define LOW 0
#define HIGH 1

#define RST   0
#define DC 22
#define MISO_PIN  9
#define MOSI_PIN  10
#define SCLK_PIN  11
#define CE0_PIN   8

#define SPI_CHANNEL 0
#define SPI_CLK 8*MEGA

#define BIAS 0x04
#define CONTRAST 24

#define BLACK 1 ///< Black pixel
#define WHITE 0 ///< White pixel

#define LCDWIDTH 84  ///< LCD is 84 pixels wide
#define LCDHEIGHT 48 ///< 48 pixels high

#define PCD8544_POWERDOWN 0x04 ///< Function set, Power down mode
#define PCD8544_ENTRYMODE 0x02 ///< Function set, Entry mode
#define PCD8544_EXTENDEDINSTRUCTION                                            \
  0x01 ///< Function set, Extended instruction set control

#define PCD8544_DISPLAYBLANK 0x0    ///< Display control, blank
#define PCD8544_DISPLAYNORMAL 0x4   ///< Display control, normal mode
#define PCD8544_DISPLAYALLON 0x1    ///< Display control, all segments on
#define PCD8544_DISPLAYINVERTED 0x5 ///< Display control, inverse mode

#define PCD8544_FUNCTIONSET 0x20 ///< Basic instruction set
#define PCD8544_DISPLAYCONTROL                                                 \
  0x08 ///< Basic instruction set - Set display configuration
#define PCD8544_SETYADDR                                                       \
  0x40 ///< Basic instruction set - Set Y address of RAM, 0 <= Y <= 5
#define PCD8544_SETXADDR                                                       \
  0x80 ///< Basic instruction set - Set X address of RAM, 0 <= X <= 83

#define PCD8544_SETTEMP                                                        \
  0x04 ///< Extended instruction set - Set temperature coefficient
#define PCD8544_SETBIAS 0x10 ///< Extended instruction set - Set bias system
#define PCD8544_SETVOP                                                         \
  0x80 ///< Extended instruction set - Write Vop to register

// typedef unsigned char bool;
typedef unsigned char uint8_t; // typedef short int int8_t;
typedef unsigned short int uint16_t;
typedef short int int16_t;

// typedef struct {
//     int* _pSpiHandle = NULL;
//     unsigned _rstpin = RST;
//     unsigned _dcpin = DC;
//     uint8_t _contrast = CONTRAST;
//     uint8_t _bias = BIAS;
//     uint8_t _reinit_interval; ///< Reinitialize the display after this many
//     ///< calls to display()
//     uint8_t _display_count;   ///< Count for reinit interval

//     uint8_t xUpdateMin, xUpdateMax, yUpdateMin, yUpdateMax;
// } DisplayInfo;

typedef struct {
    int _spiHandle;
    unsigned _rstpin;
    unsigned _dcpin;
    char _contrast;
    char _bias;
    char _reinit_interval; ///< Reinitialize the display after this many
    ///< calls to display()
    char _display_count;   ///< Count for reinit interval

    char xUpdateMin, xUpdateMax, yUpdateMin, yUpdateMax;
} DisplayInfo;

/**************************************************************************/
// int begin(DisplayInfo* d, uint8_t contrast = 40, uint8_t bias = 0x04);
int begin(DisplayInfo* d);
void initDisplay(DisplayInfo* d);
void setBias(DisplayInfo* d, char val);
void setContrast(DisplayInfo* d, char val);
void setReinitInterval(DisplayInfo* d, char val);
void command(DisplayInfo* d, char c);
void data(DisplayInfo* d, char c);
void updateBoundingBox(DisplayInfo* d,char xmin, char ymin,
                       char xmax, char ymax);
void drawPixel(int16_t x, int16_t y, uint16_t color);
void setPixel(int16_t x, int16_t y, bool color, char *buffer);
void setAddress(DisplayInfo* d, bool x, char address);
void setBothAddresses(DisplayInfo* d, char x, char y);
void clearDisplay(DisplayInfo* d);
void invertDisplay(DisplayInfo* d, bool i);
void display(DisplayInfo* d);
void drawBorder(DisplayInfo* d, const int attenuation, const int offset);
void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void drawHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
void drawVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
int16_t abs_int16(int16_t a);
void swap(int16_t* a, int16_t* b);
// void scroll(int8_t vpixels, int8_t hpixels);
void drawPoint(DisplayInfo* d, int x, int y, uint16_t color);

char min(const char a, const char b);
char max(const char a, const char b);


char getContrast(const DisplayInfo* d);
char getBias(const DisplayInfo* d);
char getReinitInterval(const DisplayInfo* d);
// bool getPixel(int16_t x, int16_t y, char *buffer);

#endif // NOKIA5110LCD_H
