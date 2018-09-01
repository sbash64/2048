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

		TEST_METHOD(testRotateClockwiseOneTwo)
		{
			assertAreEqual(
				{
					{ 0, 0, 0, 2 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				},
				rotateClockwise(
					{
						{ 2, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}));
		}
	};
}