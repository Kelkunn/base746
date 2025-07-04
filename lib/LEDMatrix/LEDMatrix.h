/**
 * LED Matrix library for http://www.seeedstudio.com/depot/ultrathin-16x32-red-led-matrix-panel-p-1582.html
 * The LED Matrix panel has 32x16 pixels. Several panel can be combined together as a large screen.
 *
 * Coordinate & Connection (mbed -> panel 0 -> panel 1 -> ...)
 *   (0, 0)                                     (0, 0)
 *     +--------+--------+--------+               +--------+--------+
 *     |   5    |    3   |    1   |               |    1   |    0   |
 *     |        |        |        |               |        |        |<----- mbed
 *     +--------+--------+--------+               +--------+--------+
 *     |   4    |    2   |    0   |                              (64, 16)
 *     |        |        |        |<----- mbed
 *     +--------+--------+--------+
 *                             (96, 32)
 *  Copyright (c) 2013 Seeed Technology Inc.
 *  @auther     Yihui Xiong
 *  @date       Nov 7, 2013
 *  @license    Apache
 */


#ifndef __LED_MATRIX_H__
#define __LED_MATRIX_H__

#include "Arduino.h"
// #include "fonts.h"

class LEDMatrix {
public:
    LEDMatrix(int pinA, int pinB, int pinC, int pinD, int pinOE,
              int pinR1, int pinR2, int pinB1, int pinB2, int pinG1, int pinG2,
              int pinSTB, int pinCLK);

    /**
     * set the display's display buffer and number, the buffer's size must be not less than 512 * number / 8 bytes
     * @param displaybuf    display buffer
     * @param number        panels' number
     */
    void begin(uint8_t *displaybuf, uint16_t width, uint16_t height);

    /**
     * draw a point
     * @param x     x
     * @param y     y
     * @param pixel 0: led off, >0: led on
     */
    void drawPoint(uint16_t x, uint16_t y, uint8_t pixel);
    void drawPointDirect(uint16_t x, uint16_t y, uint8_t pixel);

    /**
     * draw a rect
     * @param (x1, y1)   top-left position
     * @param (x2, y2)   bottom-right position, not included in the rect
     * @param pixel      0: rect off, >0: rect on
     */
    void drawRect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t pixel);

//    int drawChar(uint16_t x, uint16_t y, char c, uint8_t pixel, Font *font);

//    void drawCharString (uint16_t x, uint16_t y, char *c, uint8_t pixel, Font *font);

//    void drawCharBig(uint16_t x, uint16_t y, char c, uint8_t pixel);

    /**
     * draw a image
     * @param (x1, y1)   top-left position
     * @param (x2, y2)   bottom-right position, not included in the rect
     * @param pixels     contents, 1 bit to 1 led
     */
    void drawImage(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t *image);

    /**
     * Set screen buffer to zero
     */
    void clear();

    /**
     * turn off 1/16 leds and turn on another 1/16 leds
     */
    void scan();

    void reverse();

    uint8_t isReversed();

    void on();

    void off();

    void swap();

    int synchro();

private:
    int a, b, c, d, oe, r1, r2, b1, b2, g1, g2, stb, clk;
    uint8_t *displaybuf, *memoBuf, *drawBuf;
    uint16_t width;
    uint16_t height;
    uint8_t  mask;
    uint8_t  state;
    int bufferIndex;
    volatile int flagSwap;
};

#endif
