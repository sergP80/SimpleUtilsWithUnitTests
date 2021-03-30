#include "non_lin_eq.h"

double non_lin_eq::newton(double x0, func_t f, func_t df, int& count, double eps)
{
	double x = x0;
	count = 0;
	do {
		x = x0 - f(x0) / df(x0);
		if (std::fabs(x - x0) <= eps)
		{
			break;
		}
		x0 = x;
	} while (++count <= MAX_ITERATIONS);
	
	return (x + x0)/2;
}

double non_lin_eq::n_root(double x0, double a, int n, int& count, double eps)
{
	double x = x0;
	count = 0;
	do {
		x = x0 + (a/std::pow(x0, n - 1) - x0)/n;
		if (std::fabs(x - x0) <= eps)
		{
			break;
		}
		x0 = x;
	} while (++count <= MAX_ITERATIONS);

	return (x + x0) / 2;
}

non_lin_eq::NewtonSolver::NewtonSolver(double x, func_t f, func_t df, double eps)
	: start_x{ x }
	, result {0}
	, func{f}
	, df_func{ df }
	, eps{eps}
{
	count = 0;
	is_ready = false;
}

non_lin_eq::NewtonSolver::~NewtonSolver()
{
}

void non_lin_eq::NewtonSolver::run()
{
	double x0 = start_x;
	double x = x0;
	is_ready = false;
	do {
		x = x0 - func(x0) / df_func(x0);
		if (std::fabs(x - x0) <= eps)
		{
			break;
		}
		x0 = x;
	} while (++count <= MAX_ITERATIONS);

	is_ready = true;
	result = (x + x0) / 2;
}

const double non_lin_eq::NewtonSolver::get_result() const
{
	if (!is_ready) {
		throw "Result is not ready";
	}
	return result;
}
