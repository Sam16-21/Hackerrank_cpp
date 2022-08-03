#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <string>
using namespace std;

string timeConversion(string s) {
    //Function to obtain first and next two characters of string hour_String
    string hour_string = s.substr(0, 2);

    //Converts string hour_String to integer value
    int hour = stoi(hour_string);

    //base unsigned integer type
    size_t pos = s.find("PM");

    if (pos != string::npos) {
        if (hour + 12 < 24) {
            hour_string = to_string(hour + 12);
        }
    }
    else {
        if (hour == 12) {
            hour_string = "00";
        }
    }
    string militaryTime = s.replace(0, 2, hour_string).erase(s.size() - 2);
    cout << militaryTime << "\n\n";

    return militaryTime;
}

int main() {
    string twelveHourTime;
    cout << "Enter 12-Hour Time\n";
    getline(cin, twelveHourTime);

    cout << "24 Hour Time conversion: --> ";
    timeConversion(twelveHourTime);

    system("pause>0");
}
