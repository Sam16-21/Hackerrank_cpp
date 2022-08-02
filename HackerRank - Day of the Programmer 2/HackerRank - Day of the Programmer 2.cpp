#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//THIS SOLUTION TOOK ME 2 DAYS TO FIGURE OUT!!!

void convertDate(int day, int month, int year) {
    string finalDate;
    string Day = to_string(day), Month = to_string(month), Year = to_string(year);

    finalDate.append(Day).append(".0").append(Month).append(".").append(Year);

    cout << "\n" << finalDate;
}

string dayOfProgrammer(int year) {
    //Given the year as input, find the 256th day of that year in Russia considering
    //from 1700 - 1917 they used the Julian Calendar
    //as from 1919 they used the Gregorian calendar
    //in 1918 the 32nd day of the year was February 14th

    string presentDate;
    string dot = ".";

    int daysOfProgrammer = 256;
    int tempDateValue = 0;
    int tempDate;

    vector<int> normalYear = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<int> leapYear = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<int> julianNormalYear = { 31, 15, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    //If year is in the Julian Year System
    if (year >= 1700 && year < 1918) {

        //if julian leap year
        if (year % 4 == 0) {
            int i = 0;
            do {
                tempDateValue += leapYear[i];
                i++;
            } while (tempDateValue < daysOfProgrammer - leapYear[i]);

            tempDate = daysOfProgrammer - tempDateValue;
            convertDate(tempDate, i + 1, year);
        }
        else {
            int i = 0;
            do {
                tempDateValue += normalYear[i];
                i++;
            } while (tempDateValue < daysOfProgrammer - normalYear[i]);

            tempDate = daysOfProgrammer - tempDateValue;
            convertDate(tempDate, i + 1, year);
        }
    }
    //This year had it's 32nd day as the 14h of February
    else if (year == 1918) {
        int i = 0;
        do {
            tempDateValue += julianNormalYear[i];
            i++;
        } while (tempDateValue < daysOfProgrammer - julianNormalYear[i]);

        tempDate = daysOfProgrammer - tempDateValue;
        convertDate(tempDate, i + 1, year);
    }
    //If yaer is in the Gregorian year system
    else if (year > 1918) {

        //if year is a gregorian leap year
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            int i = 0;
            do {
                tempDateValue += leapYear[i];
                i++;
            } while (tempDateValue < daysOfProgrammer - leapYear[i]);

            tempDate = daysOfProgrammer - tempDateValue;
            convertDate(tempDate, i + 1, year);
        }
        else {
            int i = 0;
            do {
                tempDateValue += normalYear[i];
                i++;
            } while (tempDateValue < daysOfProgrammer - normalYear[i]);

            tempDate = daysOfProgrammer - tempDateValue;
            convertDate(tempDate, i + 1, year);
        }
    }

    return dot;
}


int main() {
    cout << "Given the year as input, find the 256th day of that year in Russia considering";
    cout << "\nfrom 1700 - 1917 they used the Julian Calendar";
    cout << "\nas from 1919 they used the Gregorian calendar";
    cout << "\nin 1918 the 32nd day of the year was February 14th\n\n";

    int year;
    cout << "Enter the desired year for time travel: ";
    cin >> year;

    dayOfProgrammer(year);

    EXIT_SUCCESS;
}