#include <iostream>
using namespace	std;

bool onLine(pair<int, int> p1, pair<int, int> p2, pair<int, int> pp1)
{
	if (pp1.first > p1.first && pp1.first < p2.first)
		return true;
	if (pp1.second > p1.second && pp1.second < p2.second)
		return true;
	return false;
}
bool inside(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4,
	pair<int, int> pp1) {
	if (pp1.first > p1.first && pp1.first < p1.first
		&& pp1.second > p3.second && pp1.second < p4.second)
		return true;
	return false;
}

bool isInFace(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4,
	pair<int, int> pp1, pair<int, int> pp2, pair<int, int> pp3, pair<int, int> pp4) {
	if (inside(pp1, pp2, pp3, pp4, p1))
		return true;
	if (inside(pp1, pp2, pp3, pp4, p2))
		return true;
	if (inside(pp1, pp2, pp3, pp4, p3))
		return true;
	if (inside(pp1, pp2, pp3, pp4, p4))
		return true;
	if (inside(p1, p2, p3, p4, pp1))
		return true;
	if (inside(p1, p2, p3, p4, pp2))
		return true;
	if (inside(p1, p2, p3, p4, pp3))
		return true;
	if (inside(p1, p2, p3, p4, pp4))
		return true;
	return false;
}
bool isNULL(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4,
	pair<int, int> pp1, pair<int, int> pp2, pair<int, int> pp3, pair<int, int> pp4) {
	if (pp3.second < p1.second)
		return true;
	if (pp2.first < p1.first)
		return true;
	if (pp1.first > p2.first)
		return true;
	if (pp1.second > p3.second)
		return true;

	return false;
}

bool isInLine(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4,
	pair<int, int> pp1, pair<int, int> pp2, pair<int, int> pp3, pair<int, int> pp4) {
	
	if (p3.second == pp1.second && p3.first >= pp1.first && p3.first <= pp2.first)
		return true;
	if (p4.second == pp1.second && p4.first >= pp1.first && p4.first <= pp2.first)
		return true;
	if (p1.second == pp3.second && p1.first >= pp3.first && p1.first <= pp4.first)
		return true;
	if (p2.second == pp3.second && p2.first >= pp3.first && p2.first <= pp4.first)
		return true;
	if (p2.first == pp1.first && p2.second >= pp1.second && p2.second <= pp3.second)
		return true;
	if (p4.first == pp1.first && p4.second >= pp1.second && p4.second <= pp3.second)
		return true;
	if (p1.first == pp2.first && p1.second >= pp2.second && p1.second <= pp4.second)
		return true;
	if (p3.first == pp2.first && p3.second >= pp2.second && p3.second <= pp4.second)
		return true;

	if (pp3.second == p1.second && pp3.first >= p1.first && pp3.first <= p2.first)
		return true;
	if (pp4.second == p1.second && pp4.first >= p1.first && pp4.first <= p2.first)
		return true;
	if (pp1.second == p3.second && pp1.first >= p3.first && pp1.first <= p4.first)
		return true;
	if (pp2.second == p3.second && pp2.first >= p3.first && pp2.first <= p4.first)
		return true;
	if (pp2.first == p1.first && pp2.second >= p1.second && pp2.second <= p3.second)
		return true;
	if (pp4.first == p1.first && pp4.second >= p1.second && pp4.second <= p3.second)
		return true;
	if (pp1.first == p2.first && pp1.second >= p2.second && pp1.second <= p4.second)
		return true;
	if (pp3.first == p2.first && pp3.second >= p2.second && pp3.second <= p4.second)
		return true;
	return false;
}



bool isPoint(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4,
	pair<int, int> pp1, pair<int, int> pp2, pair<int, int> pp3, pair<int, int> pp4) {
	if (p4 == pp1 || p2 == pp3 || p1 == pp4 || p3 == pp2)
		return true;
	return false;
}

int main() {
	pair<int, int> p1, p2, p3, p4;

	pair<int, int> pp1, pp2, pp3, pp4;

	cin >> p1.first;
	cin >> p1.second;
	cin >> p4.first;
	cin >> p4.second;
	cin >> pp1.first;
	cin >> pp1.second;
	cin >> pp4.first;
	cin >> pp4.second;

	p2.first = p4.first;
	p2.second = p1.second;
	p3.first = p1.first;
	p3.second = p4.second;

	pp2.first = pp4.first;
	pp2.second = pp1.second;
	pp3.first = pp1.first;
	pp3.second = pp4.second;

	//POINT
	if (isPoint(p1, p2, p3, p4, pp1, pp2, pp3, pp4))
		printf("POINT");
	//FACE
	else if (isInFace(p1,p2, p3, p4, pp1, pp2, pp3, pp4))
		printf("FACE");
	//NULL
	else if (isNULL(p1, p2, p3, p4, pp1, pp2, pp3, pp4))
		printf("NULL");
	//LINE
 	else if (isInLine(p1, p2, p3, p4, pp1, pp2, pp3, pp4))
		printf("LINE");
	else
		printf("FACE");



	return 0;
 }