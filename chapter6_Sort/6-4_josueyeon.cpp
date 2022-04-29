// quick sort

void quick_sort(vector<int> &vec, int start, int end)
{
	// 종료 조건: 크기가 1인 경우
    if (start >= end)
        return;

	// 맨 처음 데이터를 pivot으로 설정함
    int pivot = start;
	
	// 투 포인터를 두고 양쪽에서 진행함
    int left = start + 1;
    int right = end;

	// while 문에서 배열 분할 과정을 진행함
    while (left <= right)
    {
		// 큰 값을 찾음
        while (left <= end && vec[pivot] >= vec[left])
            left++;

		// 작은 값을 찾음
        while(right > start && vec[pivot] <= vec[right])
            right--;

		// 투 포인터가 엇갈린 경우, 작은 값과 pivot을 교체함.
        if (left > right)
            swap(vec[pivot], vec[right]);

		// 아닌 경우 큰 값과 작은 값을 교체함.
        else
            swap(vec[left], vec[right]);
    }

	// pivot을 기준으로 분할된 배열에 대해서도 다시 퀵 정렬을 실행함.
    quick_sort(vec, start, right - 1);
    quick_sort(vec, right + 1, end);
}

int main()
{
    vector<int> vec = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
    quick_sort(vec, 0, (int)vec.size() - 1);
    for(auto iter : vec)
        cout<<iter<<" ";
}

