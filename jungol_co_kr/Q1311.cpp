#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Card{
public:
	char c;
	int n;
};

int getSameColor(Card* arr)
{
	int color[4] = { 0, };	//R B Y G
	for (int i = 0; i < 5; i++)
	{
		if (arr[i].c == 'R')
			color[0]++;
		else if (arr[i].c == 'B')
			color[1]++;
		else if (arr[i].c == 'Y')
			color[2]++;
		else if (arr[i].c == 'G')
			color[3]++;
	}
	return max({ color[0], color[1],color[2],color[3] });
}
int getSameNum(Card* arr, int &sameValue)
{
	int num[10] = { 0, };	//1~9
	for (int i = 0; i < 5; i++)
	{
		num[arr[i].n]++;
	}
	int MAX = max({ num[1], num[2], num[3],num[4],num[5],num[6],num[7],num[8],num[9] });
	
	for (int i = 1;; i++)
	{
		if (num[i] == MAX)
		{
			sameValue = i;
			break;
		}
	}
	return MAX;
}
int getSameNum2(Card* arr, int n, int& sameValue)
{
	int num[10] = { 0, };	//1~9
	for (int i = 0; i < 5; i++)
	{
		num[arr[i].n]++;
	}
	num[n] = 0;
	int MAX = max({ num[1], num[2], num[3],num[4],num[5],num[6],num[7],num[8],num[9] });

	for (int i = 1;; i++)
	{
		if (num[i] == MAX)
		{
			sameValue = i;
			break;
		}
	}
	return MAX;
}
bool isStraight(Card* arr, int& max)
{
	int num[10] = { 0, };	//1~9
	int front =10;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i].n < front)
			front = arr[i].n;
		num[arr[i].n]++;
	}
	if (front <= 5 && num[front] && num[front + 1] && num[front + 2] && num[front + 3] && num[front + 4])
	{
		max = front + 4;
		return true;
	}
	return false;
}
int getMaxNum(Card* arr)
{
	int Max = 0;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i].n > Max)
			Max = arr[i].n;
	}
	return Max;
}

int main()
{
	Card arr[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i].c >> arr[i].n;
	}
	int temp, temp2;
	if (getSameColor(arr) == 5 && isStraight(arr, temp))
		cout << getMaxNum(arr) + 900;
	else if (getSameNum(arr, temp) == 4)
		cout << temp + 800;
	else if (getSameNum(arr, temp) == 3 && getSameNum2(arr, temp, temp2) == 2)
		cout << temp * 10 + temp2 + 700;
	else if (getSameColor(arr) == 5)
		cout << getMaxNum(arr) + 600;
	else if (isStraight(arr, temp))
		cout << temp + 500;
	else if (getSameNum(arr, temp) == 3)
		cout << temp + 400;
	else if (getSameNum(arr, temp) == 2 && getSameNum2(arr, temp, temp2) == 2)
		cout << (temp > temp2 ? temp * 10 + temp2 + 300 : temp2 * 10 + temp + 300);
	else if (getSameNum(arr, temp) == 2)
		cout << temp + 200;
	else
		cout << getMaxNum(arr) + 100;


	return 0;
}