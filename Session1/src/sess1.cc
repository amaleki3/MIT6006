#include "basic_algorithms/peak_finder.h"

int main(){

  int array[kSize] = {1, 12, 3, 4, 15, 16, 8, 10, 11 , 13};
  PrintArray1D(array, kSize);
  std::cout << PeakFinder1DSlow(array) << std::endl;\
  std::cout << PeakFinder1DFast(array) << std::endl;
	
	return 0;
}



// void passFunc(std::string tmp, int a[][10])
// {
//     for (int i=0; i< 5; i++){
// 			a[i][2] = 1.0;
//     	std::cout << a[i][2] << std::endl;
//     }
// }

// int main(){
// 	int arrayA[10][10];
// 	std::string tmp;
// 	passFunc(tmp, arrayA);
// }