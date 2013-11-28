
#include <iostream>
#include <common.h>

using namespace std;

template<class Type>
class Others{
public:
	//iterator
	typedef Type* iterator;
	//constructors
	Others(){
	}

	//methods
	bool hasDuplication( iterator array, int* size ){
		F( i, 0, (* size)-1 ){
			F( j, 0, (* size)-1 ){
				if( array[i] == array[j] && i!=j ){
					return true;
				}
			}
		}
		return false;
	}

	int binarySearchValidator( iterator array, const int begin, const int end, iterator target ){
		//brute force
		F( i, begin, end ){
			if( array[i] == (*target) ){
				return i;
			}
		} 
		return -1;
	}

	int binarySearchRec( iterator array, const int begin, const int end, iterator target ){
		//recursivly
		if( begin > end ){
			return -1;
		}
		int middle = (begin + end)/2;
		if( (*target) < array[middle] ){
			//left
			return binarySearchRec( array, begin, middle-1, target );
		}else if( (*target) > array[middle] ){
			//right
			return binarySearchRec( array, middle+1, end, target );
		}else{
			return middle;
		}
	}

	int binarySearchIter( iterator array, int begin, int end, iterator target ){
		//iteratively
		while(1){
			if( begin > end ){
				return -1;
			}
			int middle = (begin + end)/2;
			if( (*target) < array[middle] ){
				//left
				end = middle-1;
				continue;
			}else if( (*target) > array[middle] ){
				//right
				begin = middle+1; 
				continue;
			}else{
				return middle;
			}
		}
	}

	int min( iterator array, const int size ){
		if( size < 1 ){
			return -1;
		}
		Type min = array[0];
		F( i, 1, size-1 ){
			if( min > array[i] ){
				min = array[i];
			}
		}
		return min;
	}

	int max( iterator array, const int size ){
		if( size < 1 ){
			return -1;
		}
		Type max = array[0];
		F( i, 1, size-1 ){
			if( max < array[i] ){
				max = array[i];
			}
		}
		return max;
	}

	void comParallely( iterator array, Type* min, Type* max, const int i, const int j ){
		if( array[i] > array[j] ){
			if( *max < array[i] ){
				*max = array[i];
			}
			if( *min > array[j] ){
				*min = array[j];
			}
		}else{
			if( *max < array[j] ){
				*max = array[j];
			}
			if( *min > array[i] ){
				*min = array[i];
			}
		}
	}

	int minMax( iterator array, const int size, Type* min, Type* max ){
		if( size < 1 ){
			return -1;
		}
		if( size < 2 ){
			*min = array[0];
			*max = array[0];
			return 0;
		}
		//compare the first pair
		comParallely( array, min, max, 0, 1 );
		if( size % 2 == 0 ){
			F2( i, 2, size-1 ){
				comParallely( array, min, max, i, i+1 );
			}
		}
		else{
			F2( i, 2, size-2 ){
				comParallely( array, min, max, i, i+1 );
			}
			if( array[size-1] > *max ){
				*max = array[size-1];
			}
			if( array[size-1] < *min ){
				*min = array[size-1];
			}
		}
		return 0;
	}


};