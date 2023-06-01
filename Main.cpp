#include"Student.h"
#include<vector>
#include <fstream>
#include<iostream>
#include <algorithm>
using namespace std;
int main() {
    vector<Student> students;
    int choice;

    do {
        std::cout << "Student Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display Student List\n";
        std::cout << "3. Edit Student Information\n";
        std::cout << "4. Remove Student Information\n";
        std::cout << "5. Search Student Information\n";
        std::cout << "6. Save Students to File\n";
        std::cout << "7. Load Students from File\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Student newStudent;
                newStudent.inputInformation();
                students.push_back(newStudent);
                std::cout << "Student added successfully!\n";
                break;
            }
            case 2: {
                if (students.empty()) {
                    std::cout << "No students found!\n";
                } else {
                    std::cout << "Student List:\n";
                    for (const Student& student : students) {
                        student.displayInformation();
                        std::cout << endl;
                    }
                }
                break;
            }
            case 3: {
                if (students.empty()) {
                    std::cout << "No students found!\n";
                } else {
                    int studentID;
                    std::cout << "Enter the ID of the student to edit: ";
                    std::cin >> studentID;

                    bool found = false;
                    for (Student& student : students) {
                        if (student.getStudentID() == studentID) {
                            student.editInformation();
                            std::cout << "Student information has been updated.\n";
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        std::cout << "Student not found.\n";
                    }
                }
                break;
            }
            case 4: {
                if (students.empty()) {
                    std::cout << "No students found!\n";
                } else {
                    int studentID;
                    std::cout << "Enter the ID of the student to remove: ";
                    std::cin >> studentID;
                    auto it = find_if(students.begin(), students.end(), [studentID](const Student& student) {
                        return student.getStudentID() == studentID;
                    });

                    if (it != students.end()) {
                        students.erase(it);
                        std::cout << "Student information has been removed.\n";
                    } else {
                        std::cout << "Student not found.\n";
                    }
                }
                break;
            }
            case 5: {
                if (students.empty()) {
                    std::cout << "No students found!\n";
                } else {
                    string studentName;
                    std::cout << "Enter the name of the student to search: ";
                    std::cin.ignore();
                    std::getline(std::cin, studentName);

                    bool found = false;
                    for (const Student& student : students) {
                        if (student.getStudentName() == studentName) {
                            student.displayInformation();
                            std::cout <<endl;
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        std::cout << "Student not found.\n";
                    }
                }
                break;
            }
            case 6: {
                std::ofstream outputFile("students.txt");
                if (outputFile.is_open()) {
                    for (const Student& student : students) {
                        student.writeFile(outputFile);
                    }
                    outputFile.close();
                    std::cout << "Students saved to file successfully!\n";
                } else {
                    std::cout << "Failed to open file for writing!\n";
                }
                break;
            }
            case 7: {
                std::ifstream inputFile("students.txt");
                if (inputFile.is_open()) {
                    students.clear(); // Clear existing student data
                    while (!inputFile.eof()) {
                        Student student;
                        student.readFile(inputFile);
                        students.push_back(student);
                    }
                    inputFile.close();
                    std::cout << "Students loaded from file successfully!\n";
                } else {
                    std::cout << "Failed to open file for reading!\n";
                }
                break;
            }
            case 8:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }

        std::cout <<endl;
    } while (choice != 8);

    return 0;
}
