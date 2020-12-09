#include <iostream>
#include <algorithm>
#include "NewClass.h"
#include "Timer.h"
using namespace std; 

int main()
{
    const int array_size = 10; 
    int array[array_size] = {1, 45, 67, 3, 2, 57, 54, 21, 11, 14};

    Timer t;
    sort(array, array + array_size);
    cout << t.elapsed() << endl;
 
    for (int i = 0; i < array_size; ++i)
        cout << array[i] << ' ';

    t.reset();

    const int array_size_2 = 10; 
    int array_2[array_size_2] = { 1, 45, 67, 3, 2, 57, 54, 21, 11, 14 };
    sortArray(array_2, array_2 + array_size_2);
    cout << t.elapsed() << endl;
	for (int i = 0; i < array_size_2; ++i)
		cout << array_2[i] << ' ';

    return 0; 
}