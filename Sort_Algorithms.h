#ifndef __SORT_ALGORITHMS__H__
#define __SORT_ALGORITHMS__H__

namespace Sorting{
	template<typename T>
	/* Swap the element */
	void Swap(T& arg0, T& arg1);
	/* Sort an integer array with size N and its first index(default 0) using selection sort. */
	void selection_sort(int *arr, unsigned int N, unsigned int firstIndex = 0);
	/* Sort an integer array with size N and its first index(default 0) using recursive quick sort. */
	void quick_sort_recursive(int *arr, unsigned int N, unsigned int firstIndex = 0);
	/* Sort an integer array with size N and its first index(default 0) using iterative quick sort. */
	void quick_sort_iterative(int *arr, unsigned int N, unsigned int firstIndex = 0);
	/* Sort an integer array with size N and its first index(default 0) using recursive merge sort. */
	void merge_sort_recursive(int *arr, unsigned int N, unsigned int firstIndex = 0);
	/* Sort an integer array with size N and its first index(default 0) using iterative merge sort. */
	void merge_sort_iterative(int *arr, unsigned int N, unsigned int firstIndex = 0);
};

#endif