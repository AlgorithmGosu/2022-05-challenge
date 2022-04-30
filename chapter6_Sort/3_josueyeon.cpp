#include <vector>
#include <iostream>
using namespace std;

// pair로 int, string을 저장
int main()
{
    // 학생 수
    int N;
    cin>>N;

    vector<pair<int, string>> v;
    for(int i = 0;i < N;i++)
    {
        string s;
        int temp;
        cin>>s>>temp;
        v.push_back({temp, s});
    }
    sort(v.begin(), v.end());

    for(auto iter: v)
    {
        string s = iter.second;
        cout<<s<<" ";
    }

	return 0;
}

// 답지

class Student
{
	public:
		string name;
		int score;

		Student(string _name, int _score)
		{
			this->name = _name;
			this->score = _score;
		}

		bool operator<(Student &other)
		{
			return this->score < other.score;
		}
};

int main(void)
{
	int N;
	vector<Student> v;

	cin>>N;

	for(int i = 0;i < N;i++)
	{
		string name;
		int score;

		cin>>name>>score;

		v.push_back(Student(name, score));
	}

	sort(v.begin(), v.end());

	for(int i = 0;i < N;i++)
	{
		cout<<v[i].name<<" ";
	}

	return 0;
}
