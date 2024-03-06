#include <iostream>
#include <cstring>  // For string operations
using namespace std;

class Grade {
private:
    char* name;
    int kr;
    int math;
    int english;

public:
    // Constructor to initialize Grade object with name and scores
    Grade(const char* n, int k, int m, int e) : kr(k), math(m), english(e) {
        // Allocate memory for the name and copy the input string
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Destructor to release dynamically allocated memory
    ~Grade() {
        delete[] name;
    }

    // Member function to calculate and display individual student scores
    void calculateAndDisplayStudent() const {
        int total = kr + math + english;
        double average = static_cast<double>(total) / 3;

        cout << "Name: " << name << ", ";
        cout << "Total: " << total << ", ";
        cout << "Average: " << average << endl;
    }

    // Getter functions for individual subject scores
    int getKorean() const {
        return kr;
    }

    int getMath() const {
        return math;
    }

    int getEnglish() const {
        return english;
    }

    // Friend function to calculate and display subject-wise totals and averages
    friend void calculateAndDisplaySubject(const Grade grades[], int size);
};

// Friend function to calculate and display subject-wise totals and averages
void calculateAndDisplaySubject(const Grade grades[], int size) {
    int krTotal = 0, mathTotal = 0, englishTotal = 0;

    // Calculate subject-wise totals
    for (int i = 0; i < size; i++) {
        krTotal += grades[i].getKorean();
        mathTotal += grades[i].getMath();
        englishTotal += grades[i].getEnglish();
    }

    // Calculate subject-wise averages
    double krAverage = static_cast<double>(krTotal) / size;
    double mathAverage = static_cast<double>(mathTotal) / size;
    double englishAverage = static_cast<double>(englishTotal) / size;

    // Display subject-wise totals and averages
    cout << "Subject-wise Totals: Korean(" << krTotal << "), Math(" << mathTotal << "), English(" << englishTotal << ")" << endl;
    cout << "Subject-wise Averages: Korean(" << krAverage << "), Math(" << mathAverage << "), English(" << englishAverage << ")" << endl;
}

int main() {
    const int numStudents = 5;

    // Array to store Grade objects for 5 students
    Grade students[numStudents] = {
        Grade("Student1", 90, 85, 92),
        Grade("Student2", 78, 89, 95),
        Grade("Student3", 88, 92, 87),
        Grade("Student4", 95, 78, 91),
        Grade("Student5", 82, 94, 88)
    };

    // Calculate and display individual student scores
    cout << "Individual Student Scores:" << endl;
    for (int i = 0; i < numStudents; i++) {
        students[i].calculateAndDisplayStudent();
    }

    // Calculate and display subject-wise totals and averages
    calculateAndDisplaySubject(students, numStudents);

    return 0;
}
