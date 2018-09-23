#include "stdafx.h"
#include "assert_utility.h"
#include "test_board_utility.h"
#include <CppUnitTest.h>

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

		TEST_METHOD(testRotateClockwiseUniqueElements)
		{
			assertAreEqual(
				{
					{ 13, 9, 5, 1 },
					{ 14, 10, 6, 2 },
					{ 15, 11, 7, 3 },
					{ 16, 12, 8, 4 }
				},
				rotateClockwise(
					{
						{ 1, 2, 3, 4 },
						{ 5, 6, 7, 8 },
						{ 9, 10, 11, 12 },
						{ 13, 14, 15, 16 }
					}));
		}
	};
}