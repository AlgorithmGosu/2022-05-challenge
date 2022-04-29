// counting sort

int MAX = 9;
void counting_sort(vector<int> vec)
{
	// abs(max - min) + 1의 크기만큼 배열을 생성한다.
    vector<int> v(MAX + 1, 0);

	// 값에 해당하는 인덱스의 값을 증가한다.
    for(int i = 0;i < vec.size();i++)
    {
        v[vec[i]]++;
    }

    for(int i = 0;i <= MAX;i++)
    {
        for(int j = 0;j < v[i];j++)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    vector<int> vec = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
    counting_sort(vec);
}

