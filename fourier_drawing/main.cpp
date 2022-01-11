//#include "Application.h"
#include "Complex.h"

int main(int argc, char* argv[]) {
	//Application app("Fourier Drawing", 640, 480);

	//if (app.init()) app.run();

	using X = dft::OuterLoop<0, 4, dft::x, dft::ComplexList<>>::type;
	dft::print<X>();

	return 0;
}
