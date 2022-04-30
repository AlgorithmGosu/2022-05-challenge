// selection sort

// 가장 작은 값부터 앞에서부터 채워나감
void selection_sort(vector<int> &vec)
{
    for(int i = 0;i < vec.size();i++)
    {
		// 가장 작은 값인 인덱스 구하기
        int min = i;
        for(int j = i + 1;j < vec.size();j++)
        {
            if (vec[min] > vec[j])
                min = j;
        }
		// swap으로 배열 요소 교체
        swap(vec[min], vec[i]);
    }
}
int main()
{
    vector<int> vec = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
    selection_sort(vec);
    for(auto iter : vec)
        cout<<iter<<" ";
}
