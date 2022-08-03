#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void stringPrint(string result) {
    cout << result;
}

string kangaroo(int& x1, int& v1, int& x2, int& v2) {
    bool stop = false;
    string translateBoolean;
    //Kangaroo jumps till infinity
    // This check their starting point x, and intervals v, if they meet at any point
    
    vector<int> landingLocation1(50), landingLocation2(50);

    //Vector containg all landing positions for the two kangaroos
    for (int i = x1; i > 0; i += v1) {
        landingLocation1.push_back(i);
    }
    for (int j = x2; j > 0; j += v2) {
        landingLocation1.push_back(j);
    }

    //Check for same landing position
    do {
        int k = 0;
        if (landingLocation1[k] == landingLocation2[k]) {
            stop = true;
        }

        k++;
    } while (!stop);

    if (stop) {
        translateBoolean = "YES";
    }
    else {
        translateBoolean = "NO";
    }

    stringPrint(translateBoolean);

    return translateBoolean;
}

string kangaroo2(int& x1, int& v1, int& x2, int& v2) {
    double res = (double)(x1 - x2) / (v2 - v1);

    if (res == floor(res) && res >= 0) {
        return string("YES"); 
    }       

    return string("NO");
}

int main() {
    int pos1, jDist1, pos2, jDist2;

    cout << "Hackerrank Solution - Numberline Jumps\n";
    cout << "\nEnter the position and jump distance of two kangaroos respectively: \n";

    cout << "Kangaroo 1: ";
    cin >> pos1 >> jDist1;

    cout << "\n\nKangaroo 2: ";
    cin >> pos2 >> jDist2;

    cout << "\n\n";

    kangaroo(pos1, jDist1, pos2, jDist2);

    return 0;
    system("pause < 0");
}