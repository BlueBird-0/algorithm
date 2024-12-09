#include <iostream>
#include <queue>
#include <vector>
// priority queue
using namespace std;

class Patient {
public:
	string name;
	int age;
	double blood;
	bool operator< (const Patient& a) const
	{
		if (this->blood == a.blood)
			return this->age < a.age;
		return this->blood < a.blood;
	}
};

int main()
{
	/*
	const auto data = { 1,8,5,6,3,4,0,9,7,2 };
	priority_queue<int> max_heap;
	for (int n : data) max_heap.push(n);

	//최소 힙 및 초기화
	priority_queue<int, vector<int>, greater<int>> min_heap(data.begin(), data.end());

	//힙 출력
	while (!max_heap.empty()) {
		printf("%d", max_heap.top());
		max_heap.pop();
	}
	printf("\n");

	while (!min_heap.empty()) {
		printf("%d", min_heap.top());
		min_heap.pop();
	}
	printf("\n");
	*/
	priority_queue<Patient> queue;

	int n;
	string arg;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
  		cin >> arg;
		if (arg == "push") {
			Patient temp;
			cin >> temp.name >> temp.age >> temp.blood;
			queue.push(temp);
		}
		else if (arg == "pop") {
			if (!queue.empty()) {
				Patient temp = queue.top();
				printf("%s\n", temp.name.c_str());
				queue.pop();
			}
		}

	}

}