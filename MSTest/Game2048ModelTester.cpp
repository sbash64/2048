#include <Game2048Model.h>
#include <GameBoardFormatter.h>
#include <CppUnitTest.h>

class MockRandomNumberGenerator : public RandomNumberGenerator {
	int _low{};
	int _hi{};
	int _x;
public:
	explicit MockRandomNumberGenerator(int x) : _x{ x } {}
	void setRandomInt(int x) {
		_x = x;
	}
	int randomIntBetween(int low, int hi) override {
		_low = low;
		_hi = hi;
		return _x;
	}
	int low() const {
		return _low;
	}
	int hi() const {
		return _hi;
	}
};

namespace MSTest
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(Game2048ModelTester) {
	public:
		TEST_METHOD(newGamePrintsInitialBoard) {
			Game2048Model model{
				GameBoard<int>{
					{
						{ 2, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				},
				std::make_shared<GameBoardFormatter>(),
				std::make_shared<MockRandomNumberGenerator>(0) };
			Assert::AreEqual(
				std::string{ 
					"Press an arrow key to play.\n" \
					"\n"
					"2 0 0 0\n" \
					"0 0 0 0\n" \
					"0 0 0 0\n" \
					"0 0 0 0\n" \
					"\n" 
				},
				model.newGame());
		}

		TEST_METHOD(right) {
			Game2048Model model{
				GameBoard<int>{
					{
						{ 2, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				},
				std::make_shared<GameBoardFormatter>(),
				std::make_shared<MockRandomNumberGenerator>(0) };
			Assert::AreEqual(
				std::string{
					"2 0 0 2\n" \
					"0 0 0 0\n" \
					"0 0 0 0\n" \
					"0 0 0 0\n" \
					"\n"
				},
				model.right());
		}

		TEST_METHOD(down)
		{
			Game2048Model model{
				GameBoard<int>{
					{
						{ 2, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				},
				std::make_shared<GameBoardFormatter>(),
				std::make_shared<MockRandomNumberGenerator>(0) };
			Assert::AreEqual(
				std::string{
					"2 0 0 0\n" \
					"0 0 0 0\n" \
					"0 0 0 0\n" \
					"2 0 0 0\n" \
					"\n"
				},
				model.down());
		}

		TEST_METHOD(left) {
			Game2048Model model{
				GameBoard<int>{
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 2 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				},
				std::make_shared<GameBoardFormatter>(),
				std::make_shared<MockRandomNumberGenerator>(0) };
			Assert::AreEqual(
				std::string{
					"2 0 0 0\n" \
					"2 0 0 0\n" \
					"0 0 0 0\n" \
					"0 0 0 0\n" \
					"\n"
				},
				model.left());
		}

		TEST_METHOD(up) {
			Game2048Model model{
				GameBoard<int>{
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 2, 0, 0 }
					}
				},
				std::make_shared<GameBoardFormatter>(),
				std::make_shared<MockRandomNumberGenerator>(0) };
			Assert::AreEqual(
				std::string{
					"2 2 0 0\n" \
					"0 0 0 0\n" \
					"0 0 0 0\n" \
					"0 0 0 0\n" \
					"\n"
				},
				model.up());
		}

		TEST_METHOD(nextMoveCallsRandomNumberGenerator) {
			const auto generator = 
				std::make_shared<MockRandomNumberGenerator>(0);
			Game2048Model model{
				GameBoard<int>{
					{
						{ 2, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				},
				std::make_shared<GameBoardFormatter>(),
				generator };
			model.right();
			Assert::AreEqual(0, generator->low());
			Assert::AreEqual(14, generator->hi());
		}

		TEST_METHOD(nextMoveInsertsTwoAccordingToRNG) {
			Game2048Model model{
				GameBoard<int>{
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 2, 0, 0, 0 }
					}
				},
				std::make_shared<GameBoardFormatter>(),
				std::make_shared<MockRandomNumberGenerator>(5) };
			Assert::AreEqual(
				std::string{
					"0 0 0 0\n" \
					"0 2 0 0\n" \
					"0 0 0 0\n" \
					"0 0 0 2\n" \
					"\n"
				},
				model.right());
		}

		TEST_METHOD(newGameReturnsMessageOnUnluckyBoard) {
			Game2048Model model{
				GameBoard<int>{
					{
						{ 2, 4, 2, 4 },
						{ 4, 2, 4, 2 },
						{ 2, 4, 2, 4 },
						{ 4, 2, 4, 2 }
					}
				},
				std::make_shared<GameBoardFormatter>(),
				std::make_shared<MockRandomNumberGenerator>(0) };
			Assert::AreEqual(
				std::string{
					"Wow. That's unfortunate. You didn't even get to play!\n" \
					"\n"
					"2 4 2 4\n" \
					"4 2 4 2\n" \
					"2 4 2 4\n" \
					"4 2 4 2\n" \
					"\n"
				},
				model.newGame());
		}

		TEST_METHOD(nextMoveReturnsGameOverMessageWhenNoMovesLeft) {
			Game2048Model model{
				GameBoard<int>{
					{
						{ 16, 8, 4, 0 },
						{ 4, 2, 4, 2 },
						{ 2, 4, 2, 4 },
						{ 4, 2, 4, 2 }
					}
				},
				std::make_shared<GameBoardFormatter>(),
				std::make_shared<MockRandomNumberGenerator>(0) };
			Assert::AreEqual(
				std::string{
					"No more moves can be done. Game over.\n" \
					"\n"
					"2 16 8 4\n" \
					"4  2 4 2\n" \
					"2  4 2 4\n" \
					"4  2 4 2\n" \
					"\n"
				},
				model.right());
		}
	};
}