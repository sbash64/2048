#pragma once
#include <array>

template<std::size_t N>
void assertAreEqual(
	const std::array<std::array<double, N>, N> &expected,
	const std::array<std::array<double, N>, N> &actual);