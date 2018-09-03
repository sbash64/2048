#include "stdafx.h"
#include "CppUnitTest.h"
#include <GameBoard.h>
#include "assert_utility.h"
#include "test_board_utility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MSTest
{
	TEST_CLASS(GameBoardTester)
	{
	public:
		TEST_METHOD(testInvalidBoardThrows)
		{
			Assert::ExpectException<std::runtime_error>([]() { GameBoard({ {}, {} }); });
		}

		TEST_METHOD(testMoveRightAllZeros)
		{
			assertAllRotatedTransformTransitions(
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
			const std::vector<std::vector<double>> &initial,
			const std::string &movement,
			const std::vector<std::vector<double>> &final
		)
		{
			GameBoard board(initial);
			for (const auto &c : movement)
				switch (c)
				{
				case 'r':
				case 'R':
					board.moveRight();
					break;
				case 'd':
				case 'D':
					board.moveDown();
					break;
				case 'l':
				case 'L':
					break;
				case 'u':
				case 'U':
					break;
				}
			assertAreEqual(final, board.getBoard());
		}

		std::string clockwiseMovementTransform(std::string movement)
		{
			for (auto &c : movement)
				switch (c)
				{
				case 'r':
				case 'R':
					c = 'd';
					break;
				case 'd':
				case 'D':
					c = 'l';
					break;
				case 'l':
				case 'L':
					c = 'u';
					break;
				case 'u':
				case 'U':
					c = 'r';
					break;
				}
			return movement;
		}

		void assertAllRotatedTransformTransitions(
			const std::vector<std::vector<double>> &initial,
			const std::string &movement,
			const std::vector<std::vector<double>> &final
		)
		{
			assertBoardTransition(initial, movement, final);
			auto rotatedInitial(initial);
			auto rotatedMovement(movement);
			auto rotatedFinal(final);
			for (int i = 0; i < 1; i++) {
				rotatedInitial = rotateClockwise(std::move(rotatedInitial));
				rotatedMovement = clockwiseMovementTransform(std::move(rotatedMovement));
				rotatedFinal = rotateClockwise(std::move(rotatedFinal));
				assertBoardTransition(rotatedInitial, rotatedMovement, rotatedFinal);
			}
		}

	public:
		TEST_METHOD(testMoveRightOneTwo)
		{
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
			{
				{ 0, 2, 0, 0 },
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
			assertAllRotatedTransformTransitions(
			{
				{ 0, 0, 2, 0 },
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
			assertAllRotatedTransformTransitions(
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
			assertBoardTransition(
			{
				{ 0, 2, 2, 0 },
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
				{ 0, 2, 0, 2 },
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
				{ 0, 0, 2, 2 },
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
			assertBoardTransition(
			{
				{ 2, 2, 0, 2 },
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
			assertBoardTransition(
			{
				{ 2, 0, 2, 2 },
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
			assertBoardTransition(
			{
				{ 0, 2, 2, 2 },
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

		TEST_METHOD(testMoveRightFourTwos)
		{
			assertBoardTransition(
			{
				{ 2, 2, 2, 2 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 0, 4, 4 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
		}

		TEST_METHOD(testMoveRightTwoUnequals)
		{
			assertBoardTransition(
			{
				{ 2, 4, 0, 0 },
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
			assertBoardTransition(
			{
				{ 2, 0, 4, 0 },
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
			assertBoardTransition(
			{
				{ 2, 0, 0, 4 },
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
			assertBoardTransition(
			{
				{ 0, 2, 4, 0 },
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
			assertBoardTransition(
			{
				{ 0, 2, 0, 4 },
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
			assertBoardTransition(
			{
				{ 0, 0, 2, 4 },
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

		TEST_METHOD(testMoveRightThreeUnequals)
		{
			assertBoardTransition(
			{
				{ 2, 4, 8, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 2, 4, 8 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
			assertBoardTransition(
			{
				{ 2, 4, 0, 8 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 2, 4, 8 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
			assertBoardTransition(
			{
				{ 2, 0, 4, 8 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 2, 4, 8 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
			assertBoardTransition(
			{
				{ 0, 2, 4, 8 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 2, 4, 8 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
		}

		TEST_METHOD(testMoveRightFourUnequals)
		{
			assertBoardTransition(
			{
				{ 2, 4, 8, 16 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 2, 4, 8, 16 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
		}

		TEST_METHOD(testMoveRightCombinesOnlyOnce)
		{
			assertBoardTransition(
			{
				{ 4, 2, 2, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 0, 4, 4 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
			assertBoardTransition(
			{
				{ 4, 2, 0, 2 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 0, 4, 4 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
			assertBoardTransition(
			{
				{ 4, 0, 2, 2 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 0, 4, 4 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
			assertBoardTransition(
			{
				{ 0, 4, 2, 2 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"r",
			{
				{ 0, 0, 4, 4 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
		}

		TEST_METHOD(testMoveRightTwiceAllZeros)
		{
			assertBoardTransition(
			{
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"rr",
			{
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
		}

		TEST_METHOD(testMoveRightThreeCombos)
		{
			assertBoardTransition(
			{
				{ 8, 4, 2, 2 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			"rrr",
			{
				{ 0, 0, 0, 16 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			});
		}
	};
};
