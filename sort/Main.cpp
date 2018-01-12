#include "Sort_Algorithms.h"

int main() {
	int arr[] = {80,75,10,60,15,49,12,25};
	Sorting::quick_sort_recursive(arr);
	Sorting::printArray(arr);
	return 0;
}