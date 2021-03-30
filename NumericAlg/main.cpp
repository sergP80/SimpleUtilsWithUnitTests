#include "non_lin_eq.h"
#include <thread>
#include <chrono>

double f(double x) {
	return x * std::sin(x) / (x - 1);
}

double df(double x) {
	return (x * std::sin(x) + std::sin(x) + x*std::cos(x)) / (x - 1)*(x-1);
}

int main() {

	non_lin_eq::NewtonSolver solver{ -3, f, df, 1e-4 };
	solver.run();
	
	while (!solver.get_is_ready()) {
		using std::chrono::operator""ms;
		std::this_thread::sleep_for(1000ms);
	}

	std::cout << "Result: " << solver.get_result() << std::endl;
	std::cout << "Iterations: " << solver.get_count() << std::endl;

	return 0;
}