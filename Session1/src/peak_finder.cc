#include "basic_algorithms/peak_finder.h"

void PrintArray1D(int this_array[], int size){

	for (int i = 0; i < size; i++)
		std::cout << this_array[i] << " ";

	std::cout << std::endl;
}

int PeakFinder1DSlow(int this_array[]){
	if (this_array[0] >= this_array[1])
		return this_array[0];

	for (int i=1; i < kSize - 1; i++)
		if ((this_array[i] >= this_array[i + 1]) and (this_array[i] >= this_array[i - 1]))
			return this_array[i];

	return this_array[kSize - 1]; 
}

int PeakFinder1DFast(int this_array[], int array_size){
	if (array_size == 1)
		return this_array[0];

	int mid = array_size / 2;
	if (this_array[mid] < this_array[mid - 1])
		return	PeakFinder1DFast(this_array, mid);
	else
		if (this_array[mid] < this_array[mid + 1])
			return PeakFinder1DFast(&this_array[mid], array_size - mid);
		else
			return this_array[mid];
}

int PeakFinder1DFast(int this_array[]){
	return PeakFinder1DFast(this_array, kSize);
}