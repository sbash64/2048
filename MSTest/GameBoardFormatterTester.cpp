#include <GameBoardFormatter.h>
#include <CppUnitTest.h>

namespace MSTest
{
	TEST_CLASS(GameBoardFormatterTester) {
		void assertFormatEqualTo(
			std::string expected, 
			std::vector<std::vector<double>> board)
		{
			using namespace Microsoft::VisualStudio::CppUnitTestFramework;
			Assert::AreEqual(
				expected.c_str(),
				GameBoardFormatter{}.asString(GameBoard(board)).c_str());
		}

	public:
		TEST_METHOD(testAsString) {
			assertFormatEqualTo(
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0",
				{
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				}
			);
			assertFormatEqualTo(
				"0 0 0 2\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0",
				{
					{ 0, 0, 0, 2 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				}
			);
			assertFormatEqualTo(
				" 1  2  3  4\n" \
				" 5  6  7  8\n" \
				" 9 10 11 12\n" \
				"13 14 15 16",
				{
					{ 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 }
				}
			);
			assertFormatEqualTo(
				"    1     2     3     4\n" \
				"   50    60    70    80\n" \
				"  900  1000  1100  1200\n" \
				"13000 14000 15000 16000",
				{
					{ 1, 2, 3, 4 },
					{ 50, 60, 70, 80 },
					{ 900, 1000, 1100, 1200 },
					{ 13000, 14000, 15000, 16000 }
				}
			);
			assertFormatEqualTo(
				"  1     2 3000   4\n" \
				" 50     6    7 800\n" \
				"900    10  110  12\n" \
				" 13 14000  150 160",
				{
					{ 1, 2, 3000, 4 },
					{ 50, 6, 7, 800 },
					{ 900, 10, 110, 12 },
					{ 13, 14000, 150, 160 }
				}
			);
		}
	};
}