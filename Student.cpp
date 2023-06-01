#include "Student.h"
#include <iostream>
using namespace std;
Student::Student()
{
}
Student::Student(int id, const string& name, const string& sexs, float mathPoints, float physicPoints, float chemiPoints)
    : studentID(id), studentName(name), sex(sexs), mathPoint(mathPoints),physicPoint(physicPoints), chemiPoint(chemiPoints)
{

}

int Student::getStudentID() const {
    return studentID;
}

string Student::getStudentName() const {
    return studentName;
}

string Student::getSex() const {
    return sex;
}

float Student::getMathPoint() const {
    return mathPoint;
}

float Student::getPhysicPoint() const {
    return physicPoint;
}

float Student::getChemiPoint() const {
    return chemiPoint;
}

void Student::setStudentID(int id) {
    studentID = id;
}

void Student::setStudentName(const string& name) {
    studentName = name;
}

void Student::setSex(const string& sexs) {
    sex=sexs;
}

void Student::setMathPoint(float point) {
    mathPoint = point;
}

void Student::setPhysicPoint(float point) {
    physicPoint = point;
}

void Student::setChemiPoint(float point) {
    chemiPoint = point;
}

float Student::calculateAveragePoint() const {
    return (mathPoint + physicPoint + chemiPoint) / 3.0f;
}

string Student::calculateAcademicRank() const {
    float averagePoint = calculateAveragePoint();

    if (averagePoint >= 8.5f) {
        return "Excellent";
    } else if (averagePoint >= 7.0f) {
        return "Good";
    } else if (averagePoint >= 5.0f) {
        return "Average";
    } else {
        return "Below Average";
    }
}
void Student::inputInformation() {
    std::cout << "Enter Student ID: ";
    std::cin >> studentID;

    std::cout << "Enter Student Name: ";
    std::cin.ignore(); // Ignore the newline character from previous input
    std::getline(std::cin, studentName);

    std::cout << "Enter Sex: ";
    std::getline(std::cin, sex);

    std::cout << "Enter Math Point: ";
    std::cin >> mathPoint;

    std::cout << "Enter Physics Point: ";
    std::cin >> physicPoint;

    std::cout << "Enter Chemistry Point: ";
    std::cin >> chemiPoint;
}
void Student::displayInformation() const{
    std::cout << "Student ID: " << studentID << endl;
    std::cout << "Student Name: " << studentName << endl;
    std::cout << "Sex: " << sex <<endl;
    std::cout << "Math Point: " << mathPoint << endl;
    std::cout << "Physics Point: " << physicPoint << endl;
    std::cout << "Chemistry Point: " << chemiPoint << endl;
    std::cout << "Average Point: " << calculateAveragePoint() << endl;
    std::cout << "Academic Rank: " << calculateAcademicRank() << endl;
}
void Student::deleteInformation(vector<Student>& students, int studentID) {
    std::cout << "Enter ID of the student you want to remove: ";
    std::cin >> studentID;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getStudentID() == studentID) {
            students.erase(it);
            std::cout << "Student information has been deleted." << endl;
            return;
        }
    }

    std::cout << "Student not found." << std::endl;
}
void Student::editInformation() {
    int choice;
    std::cout << "Select the information to edit:" << endl;
    std::cout << "1. Student ID" << endl;
    std::cout << "2. Student Name" <<endl;
    std::cout << "3. Sex" << endl;
    std::cout << "4. Math Point" << endl;
    std::cout << "5. Physics Point" << endl;
    std::cout << "6. Chemistry Point" << endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Enter new Student ID: ";
            std::cin >> studentID;
            break;
        case 2:
            std::cout << "Enter new Student Name: ";
            std::cin.ignore();
            std::getline(std::cin, studentName);
            break;
        case 3:
            std::cout << "Enter new Sex: ";
            std::cin.ignore();
            std::getline(std::cin, sex);
            break;
        case 4:
            std::cout << "Enter new Math Point: ";
            std::cin >> mathPoint;
            break;
        case 5:
            std::cout << "Enter new Physics Point: ";
            std::cin >> physicPoint;
            break;
        case 6:
            std::cout << "Enter new Chemistry Point: ";
            std::cin >> chemiPoint;
            break;
        default:
            std::cout << "Invalid choice." <<endl;
            break;
    }
}

void Student::deleteInformation(vector<Student>& students, int studentID) {
    std::cout << "Enter ID of the student you want to remove: ";
    std::cin >> studentID;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getStudentID() == studentID) {
            students.erase(it);
            std::cout << "Student information has been deleted." << endl;
            return;
        }
    }

    std::cout << "Student not found." << std::endl;
}

void Student::searchInformation(const string& name) const {
    if (studentName == name) {
        std::cout << "Student found:" << endl;
        displayInformation();
    } else {
        std::cout << "Student not found." << endl;
    }
}
void Student::writeFile(ofstream& file) const {
    file << studentID << endl;
    file << studentName << endl;
    file << sex << endl;
    file << mathPoint << endl;
    file << physicPoint << endl;
    file << chemiPoint << endl;
}

void Student::readFile(ifstream& file)  {
    file >> studentID;
    file.ignore();

    std::getline(file, studentName);
    std::getline(file, sex);

    file >> mathPoint;
    file >> physicPoint;
    file >> chemiPoint;
}
