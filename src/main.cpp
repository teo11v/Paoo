#include<iostream>
using namespace std;

class Person{

    public:
        Person::Person(int age,const std::string&name)
        :age(age),
         name(name)
        {cout<<"Person constructor"<<endl;}
        Person::Person(const Person& p1){
            age=p1.age;
            name=p1.name;
        }
    private:
        int age;
        std::string name;    
};


class Student:private Person{
    public:
        Student(int id)::Person(int age,const std::string&name)
            :age(age),
             name(name)
             id_stud(id)
            {cout<<"Student constructor"<<endl;}
        Student::~Student(){
            delete[] id_stud;
            cout<<"Student destructor"<<endl;
        }
    private:
        int id_stud;
};
//item 6
class Uncopyable{
    protected:
    Uncopyable(){}
    ~Uncopyable() {}
    private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};

class Grade: private Uncopyable{
    public:
        Grade()::Uncopyable(){}
    private:
        int grade;
} 

int main(){
    Person p1(21, "Milana"); //normal constructor called here
    Person p2=p1; //copy constructor called here
    Student s;
    Grade g1();
    Grade g2();
    Grade g3(g1);
    g1=g2;

}