//#########################
//Pekka Kana 2
//by Janne Kivilahti from Piste Gamez (2003)
//#########################
#pragma once

#include "engine/PFont.hpp"
#include "engine/platform.hpp"

namespace PDraw {

const int FADE_FAST = 5;
const int FADE_NORMAL = 2;
const int FADE_SLOW = 1;

const char FILTER_NEAREST[] = "0";
const char FILTER_BILINEAR[] = "1";

struct RECT{
    DWORD x, y, w, h;
};

bool  is_fading();
int   fade_out(int speed);
int   fade_in(int speed);
void  rotate_palette(BYTE start, BYTE end);

int   image_new(int w, int h);
int   image_load(const char* filename, bool getPalette);
int   image_load(int& index, const char* filename, bool getPalette);
int   image_copy(int src_i, int dst_i);
int   image_cut(int ImgIndex, int x, int y, int w, int h);
int   image_cut(int ImgIndex, RECT area);
int   image_clip(int index, int x, int y);
int   image_cliptransparent(int index, int x, int y, int alpha);
int   image_cutclip(int index, int dstx, int dsty, int srcx, int srcy, int oikea, int ala);
int   image_cutclip(int index, RECT srcrect, RECT dstrect);
int   image_cutcliptransparent(int index, RECT srcrect, RECT dstrect, int alpha);
int   image_cutcliptransparent(int index, RECT srcrect, RECT dstrect, int alpha, int colorsum);
int   image_cutcliptransparent(int index, DWORD src_x, DWORD src_y, DWORD src_w, DWORD src_h,
    DWORD dst_x, DWORD dst_y, int alpha, BYTE colorsum);
void  image_getsize(int index, int& w, int& h);
int   image_fliphori(int index);
int   image_snapshot(int index);
int   image_delete(int& index);

int   image_fill(int index, BYTE color);
int   image_fill(int index, int posx, int posy, int oikea, int ala, BYTE color);
int   screen_fill(BYTE color);
int   screen_fill(int posx, int posy, int oikea, int ala, BYTE color);
void  set_mask(int x, int y, int w, int h);

int   drawscreen_start(BYTE *&pixels, DWORD &pitch);
int   drawscreen_end();
int   drawimage_start(int index, BYTE *&pixels, DWORD &pitch);
int   drawimage_end(int index);
BYTE  blend_colors(BYTE color, BYTE colBack,int alpha);

int   font_create(int image, int x, int y, int width, int height, int count);
int   font_create(const char* path, const char* file);
int   font_write(int font_index, const char* text, int x, int y);
int   font_writealpha(int font_index, const char* text, int x, int y, BYTE alpha);

int   set_filter(const char* filter);
void  set_fullscreen(bool set);
void  adjust_screen();
void  fit_screen(bool fit);
void  change_resolution(int w, int h);

void  get_windowposition(int* x, int* y);

int   get_xoffset();
void  set_xoffset(int x);
void  clear_fonts();
void  update(bool draw);

int  init(int width, int height, const char* name, const char* icon);
int  terminate();

}