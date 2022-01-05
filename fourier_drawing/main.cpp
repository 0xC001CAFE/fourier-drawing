#include "Application.h"

int main(int argc, char* argv[]) {
	Application app("Fourier Drawing", 640, 480);

	if (app.init()) app.run();

	return 0;
}
