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
			Assert::AreEqual(
				"    1     2     3     4\n" \
				"   50    60    70    80\n" \
				"  900  1000  1100  1200\n" \
				"13000 14000 15000 16000",
				GameBoardFormatter{}.asString(
					GameBoard(
						{
							{ 1, 2, 3, 4 },
							{ 50, 60, 70, 80 },
							{ 900, 1000, 1100, 1200 },
							{ 13000, 14000, 15000, 16000 }
						}
					)
				).c_str());
			Assert::AreEqual(
				"  1     2 3000   4\n" \
				" 50     6    7 800\n" \
				"900    10  110  12\n" \
				" 13 14000  150 160",
				GameBoardFormatter{}.asString(
					GameBoard(
						{
							{ 1, 2, 3000, 4 },
							{ 50, 6, 7, 800 },
							{ 900, 10, 110, 12 },
							{ 13, 14000, 150, 160 }
						}
					)
				).c_str());
		}
	};
}