#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <fstream>
#include<vector>
using namespace std;
class Student {
private:
    int studentID;
    string studentName;
    string sex;
    float mathPoint;
    float physicPoint;
    float chemiPoint;

public:
    Student();
    Student(int id, const string& name, const string& sexs, float mathPoints, float physicPoints, float chemiPoints);
    int getStudentID() const;
    string getStudentName() const;
    string getSex() const;
    float getMathPoint() const;
    float getPhysicPoint() const;
    float getChemiPoint() const;

    void setStudentID(int id);
    void setStudentName(const string& name);
    void setSex(const string& sex);
    void setMathPoint(float point);
    void setPhysicPoint(float point);
    void setChemiPoint(float point);

    float calculateAveragePoint() const;
    string calculateAcademicRank() const;

    void inputInformation();
    void displayInformation() const;
    void deleteInformation(vector<Student> &students, int studentID);
    void searchInformation(const string& name) const;
    void editInformation();
    void writeFile(ofstream& file) const;
    void readFile(ifstream& file);
};

#endif
