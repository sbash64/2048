#include "stdafx.h"
#include "assert_utility.h"

void assertAreEqual(const std::vector<std::vector<double>>& expected, const std::vector<std::vector<double>>& actual)
{
	for (size_t i = 0; i < expected.size(); i++)
		for (size_t j = 0; j < expected[i].size(); j++)
			Assert::AreEqual(
				expected[i][j],
				actual[i][j]
			);

}
