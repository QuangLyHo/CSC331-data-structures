#include <iostream>
using namespace std;

int largest(const int arr[], int, int);

int main() 
{
    int intArr[10] = {23, 43, 35, 38, 67, 12, 76, 10, 34, 8};
    cout    << "The largest element in intArr: " 
            << largest(intArr, 0, 9);
    cout    << endl;
    
    return 0;
}

int largest(const int arr[], int lowerIndex, int upperIndex) 
{
    int max;
    if (lowerIndex == upperIndex) 
        return arr[lowerIndex];
    else 
    {
        max = largest(arr, lowerIndex + 1, upperIndex);
        if (arr[lowerIndex] >= max)
            return arr[lowerIndex];
        else 
            return max;
    }
}