#ifndef __SORT_ALGORITHMS__H__
#define __SORT_ALGORITHMS__H__

namespace Sorting{
	template<typename T>
	void Swap(T& arg0, T& arg1);

	void selection_sort(int *arr, unsigned int N, unsigned int firstIndex = 0);
	void quick_sort_recursive(int *arr, unsigned int N, unsigned int firstIndex = 0);
	void quick_sort_iterative(int *arr, unsigned int N, unsigned int firstIndex = 0);
	void merge_sort_recursive(int *arr, unsigned int N, unsigned int firstIndex = 0);
	void merge_sort_iterative(int *arr, unsigned int N, unsigned int firstIndex = 0);
};

#endif