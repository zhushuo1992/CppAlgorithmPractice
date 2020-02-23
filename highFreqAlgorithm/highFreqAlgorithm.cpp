#include <iostream>

using namespace std;

void reverse(string &s)
{

    int size = s.size();
    for (int i = 0; i < size / 2; i++)
    {
        swap(s[i], s[size - i - 1]);
    }
}

int binarySearch(int arr[], int n, int target)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (r - l) / 2 + l;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return -1;
}

//闭区间
int binarySearch(int arr[], int l, int r, int target)
{
    if (l > r)
        return -1;
    int mid = (r - l) / 2 + l;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binarySearch(arr, l, mid - 1, target);
    }
    else
    {
        return binarySearch(arr, mid + 1, r, target);
    }
}

string intToString(int num)
{
    string flag = "";
    string res = "";
    if (num < 0)
    {
        flag = "-";
        num = -num;
    }

    while (num)
    {
        res += '0' + num % 10;
        num /= 10;
    }
    if (res == "")
        res = "0";
    reverse(res);

    return flag + res;
}

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    for (int i = 3; i * i <= num; i += 2)
        if (0 == num % i)
            return false;

    return true;
}

double pow(double x, int n)
{
    if(0 == n)
        return 1.0;
    
    double t = pow(x, n/2);
    if(n%2)
        return x*t*t;
    
    return t*t;
}

int *generateOrderedArray(int n) 
{


    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        arr[i] = i;
    return arr;
}

int main()
{

    cout << intToString(123) << endl;
    cout << intToString(0) << endl;
    cout << intToString(-123) << endl;

    cout << endl;

    if (isPrime(137))
        cout << "137 is a prime." << endl;
    else
        cout << "137 is not a prime." << endl;

    if (isPrime(121))
        cout << "121 is a prime." << endl;
    else
        cout << "121 is not a prime." << endl;

    cout << pow(2, 10) << endl;

    int * arr=generateOrderedArray(1000);
    cout<<binarySearch(arr, 1000, 871)<<endl;
    cout<<binarySearch(arr,0,  1000-1, 365)<<endl;
    return 0;
}
