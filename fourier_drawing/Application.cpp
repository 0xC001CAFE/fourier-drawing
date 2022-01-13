#include <iostream>
#include <numbers>

#include "Application.h"
#include "Epicycle.h"

Application::Application(std::string title, unsigned int width, unsigned int height) : title(title), width(width), height(height), window(nullptr), renderer(nullptr) {}

Application::~Application() {
	if (window != nullptr) SDL_DestroyWindow(window);
	if (renderer != nullptr) delete renderer;

	SDL_Quit();
}

bool Application::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Could not initialize SDL: " << SDL_GetError() << '\n';

		return false;
	}

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	if (window == nullptr) {
		std::cout << "Could not create window: " << SDL_GetError() << '\n';

		return false;
	}

	SDL_Renderer* sdlRenderer = SDL_CreateRenderer(window, -1, 0);
	if (sdlRenderer == nullptr) {
		std::cout << "Could not create renderer: " << SDL_GetError() << '\n';

		return false;
	}

	renderer = new Renderer(sdlRenderer);

	return true;
}

void Application::run(const std::vector<std::complex<double>>& drawing) const {
	SDL_Event event;
	double time = 0;

	std::vector<Epicycle*> epicycles;
	epicycles.push_back(new Epicycle(*renderer, Vector<double>(), 0, drawing[0]));
	for (size_t i = 1; i < drawing.size(); i++) {
		epicycles.push_back(new Epicycle(*renderer, epicycles[i - 1]->getCirclingPoint(), i, drawing[i]));
	}

	const double deltaTime = (2 * std::numbers::pi) / epicycles.size();

	std::vector<Vector<double>> path;

	while (true) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) break;

		renderer->clear(black);

		for (auto& epicycle : epicycles) {
			epicycle->draw(time, white);
		}

		path.push_back(epicycles.back()->getCirclingPoint());
		for (const auto& point : path) {
			// TODO: Implement type conversion
			renderer->drawPoint(VectorUInt(point.x, point.y), Color(0xff, 0xff, 0x00));
		}

		renderer->render();

		if (time >= 2 * std::numbers::pi) {
			path.clear();

			time = 0;
		}
		else {
			time += deltaTime;
		}

		SDL_Delay(50);
	}
}
