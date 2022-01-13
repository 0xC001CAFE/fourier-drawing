#pragma once

#include <string>
#include <SDL.h>
#include <vector>
#include <complex>

#include "Renderer.h"

class Application {
private:
	const std::string title;
	const unsigned int width;
	const unsigned int height;
	SDL_Window* window;
	Renderer* renderer;

public:
	Application(std::string title, unsigned int width, unsigned int height);
	~Application();

	bool init();
	void run(const std::vector<std::complex<double>>& drawing) const;
};
