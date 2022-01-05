#pragma once

#include <vector>
#include <complex>

using namespace std;

class Fourier {
public:
	static vector<complex<double>> dft(vector<complex<double>> x);
};
