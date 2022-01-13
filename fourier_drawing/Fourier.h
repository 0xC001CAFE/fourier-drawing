#pragma once

#include <vector>
#include <complex>
#include <numbers>

#include "Complex.h"
#include "Math.h"

namespace Fourier {
	// Calculates DFT during run-time
	std::vector<std::complex<double>> dft(const std::vector<std::complex<double>>& x);

	constexpr double phi(size_t k, size_t n, size_t N) {
		return (2 * std::numbers::pi * k * n) / N;
	}

	template <size_t K, size_t N, size_t N_MAX, IsComplex SUM, typename... X_INPUT>
	struct InnerLoop {
		using type = InnerLoop<
			K,
			N + 1,
			N_MAX,
			ComplexAdd<
			SUM,
			ComplexMultiply<
			typename ComplexListItem<N, X_INPUT...>::type,
			Complex<math::cos(phi(K, N, N_MAX)), -math::sin(phi(K, N, N_MAX))>
			>
			>,
			X_INPUT...
		>::type;
	};

	template <size_t K, size_t N_MAX, IsComplex SUM, typename... X_INPUT>
	struct InnerLoop<K, N_MAX, N_MAX, SUM, X_INPUT...> {
		//using type = SUM;

		using type = Complex<
			SUM::re / N_MAX,
			SUM::im / N_MAX
		>;
	};

	template <size_t, size_t, typename...>
	struct OuterLoop {};

	template <size_t K, size_t K_MAX, typename... X_INPUT, typename... X_OUTPUT>
	struct OuterLoop<K, K_MAX, ComplexList<X_INPUT...>, ComplexList<X_OUTPUT...>> {
		using type = OuterLoop<
			K + 1,
			K_MAX,
			ComplexList<X_INPUT...>,
			ComplexList<
			X_OUTPUT...,
			typename InnerLoop<K, 0, K_MAX, Complex<0., 0.>, X_INPUT...>::type
			>
		>::type;
	};

	template <size_t K_MAX, typename... X_INPUT, typename... X_OUTPUT>
	struct OuterLoop<K_MAX, K_MAX, ComplexList<X_INPUT...>, ComplexList<X_OUTPUT...>> {
		using type = ComplexList<X_OUTPUT...>;
	};

	template <typename...>
	struct DFT {};

	template <typename... X>
	struct DFT<ComplexList<X...>> {
		using type = OuterLoop<0, sizeof...(X), ComplexList<X...>, ComplexList<>>::type;
	};

	// Calculates DFT during compile-time
	template <typename LIST>
	using DftResult = DFT<LIST>::type;
}
