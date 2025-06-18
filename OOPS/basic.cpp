#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<string>

class teacher {
  // properties /attributes
  public:
  string name;
  string department;
  string subject;
  private:
  int salary;
  float* rating;

  public: 
  //method (a function inside a class)
    void setdepartment(string new_department) {
        department = new_department;
    }
    void setSalary(int new_salary) {
        salary = new_salary;
    }
    void setName(string new_name) {
        name = new_name;
    }
    void setSubject(string new_subject) {
        subject = new_subject;
    }
    void setRating(float new_rating) {
        if (rating == nullptr) {
            rating = new float; // allocate memory if not already allocated
        }
        *rating = new_rating; // dereference pointer to assign value
    }
    void printDetails() {
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
        cout << "Rating: " << *rating << endl; //dereferencing the pointer to get the value
    }
 
    teacher(string name, string dept, string subject, int salary, float rating){
        this->name = name; //correct usage of 'this' pointer
        this->department = dept;
        this->subject = subject;
        this->salary = salary;
        this->rating = new float; //making a place by DMA for the pointer named rating with the data type float
        *(this->rating) = rating; //dereferencing the pointer to assign value
    }
    teacher (teacher &obj ){ //copy constructor 
        this->name = obj.name;
        this->department = obj.department;
        this->subject = obj.subject;
        this->salary = obj.salary;
        this->rating = new float; 
        *(this->rating) = *(obj.rating); 
       // this->rating = obj.rating;  //shallow copy, retains the same value irrespective of the object
    }
};

using namespace std;

int main() {
    teacher t1("John Doe", "Mathematics", "Algebra", 50000, 4.5);
    teacher t2(t1); // Using copy constructor
    t2.setName("Jane Smith");
    t1.setRating(4.8); 
    t2.printDetails(); //all the details of t1 has been copied to t2
    t1.setSalary(50000); 
    t1.printDetails();
    return 0;
}