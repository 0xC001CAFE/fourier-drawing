#pragma once

#include <complex>

#include "Application.h"
#include "Vector.h"

using namespace std;

class Epicycle {
private:
	const Application& app;
	const Vector<double>& pivotPoint;
	Vector<double> circlingPoint;
	const unsigned int frequency;
	const complex<double> fourier;

public:
	Epicycle(const Application& app, const Vector<double>& pivotPoint, unsigned int frequency, complex<double> fourier);

	const Vector<double>& getCirclingPoint() const;
	void draw(double time);
};
