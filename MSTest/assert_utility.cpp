#include "stdafx.h"
#include "CppUnitTest.h"
#include "assert_utility.h"

template<std::size_t N>
void assertAreEqual(
	const std::array<std::array<double, N>, N>& expected,
	const std::array<std::array<double, N>, N>& actual)
{
	for (size_t i = 0; i < expected.size(); i++)
		for (size_t j = 0; j < expected[i].size(); j++)
			Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(
				expected[i][j],
				actual[i][j]
			);

}

template void assertAreEqual(
	const std::array<std::array<double, 4>, 4>& expected,
	const std::array<std::array<double, 4>, 4>& actual);
