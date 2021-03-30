#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixUtils/matrix.h"
#include "../MatrixUtils/matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixUtilsTest
{
	TEST_CLASS(MatrixUtilsTest)
	{
	public:
		
		TEST_METHOD(TestMaxMinItemForMatrix1)
		{
			matrix::Matrix matr(3, 3);
			init_matrix1(matr);
			double actual_min = matr.min();
			Assert::AreEqual(-11, actual_min, 1e-5);
			double actual_max = matr.max();
			Assert::AreEqual(12, actual_max, 1e-5);
		}

		static void init_matrix1(matrix::Matrix& m)
		{
			m(0, 0) = -1;
			m(0, 1) = 2;
			m(0, 2) = 6;

			m(1, 0) = 12;
			m(1, 1) = 6;
			m(1, 2) = -11;

			m(2, 0) = -7;
			m(2, 1) = 10;
			m(2, 2) = 3;

		}

		TEST_METHOD(TestMaxMinItemForMatrix2)
		{
			matrix::Matrix matr(3, 3);
			init_matrix2(matr);
			double actual_min = matr.min();
			Assert::AreEqual(-7, actual_min, 1e-5);
			double actual_max = matr.max();
			Assert::AreEqual(8, actual_max, 1e-5);
		}

		static void init_matrix2(matrix::Matrix& m)
		{
			m(0, 0) = 1;
			m(0, 1) = 3;
			m(0, 2) = 5;

			m(1, 0) = -7;
			m(1, 1) = 4;
			m(1, 2) = 0;

			m(2, 0) = 1;
			m(2, 1) = 8;
			m(2, 2) = 5;

		}
	};
}
