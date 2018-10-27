#include "assert_utility.h"
#include <GameBoardAnalyzer.h>
#include <CppUnitTest.h>

namespace MSTest {
	TEST_CLASS(GameBoardAnalyzerTester) {
		void assertOpenCellsEqual(
			std::vector<std::size_t> indeces,
			std::vector<std::vector<double>> board)
		{
			assertAreEqual(
				std::move(indeces),
				GameBoardAnalyzer{}.openCells(
					GameBoard{ std::move(board) }));
		}

	public:
		TEST_METHOD(openCells) {
			assertOpenCellsEqual(
				{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
				{
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				}
			);
			assertOpenCellsEqual(
				{ 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14 },
				{
					{ 1, 0, 0, 0 },
					{ 0, 1, 0, 0 },
					{ 0, 0, 1, 0 },
					{ 0, 0, 0, 1 }
				}
			);
			assertOpenCellsEqual(
				{ 1, 2, 3, 12, 13, 14 },
				{
					{ 1, 1, 1, 0 },
					{ 0, 1, 1, 0 },
					{ 0, 1, 1, 0 },
					{ 0, 1, 1, 1 }
				}
			);
		}

	private:
		bool boardCanMove(std::vector<std::vector<double>> board) {
			return GameBoardAnalyzer{}.canMove(
				GameBoard{ std::move(board) }
			);
		}

	public:
		TEST_METHOD(canMove) {
			using namespace Microsoft::VisualStudio::CppUnitTestFramework;
			Assert::IsTrue(
				boardCanMove(
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				)
			);
			Assert::IsFalse(
				boardCanMove(
					{
						{ 2, 4, 2, 4 },
						{ 4, 2, 4, 2 },
						{ 2, 4, 2, 4 },
						{ 4, 2, 4, 2 }
					}
				)
			);
			Assert::IsTrue(
				boardCanMove(
					{
						{ 2, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				)
			);
			Assert::IsTrue(
				boardCanMove(
					{
						{ 2, 2, 2, 2 },
						{ 2, 2, 2, 2 },
						{ 2, 2, 2, 2 },
						{ 2, 2, 2, 2 }
					}
				)
			);
			Assert::IsTrue(
				boardCanMove(
					{
						{ 2, 4, 2, 4 },
						{ 4, 2, 4, 8 },
						{ 2, 4, 2, 8 },
						{ 4, 2, 4, 2 }
					}
				)
			);
		}
	};
}