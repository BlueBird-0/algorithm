/*#include <iostream>
using namespace std;

struct Student {
	char name[20];
	int age;
	double height;
	bool less(Student right) {
		return age < right.age;
	}
	bool operator<(Student right) {
		return age < right.age;
	}
};
bool Studentless(Student left, Student right) {
	return left.age < right.age;
}
int main()
{
	Student s1 = { "¸ÚÀïÀÌ", 17, 178.5 };
	Student s2 = { "ÀÌ»ÛÀÌ", 18, 165.9 };
	//if (Studentless(s1, s2))		// ¨ç
	//if(s1.less(s2))	// ¨è
	if(s1 < s2)
		printf("%s wins!\n", s2.name);
	else
		printf("%s wins!\n", s1.name);
}
*/


#include <stdio.h>
struct Rectangle
{
	int width, height;
	friend bool operator<(const Rectangle &obj, Rectangle right);
	//bool operator<(Rectangle right) {
	//	return (width * height) < (right.width * right.height);
	//}
};
bool operator<(const Rectangle& obj, Rectangle right) {
	return (obj.width * obj.height) < (right.width * right.height);
}

int main() {
	Rectangle a, b;
	
	scanf("%d %d", &a.width, &a.height);
	scanf("%d %d", &b.width, &b.height);
	
	if (a < b) printf("a is smaller\n");
	else       printf("b is smaller\n");
	
	return 0;
}