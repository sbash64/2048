#include "stdafx.h"
#include "CppUnitTest.h"
#include <GameBoard.h>
#include "assert_utility.h"
#include "test_board_utility.h"

namespace MSTest
{
	TEST_CLASS(GameBoardTester)
	{
	public:
		TEST_METHOD(testInvalidBoardThrows)
		{
			using namespace Microsoft::VisualStudio::CppUnitTestFramework;
			Assert::ExpectException<std::runtime_error>(
				[]() { GameBoard<0>({}); });
			GameBoard<1>(
				{
					{ 0 }
				});
			GameBoard<2>(
				{ {
					{ 0, 0 },
					{ 0, 0 }
				} });
			GameBoard<3>(
				{ {
					{ 0, 0, 0 },
					{ 0, 0, 0 },
					{ 0, 0, 0 }
				} });
			GameBoard<4>(
				{ {
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				} });
		}

		TEST_METHOD(testAllZeros)
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
		void assertAllRotatedTransformTransitions(
			std::vector<std::vector<double>> initial,
			std::string movement,
			std::vector<std::vector<double>> final
		)
		{
			for (int i = 0; i < 4; i++) {
				assertBoardTransition(initial, movement, final);
				initial = rotateClockwise(std::move(initial));
				movement = clockwiseMovementTransform(std::move(movement));
				final = rotateClockwise(std::move(final));
			}
		}

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
					board.moveLeft();
					break;
				case 'u':
				case 'U':
					board.moveUp();
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

	public:
		TEST_METHOD(testOneTwo)
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

		TEST_METHOD(testTwoTwos)
		{
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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

		TEST_METHOD(testThreeTwos)
		{
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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

		TEST_METHOD(testFourTwos)
		{
			assertAllRotatedTransformTransitions(
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

		TEST_METHOD(testTwoUnequals)
		{
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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

		TEST_METHOD(testThreeUnequals)
		{
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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

		TEST_METHOD(testFourUnequals)
		{
			assertAllRotatedTransformTransitions(
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

		TEST_METHOD(testCombinesOnlyOnce)
		{
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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
			assertAllRotatedTransformTransitions(
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

		TEST_METHOD(testTwiceAllZeros)
		{
			assertAllRotatedTransformTransitions(
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

		TEST_METHOD(testThreeCombos)
		{
			assertAllRotatedTransformTransitions(
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

		TEST_METHOD(testUnfortunateBoard)
		{
			assertAllRotatedTransformTransitions(
				{
					{ 2, 4, 2, 4 },
					{ 4, 2, 4, 2 },
					{ 2, 4, 2, 4 },
					{ 4, 2, 4, 2 }
				},
				"rdlu",
				{
					{ 2, 4, 2, 4 },
					{ 4, 2, 4, 2 },
					{ 2, 4, 2, 4 },
					{ 4, 2, 4, 2 }
				});
		}

		TEST_METHOD(testVeryFortunateBoard)
		{
			assertAllRotatedTransformTransitions(
				{
					{ 2, 2, 2, 2 },
					{ 2, 2, 2, 2 },
					{ 2, 2, 2, 2 },
					{ 2, 2, 2, 2 }
				},
				"rdlu",
				{
					{ 32, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				});
		}
	};
};
