#include "Fourier.h"

std::vector<std::complex<double>> Fourier::dft(const std::vector<std::complex<double>>& x) {
	const size_t N = x.size();

	std::vector<std::complex<double>> X;
	X.reserve(N);

	for (size_t k = 0; k < N; k++) {
		std::complex<double> sum;

		for (size_t n = 0; n < N; n++) {
			const double phi = (2 * std::numbers::pi * k * n) / N;

			sum += x[n] * std::complex<double>(cos(phi), -sin(phi));
		}

		sum /= N;
		X.push_back(sum);
	}

	return X;
}
