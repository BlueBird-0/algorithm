#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>

using namespace std;

int getRank(int score)
{
	for (int i = 0;;i++)
	{
		if (score >= 100 - i * 5)
			return i + 1;
	}
}
class Student {
public:
	string name;
	int score;
	int rank = -1;
};

int main()
{
	ifstream fin("input.txt", ios::in);
	if (!fin)
	{
		cout << "오류" << endl;
		return 0;
	}
	ofstream fout("output.txt", ios::out);
	if (!fout)
	{
		cout << "오류2" << endl;
		return 0;
	}

	vector<Student> arr;
	for (int i = 0; i < 10; i++)
	{
		Student student;
		fin >> student.name >> student.score;
		arr.push_back(student);
	}


	//set rank
	int set_rank = 1;
	int set_people = 1;
	while (set_people <= 10)
	{
		int max = 0;
		for (auto &data : arr)
		{
			if (data.rank == -1 && data.score > max)
			{
				max = data.score;
			}
		}
		for (auto &data : arr)
		{
			if (data.score == max)
			{
				data.rank = set_rank;
				set_people++;
			}
		}
		set_rank = set_people;
	}

	fout << "Name Score Rank" << endl;
	for (auto data : arr)
	{
		fout.width(4);
		fout << data.name<< " ";
		fout.width(5);
		fout << data.score << " ";
		fout.width(4);
		fout << data.rank;
		fout << endl;
	}

	fin.close();
	fout.close();
	return 0;
}