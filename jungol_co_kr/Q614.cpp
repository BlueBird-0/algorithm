#include <iostream>
#include <string>
using namespace std;

struct people {
	string school;
	int grade;
	void print() {
		printf("%d grade in %s School\n", grade, school.c_str());
	};
};
int main()
{
	people a, b;
	a.school = "Jejuelementary";
	a.grade = 6;

	cin >> b.school;
	cin >> b.grade;

	a.print();
	b.print();

	return 0;
}