#pragma once

#include <SDL.h>

#include "Vector.h"
#include "Color.h"

class Renderer {
private:
	SDL_Renderer* renderer;

public:
	Renderer(SDL_Renderer* renderer);
	~Renderer();

	void clear(const Color& color = white) const;
	void render() const;

	void drawPoint(const VectorUInt& point, const Color& color = black) const;
	void drawLine(const VectorUInt& start, const VectorUInt& end, const Color& color = black) const;

private:
	void setColor(const Color& color) const;
};
