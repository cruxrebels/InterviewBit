// Example program
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& i)
{
    for (const auto& in : i)
        cout << in << " ";
    cout << std::endl;
}

void insertionSort(vector<int>& A)
{
    int hole = 0, val = 0;
    for (unsigned int a = 1; a < A.size(); ++a) {
        hole = a;
        val = A[a];
        while (hole > 0 && A[hole-1] > val) {
            A[hole] = A[hole - 1];
            --hole;
        }
        A[hole] = val;
    }
}

int main()
{
  vector<int> i;
  int n = 0;
  cout << "Enter the number of elements: " << std::endl;
  cin >> n;
  for (auto c = 0; c < n; ++c) {
    int temp = 0;
    cin >> temp;
    i.emplace_back(temp);
  }
  
  cout << "The list you entered is: ";
  print(i);
  
  if (n==1) {
      print(i);
      return 0;
  }
  insertionSort(i);
  cout << "After sorting: "; 
  print(i);
  
  return 0;
}
