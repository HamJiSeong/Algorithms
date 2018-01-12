#include "Sort_Algorithms.h"

/* Swap the element */
template<typename T>
void Sorting::Swap(T& arg0, T& arg1)
{
	T temp = arg0;
	arg0 = arg1;
	arg1 = temp;
}

/* print the elements in an array */
template<typename T, int N>
void Sorting::printArray(const T(&arr)[N]) {
	for (int i = 0; i < N; ++i)
		std::cout << "Item #" << i + 1 << ": " << arr[i] << std::endl;
}

/* Sort an integer array with size N and its first index(default 0) using selection sort. */
// Selction Sort
template<typename T, int N>
void Sorting::selection_sort(T(&arr)[N], unsigned int firstIndex) {
	unsigned int i, j, min_id;
	for (i = firstIndex; i < N - 1; ++i) {
		min_id = i;
		for (j = i + 1; j < N; ++j) {
			if (arr[j] < arr[min_id]) {
				min_id = j;
			}
		}
		Swap(arr[i], arr[min_id]);
	}
}

/* Sort an integer array with size N and its first index(default 0) using insertion sort. */
template<typename T, int N>
void Sorting::insertion_sort(T(&arr)[N], unsigned int firstIndex) {
	unsigned int i, j, k;
	for (i = firstIndex + 1; i < N; ++i) {
		T key = arr[i];
		j = i - 1;
		while (j >= firstIndex && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

/* Sort an integer array with size N and its first index(default 0) using recursive quick sort. */
// Recursive Quick Sort
template<typename T, int N>
void Sorting::quick_sort_recursive(T(&arr)[N], unsigned int firstIndex) {
	if (N <= 1) return;
	int l = firstIndex, r = firstIndex + N - 2;
	int pivot = r + 1;
	while (l <= r) {
		while (arr[l] < arr[pivot]) ++l;
		while (arr[r] > arr[pivot]) --r;
		if (l > r) break;
		Swap(arr[l], arr[r]);
	}
	Swap(arr[l], arr[pivot]);
	quick_sort_recursive(arr, l - firstIndex, firstIndex);
	quick_sort_recursive(arr, firstIndex + N - l - 1, l + 1);
}


/* Sort an integer array with size N and its first index(default 0) using iterative quick sort. */
// Iterative Quick Sort
template<typename T, int N>
void Sorting::quick_sort_iterative(T(&arr)[N], unsigned int firstIndex) {
	if (N <= 1) return;
	int *stack = new int[2 * N];
	int front, end, l, r, pivot, top = 0;
	stack[top++] = firstIndex;
	stack[top++] = firstIndex + N - 1;
	while (top) {
		end = stack[--top];
		front = stack[--top];
		l = front;
		r = end - 1;
		pivot = end;
		while (l <= r) {
			while (arr[l] < arr[pivot]) ++l;
			while (arr[r] > arr[pivot]) --r;
			if (l > r) break;
			Swap(arr[l], arr[r]);
		}
		Swap(arr[l], arr[pivot]);
		if (l - front > 1) {
			stack[top++] = front;
			stack[top++] = l - 1;
		}
		if (end - l > 1) {
			stack[top++] = l + 1;
			stack[top++] = end;
		}
	}
	delete[]stack;
}


/* Sort an integer array with size N and its first index(default 0) using recursive merge sort. */
// Recursive Merge Sort
template<typename T, int N>
void Sorting::merge_sort_recursive(T(&arr)[N], unsigned int firstIndex) {
	if (N <= 1)
		return;
	merge_sort_recursive(arr, N / 2, firstIndex);
	merge_sort_recursive(arr, N - N / 2, firstIndex + N / 2);
	int p = firstIndex, q = firstIndex + N / 2;
	int *tempArr = new int[N], i = 0;
	while (i < N) {
		if (p < firstIndex + N / 2 && q < firstIndex + N) {
			if (arr[p] < arr[q])
			{
				tempArr[i++] = arr[p++];
			}
			else
			{
				tempArr[i++] = arr[q++];
			}
		}
		else if (p < firstIndex + N / 2)
		{
			tempArr[i++] = arr[p++];
		}
		else if (q < firstIndex + N)
		{
			tempArr[i++] = arr[q++];
		}
	}
	for (i = 0; i < N; ++i)
		arr[firstIndex + i] = tempArr[i];
	delete[]tempArr;
}

/* Sort an integer array with size N and its first index(default 0) using iterative merge sort. */
// Iterative Merge Sort (still working on)
template<typename T, int N>
void Sorting::merge_sort_iterative(T(&arr)[N], unsigned int firstIndex) {
	if (N <= 1) return;
	int *stack = new int[2 * N];
	int f1, f2, e1, e2, top = 0;
	stack[top++] = firstIndex;
	stack[top++] = firstIndex + N / 2 - 1;
	stack[top++] = firstIndex + N / 2;
	stack[top++] = firstIndex + N - 1;
	while (top) {
		e2 = stack[--top];
		f2 = stack[--top];
		e1 = stack[--top];
		f1 = stack[--top];

		int s2 = e2 - f2 + 1;
		int s1 = e1 - f1 + 1;
		if (s1 > 1) {
			stack[top++] = f1;
			stack[top++] = f1 + s1 / 2 - 1;
			stack[top++] = f1 + s1 / 2;
			stack[top++] = e1;
		}
		if (s2 > 1) {
			stack[top++] = f2;
			stack[top++] = f2 + s2 / 2 - 1;
			stack[top++] = f2 + s2 / 2;
			stack[top++] = e2;
		}
	}
	delete[]stack;
}