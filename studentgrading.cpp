#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, double> student_grades; // Map to store student names and grades

    // Input loop to get student names and grades
    while (true) {
        string student_name;
        cout << "Enter student name (or type 'done' to finish): ";
        getline(cin, student_name);
        if (student_name == "done") // Check if user wants to finish input
            break;
        
        double grade;
        cout << "Enter " << student_name << "'s grade: ";
        cin >> grade;

        if (grade >= 0 && grade <= 100) {
            student_grades[student_name] = grade; // Store the grade
        } else {
            cout << "Grade should be between 0 and 100. Try again." << endl;
        }

        cin.ignore(); // Clear input buffer
    }

    // Calculate average grade
    double total_grades = 0;
    int num_students = 0;
    for (const auto& pair : student_grades) {
        total_grades += pair.second; // Add grade to total
        num_students++; // Increment student count
    }

    double average_grade = num_students > 0 ? total_grades / num_students : 0;

    // Display average grade
    cout << "Average grade: " << average_grade << endl;

    // Find highest and lowest grades
    if (!student_grades.empty()) {
        double highest_grade = student_grades.begin()->second;
        double lowest_grade = student_grades.begin()->second;
        for (const auto& pair : student_grades) {
            highest_grade = max(highest_grade, pair.second); // Update highest grade
            lowest_grade = min(lowest_grade, pair.second); // Update lowest grade
        }
        cout << "Highest grade: " << highest_grade << endl;
        cout << "Lowest grade: " << lowest_grade << endl;
    } else {
        cout << "No grades entered." << endl;
    }

    return 0;
}
