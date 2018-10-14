#include "stdafx.h"
#include "assert_utility.h"
#include "test_board_utility.h"
#include <GameBoard.h>
#include <CppUnitTest.h>

namespace MSTest
{
	TEST_CLASS(GameBoardTester) {
	public:
		TEST_METHOD(constructorThrowsWhenInvalidBoardPassed) {
			using namespace Microsoft::VisualStudio::CppUnitTestFramework;
			Assert::ExpectException<std::runtime_error>(
				[]() { GameBoard({}); });
			Assert::ExpectException<std::runtime_error>(
				[]() { GameBoard({ {}, {} }); });
			Assert::ExpectException<std::runtime_error>(
				[]() { GameBoard({ { 0 }, {} }); });
			Assert::ExpectException<std::runtime_error>(
				[]() { GameBoard({ {}, { 0 } }); });
			Assert::ExpectException<std::runtime_error>(
				[]() { GameBoard({ { 0 }, { 0 } }); });
			Assert::ExpectException<std::runtime_error>(
				[]() { GameBoard({ { 0, 0 }, {} }); });
			Assert::ExpectException<std::runtime_error>(
				[]() { GameBoard({ {}, { 0, 0 } }); });
			Assert::ExpectException<std::runtime_error>(
				[]() { GameBoard({ { 0, 0 }, { 0 } }); });
			Assert::ExpectException<std::runtime_error>(
				[]() { GameBoard({ { 0 }, { 0, 0 } }); });
			GameBoard(
				{
					{ 0 }
				});
			GameBoard(
				{ 
					{ 0, 0 }, 
					{ 0, 0 } 
				});
			GameBoard(
				{ 
					{ 0, 0, 0 }, 
					{ 0, 0, 0 },
					{ 0, 0, 0 }
				});
			GameBoard(
				{
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				});
		}

		TEST_METHOD(allZeros) {
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

	private:
		void assertAllRotatedTransformTransitions(
			std::vector<std::vector<double>> initial,
			std::string movement,
			std::vector<std::vector<double>> final)
		{
			for (int i = 0; i < 4; i++) {
				assertBoardTransition(initial, movement, final);
				initial = rotateClockwise(std::move(initial));
				movement = transformClockwise(std::move(movement));
				final = rotateClockwise(std::move(final));
			}
		}

		void assertBoardTransition(
			const std::vector<std::vector<double>> &initial,
			const std::string &movement,
			const std::vector<std::vector<double>> &final)
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
			assertAreEqual(final, board);
		}

		std::string transformClockwise(std::string movement) {
			for (auto &c : movement)
				switch (c) {
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
		TEST_METHOD(singleTwo) {
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

		TEST_METHOD(DoubleTwos) {
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

		TEST_METHOD(tripleTwos) {
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

		TEST_METHOD(quadrupleTwos) {
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

		TEST_METHOD(TwoUnequals) {
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

		TEST_METHOD(threeUnequals) {
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

		TEST_METHOD(fourUnequals) {
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

		TEST_METHOD(combinesOnlyOnce) {
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

		TEST_METHOD(threeCombos) {
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

		TEST_METHOD(unfortunateBoard) {
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

		TEST_METHOD(veryFortunateBoard) {
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

		TEST_METHOD(setCell) {
			GameBoard board(
				{
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				}
			);
			board.setCell(0, 0, 1);
			assertAreEqual(
				{
					{ 1, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				}, 
				board);

			board.setCell(3, 2, 1);
			assertAreEqual(
				{
					{ 1, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 1, 0 }
				},
				board);
		}
	};
};
