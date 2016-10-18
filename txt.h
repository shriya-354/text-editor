#include <SDL_image.h>
#include "main.h"

typedef Uint32 u32;

enum BitmapFont {
	BITMAP_FONT_1,
	BITMAP_FONT_2,
	BITMAP_FONT_3,
	BITMAP_FONT_4,
	BITMAP_FONT_5,
	BITMAP_FONT_6,
	BITMAP_FONT_7,
	BITMAP_FONT_8,
	BITMAP_FONT_9,
	BITMAP_FONT_10,
	BITMAP_FONT_11,
	BITMAP_FONT_12,
	BITMAP_FONT_13,
	BITMAP_FONT_14,
	BITMAP_FONT_15,
	BITMAP_FONT_16,
	BITMAP_FONT_17,
	BITMAP_FONT_18,
	BITMAP_FONT_19,
	BITMAP_FONT_20,
	MAX_BITMAP_FONTS
};

void TXT_Init();
char* ReadFileToStr(SDL_RWops *file, int file_size);

void TXT_DrawText(const char *str,int x, int y, u32 *screen);
void TXT_BitmapFont(enum BitmapFont, desired_font);
void TXT_TextWidth(const char *str);
void TXT_TextHeight(const char *str);
