#include <iostream>
#include <fstream>
using namespace std;
class student{
    private:
    int id;
    string name;
    double gpa;
    string department;
    public:
    student(int id, string name, double gpa, string department){
        this->id = id;
        this->name = name;
        this->department = department;
        this->gpa = gpa;
    }
    int getID(){
        return id;
    }
    void setID(int id){
        this->id = id;
    }
    string getName(){
        return name;
    }
    void setID(string name){
        this->name = name;
    }
    double getGPA(){
        return gpa;
    }
    void setGPA(double gpa){
        this->gpa = gpa;
    }
    string getDepartment(){
        return department;
    }
    void setDepartment(string department){
        this->department = department;
    }
};