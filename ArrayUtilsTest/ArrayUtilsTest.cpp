#include "pch.h"
#include "CppUnitTest.h"
#include "../ArrayUtils/array_utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayUtilsTest
{
	TEST_CLASS(ArrayUtilsTest)
	{
	public:
		
		TEST_METHOD(MaxFromIntArray)
		{
			int a1[] = { -1, 5, 9, 15, 18, -20 };
			auto expected = 18;
			auto actual = ArrayUtils::max_from(a1);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(MaxFromDoubleArray)
		{
			double a1[] = { 1e-1, -2.1e+3, 1342.324, 13.05 };
			auto expected = 1342.324;
			auto actual = ArrayUtils::max_from(a1);
			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(AvgFromDoubleArray)
		{
			double a1[] = { 1.5, -2.3, 11.6, 17.134 };
			auto expected = 6.9835;
			auto actual = ArrayUtils::avg_from(a1);
			Assert::AreEqual(expected, actual, 0.0001);
		}
	};
}
