#pragma once
#include <Game/GameBoard.h>
#include <CppUnitTest.h>
#include <vector>

template<typename T>
void assertAreEqual(const T &expected, const T &actual) {
	using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
	Assert::AreEqual(expected, actual);
}

template<typename T>
void assertAreEqual(
	const std::vector<T> &expected,
	const std::vector<T> &actual)
{
	assertAreEqual(expected.size(), actual.size());
	using size_type = std::vector<T>::size_type;
	for (size_type i = 0; i < expected.size(); ++i)
		assertAreEqual(expected[i], actual[i]);
}

template <typename T>
void assertAreEqual(
	const std::vector<std::vector<T>>& expected,
	const GameBoard<T> &actual)
{
	assertAreEqual(expected.size(), actual.size());
	using size_type = std::vector<T>::size_type;
	for (size_type i = 0; i < expected.size(); i++)
		assertAreEqual(expected[i], actual[i]);
}