#include "assert_utility.h"
#include "test_board_utility.h"
#include <GameBoard.h>
#include <CppUnitTest.h>

namespace MSTest {
	TEST_CLASS(GameBoardTester) {
	public:
		TEST_METHOD(constructorThrowsWhenInvalidBoardPassed) {
			assertThrowsInvalidBoard({});
			assertThrowsInvalidBoard({ {}, {} });
			assertThrowsInvalidBoard({ { 0 }, {} });
			assertThrowsInvalidBoard({ {}, { 0 } });
			assertThrowsInvalidBoard({ { 0 }, { 0 } });
			assertThrowsInvalidBoard({ { 0, 0 }, {} });
			assertThrowsInvalidBoard({ {}, { 0, 0 } });
			assertThrowsInvalidBoard({ { 0, 0 }, { 0 } });
			assertThrowsInvalidBoard({ { 0 }, { 0, 0 } });
		}

	private:
		void assertThrowsInvalidBoard(
			std::vector<std::vector<int>> board) 
		{
			using namespace Microsoft::VisualStudio::CppUnitTestFramework;
			Assert::ExpectException<GameBoard<int>::InvalidBoard>(
				[&]() {
					GameBoard<int> b{ std::move(board) };
				}
			);
		}

	public:
		TEST_METHOD(allZeros) {
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
				{
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				},
				"rl",
				{
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				}
			);
		}

	private:
		void assertBoardMovementAndAllRotatedTransforms(
			std::vector<std::vector<int>> initial,
			std::string movement,
			std::vector<std::vector<int>> final)
		{
			for (int i = 0; i < 4; ++i) {
				assertBoardMove(initial, movement, final);
				initial = rotateClockwise(std::move(initial));
				movement = transformClockwise(std::move(movement));
				final = rotateClockwise(std::move(final));
			}
		}

		void assertBoardMove(
			const std::vector<std::vector<int>> &initial,
			const std::string &movement,
			const std::vector<std::vector<int>> &final)
		{
			GameBoard<int> board{ initial };
			for (const auto &c : movement)
				switch (c)
				{
				case 'r':
				case 'R':
					board.slideRight();
					break;
				case 'd':
				case 'D':
					board.slideDown();
					break;
				case 'l':
				case 'L':
					board.slideLeft();
					break;
				case 'u':
				case 'U':
					board.slideUp();
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
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
		}

		TEST_METHOD(DoubleTwos) {
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
		}

		TEST_METHOD(tripleTwos) {
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
		}

		TEST_METHOD(quadrupleTwos) {
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
		}

		TEST_METHOD(TwoUnequals) {
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
		}

		TEST_METHOD(threeUnequals) {
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
		}

		TEST_METHOD(fourUnequals) {
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
		}

		TEST_METHOD(combinesOnlyOnce) {
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
		}

		TEST_METHOD(threeCombos) {
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
		}

		TEST_METHOD(unfortunateBoard) {
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
		}

		TEST_METHOD(veryFortunateBoard) {
			assertBoardMovementAndAllRotatedTransforms(
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
				}
			);
		}

		TEST_METHOD(setCell) {
			GameBoard<int> board{
				{
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				}
			};
			board.setCell({ 0, 0 }, 1);
			assertAreEqual(
				{
					{ 1, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				}, 
				board
			);

			board.setCell({ 3, 2 }, 1);
			assertAreEqual(
				{
					{ 1, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 1, 0 }
				},
				board
			);
		}
	};
};
