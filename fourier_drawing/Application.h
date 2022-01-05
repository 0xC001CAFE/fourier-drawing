#pragma once

#include <string>
#include <SDL.h>

#include "Vector.h"
#include "Color.h"

using namespace std;

class Application {
private:
	const string title;
	const unsigned int width;
	const unsigned int height;
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	Application(string title, unsigned int width, unsigned int height);
	~Application();

	bool init();
	void run() const;

	void drawLine(VectorUInt start, VectorUInt end, Color color = black) const;
	void drawPoint(VectorUInt position, Color color = black) const;

private:
	void setColor(Color color) const;
	void clear() const;
	void render() const;
};
