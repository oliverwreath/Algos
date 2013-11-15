
#include <acm.h>
#include <sorting.h>

typedef int entry_type;

using namespace std;

int main()
{
	//MergeSort
		//generate data as input
	srand( (unsigned)time(NULL) ); 
	int in_array [MAXArray+1]; 
	F( i, 0, sizeof(in_array)/ sizeof(* in_array) - 1 ){ 
		in_array[i] = (double)rand() / (RAND_MAX + 1) * (MAXArray-1); 
	} 

		//operations
	clock_t c1, c1e, c2, c2e, c3, c3e;  
	c1 = clock();
	mergeSort( in_array, 1, sizeof(in_array) / sizeof(* in_array) - 1 ); 
	c1e = clock();

	////QuickSort
	//	//generate data as input
	//int in_array2 [MAXArray+1]; 
	//F( i, 0, sizeof(in_array2)/ sizeof(* in_array2) - 1 ){ 
	//	in_array2[i] = (double)rand() / (RAND_MAX + 1) * (MAXArray-1); 
	//} 
	//	//operations
	//c2 = clock();
	//quickSort( in_array2, 0, sizeof(in_array2) / sizeof( * in_array2 ) - 1 );
	//c2e = clock();

	//randQuickSort
		//generate data as input
	int in_array3 [MAXArray+1]; 
	F( i, 0, sizeof(in_array3)/ sizeof(* in_array3) - 1 ){ 
		in_array3[i] = (double)rand() / (RAND_MAX + 1) * (MAXArray-1); 
	} 
		//operations
	c3 = clock();
	selectionSort( in_array3, 0, sizeof(in_array3) / sizeof( * in_array3 ) - 1 );
	c3e = clock();

	//output
	//F( i, 1, sizeof(in_array) / sizeof(* in_array) - 1 ){
	//	cout << in_array[i] << ' ';
	//}
	//cout << endl;

	//F( i, 1, sizeof(in_array2) / sizeof(* in_array2) - 1 ){
	//	cout << in_array2[i] << ' ';
	//}
	//cout << endl;

	F( i, 1, sizeof(in_array3) / sizeof(* in_array3) - 1 ){
		cout << in_array3[i] << ' ';
	}
	cout << endl;

	//output Timer
	cout << "MergeS : " << (double)(c1e - c1)/CLOCKS_PER_SEC << endl;
	//cout << "QuickSort : " << (double)(c2e - c2)/CLOCKS_PER_SEC << endl;
	cout << "randQuickSort : " << (double)(c3e - c3)/CLOCKS_PER_SEC << endl;

	system("pause");
	return 0;
}



