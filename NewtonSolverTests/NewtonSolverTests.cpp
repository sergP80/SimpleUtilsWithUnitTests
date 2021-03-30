#include "pch.h"
#include "CppUnitTest.h"
#include "../NumericAlg/non_lin_eq.h"
#include "../NumericAlg/non_lin_eq.cpp"

#include <thread>
#include <chrono>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NewtonSolverTests
{
	TEST_CLASS(NewtonSolverTests1)
	{
	public:
		
		TEST_METHOD(SolveForEquation1)
		{
			non_lin_eq::NewtonSolver solver{ 3, f, df, 1e-4 };
			solver.run();

			while (!solver.get_is_ready()) {
				using std::chrono::operator""ms;
				std::this_thread::sleep_for(1000ms);
			}
			double expected = 3.1415926;
			Assert::AreEqual(expected, solver.get_result(), 1e-3);
			Assert::IsTrue(solver.get_count() < non_lin_eq::MAX_ITERATIONS);
		}

		TEST_METHOD(SolveForEquation2)
		{
			non_lin_eq::NewtonSolver solver{ -3, f, df, 1e-4 };
			solver.run();

			while (!solver.get_is_ready()) {
				using std::chrono::operator""ms;
				std::this_thread::sleep_for(1000ms);
			}
			double expected = -3.1415926;
			Assert::AreEqual(expected, solver.get_result(), 1e-3);
			Assert::IsTrue(solver.get_count() < non_lin_eq::MAX_ITERATIONS);
		}

		static double f(double x) {
			return x * std::sin(x) / (x - 1);
		}

		static double df(double x) {
			return (x * std::sin(x) + std::sin(x) + x * std::cos(x)) / (x - 1) * (x - 1);
		}

	};
}
