#include "Application.h"
#include "Complex.h"

#include <vector>
#include <complex>

template <typename... DFT_RESULT>
std::vector<std::complex<double>> convert(dft::ComplexList<DFT_RESULT...>) {
	std::vector<std::complex<double>> X;

	(X.push_back(std::complex<double>(DFT_RESULT::re, DFT_RESULT::im)), ...);

	return X;
}

int main(int argc, char* argv[]) {
	Application app("Fourier Drawing", 640, 480);

#pragma region DFT input
	using x = dft::ComplexList <
		dft::complex_d<196.9, 228.8>,
		dft::complex_d<195.1, 192.7>,
		dft::complex_d<224.7, 186.6>,
		dft::complex_d<234.5, 165.5>,
		dft::complex_d<257.7, 162.2>,
		dft::complex_d<251.1, 126.5>,
		dft::complex_d<246.5, 90.7>,
		dft::complex_d<275.4, 84.1>,
		dft::complex_d<284.8, 118.7>,
		dft::complex_d<291.5, 154.4>,
		dft::complex_d<298.3, 190.1>,
		dft::complex_d<306.5, 155.7>,
		dft::complex_d<314.8, 120.3>,
		dft::complex_d<325.5, 86.1>,
		dft::complex_d<355.2, 93.1>,
		dft::complex_d<349.2, 128.6>,
		dft::complex_d<340.9, 164.>,
		dft::complex_d<332.7, 199.4>,
		dft::complex_d<348.2, 227.8>,
		dft::complex_d<349.2, 263.6>,
		dft::complex_d<332.5, 295.3>,
		dft::complex_d<302.9, 315.7>,
		dft::complex_d<267.2, 320.8>,
		dft::complex_d<232.5, 311.3>,
		dft::complex_d<207.9, 285.5>,
		dft::complex_d<198.4, 250.6>
	> ;
#pragma endregion

	using X = dft::OuterLoop<0, 26, x, dft::ComplexList<>>::type;
	dft::printComplexList(X{});

	const auto convertedX = convert(X{});
	//for (const auto& c : convertedX) {
	//	std::cout << c << '\n';
	//}

	if (app.init()) app.run(convertedX);

	return 0;
}
