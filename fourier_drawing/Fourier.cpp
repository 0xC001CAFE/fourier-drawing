#include <numbers>

#include "Fourier.h"

vector<complex<double>> Fourier::dft(vector<complex<double>> x) {
	const size_t N = x.size();

	vector<complex<double>> X;
	X.reserve(N);

	for (size_t k = 0; k < N; k++) {
		complex<double> sum;

		for (size_t n = 0; n < N; n++) {
			const double phi = (2 * numbers::pi * k * n) / N;

			sum += x[n] * complex<double>(cos(phi), -sin(phi));
		}

		sum /= N;
		X.push_back(sum);
	}

	return X;
}
