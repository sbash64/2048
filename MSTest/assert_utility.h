#pragma once
#include "stdafx.h"
#include <GameBoard.h>
#include <CppUnitTest.h>
#include <vector>

template<typename T>
void assertAreEqual(
	const std::vector<T> &expected,
	const std::vector<T> &actual)
{
	for (std::size_t i = 0; i < expected.size(); ++i)
		Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(
			expected[i],
			actual[i]
		);
}

template<typename T>
void assertAreEqual(
	const std::vector<std::vector<T>> &expected,
	const std::vector<std::vector<T>> &actual)
{
	for (std::size_t i = 0; i < expected.size(); ++i)
		assertAreEqual(
			expected[i],
			actual[i]
		);
}

void assertAreEqual(
	const std::vector<std::vector<double>>& expected,
	const GameBoard& actual);