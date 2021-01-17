//#########################
//Pekka Kana 2
//Copyright (c) 2003 Janne Kivilahti
//#########################
#pragma once

#include "engine/PRender.hpp"

#include <SDL.h>

class PSdlSoft : public PRender::Renderer {

public:

	void* create_texture(void* surface) override;
	void remove_texture(void* texture) override;
	void render_texture(void* texture, float x, float y, float w, float h, float alpha) override;

    void clear_screen() override;
    void set_screen(PRender::FRECT screen_dst) override;
    int  set_shader(int mode) override;
    int  set_vsync(bool set) override;
    void update(void* buffer8) override;

    PSdlSoft(int width, int height, void* window);
    ~PSdlSoft();

private:

    SDL_Window* curr_window;

};