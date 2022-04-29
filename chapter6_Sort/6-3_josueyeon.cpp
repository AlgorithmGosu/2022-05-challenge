// insertion sort

void insertion_sort(vector<int> &vec)
{
    for(int i = 1;i < vec.size();i++)
    {
		// 정렬되어 있다고 가정하고 특정 위치에 데이터를 넣음
        int j = i;
        while (j > 0)
        {
            if (vec[j] >= vec[j - 1])
                break;
            else
                swap(vec[j], vec[j - 1]);
            j--;
        }
    }
}

int main()
{
    vector<int> vec = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
    insertion_sort(vec);
    for(auto iter : vec)
        cout<<iter<<" ";
}

// 답지

void insertion_sort2(vector<int> &vec)
{
    for(int i = 1;i < vec.size();i++)
    {
        for(int j = i;j > 0;j--)
        {
            if (vec[j] < vec[j - 1])
                swap(vec[j], vec[j - 1]);
            else
                break;
        }
    }
}
