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
	cout << "����� �̸� : " << this->name << ", ���� : " << this->age << endl;
	cout << "ģ���� �̸� : " << fr->name << ", ���� : " << fr->age << endl;
}

int main()
{
	Student me("�տ���", 12);
	cout << "ģ�� ģ���� �̸��� ���̸� �Է��ϼ���. ";
	string name;
	int age;

	cin >> name >> age;
	me.fr = new Student(name, age);
	me.print();
	return 0;
}