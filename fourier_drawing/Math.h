#pragma once

#include <numbers>

namespace math {
	constexpr double tolerance = 0.001;

	constexpr double cube(double x) {
		return x * x * x;
	}

	constexpr double sinHelper(double x) {
		return x < tolerance ? x : 3 * sinHelper(x / 3) - 4 * cube(sinHelper(x / 3));
	}

	constexpr double sin(double x) {
		return sinHelper(x < 0 ? -x + std::numbers::pi : x);
	}

	constexpr double cos(double x) {
		return sin(std::numbers::pi / 2 - x);
	}
}
