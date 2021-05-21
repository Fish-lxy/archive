#include<iostream>
#include<string>
using namespace std;

class Student
{
    private:
		int ID;
		string Name;
		int Score;
	public:
	    Student(int,string,int);
	    Student();
	    ~Student();
	    friend void setAll(Student*,int,int);//友元函数
		void printStu(void)const;//const成员函数在函数头部结尾加const,只能读取成员变量不能修改
		void setID(int);
		void setScore(int);
		void setName(string);
};
int main()
{
	class Student stu1;
    stu1.setID(1);
    stu1.setScore(95);
    stu1.setName("S1");
	stu1.printStu();

	class Student stu2(2,"S2",90);
	stu2.printStu();
	setAll(&stu2,0,0);
	stu2.printStu();

	class Student *p;
	p=new Student(3,"S3",85);
	p->printStu();
	delete p;
}
//构造函数 初始化对象
Student::Student(int ID,string Name,int Score)
{
    this->ID=ID;
    this->Name=Name;
    this->Score=Score;
}
//构造函数的重载
Student::Student()
{
    this->ID=0;
    this->Score=0;
}
//析构函数
Student::~Student()
{
    cout<<"deleted a student:"<<ID<<" "<<Name<<endl;
}
//友元函数
void setAll(Student *stu,int ID,int Score)
{
    stu->ID=ID;
    stu->Score=Score;
}
//成员函数
void Student::printStu(void)const
{
    cout<<"Name:"<<Name<<endl;
    cout<<"ID:"<<ID<<endl;
    cout<<"Score:"<<Score<<endl;
    cout<<endl;
}
void Student::setID(int n)
{
    ID=n;
}
void Student::setScore(int n)
{
    Score=n;
}
void Student::setName(string n)
{
    Name=n;
}
