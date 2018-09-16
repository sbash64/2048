#include "stdafx.h"
#include "CppUnitTest.h"
#include "assert_utility.h"
#include <GameBoardAnalyzer.h>

namespace MSTest
{
	TEST_CLASS(GameBoardAnalyzerTester)
	{
	public:
		TEST_METHOD(testOpenCells)
		{
			assertAreEqual(
				{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
				GameBoardAnalyzer{}.openCells(
					GameBoard(
						{
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 }
						}
					)
				));
		}
	};
}