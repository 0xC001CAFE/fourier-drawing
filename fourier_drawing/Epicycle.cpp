#include "Epicycle.h"

Epicycle::Epicycle(const Renderer& renderer, const Vector<double>& pivotPoint, unsigned int frequency, std::complex<double> fourier) : renderer(renderer), pivotPoint(pivotPoint), frequency(frequency), fourier(fourier) {}

const Vector<double>& Epicycle::getCirclingPoint() const {
	return circlingPoint;
}

void Epicycle::draw(double time, const Color& color) {
	const double radius = abs(fourier);
	const double phase = arg(fourier);

	circlingPoint.x = pivotPoint.x + radius * cos(phase + frequency * time);
	circlingPoint.y = pivotPoint.y + radius * sin(phase + frequency * time);

	// TODO: Implement type conversion
	renderer.drawLine(VectorUInt(pivotPoint.x, pivotPoint.y), VectorUInt(circlingPoint.x, circlingPoint.y), color);
}
