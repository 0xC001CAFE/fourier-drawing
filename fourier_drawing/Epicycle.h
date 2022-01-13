#pragma once

#include <complex>

#include "Renderer.h"
#include "Vector.h"
#include "Color.h"

class Epicycle {
private:
	const Renderer& renderer;
	const Vector<double>& pivotPoint;
	Vector<double> circlingPoint;
	const unsigned int frequency;
	const std::complex<double> fourier;

public:
	Epicycle(const Renderer& renderer, const Vector<double>& pivotPoint, unsigned int frequency, std::complex<double> fourier);

	const Vector<double>& getCirclingPoint() const;
	void draw(double time, const Color& color = black);
};
