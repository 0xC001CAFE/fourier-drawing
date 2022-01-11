#pragma once

#include <numbers>
#include <iostream>

namespace math {
	constexpr double cube(double x) {
		return x * x * x;
	}

	constexpr double sin_helper(double x) {
		return x < 0.001 ? x : 3 * sin_helper(x / 3.) - 4 * cube(sin_helper(x / 3.));
	}

	constexpr double sin(double x) {
		return sin_helper(x < 0 ? -x + std::numbers::pi : x);
	}

	constexpr double cos(double x) {
		return sin((std::numbers::pi / 2) - x);
	}
}

namespace dft {
	template <typename T, T RE, T IM>
	struct complex {
		static constexpr T re = RE;
		static constexpr T im = IM;
	};

	template <double RE, double IM>
	using complex_d = complex<double, RE, IM>;

	template <typename A, typename B>
	using complex_d_add = complex_d<
		A::re + B::re,
		A::im + B::im
	>;

	template <typename A, typename B>
	using complex_d_multiply = complex_d<
		A::re* B::re - A::im * B::im,
		A::re* B::im + A::im * B::re
	>;

	template <typename...>
	struct ComplexList {};

	using x = ComplexList<
		complex_d<1., 0.>,	// --DFT--> 2
		complex_d<2., -1.>,	// --DFT--> -2-2i
		complex_d<0., -1.>,	// --DFT--> -2i
		complex_d<-1., 2.>	// --DFT--> 4+4i
	>;

	template <size_t, typename...>
	struct ListItem {};

	template <typename ITEM, typename... LIST>
	struct ListItem<0, ITEM, LIST...> {
		using type = ITEM;
	};

	template <size_t INDEX, typename ITEM, typename... LIST>
	struct ListItem<INDEX, ITEM, LIST...> {
		using type = ListItem<INDEX - 1, LIST...>::type;
	};

	constexpr double phi(size_t k, size_t n, size_t N) {
		return (2 * std::numbers::pi * k * n) / N;
	}

	template <size_t K, size_t N, size_t N_MAX, typename SUM, typename... X_INPUT>
	struct InnerLoop {
		using type = InnerLoop<
			K,
			N + 1,
			N_MAX,
			complex_d_add<
			SUM,
			complex_d_multiply<
			typename ListItem<N, X_INPUT...>::type,
			complex_d<math::cos(phi(K, N, N_MAX)), -math::sin(phi(K, N, N_MAX))>
			>
			>,
			X_INPUT...
		>::type;
	};

	template <size_t K, size_t N_MAX, typename SUM, typename... X_INPUT>
	struct InnerLoop<K, N_MAX, N_MAX, SUM, X_INPUT...> {
		//using type = complex_d<
		//	SUM::re / N_MAX,
		//	SUM::im / N_MAX
		//>;

		using type = SUM;
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
			typename InnerLoop<K, 0, K_MAX, complex_d<0., 0.>, X_INPUT...>::type
			>
		>::type;
	};

	template <size_t K_MAX, typename... X_INPUT, typename... X_OUTPUT>
	struct OuterLoop<K_MAX, K_MAX, ComplexList<X_INPUT...>, ComplexList<X_OUTPUT...>> {
		using type = ComplexList<X_OUTPUT...>;
	};

	template <typename>
	void print() {
		std::cout << __FUNCSIG__ << '\n';
	}
}
