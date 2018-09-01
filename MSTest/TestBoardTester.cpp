#include "stdafx.h"
#include "CppUnitTest.h"
#include "assert_utility.h"
#include "test_board_utility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MSTest
{
	TEST_CLASS(TestBoardTester)
	{
	public:
		TEST_METHOD(testRotateClockwiseAllZeros)
		{
			assertAreEqual(
				{
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				},
				rotateClockwise(
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}));
		}
	};
}