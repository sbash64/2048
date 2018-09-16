#include "stdafx.h"
#include <ConsoleGameController.h>
#include <GameBoardFormatter.h>
#include <CppUnitTest.h>

class MockIODevice : public IODevice
{
	std::string _lastOutput;
	bool _rightArrowKey = false;
	bool _downArrowKey = false;
	bool _leftArrowKey = false;
public:
	void setRightArrowKeyTrue()
	{
		_rightArrowKey = true;
	}
	virtual bool rightArrowKeyPressed() override
	{
		return _rightArrowKey;
	}
	void setDownArrowKeyTrue()
	{
		_downArrowKey = true;
	}
	virtual bool downArrowKeyPressed() override
	{
		return _downArrowKey;
	}
	void setLeftArrowKeyTrue()
	{
		_leftArrowKey = true;
	}
	virtual bool leftArrowKeyPressed() override
	{
		return _leftArrowKey;
	}
	void setUpArrowKeyTrue()
	{

	}
	std::string lastOutput() const
	{
		return _lastOutput;
	}
	virtual void print(std::string output) override
	{
		_lastOutput = output;
	}
};

namespace MSTest
{
	TEST_CLASS(ConsoleGameControllerTester)
	{
	public:
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
				device);
			device->setRightArrowKeyTrue();
			controller.next();
			Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(
				"0 0 0 2\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0",
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
				device);
			device->setDownArrowKeyTrue();
			controller.next();
			Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"2 0 0 0",
				device->lastOutput().c_str());
		}

		TEST_METHOD(testNextWithLeftArrowKey)
		{
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller(
				GameBoard(
					{
						{ 0, 0, 0, 2 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}
				),
				std::make_shared<GameBoardFormatter>(),
				device);
			device->setLeftArrowKeyTrue();
			controller.next();
			Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(
				"2 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0",
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
				device);
			device->setUpArrowKeyTrue();
			controller.next();
			Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(
				"0 2 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0",
				device->lastOutput().c_str());
		}
	};
}