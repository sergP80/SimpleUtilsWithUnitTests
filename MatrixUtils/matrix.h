#pragma once

/// <summary>
/// Додати на ваш вибір сервісні методи до класу матриці
/// Перевизначити операції додавання, віднімання та множення
/// Перевизначити операцію виведення у потік
/// </summary>
namespace matrix {
	class xIndicesOutOfRange{};
	class xIndicesForEmptyMatrix{};

	class Matrix
	{
	private:
		int rows;
		int cols;
		double** data;

		void init_data();
		void check_indices(int i, int j) const;
	public:
		Matrix(int, int);
		virtual ~Matrix();
		
		void clear();

		const bool is_empty() const;

		double& operator()(int, int);
		const double& operator()(int, int) const;

		const int get_rows() const { return this->rows; }
		const int get_cols() const { return this->cols; }

		const double& max() const;
		const double& min() const;
		const double& det() const;
		Matrix& inverse();
	};
}