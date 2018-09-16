#pragma once
#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

template<typename T>
void assertAreEqual(
	const std::vector<T> &expected,
	const std::vector<T> &actual)
{
	for (size_t i = 0; i < expected.size(); ++i)
		Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(
			expected[i],
			actual[i]
		);
}

template<typename T>
void assertAreEqual(
	const std::vector<std::vector<T>>& expected,
	const std::vector<std::vector<T>>& actual)
{
	for (size_t i = 0; i < expected.size(); i++)
		for (size_t j = 0; j < expected[i].size(); j++)
			Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(
				expected[i][j],
				actual[i][j]
			);

}