//所有实现不考虑过于异常的数据输入情况
#ifndef _SORT_ALGORITHM_H_
#define _SORT_ALGORITHM_H_
#include <iostream>
#include <algorithm>

using namespace std;

namespace SortAlgorithm
{

//选择排序
//基本思想：两层循环遍历数组，第一层[0, n)，保证前面几个一定是有序的，每次遍历时只需要遍历后面的数组，把其中最小的数移动到前面有序数组的末尾即可
//所以取一个临时的变量保存一个假定的index，这样后面遍历，当数比a[index]小时，就可以更新这个index，内层循环结束后进行交换即可。
//算法复杂度: O(n^2)
template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        T minIndex = i; //假定index就是i，进入后面的数组遍历，获得真正最小的那个索引
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        //已经获得minIndex，交换
        swap(arr[i], arr[minIndex]);
    }
}

//插入排序
//基本思想：两层循环遍历数组，第一层[1, n)，保证前面几个一定是有序的，每次遍历时只需要取出新的一个元素，然后将这个元素插入到前面已经排好序的数组中合适的位置
//当将这个新元素插入时，需要将前面有序数组中比该元素大的数据依次后移，需要考虑性能。就是打扑克
//算法复杂度: O(n^2)
//适用于近乎有序的数据
template <typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        //假定前面的数组已经有序，此时新进来的元素就是arr[i]，下面需要给arr[i]寻找合适的位置，在寻找的过程中，需要向后移动其他数据
        //完成的标准就是移动到最前或者前面一个已经不再大于我当前这个元素了，此时立即终止循环
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
        {
            //所有符合条件的元素都需要这样
            swap(arr[j - 1], arr[j]);
        }
    }
}

//冒泡排序
//基本思想：两层循环遍历数组，第一层[1, n)，先比较前两个，小的放前面，大的放后面，然后再比较23两个，这样比完一圈，最大的就在最后了
//然后再从头比，这样第二大就放到倒数第二，如此就完成了排序。PS:有点类似于选择排序
//算法复杂度: O(n^2)
template <typename T>
void bubbleSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i - 1; j++) //最后一个不再考虑了
        {
            //交换
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//希尔排序
//基本思想：类似于将数据切割为小的数组进行插入排序，再合并再插入排序，我不想写了
//算法复杂度: O(n^2)

//归并排序
//基本思想：将数据不断等分，到最后只有一个元素了，这样就天生有序，这个时候就再向上合并即可。
//需要辅助空间，2n
//是一种分治算法。有三个游标，一个指在最后结果数组的头部，一个放子1头，一个放子2头，不断后移，这样就合并成功了
//算法复杂度O(nlogn)

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template <typename T>
void __merge(T arr[], int l, int mid, int r)
{
    T aux[r - l + 1]; //临时存储空间
    for (int i = l; i <= r; i++)
    {
        aux[i - l] = arr[i]; //临时空间赋值
    }

    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++)
    {
        if (i > mid) //i已经排序完，剩下的把j的放进去即可
        {
            arr[k] = aux[j - l];
            j++;
        }
        else if (j > r)
        {
            arr[k] = aux[i - l];
            i++;
        }
        else if (aux[i - l] > aux[j - l])
        {
            arr[k] = aux[j - l];
            j++;
        }
        else
        {
            arr[k] = aux[i - l];
            i++;
        }
    }
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
template <typename T>
void __mergeSort(T arr[], int l, int r)
{
    if( l >= r )
        return;
    int mid = (r - l) / 2 + l;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    __merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T arr[], int n)
{
    __mergeSort(arr, 0, n - 1);
}

//快速排序
//算法思想：就是将一个数组分成>v和<v两部分，然后再把v放回去，这样如此递归下去，就可以完成
//算法复杂度：Ο(nlogn)

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r)
{
    T v = arr[l];
    int j = l;
    for (int i = l + 1; i < r + 1; i++)
    {
        if (arr[i] < v)
        {
            swap(arr[j + 1], arr[i]);
            j++;
        }
    }

    swap(arr[l], arr[j]);

    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r)
{
    if (l >= r)
        return;
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template <typename T>
void quickSort(T arr[], int n)
{
    __quickSort(arr, 0, n - 1);
}

// 对arr[l...r]范围的数组进行插入排序
template<typename T>
void insertionSort(T arr[], int l, int r){

    for( int i = l+1 ; i <= r ; i ++ ) {

        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }

    return;
}

//三路快速排序
//算法思想：就是将一个数组分成>v、=v、<v三部分，这样如此递归下去，就可以完成
//算法复杂度：Ο(nlogn)

// 递归的三路快速排序算法
template <typename T>
void __quickSort3Ways(T arr[], int l, int r)
{

    // 对于小规模数组, 使用插入排序进行优化
    
    if (r - l <= 15)
    {
        insertionSort(arr, l, r);
        return;
    }

    // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
    swap(arr[l], arr[rand() % (r - l + 1) + l]);

    T v = arr[l];

    int lt = l;     // arr[l+1...lt] < v
    int gt = r + 1; // arr[gt...r] > v
    int i = l + 1;  // arr[lt+1...i) == v
    while (i < gt)
    {
        if (arr[i] < v)
        {
            swap(arr[i], arr[lt + 1]);
            i++;
            lt++;
        }
        else if (arr[i] > v)
        {
            swap(arr[i], arr[gt - 1]);
            gt--;
        }
        else
        { // arr[i] == v
            i++;
        }
    }

    swap(arr[l], arr[lt]);

    __quickSort3Ways(arr, l, lt - 1);
    __quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n)
{

    srand(time(NULL));
    __quickSort3Ways(arr, 0, n - 1);
}
//堆排序
//堆：完全二叉树，且满足，所有根节点大于等于左右子树（大顶堆），（小于等于的叫小顶堆）
//完全二叉树：除了最后一层，其他层都是左右都有，且最后一层所有节点都连续集中在左侧。
//若设二叉树的深度为k，除第k层外，其他各层（1～（k-1）层）的节点数都达到最大值，且第k层所有的节点都连续集中在最左边，这样的树就是完全二叉树
//算法复杂度：Ο(nlogn)

}; // namespace SortAlgorithm

#endif