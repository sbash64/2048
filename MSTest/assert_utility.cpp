#include "stdafx.h"
#include "CppUnitTest.h"
#include "assert_utility.h"

void assertAreEqual(
	const std::vector<std::vector<double>>& expected, 
	const std::vector<std::vector<double>>& actual)
{
	for (size_t i = 0; i < expected.size(); i++)
		for (size_t j = 0; j < expected[i].size(); j++)
			Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(
				expected[i][j],
				actual[i][j]
			);

}
