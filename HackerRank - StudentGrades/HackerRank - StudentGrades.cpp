#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> vector) {
	cout << "\n";

	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i] << " ";
	}

	cout << "\n";
}

vector<int>& gradingStudents(vector<int>& studentGrades) {
	//Variable for modulo 5
	int n;

	//For-each loop going through every vector element
	for (int& grades : studentGrades) {
		n = grades % 5;

		if (n >= 38) {
			if (grades >= 3) {
				grades += (5 - n);
			}
		}
		
	}
	printVector(studentGrades);

	return studentGrades;
}

int main() {
	cout << "Hackerrank grading system";
	cout << "\nAccepts array of grades and rounds them based on criteria\n\n";

	//Number of students
	int n;
	cout << "Enter number of students: ";
	cin >> n;

	//Grades input by vector
	vector<int> grades(n);
	cout << "\nEnter grades: ";

	for (int i = 0; i < n; i++) {
		cin >> grades[i];
	}

	gradingStudents(grades);

	return 0;
	system("pause > 0");

}

