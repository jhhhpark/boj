#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct person
{
	int no;
	int age;
	string name;
	person(int no, int age, string name)
	{
		this->no = no;
		this->age = age;
		this->name = name;
	}
};

int compare(person p1, person p2)
{
	return p1.age == p2.age ? p1.no < p2.no : p1.age < p2.age;
}

int problem_10814()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<person> members;
	int N = 0;
	cin >> N;
	members.reserve(N);
	int age = 0;
	string name = "";
	for (int i = 0; i < N; ++i)
	{
		cin >> age >> name;
		members.push_back(person(i, age, name));
	}
	sort(members.begin(), members.end(), compare);
	for (size_t i = 0; i < members.size(); ++i)
	{
		cout << members[i].age << ' ' << members[i].name << '\n';
	}
	return 0;
}