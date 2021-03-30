#include "pch.h"
#include "CppUnitTest.h"
#include "../NumericAlg/non_lin_eq.h"
#include "../NumericAlg/non_lin_eq.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumericAlgTests
{
	TEST_CLASS(NumericAlgTests)
	{
	public:
		
		TEST_METHOD(TestMethodForCubicRoot)
		{
			double x = 1.1;
			double a = 5.431;
			int n = 3;
			double expected = 1.75776;
			int count;
			double actual = non_lin_eq::n_root(x, a, n, count);
			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(TestMethodForCubicRootWithNewton)
		{
			double x = 0.1;
			int n = 3;
			double expected = 1.75776;
			int count;
			double actual = non_lin_eq::newton(x, f3, f3dx, count);
			Assert::AreEqual(expected, actual, 0.0001);
		}

		static double f3(double x) {
			return x * x * x - 5.431;
		}

		static double f3dx(double x) {
			return 3* x * x;
		}
	};
}
