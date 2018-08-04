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
			assertBoardTransition(
			{
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
		}

	private:
		void assertBoardTransition(
			std::vector<std::vector<double>> initial,
			std::string movement,
			std::vector<std::vector<double>> final
		)
		{
			GameBoard board(initial);
			for (const auto &c : movement)
				if (c == 'r' || c == 'R')
					board.moveRight();
			assertAreEqual(final, board.getBoard());
		}

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
			assertBoardTransition(
			{
				{ 2, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 0, 0, 2 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});

			assertBoardTransition(
			{
				{ 0, 0, 0, 2 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 0, 0, 2 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
		}

		TEST_METHOD(testMoveRightTwoTwos)
		{
			assertBoardTransition(
			{
				{ 2, 2, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 0, 0, 4 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
			assertBoardTransition(
			{
				{ 2, 0, 2, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 0, 0, 4 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
			assertBoardTransition(
			{
				{ 2, 0, 0, 2 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 0, 0, 4 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
		}

		TEST_METHOD(testMoveRightThreeTwos)
		{
			assertBoardTransition(
			{
				{ 2, 2, 2, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 0, 2, 4 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
		}
	};
};
