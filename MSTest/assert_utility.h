#pragma once
#include "stdafx.h"
#include <vector>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void assertAreEqual(
	const std::vector<std::vector<double>> &expected,
	const std::vector<std::vector<double>> &actual);