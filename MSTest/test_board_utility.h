#pragma once
#include <array>

template<std::size_t N>
std::array<std::array<double, N>, N> rotateClockwise(
	std::array<std::array<double, N>, N> board);