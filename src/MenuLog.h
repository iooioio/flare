/**
 * class MenuLog
 *
 * @author Clint Bellanger
 * @license GPL
 */

#ifndef MENU_LOG_H
#define MENU_LOG_H

#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "InputState.h"
#include "Utils.h"
#include "FontEngine.h"
#include "WidgetButton.h"

const int MAX_LOG_MESSAGES = 100;

const int LOG_TYPE_COUNT = 4;
const int LOG_TYPE_QUESTS = 0;
const int LOG_TYPE_MESSAGES = 1;
const int LOG_TYPE_ACHIEVEMENTS = 2;
const int LOG_TYPE_STATISTICS = 3;

class MenuLog {
private:
	SDL_Surface *screen;
	InputState *inp;
	FontEngine *font;

	SDL_Surface *background;
	SDL_Surface *tab_active;
	SDL_Surface *tab_inactive;
	WidgetButton *closeButton;
	
	void loadGraphics();
	void renderTab();
	
	string log_msg[LOG_TYPE_COUNT][MAX_LOG_MESSAGES];
	int log_count[LOG_TYPE_COUNT];
	string tab_labels[LOG_TYPE_COUNT];
	SDL_Rect tab_rect[LOG_TYPE_COUNT];
	Point tab_padding;
	int active_log;
	int paragraph_spacing;
	
public:
	MenuLog(SDL_Surface *screen, InputState *inp, FontEngine *font);
	~MenuLog();

	void logic();
	void render();
	void renderTab(int log_type);
	void add(string s, int log_type);
	void clear(int log_type);
	void clear();
	void clickTab(Point mouse);
	
	bool visible;
	SDL_Rect menu_area;
	SDL_Rect list_area;
	SDL_Rect tabs_area;

};

#endif
