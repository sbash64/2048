#include "stdafx.h"
#include "CppUnitTest.h"

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