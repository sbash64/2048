#include "stdafx.h"
#include <ConsoleGameController.h>
#include <GameBoardFormatter.h>
#include <CppUnitTest.h>
#include <string>

class MockIODevice : public IODevice
{
	std::string _lastOutput;
public:
	void setRightArrowKeyTrue()
	{

	}
	void setDownArrowKeyTrue()
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
	};
}