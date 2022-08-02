#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;

int divisibleSumPairs(int n, int k, vector<int> ar) {
    //Given an array of integers and a positive integer 
    //determine the number of  pairs where i < j and  ar[i] + ar[j] is divisible by k
    //Where n is the size of the array.

    int divisiblePairs = 0;

    //Sort array for better handling
    sort(ar.begin(), ar.end());

    for (int i = 0; i < n; i++) {
        cout << ar[i] << " ";
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {

            //nested for loop to sum sorted pairs
            if ((ar[i] + ar[j]) % k == 0) {
                cout << "\n" << (ar[i] + ar[j]);
                divisiblePairs++;
            }
        }
    }

    cout << "\n\nDivisible pairs found: " << divisiblePairs << "\n\n";

    return divisiblePairs;
}

int main() {
    int arrSize, divisor;
    cout << "Enter array size: ";
    cin >> arrSize;

    vector<int> arr(arrSize);

    cout << "\n\nEnter array: ";
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    cout << "\n\nEnter divisor: ";
    cin >> divisor;

    cout << "\n\n";
    divisibleSumPairs(arrSize, divisor, arr);
}