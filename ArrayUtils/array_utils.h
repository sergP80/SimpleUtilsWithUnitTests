#pragma once

namespace ArrayUtils {
	template<typename T, int size>
	T max_from(T(&arr)[size]) {
		int k = 0;
		for (int i = 1; i < size; ++i) {
			if (arr[i] > arr[k]) {
				k = i;
			}
		}
		return arr[k];
	}

	template<typename T, int size>
	double avg_from(T(&arr)[size]) {
		double s = 0.0;
		for (int i = 0; i < size; ++i) {
			s += arr[i];
		}
		return s / size;
	}

	template<typename T, int size>
	void shuffle(T(&arr)[size]) {
	}

}
