#pragma once
#include <vector>

void assertAreEqual(
	const std::vector<std::vector<double>> &expected,
	const std::vector<std::vector<double>> &actual);
void assertAreEqual(
	const std::vector<size_t> &expected,
	const std::vector<size_t> &actual);