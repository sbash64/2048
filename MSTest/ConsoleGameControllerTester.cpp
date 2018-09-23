#include "stdafx.h"
#include <ConsoleGameController.h>
#include <GameBoardFormatter.h>
#include <CppUnitTest.h>

class MockRandomNumberGenerator : public RandomNumberGenerator
{
	int _low;
	int _hi;
	int _x;
	bool _randomIntCalled = false;
public:
	explicit MockRandomNumberGenerator(int _x) : _x(_x) {}
	bool randomIntCalled() const
	{
		return _randomIntCalled;
	}
	void setRandomInt(int x)
	{
		_x = x;
	}
	virtual int randomIntBetween(int low, int hi) override
	{
		_randomIntCalled = true;
		_low = low;
		_hi = hi;
		return _x;
	}
	int low() const
	{
		return _low;
	}
	int hi() const
	{
		return _hi;
	}
};

class MockIODevice : public IODevice
{
	std::string _lastOutput;
	std::string _keyControllerLog;
	bool _rightArrowKey = false;
	bool _downArrowKey = false;
	bool _leftArrowKey = false;
	bool _upArrowKey = false;
	bool _getKeyPressCalled = false;
public:
	void setRightArrowKeyTrue()
	{
		_rightArrowKey = true;
	}
	virtual bool rightArrowKeyPressed() override
	{
		_keyControllerLog += "rightArrowKeyPressed ";
		return _rightArrowKey;
	}
	void setDownArrowKeyTrue()
	{
		_downArrowKey = true;
	}
	virtual bool downArrowKeyPressed() override
	{
		_keyControllerLog += "downArrowKeyPressed ";
		return _downArrowKey;
	}
	void setLeftArrowKeyTrue()
	{
		_leftArrowKey = true;
	}
	virtual bool leftArrowKeyPressed() override
	{
		_keyControllerLog += "leftArrowKeyPressed ";
		return _leftArrowKey;
	}
	void setUpArrowKeyTrue()
	{
		_upArrowKey = true;
	}
	void setUpArrowKeyFalse()
	{
		_upArrowKey = false;
	}
	virtual bool upArrowKeyPressed() override
	{
		_keyControllerLog += "upArrowKeyPressed ";
		return _upArrowKey;
	}
	virtual void getKeyPress() override
	{
		_keyControllerLog += "getKeyPress ";
		_getKeyPressCalled = true;
	}
	bool getKeyPressCalled() const
	{
		return _getKeyPressCalled;
	}
	std::string lastOutput() const
	{
		return _lastOutput;
	}
	virtual void print(std::string output) override
	{
		_lastOutput = output;
	}
	std::string keyControllerLog() const
	{
		return _keyControllerLog;
	}
};

static bool beginsWith(std::string const &beginning, std::string const &s) {
	if (s.length() >= beginning.length())
		return (0 == s.compare(0, beginning.length(), beginning));
	else
		return false;
}

static bool contains(std::string const &s1, std::string const &s2)
{
	return s2.find(s1) != std::string::npos;
}

namespace MSTest
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(ConsoleGameControllerTester)
	{
	public:
		TEST_METHOD(testConstructorPrintsInitialBoard)
		{
			const auto device = std::make_shared<MockIODevice>();
			Assert::IsTrue(device->lastOutput().empty());
			ConsoleGameController(
				GameBoard(
					{
						{ 2, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				),
				std::make_shared<GameBoardFormatter>(),
				device,
				std::make_shared<MockRandomNumberGenerator>(0));
			Assert::AreEqual(
				"Press an arrow key to play.\n" \
				"\n"
				"2 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"\n",
				device->lastOutput().c_str());
		}

		TEST_METHOD(testNextCallsGetKeyPress)
		{
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller(
				GameBoard(
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				),
				std::make_shared<GameBoardFormatter>(),
				device,
				std::make_shared<MockRandomNumberGenerator>(0));
			Assert::IsFalse(device->getKeyPressCalled());
			controller.next();
			Assert::IsTrue(device->getKeyPressCalled());
		}

		TEST_METHOD(testNextCallsGetKeyPressBeforeQueryingKeys)
		{
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller(
				GameBoard(
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				),
				std::make_shared<GameBoardFormatter>(),
				device,
				std::make_shared<MockRandomNumberGenerator>(0));
			Assert::IsTrue(device->keyControllerLog().empty());
			controller.next();
			Assert::IsTrue(beginsWith("getKeyPress", device->keyControllerLog()));
			Assert::IsTrue(contains("leftArrowKeyPressed", device->keyControllerLog()));
			Assert::IsTrue(contains("rightArrowKeyPressed", device->keyControllerLog()));
			Assert::IsTrue(contains("upArrowKeyPressed", device->keyControllerLog()));
			Assert::IsTrue(contains("downArrowKeyPressed", device->keyControllerLog()));
		}

		TEST_METHOD(testNextWithRightArrowKey)
		{
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller(
				GameBoard(
					{
						{ 2, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				),
				std::make_shared<GameBoardFormatter>(),
				device,
				std::make_shared<MockRandomNumberGenerator>(0));
			device->setRightArrowKeyTrue();
			controller.next();
			Assert::AreEqual(
				"2 0 0 2\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"\n",
				device->lastOutput().c_str());
		}

		TEST_METHOD(testNextWithDownArrowKey)
		{
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller(
				GameBoard(
					{
						{ 2, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				),
				std::make_shared<GameBoardFormatter>(),
				device,
				std::make_shared<MockRandomNumberGenerator>(0));
			device->setDownArrowKeyTrue();
			controller.next();
			Assert::AreEqual(
				"2 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"2 0 0 0\n" \
				"\n",
				device->lastOutput().c_str());
		}

		TEST_METHOD(testNextWithLeftArrowKey)
		{
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller(
				GameBoard(
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 2 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				),
				std::make_shared<GameBoardFormatter>(),
				device,
				std::make_shared<MockRandomNumberGenerator>(0));
			device->setLeftArrowKeyTrue();
			controller.next();
			Assert::AreEqual(
				"2 0 0 0\n" \
				"2 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"\n",
				device->lastOutput().c_str());
		}

		TEST_METHOD(testNextWithUpArrowKey)
		{
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller(
				GameBoard(
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 2, 0, 0 }
					}
				),
				std::make_shared<GameBoardFormatter>(),
				device,
				std::make_shared<MockRandomNumberGenerator>(0));
			device->setUpArrowKeyTrue();
			controller.next();
			Assert::AreEqual(
				"2 2 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"\n",
				device->lastOutput().c_str());
		}

		TEST_METHOD(testNextWithNoArrowKey)
		{
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller(
				GameBoard(
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 2, 0, 0 }
					}
				),
				std::make_shared<GameBoardFormatter>(),
				device,
				std::make_shared<MockRandomNumberGenerator>(0));
			controller.next();
			Assert::AreEqual(
				"Unrecognized key pressed.\n" \
				"Press an arrow key to play.\n" \
				"\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 2 0 0\n" \
				"\n",
				device->lastOutput().c_str());
		}

		TEST_METHOD(testTwoMoves)
		{
			const auto device = std::make_shared<MockIODevice>();
			const auto generator = std::make_shared<MockRandomNumberGenerator>(0);
			ConsoleGameController controller(
				GameBoard(
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 2, 0, 0 }
					}
				),
				std::make_shared<GameBoardFormatter>(),
				device,
				generator);
			device->setUpArrowKeyTrue();
			controller.next();
			device->setUpArrowKeyFalse();
			device->setLeftArrowKeyTrue();
			generator->setRandomInt(14);
			controller.next();
			Assert::AreEqual(
				"4 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 2\n" \
				"\n",
				device->lastOutput().c_str());
		}

		TEST_METHOD(testNextCallsRandomNumberGenerator)
		{
			const auto device = std::make_shared<MockIODevice>();
			const auto generator = std::make_shared<MockRandomNumberGenerator>(0);
			ConsoleGameController controller(
				GameBoard(
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 2, 0, 0 }
					}
				),
				std::make_shared<GameBoardFormatter>(),
				device,
				generator);
			device->setRightArrowKeyTrue();
			Assert::IsFalse(generator->randomIntCalled());
			controller.next();
			Assert::IsTrue(generator->randomIntCalled());
			Assert::AreEqual(0, generator->low());
			Assert::AreEqual(14, generator->hi());
		}

		TEST_METHOD(testNextInsertsTwoAccordingToRNG)
		{
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller(
				GameBoard(
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 2, 0, 0 }
					}
				),
				std::make_shared<GameBoardFormatter>(),
				device,
				std::make_shared<MockRandomNumberGenerator>(5));
			device->setRightArrowKeyTrue();
			controller.next();
			Assert::AreEqual(
				"0 0 0 0\n" \
				"0 2 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 2\n" \
				"\n",
				device->lastOutput().c_str());
		}
	};
}