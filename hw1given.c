#include "hw1given.h"
#include <stdio.h>
#include <assert.h>

const Pixel ANSI_COLORS[NUM_ANSI_COLORS] = {
	{0,0,255},
	{0,255,0},
	{0,255,255},
	{255,0,0},
	{255,0,255},
	{255,255,0},
	{255,255,255}
};

void PrintASCIIChar(enum Ansi_Color color, char character)
{
	switch (color)
	{
	case BrightBlue:
		fprintf(stdout, "\x1B[1;34m%c\033[0m", character);
		break;
	case BrightGreen:
		fprintf(stdout, "\x1B[1;32m%c\033[0m", character);
		break;
	case BrightCyan:
		fprintf(stdout, "\x1B[1;36m%c\033[0m", character);
		break;
	case BrightRed:
		fprintf(stdout, "\x1B[1;31m%c\033[0m", character);
		break;
	case BrightMagenta:
		fprintf(stdout, "\x1B[1;35m%c\033[0m", character);
		break;
	case BrightYellow:
		fprintf(stdout, "\x1B[1;33m%c\033[0m", character);
		break;
	case BrightWhite:
		fprintf(stdout, "\x1B[1;0m%c\033[0m", character);
		break;
	default:
		assert(0);
		break;
	}
}