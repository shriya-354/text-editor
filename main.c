#include <stdio.h>
#include <SDL.h>
#include <assert.h>
#include <stdlib.h>
//#include "main.h"
#include "SDL/SDL_ttf.h"

#define SCREEN_WIDTH 1256
#define SCREEN_HEIGHT 700
#define BOOLEAN u32
#define TRUE 1
#define FALSE 0
#define MAX 120
#define internal static

Uint32* screen_pixels;

typedef Uint32 u32;
typedef Uint64 u64;
typedef Sint32 s32;
typedef Sint64 s64;

typedef struct recta{
	int x,y,w,h;
}rect_t;
SDL_Surface *surface;

// internal here is for the function or the variable to visible only by the compilation unit or file then it's prefixed by static
internal void FillRectangle(rect_t rect, u32 pixel_color, u32 *screen_pixel);
internal void FillRectangle(rect_t rect, u32 pixel_color, u32 *screen_pixel){
	SDL_assert(screen_pixels);
	for(int row = 0; row<rect.h ;row++){
		for(int col = 0; col< rect.w; ++col){
		screen_pixels[(row + rect.y)*SCREEN_WIDTH + col + rect.x] = pixel_color;
		}
	}
}


int main(int argc , char *argv[]){
	//The window we'll be rendering to
	SDL_Window* win = NULL;
	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;
	SDL_Texture *bitmapTex = NULL;
	SDL_Surface *bitmapSurface = NULL;

	//Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeSansBold.ttf",32);
	SDL_Surface* screen, *image, *text;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else{
	SDL_Surface *screenSurface = SDL_CreateRGBSurfaceFrom(NULL,
                                   SCREEN_WIDTH, SCREEN_HEIGHT,
                                   32, 4,
                                   0x00FF0000,
                                   0x0000FF00,
                                   0x000000FF,
                                   0xFF000000);
	
	SDL_PixelFormat *format = SDL_AllocFormat(SDL_PIXELFORMAT_ARGB8888);
	assert(format);

	SDL_Window *win = SDL_CreateWindow("My_text_editor",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					SCREEN_WIDTH,
					SCREEN_HEIGHT,
					SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MINIMIZED |SDL_WINDOW_MAXIMIZED | SDL_WINDOW_SHOWN
					);
	assert(win);
	
	SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	assert(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	bitmapTex = SDL_CreateTextureFromSurface(renderer, screenSurface);
	SDL_Texture *screen = SDL_CreateTexture(renderer,
						SDL_PIXELFORMAT_ARGB8888,
						SDL_TEXTUREACCESS_STREAMING,
						SCREEN_WIDTH,
						SCREEN_HEIGHT);
	assert(screen);
	//screenSurface = SDL_LoadBMP("img/hello.bmp");
    	bitmapTex = SDL_CreateTextureFromSurface(renderer, screenSurface);

	//allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.
	screen_pixels = (u32*)calloc(SCREEN_WIDTH * SCREEN_HEIGHT , sizeof(u32));
	assert(screen_pixels);

	rect_t square = {0, 3, 2, 15};
	rect_t txt_box = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
	u32 glyph_h = TXT_TextHeight("0");
	u32 glyph_w = TXT_TextWidth("0");
	SDL_assert(txt_box.w % glyph_w == 0);
	SDL_assert(txt_box.h % glyh_h == 0);
	u32 pixel_color = SDL_MapRGBA(format, 225, 0, 0, 50);
	FillRectangle(square, pixel_color, screen_pixels);		
	
	BOOLEAN done = TRUE;
	BOOLEAN pressed_up = FALSE;
	BOOLEAN  pressed_down= FALSE;
	BOOLEAN pressed_left = FALSE;
	BOOLEAN pressed_right = FALSE;
	
	text = TTF_RenderText_Solid(font,)

	char curr_ch = '\0';
	char lines[MAX_LINES][MAX_LINE_LENGTH] = { 0 };
	u32 line_idx = 0;
	u32 char_idx = 0;

	u32 start_time =SDL_GetTicks();
	BOOLEAN no_square = TRUE;

		while(done){
			SDL_Event event;
			while(SDL_PollEvent(&event)){
				if(event.type == SDL_QUIT){
					done = FALSE;
					break;
				}

				if(event.type != SDL_KEYDOWN && event.type != SDL_KEYUP){
					break;
				}
				SDL_Keycode code = event.key.keysym.sym;
				
				switch(code){
					case SDLK_ESCAPE:
						done = event.type == SDL_KEYDOWN;
						break;
					case SDLK_UP:
						pressed_up = event.type == SDL_KEYDOWN;;
						break;
					case SDLK_DOWN:
						pressed_down = event.type == SDL_KEYDOWN;;
						break;
					case SDLK_LEFT:
						pressed_left = event.type == SDL_KEYDOWN;;
						break;
					case SDLK_RIGHT:
						pressed_right = event.type == SDL_KEYDOWN;;
						break;
					default:
						if ( event.type != SDL_KEYUP) {
							curr_ch = (char)code;
						}
						break;
				}

		
		memset(screen_pixels, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(u32));
//update text buffer based on input{
		if ((curr_ch >= 'a' && curr_ch <= 'z') || (curr_ch >= 'A' && curr_ch <= 'Z') || (curr_ch >= '0' && curr_ch <= '9') || (curr_ch == '.') || (curr_ch == ' ') || (curr_ch == ','));
			lines[line_idx][--char_idx] = curr_ch;
		else if ((curr_ch == '\n') | (curr_ch == '\t')) {
			++line_idx;
			char_idx = 0;
		}
//}
//move word to next line if line is full { }
{    
i32 line_w = glyph_w * (char_idx + 1);
printf("%d\n", line_w);
}


//updating screen pixels based on the new text buffer {
		i32 y = 0;
		for (i32 i= 0; i<= line_idx; ++i) {
			y = i* (glyph_h +5);
			TXT_DrawText(lines[i], 0, y, screen_pixels );
		}
//}
//		square.x = strlen(line)* glyph_w + 1;
		
				if(pressed_up){
					square.y -=8;
				}
				if(pressed_down){
					square.y +=8;
				}
				if(pressed_left){
					square.x -=8;
				}
				if(pressed_right){
					square.x +=8;
				}
/*		char *msg ="hello world";
		int width = TXT_TextWidth(msg);
		TXT_DrawText("msg , (SCREEN_WIDTH-width)/4, 50, screen_pixels);
*/
		FillRectangle(square ,no_square ? 0 : SDL_MapRGB(format, 255, 0, 0), screen_pixels);
		if (SDL_GetTicks - start_time >500) {
			no_square = !no_square;
			start_time = SDL_GetTicks();
		}

		SDL_UpdateTexture(screen, NULL, screen_pixels, SCREEN_WIDTH * sizeof(u32));
		SDL_RenderClear(renderer);
		SDL_DestroyTexture(bitmapTex);
		SDL_RenderCopy(renderer, screen, NULL,NULL);
		SDL_RenderPresent(renderer);
					}
		SDL_BlitSurface(text,NULL,screen,NULL);
		//SDL_FreeSurface(image);
		SDL_FreeSurface(text);
		TTF_CloseFont(font);
		TTF_Quit();
		}
	}		
return 0;
}
