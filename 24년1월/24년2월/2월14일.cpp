﻿#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
namespace {
	vector<pair<int, int>> A;
	int B[51];
	int N;
}

int Q1015()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		A.push_back(make_pair(temp, i));
	}

	sort(A.begin(), A.end());

	int count = 0;
	for (pair<int, int> arr : A)
	{
		B[arr.second] = count;
		count++;
	}

	for (int i = 0; i < N; i++)
	{
		cout << B[i] << ' ';
	}

	return 0;
}