#ifndef __SORT_ALGORITHMS__H__
#define __SORT_ALGORITHMS__H__

#include <iostream>

namespace Sorting {

	template<typename T>
	inline void Swap(T& arg0, T& arg1);
	
	template<typename T, int N>
	void printArray(const T(&arr)[N]);

	template<typename T, int N>
	void selection_sort(T(&arr)[N], unsigned int firstIndex = 0);

	template<typename T, int N>
	void insertion_sort(T(&arr)[N], unsigned int firstIndex = 0);

	template<typename T, int N>
	void quick_sort_recursive(T(&arr)[N], unsigned int firstIndex = 0);

	template<typename T, int N>
	void quick_sort_iterative(T(&arr)[N], unsigned int firstIndex = 0);

	template<typename T, int N>
	void merge_sort_recursive(T(&arr)[N], unsigned int firstIndex = 0);

	template<typename T, int N>
	void merge_sort_iterative(T(&arr)[N], unsigned int firstIndex = 0);
	
};

#include "Sort_Algorithm.hpp"

#endif