#include "stdafx.h"
#include "CppUnitTest.h"
#include <GameBoardFormatter.h>

namespace MSTest
{
	TEST_CLASS(GameBoardFormatterTester)
	{
	public:
		TEST_METHOD(testAsString)
		{
			using namespace Microsoft::VisualStudio::CppUnitTestFramework;
			Assert::AreEqual(
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0",
				GameBoardFormatter{}.asString(
					GameBoard(
						{
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 }
						}
					)
				).c_str());
			Assert::AreEqual(
				" 1  2  3  4\n" \
				" 5  6  7  8\n" \
				" 9 10 11 12\n" \
				"13 14 15 16",
				GameBoardFormatter{}.asString(
					GameBoard(
						{
							{ 1, 2, 3, 4 },
							{ 5, 6, 7, 8 },
							{ 9, 10, 11, 12 },
							{ 13, 14, 15, 16 }
						}
					)
				).c_str());
		}
	};
}