#include "Renderer.h"

Renderer::Renderer(SDL_Renderer* renderer) : renderer(renderer) {}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer);
}

void Renderer::clear(const Color& color) const {
	setColor(color);
	SDL_RenderClear(renderer);
}

void Renderer::render() const {
	SDL_RenderPresent(renderer);
}

void Renderer::drawPoint(const VectorUInt& point, const Color& color) const {
	setColor(color);
	SDL_RenderDrawPoint(renderer, point.x, point.y);
}

void Renderer::drawLine(const VectorUInt& start, const VectorUInt& end, const Color& color) const {
	setColor(color);
	SDL_RenderDrawLine(renderer, start.x, start.y, end.x, end.y);
}

void Renderer::setColor(const Color& color) const {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}
