#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
//New library learnt

using namespace std;

int migratoryBirds(vector<int> arr) {
    //Given an array of bird sightings where every element represents a bird type id
    //determine the id of the most frequently sighted type.
    //If more than 1 type has been spotted that maximum amount, return the smallest of their ids.

    //Try to understand the code because of the map library

    map<int, int> birds;

    for (int& b : arr) {
        birds[b]++;
    }

    //Track which type of bird is most commonly seen
    map<int, int>::iterator tracker = birds.begin();

    //Most commonly seen type (Lowest Type rule applies)
    for (map<int, int>::iterator itr = ++tracker; itr != birds.end(); ++itr) {
        if (itr->second > tracker->second) {
            tracker = itr;
        }
        else if (itr->second == tracker->second) {
            tracker = (tracker->first < itr->first) ? tracker : itr;
        }
    }

    cout << "\n\n" << tracker->first;

    return tracker->first;
}

int main(){
    cout << "Migratory Bird Statistics\n\n";

    int numberOfBirds;
    cout << "Enter the number of birds: ";
    cin >> numberOfBirds;

    cout << "\n\nEnter Bird IDs: ";

    vector<int> birds(numberOfBirds);
    for (int i = 0; i < numberOfBirds; i++) {
        cin >> birds[i];
    }

    cout << "\n\n";

    migratoryBirds(birds);

    return 0;
}