//Author: Stefan Toman

// the following lines were given
using namespace std;
#include <iostream>

class Person{
public:
    int age;
    Person(int initial_Age);
    void amIOld();
    void yearPasses();
};

//the following three functions were given empty
Person::Person(int initial_Age){
    // Add some more code to run some checks on initial_Age
    if(initial_Age < 0) {
        cout << "This person is not valid, setting age to 0." << endl;
        age = 0;
    }
    else {
        age = initial_Age;
    }
}

void Person::amIOld(){
    // Do some computations in here and print out the correct statement to the console 
    if(age < 13) {
        cout << "You are young." << endl;
    }
    else if(age < 18) {
        cout << "You are a teenager." << endl;
    }
    else {
        cout << "You are old." << endl;
    }
}
    
// everything following was given
void Person::yearPasses(){
    // Increment the age of the person in here
    age++;
}

int main(){
    int T,age;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>age;
        Person p(age);
        p.amIOld();
        for(int j=0;j<3;j++)
        {
            p.yearPasses();
            
        }
        p.amIOld();
        cout<<"\n";
    }
    return 0;
}
    