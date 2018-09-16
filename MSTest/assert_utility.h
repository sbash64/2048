#pragma once
#include <vector>

void assertAreEqual(
	const std::vector<std::vector<double>> &expected,
	const std::vector<std::vector<double>> &actual);
void assertAreEqual(
	const std::vector<double> &expected,
	const std::vector<double> &actual);