#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void toString(int n) {
	if (n == 1) {
		cout << "\nThere are " << n << " integer between the sets/arrays\n";
	}
	else if (n > 1) {
		cout << "\nThere are " << n << " integers between the sets/arrays\n";
	}
	else {
		cout << "\nThere are no integers between the sets/arrays\n";
	}
	
}

int getTotalX(vector<int> a, vector<int> b) {
	//Function to find common numbers
	//Two arrays a, b as arguments
	//Find multiples of each element in a, find factors of each element in b
	//Return how many numbers are common between the factors and multiples.

	// Range of int goes from the LAST element of A to the LAST of B
	// (some have said it should end on the FIRST of B, but I played it safely)

	int start = a.back(), end = b.back();
	int count = 0;

	for (int x = start; x <= end; x++) {
		// Booleans to test whether X fulfills condition
		bool a_pass = true, b_pass = true;

		for (const auto& ai : a) {
			if (x % ai != 0) {
				// If it doesn't, set flag and break out of A loop
				a_pass = false;
				break;
			}
		}

		// If A didn't complete successfully, continue with next integer
		if (!a_pass) continue;

		for (const auto& bi : b) {
			if (bi % x != 0) {
				// Idem A loop
				b_pass = false;
				break;
			}
		}

		// If both test were OK, count that integer
		if (a_pass && b_pass) count++;

	}
	
	toString(count);
	return count;
}

int main() {
	cout << "\nHackerRank - Between two sets\n\n";
	cout << "Function to find common numbers\n\nTwo arrays a, b as arguments";
	cout << "\nFind multiples of each element in a, find factors of each element in b\n";
	cout << "Return how many numbers are common between the factors and multiples.\n\n";

	int arrSize1, arrSize2;

	cout << "\tEnter size of first array: ";
	cin >> arrSize1;

	cout << "\n\tEnter size of second array: ";
	cin >> arrSize2;

	vector<int> arr1(arrSize1);
	vector<int> arr2(arrSize2);

	cout << "\nEnter elements for first array: ";
	for (int i = 0; i < arrSize1; i++) {
		cin >> arr1[i];
	}

	cout << "\nEnter elements for second array: ";
	for (int i = 0; i < arrSize2; i++) {
		cin >> arr1[i];
	}

	getTotalX(arr1, arr2);

	return 0;
	system("pause > 0");
}