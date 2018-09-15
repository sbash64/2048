#include "stdafx.h"
#include "CppUnitTest.h"
#include <GameBoardFormatter.h>

namespace MSTest
{
	TEST_CLASS(GameBoardFormatterTester)
	{
	public:
		TEST_METHOD(testInitialDisplay)
		{
			using namespace Microsoft::VisualStudio::CppUnitTestFramework;
			Assert::AreEqual(
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0\n" \
				"0 0 0 0",
				GameBoardFormatter{}.as_string(
					GameBoard(
						{
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 }
						}
					)
				).c_str());
		}
	};
}