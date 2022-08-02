// HackerRank - Breaking the Records.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

void printVector(vector<int> Array) {
    for (int i = 0; i < Array.size(); i++) {
        cout << Array[i] << " ";
    }
}

vector<int> breakingRecords(vector<int> scores) {
    //Record basketball game scores for Maria
    //STDIN array with gamescores
    //For all elements in array, determine the lowest and highest record set compared 
    //to the Standard record

    int min = scores[0], max = scores[0], least = 0, most = 0;

    for (int i = 0; i < scores.size(); i++) {
        if (scores[i] > max) {
            max = scores[i];
            most++;
        }
        else if (scores[i] < min) {
            min = scores[i];
            least++;
        }
    }
    printVector(vector<int>({ most, least }));

    return vector<int>({ most, least });
}

int main() {
    int nScores;
    cout << "Enter number of scores: ";
    cin >> nScores;

    vector<int> currScores(nScores);
    
    cout << "\n\nEnter Currnet scores: \n";
    for (int i = 0; i < nScores; i++) {
        cin >> currScores[i];
    }

    cout << "\n\nCalculating Statistics...\n";

    chrono::seconds waitTime(7);
    this_thread::sleep_for(waitTime);

    breakingRecords(currScores);

}