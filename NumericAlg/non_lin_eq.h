#pragma once

#include <iostream>
#include <cmath>

namespace non_lin_eq {
	const int MAX_ITERATIONS = 1000;

	typedef double (*func_t)(double);

	double newton(double, func_t, func_t, int &count, double eps = 1e-3);
	double n_root(double, double, int, int& count, double eps = 1e-3);

	class NewtonSolver {
	private:
		double start_x;
		double result;
		func_t func;
		func_t df_func;
		double eps;
		int count;
		bool is_ready;
	public:
		NewtonSolver(double x, func_t f, func_t df, double eps);
		virtual ~NewtonSolver();

		void run();

		const double get_result() const;
		const bool get_is_ready() const { return this->is_ready; };
		const int get_count() const { return this->count; }
	};
}

