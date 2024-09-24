#include <iostream>
#include <string>
#include <memory.h>	
using namespace std;

void functionL(int& pos, int& len) {
	if (pos > 0)
		pos--;
}

void functionR(int& pos, int& len) {
	if (pos < len)
		pos++;
}

void functionD(char* initString, int& pos, int& len) {
	if (pos > 0) {
		memcpy(initString + (pos - 1), initString + pos, (len - pos + 1));
		functionL(pos, len);
	}
}

void functionP(char* initString, int& pos, int& len, char ch);
void functionI(char* initString, int& pos, int& len, char ch) {
	if (pos == len) {
		functionP(initString, pos, len, ch);
	}
	else {
		initString[pos] = ch;
		functionR(pos, len);
	}
}

void functionP(char* initString, int& pos, int& len, char ch) {
	memcpy(initString + (pos + 1), initString + pos, (len - pos + 1));
	initString[pos] = ch;
	len++;
	functionR(pos, len);
}

int main()
{
	char initString[200001] = { 0, };
	int pos = 0, len = 0;
	string initStr = "abcd";
	//string initStr = "";
	strcpy(initString, initStr.c_str());
	pos = len = initStr.size();
	

	string commands[] = {"L", "P Z", "L", "D", "R", "I x"};
	//string commands[] = { "P a", "P b", "L", "I c", "I d" };
	int N = sizeof(commands) / sizeof(string);	// command 배열의 크기
	for (int i = 0; i < N; i++) {
		if (commands[i][0] == 'L')
			functionL(pos, len);
		if (commands[i][0] == 'R')
			functionR(pos, len);
		if (commands[i][0] == 'D')
			functionD(initString, pos, len);
		if (commands[i][0] == 'I')
			functionI(initString, pos, len, commands[i][2]);
		if (commands[i][0] == 'P')
			functionP(initString, pos, len, commands[i][2]);

		printf("%s\n", initString);
	}
}