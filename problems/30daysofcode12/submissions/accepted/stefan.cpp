//Author: Stefan Toman

//The following code was given.
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Student{
    protected:
        string firstName;
        string lastName;
        int phone;
    public:
        Student(string fname,string lname,int p){
            firstName=fname;
            lastName=lname;
            phone=p;
        }
        void display(){
            cout<<"First Name: "<<firstName<<"\nLast Name: "<<lastName<<"\nPhone: "<<phone; 

        }
    
};

//End of given code
class Grade : public Student {
    private:
        int score;
    public:
        Grade(string firstname, string lastname, int phone, int score) : Student(firstname, lastname, phone), score(score) {}
        char calculate() {
            if(score < 40) return 'D';
            if(score < 60) return 'B';
            if(score < 75) return 'A';
            if(score < 90) return 'E';
            return 'O';
        }
};

//The following code was given.
int main() {
    string firstName,lastName;
    int score,phone;
    cin>>firstName;
    cin>>lastName;
    cin>>phone;
    cin>>score;    
    Student *stu=new Grade(firstName,lastName,phone,score);
    stu->display();
    Grade *g=(Grade*)stu;
    cout<< "\nGrade: "<<g->calculate();
    return 0;
}
