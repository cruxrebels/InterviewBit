// Example program
#include <iostream>

using namespace std;

void merge(int *input, int start, int mid, int end)
{
    int temp[end-start+1];
    int i = start, j = mid+1, k = 0;
    
    while (i <= mid && j <= end) {
        if (input[i] <= input[j]) {
            temp[k] = input[i];
            ++i;
        }
        else {
            temp[k] = input[j];
            ++j;
        }
        ++k;
    }
    
    while (i <= mid) {
        temp[k] = input[i];
        ++i; ++k;
    }
    while (j <= end) {
        temp[k] = input[j];
        ++j; ++k;
    }
    
    for (i = start; i <= end; ++i)
        input[i] = temp[i - start];
}

void mergeSort(int *input, int start, int end)
{
    if (start < end) {
        int mid = (start + end)/2;
        mergeSort(input, start, mid);
        mergeSort(input, mid+1, end);
        merge(input, start, mid, end);
    }
}

void print(int *input, int n) 
{
    for (int i = 0; i < n; ++i)
        cout << input[i] << " ";
    cout << endl;
}

int main()
{
  int y = 0;
  cout << "Enter no. of elements: " << endl;
  cin >> y;
  int input[y];
  cout << "Enter elements to merge sort:" << endl;
  int count = 0;
  while (count < y) {
      int x = 0;
      cin >> x;
      input[count++] = x;
  }  
  print(input, y);
  
  mergeSort(input, 0, y-1);
  cout << "Sorted list: ";
  print(input, y);
}
