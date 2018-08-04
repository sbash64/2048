#include "stdafx.h"
#include "CppUnitTest.h"
#include <GameBoard.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MSTest
{		
	TEST_CLASS(GameBoardTester)
	{
	public:
		TEST_METHOD(testMoveRightAllZeros)
		{
			GameBoard board(
			{
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
			board.moveRight();
			assertAreEqual(
			{
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
				board.getBoard());
		}

	private:
		void assertAreEqual(
			std::vector<std::vector<double>> expected,
			std::vector<std::vector<double>> actual)
		{
			for (size_t i = 0; i < expected.size(); i++)
				for (size_t j = 0; j < expected[i].size(); j++)
					Assert::AreEqual(
						expected[i][j],
						actual[i][j]
					);

		}

	public:
		TEST_METHOD(testMoveRightOneTwo)
		{
			GameBoard board(
			{
				{ 2, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
			board.moveRight();
			assertAreEqual(
			{
				{ 0, 0, 0, 2 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
				board.getBoard());
		}

		TEST_METHOD(testMoveRightTwoTwos)
		{
			GameBoard board(
			{
				{ 2, 2, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
			board.moveRight();
			assertAreEqual(
			{
				{ 0, 0, 0, 4 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
				board.getBoard());
		}
	};
}