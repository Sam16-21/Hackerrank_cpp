#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void birthdayCandles(vector<int> candles, int n) {

    //Sort candles[]
    sort(candles.begin(), candles.end());

    //Since largest should be the last element
    int largestCandle = candles[n - 1];
    int counter = 0;

    for (int i = 0; i < n; i++) {
        if (candles[i] == largestCandle) {
            counter++;
        }
    }

    cout << counter;
}

int main() {
    //This is an algorithm solution for HackerRank Exercise, few adjustments
    //Given an array, find the frequency of the largest element
    int numOfCandles;

    cout << "How many birthday candles?: ";
    cin >> numOfCandles;
    vector<int> candles(numOfCandles);

    cout << "Enter birthday candles: \n";
   
    for (int i = 0; i < numOfCandles; i++) {
        cin >> candles[i];
    }

    birthdayCandles(candles, numOfCandles);

    system("pause > 0");
}
