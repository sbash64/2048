#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MSTest
{
	TEST_CLASS(TestBoardTester)
	{
	public:
		TEST_METHOD(testRotateClockwiseAllZeros)
		{
			assertAreEqual(
				rotateClockwise(
					{
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					}),
				{
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				});
		}
	};
}