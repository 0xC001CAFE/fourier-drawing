#pragma once

#include <complex>

#include "Renderer.h"
#include "Vector.h"

using namespace std;

class Epicycle {
private:
	const Renderer& renderer;
	const Vector<double>& pivotPoint;
	Vector<double> circlingPoint;
	const unsigned int frequency;
	const complex<double> fourier;

public:
	Epicycle(const Renderer& renderer, const Vector<double>& pivotPoint, unsigned int frequency, complex<double> fourier);

	const Vector<double>& getCirclingPoint() const;
	void draw(double time);
};
