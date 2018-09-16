#include "stdafx.h"
#include <ConsoleGameController.h>
#include <CppUnitTest.h>
#include <string>

class MockIODevice : public IODevice
{
	std::string _lastOutput;
public:
	void setRightArrowKeyTrue()
	{

	}
	std::string lastOutput() const
	{
		return _lastOutput;
	}
};

namespace MSTest
{
	TEST_CLASS(ConsoleGameControllerTester)
	{
	public:
		TEST_METHOD(testPrintToIODevice)
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
	};
}