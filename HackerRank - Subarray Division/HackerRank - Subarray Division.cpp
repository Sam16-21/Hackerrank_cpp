#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Birthday(vector<int> s, int d, int m) {
    //Two children, Lilyand Ron, want to share a chocolate bar.Each of the squares has an integer on it.
    //Lily decides to share a contiguous segment of the bar selected such that 
    //The length of the segment matches Ron's birth month, and,
    //The sum of the integers on the squares is equal to his birth day.
    //Determine how many ways she can divide the chocolate.

    int sum = 0, counter = 0, valid = 0;

    for (int i = 0; i < s.size(); i++) {

        counter++;
        sum += s[i];
        if (counter == m) {
            if (sum == d) {
                ++valid;
            }

            counter--;
            sum -= s[i - m + 1];
        }
    }
    cout << valid;

    return valid;

}

int main() {
    int bars, birthday, birthMonth;

    cout << "\nEnter chocloate length: ";
    cin >> bars;

    cout << "\n\nEnter Birthday: ";
    cin >> birthday;

    cout << "\n\nEnter Month of birth: ";
    cin >> birthMonth;

    vector<int> chocolateBars(bars);

    cout << "\n\nEnter Chocolate integers: ";
    for (int i = 0; i < bars; i++) {
        cin >> chocolateBars[i];
    }

    Birthday(chocolateBars, birthday, birthMonth);

}
