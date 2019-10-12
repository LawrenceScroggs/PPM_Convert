#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//ASCII LUMINANCE RAMP
#define ASCII_MAP_STRING "    ...''`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%BB@@@$$$$"

#define NUM_ANSI_COLORS 7

enum Ansi_Color
{
	BrightBlue,
	BrightGreen,
	BrightCyan,
	BrightRed,
	BrightMagenta,
	BrightYellow,
	BrightWhite
};

typedef struct Pixel
{
	unsigned char Red;
	unsigned char Green;
	unsigned char Blue;

  unsigned int avg;
} Pixel;

//THIS ARRAY OF PIXELS SPECIFIES EACH OF THE COLORS AVAILABLE IN ANSI. EACH COLOR IS INDEXED BY ENUM ANSI_COLOR ABOVE
extern const Pixel ANSI_COLORS[NUM_ANSI_COLORS];

//THIS FUNCTION PRINTS A CHARACTER ON SCREEN USING THE COLOR SPECIFIED
void PrintASCIIChar(enum Ansi_Color color, char character);
