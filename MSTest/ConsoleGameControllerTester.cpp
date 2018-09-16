#include "stdafx.h"
#include <ConsoleGameController.h>
#include "CppUnitTest.h"

class MockIODevice : public IODevice
{

};

namespace MSTest
{
	TEST_CLASS(ConsoleGameControllerTester)
	{
	public:
		TEST_METHOD(testPrintToIODevice)
		{
			ConsoleGameController controller(MockIODevice);
		}
	};
}