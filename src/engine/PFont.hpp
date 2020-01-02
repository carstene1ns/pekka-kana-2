//#########################
//Pekka Kana 2
//by Janne Kivilahti from Piste Gamez (2003)
//#########################
#pragma once

#include "engine/platform.hpp"

class PFont{
private:
	int charlist[256];
	int char_w, char_h, char_count;
	int image_index = -1;
	int init_charlist();
	int get_image(int x,int y,int img_source);

public:
	int write(int posx, int posy, const char *text);
	int write_trasparent(int posx, int posy, const char* text, int alpha);
	
	PFont(int img_source, int x, int y, int width, int height, int count);
	PFont();
	~PFont();

	int load(const char* file_path, const char* file);
};