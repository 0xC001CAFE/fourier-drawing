#pragma once

#include <iostream>
#include <vector>
#include <complex>

template <typename T, T RE, T IM>
struct GenericComplex {
	static constexpr T re = RE;
	static constexpr T im = IM;
};

template <double RE, double IM>
using Complex = GenericComplex<double, RE, IM>;

template <typename A, typename B>
using ComplexAdd = Complex<
	A::re + B::re,
	A::im + B::im
>;

template <typename A, typename B>
using ComplexMultiply = Complex<
	A::re* B::re - A::im * B::im,
	A::re* B::im + A::im * B::re
>;

template <typename...>
struct ComplexList {};

template <typename... LIST>
void printComplexList(ComplexList<LIST...>) {
	((std::cout << '(' << LIST::re << ", " << LIST::im << ')' << '\n'), ...);
}

template <typename... LIST>
std::vector<std::complex<double>> convertComplexList(ComplexList<LIST...>) {
	std::vector<std::complex<double>> result;

	(result.push_back(std::complex<double>(LIST::re, LIST::im)), ...);

	return result;
}

template <size_t, typename...>
struct ComplexListItem {};

template <typename ITEM, typename... LIST>
struct ComplexListItem<0, ITEM, LIST...> {
	using type = ITEM;
};

template <size_t INDEX, typename ITEM, typename... LIST>
struct ComplexListItem<INDEX, ITEM, LIST...> {
	using type = ComplexListItem<INDEX - 1, LIST...>::type;
};
