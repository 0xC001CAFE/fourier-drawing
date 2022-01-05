#pragma once

template <typename T>
struct Vector {
	T x;
	T y;

	Vector(T x = 0, T y = 0) : x(x), y(y) {}
};

using VectorUInt = Vector<unsigned int>;
