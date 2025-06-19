#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<string>
using namespace std;

struct person {
    string name;
    int age;
    void printDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};
//single inheritance. 
struct student : protected person { //access specifier can only change data to a more protected state, not less.
    string school;
    int roll_no;

    void printDetails() {
        person::printDetails(); // INHERITING METHODS. 
        //this calls the printDetails method of the base class person
        cout << "School: " << school << endl;
        cout << "Roll No: " << roll_no << endl;
    }
    student(string name, int age, string school, int roll_no) : person( name ,  age) {
        this->school = school;
        this->roll_no = roll_no;

    }
};

struct stream : protected student { //Multi Level Inheritance
    string stream_name;

    void printDetails() {
        student::printDetails(); 
        cout << "Stream: " << stream_name << endl;
    }
    stream(string name, int age, string school, int roll_no, string stream_name) 
        : student(name, age, school, roll_no) {
        this->stream_name = stream_name;
    }
    
};

struct subjects : protected stream , student { // Multiple Inheritance
    // this creates ambiguity because stream already inherits from student
    // for actual multiple inheritance we generally take classes with different data.  or use virtual inheritance. 
    string subject;
    void printDetails() {
        stream::printDetails(); 
        cout << "Subject: " << subject << endl;
    }
    subjects(string name, int age, string school, int roll_no, string stream_name, string subject) 
        : stream(name,age,school,roll_no, stream_name) , student(name, age, school, roll_no) {
        this->subject = subject;
    }
   subjects(stream &s, string subject) : stream(s) , student(s) {
        this->subject = subject;
    }
};


int main() {
    stream s("John Doe", 16, "ABC High School", 101, "Science");
    subjects sub(s , "Mathematics");
    sub.printDetails();
    return 0;
}