#include "stdafx.h"
#include "assert_utility.h"
#include <GameBoardAnalyzer.h>
#include <CppUnitTest.h>

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
			assertAreEqual(
				{ 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14 },
				GameBoardAnalyzer{}.openCells(
					GameBoard(
						{
							{ 1, 0, 0, 0 },
							{ 0, 1, 0, 0 },
							{ 0, 0, 1, 0 },
							{ 0, 0, 0, 1 }
						}
					)
				));
			assertAreEqual(
				{ 1, 2, 3, 12, 13, 14 },
				GameBoardAnalyzer{}.openCells(
					GameBoard(
						{
							{ 1, 1, 1, 0 },
							{ 0, 1, 1, 0 },
							{ 0, 1, 1, 0 },
							{ 0, 1, 1, 1 }
						}
					)
				));
		}
		TEST_METHOD(testCanMove)
		{
			using namespace Microsoft::VisualStudio::CppUnitTestFramework;
			Assert::IsTrue(
				GameBoardAnalyzer{}.canMove(
					GameBoard(
						{
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 }
						}
					)
				)
			);
		}
	};
}