#include "Epicycle.h"

Epicycle::Epicycle(const Application& app, const Vector<double>& pivotPoint, unsigned int frequency, complex<double> fourier) : app(app), pivotPoint(pivotPoint), frequency(frequency), fourier(fourier) {}

const Vector<double>& Epicycle::getCirclingPoint() const {
	return circlingPoint;
}

void Epicycle::draw(double time) {
	const double radius = abs(fourier);
	const double phase = arg(fourier);

	circlingPoint.x = pivotPoint.x + radius * cos(phase + frequency * time);
	circlingPoint.y = pivotPoint.y + radius * sin(phase + frequency * time);

	// TODO: Implement type conversion
	app.drawLine(VectorUInt(pivotPoint.x, pivotPoint.y), VectorUInt(circlingPoint.x, circlingPoint.y));
}
