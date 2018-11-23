#include "assert_utility.h"

void assertAreEqual(
	const std::vector<std::vector<double>> &expected, 
	const GameBoard &actual)
{
	for (std::size_t i = 0; i < expected.size(); i++)
		assertAreEqual(expected[i], actual[i]);
}
