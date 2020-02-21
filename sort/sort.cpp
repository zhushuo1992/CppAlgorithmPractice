#include "SortTestHelper.h"
#include "SortAlgorithm.h"
#include <ctime>
using namespace std;

int main()
{

    //下面是不同的排序算法，具体算法实现在另外一个文件中
    int n = 10000;
    int * arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    clock_t startTime = clock();
    SortAlgorithm::selectionSort(arr1, n);
    clock_t endTime = clock();
    cout << "selectionSort" << " : " << double(endTime - startTime)  << " ms"<<endl;
    if(!SortTestHelper::isSorted(arr1, n))
    {
        cout<<"selectionSort error!"<<endl;
    }


    int * arr2 = SortTestHelper::generateRandomArray(n, 0, n);
    startTime = clock();
    SortAlgorithm::insertionSort(arr2, n);
    endTime = clock();
    cout << "insertionSort" << " : " << double(endTime - startTime)  << " ms"<<endl;
    if(!SortTestHelper::isSorted(arr2, n))
    {
        cout<<"insertionSort error!"<<endl;
    }

    int * arr3 = SortTestHelper::generateRandomArray(n, 0, n);
    startTime = clock();
    SortAlgorithm::bubbleSort(arr3, n);
    endTime = clock();
    cout << "bubbleSort" << " : " << double(endTime - startTime)  << " ms"<<endl;
    if(!SortTestHelper::isSorted(arr3, n))
    {
        cout<<"bubbleSort error!"<<endl;
    }

    int * arr4 = SortTestHelper::generateRandomArray(n, 0, n);
    startTime = clock();
    SortAlgorithm::mergeSort(arr4, n);
    endTime = clock();
    cout << "mergeSort" << " : " << double(endTime - startTime)  << " ms"<<endl;
    if(!SortTestHelper::isSorted(arr4, n))
    {
        cout<<"mergeSort error!"<<endl;
    }

    int * arr5 = SortTestHelper::generateRandomArray(n, 0, n/10);
    startTime = clock();
    SortAlgorithm::quickSort(arr5, n);
    endTime = clock();
    cout << "quickSort" << " : " << double(endTime - startTime)  << " ms"<<endl;
    if(!SortTestHelper::isSorted(arr5, n))
    {
        cout<<"quickSort error!"<<endl;
    }

    int * arr6 = SortTestHelper::generateRandomArray(n, 0, n/10);
    startTime = clock();
    SortAlgorithm::quickSort3Ways(arr6, n);
    endTime = clock();
    cout << "quickSort3Ways" << " : " << double(endTime - startTime)  << " ms"<<endl;
    if(!SortTestHelper::isSorted(arr6, n))
    {
        cout<<"quickSort3Ways error!"<<endl;
    }

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    return 0;
}
