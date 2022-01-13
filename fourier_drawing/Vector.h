#pragma once

template <typename T>
struct Vector {
	T x;
	T y;

	Vector(T x = 0, T y = 0) : x(x), y(y) {}

	template <typename TYPE>
	Vector<TYPE> as() const {
		return Vector<TYPE>(static_cast<TYPE>(x), static_cast<TYPE>(y));
	}
};

using VectorUInt = Vector<unsigned int>;
