#pragma once

#include <string>
#include <SDL.h>

#include "Renderer.h"

using namespace std;

class Application {
private:
	const string title;
	const unsigned int width;
	const unsigned int height;
	SDL_Window* window;
	Renderer* renderer;

public:
	Application(string title, unsigned int width, unsigned int height);
	~Application();

	bool init();
	void run() const;
};
