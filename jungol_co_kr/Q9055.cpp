#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	string name;
	int age;
	Student* fr = nullptr;
	Student(string n, int a);
	void print();
};

Student::Student(string n, int a)
{
	this->name = n;
	this->age = a;
}

void Student::print()
{
	cout << "당신의 이름 : " << this->name << ", 나이 : " << this->age << endl;
	cout << "친구의 이름 : " << fr->name << ", 나이 : " << fr->age << endl;
}

int main()
{
	Student me("손예준", 12);
	cout << "친한 친구의 이름과 나이를 입력하세요. ";
	string name;
	int age;

	cin >> name >> age;
	me.fr = new Student(name, age);
	me.print();
	return 0;
}