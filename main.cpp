#include<iostream>
#include<string>
using namespace std;

class Person
{
protected:
    string name;
    int id;

public:
    void setData()
    {
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter ID: ";
        cin>>id;
    }

    void displayInfo()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
    }
};

class Student : public Person
{
private:
    int marks;
    float attendance;

public:
    void inputMarks()
    {
        cout<<"Enter Marks (0-100): ";
        cin>>marks;
        if(marks<0 || marks>100)
        {
            cout<<"Invalid! Marks set to 0."<<endl;
            marks=0;
        }
    }

    void checkAttendance()
    {
        cout<<"Enter Attendance %: ";
        cin>>attendance;
        if(attendance>=75)
            cout<<"Status: Eligible"<<endl;
        else
            cout<<"Status: Short"<<endl;
    }

    void displayInfo()
    {
        cout<<"\n--- Student Record ---"<<endl;
        Person::displayInfo();
        cout<<"Marks: "<<marks<<endl;
        cout<<"Attendance: "<<attendance<<"%"<<endl;
    }
};

class Teacher : public Person
{
private:
    string subject;

public:
    void assignSubject()
    {
        cout<<"Enter Subject: ";
        cin>>subject;
    }

    void displayInfo()
    {
        cout<<"\n--- Teacher Record ---"<<endl;
        Person::displayInfo();
        cout<<"Subject: "<<subject<<endl;
    }
};

class Course
{
private:
    string courseName;
    int courseID;
    string assignedTeacher;

public:
    void setData()
    {
        cout<<"Enter Course Name: ";
        cin>>courseName;
        cout<<"Enter Course ID: ";
        cin>>courseID;
    }

    void assignCourse()
    {
        cout<<"Enter Teacher Name: ";
        cin>>assignedTeacher;
    }

    void displayInfo()
    {
        cout<<"\n--- Course Record ---"<<endl;
        cout<<"Course Name: "<<courseName<<endl;
        cout<<"Course ID: "<<courseID<<endl;
        cout<<"Assigned Teacher: "<<assignedTeacher<<endl;
    }
};

int main()
{
    int choice;

    cout<<"=== School Management System ==="<<endl;

    do
    {
        cout<<"\n1. Student"<<endl;
        cout<<"2. Teacher"<<endl;
        cout<<"3. Course"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice==1)
        {
            Student s;
            s.setData();
            s.inputMarks();
            s.checkAttendance();
            s.displayInfo();
        }
        else if(choice==2)
        {
            Teacher t;
            t.setData();
            t.assignSubject();
            t.displayInfo();
        }
        else if(choice==3)
        {
            Course c;
            c.setData();
            c.assignCourse();
            c.displayInfo();
        }
        else if(choice!=4)
        {
            cout<<"Invalid choice!"<<endl;
        }

    }while(choice!=4);

    cout<<"Goodbye!"<<endl;
    return 0;
}
