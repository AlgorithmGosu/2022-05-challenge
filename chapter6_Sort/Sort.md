# Sort
### 데이터를 특정한 기준에 따라서 순서대로 나열하는 것
* 버블 정렬
* 선택 정렬
* 삽입 정렬
* 퀵 정렬
* 계수 정렬
* 힙 정렬
* 기수 정렬
    
## 버블 정렬 Bubble Sort
인접한 두 요소를 비교하여 정렬하는 과정을 반복한다.<br>
즉 <strong> 가장 큰 요소부터 배열의 뒤에 정렬되게 된다. </strong>
         
#### 예시 in c++
```cpp
void bubble_sort(vector<int> &vec)
{
    for(int i = 0;i < vec.size();i++)
    {
        for(int j = 0;j < vec.size() - 1 - i;j++)
        {
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
        }
    }
}
```
     
#### 시간 복잡도
<img src="https://latex.codecogs.com/png.image?\dpi{110}O(n^2)" title="https://latex.codecogs.com/png.image?\dpi{110}O(n^2)"/>

## 선택 정렬 Selection Sort
데이터 중 가장 작은 요소를 맨 앞의 요소와 교체하고, 그 다음으로 작은 데이터를 앞에서 두번째 요소와 교체하는 과정을 반복.<br>
즉 <strong> 매번 가장 작은 요소를 선택해서 배열의 앞에서부터 교체해나감</strong>

#### 예시 in c++
```cpp
void selection_sort(vector<int> &vec)
{
    for(int i = 0;i < vec.size();i++)
    {
        int min = i;
        for(int j = i + 1;j < vec.size();j++)
        {
            if (vec[min] > vec[j])
                min = j;
        }
        swap(vec[min], vec[i]);
    }
}
```
    
#### 예시 in python
```python
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for i in range(len(array)):
    min_index = i # 가장 작은 원소의 인덱스
    for j in range(i + 1, len(array)):
        if array[min_index] > array[j]:
            min_index = j
    array[i], array[min_index] = array[min_index], array[i] # 스와프

print(array)
```
     
#### 시간 복잡도
<img src="https://latex.codecogs.com/png.image?\dpi{110}O(n^2)" title="https://latex.codecogs.com/png.image?\dpi{110}O(n^2)"/>
    
      
      
## 삽입 정렬 Insertion Sort
데이터 중 특정 요소의 위치를 지정해서 적절한 위치에 삽입하여 정렬한다.<br>
필요할 때만 위치를 바꾸기 때문에 데이터가 거의 정렬되어 있을 때 효율적이다.<br>
이때 삽입 정렬은 <strong> 특정한 데이터가 적절한 위치에 들어가기 이전에, 그전까지의 데이터는 모두 정렬되어 있다고 가정한다.</strong><br>
따라서 배열의 두번째 요소부터 정렬을 시작한다. (첫번째 요소는 이미 그 위치에 정렬되어 있기 때문)<br>
    
#### 예시 in c++
```cpp
void insertion_sort(vector<int> &vec)
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
```
    
#### 예시 in python
```python
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for i in range(1, len(array)):
    for j in range(i, 0, -1): # 인덱스 i부터 1까지 1씩 감소하며 반복하는 문법
        if array[j] < array[j - 1]: # 한 칸씩 왼쪽으로 이동
            array[j], array[j - 1] = array[j - 1], array[j]
        else: # 자기보다 작은 데이터를 만나면 그 위치에서 멈춤
            break

print(array)
```
    
    
#### 시간 복잡도
<img src="https://latex.codecogs.com/png.image?\dpi{110}O(n^2)" title="https://latex.codecogs.com/png.image?\dpi{110}O(n^2)" />
(시간 복잡도는 같지만 삽입 정렬은 필요한 데이터에 대해서만 정렬을 하기 때문에 선택 정렬보다 효율적임)
    
    
        
## 퀵 정렬 Quick Sort
기준 데이터(pivot)를 설정하고, 기준 데이터보다 큰 수와 작은 수를 구분하여 위치를 바꾸어 정렬.<br>
즉 <strong> 기준을 설정한 다음 큰 수와 작은 수를 교환하여 리스트를 반으로 나누고, 각각의 리스트에 대해서 다시 정렬하는 방식 </strong><br>
    
* 이때, 큰 수와 작은 수를 구분하는 기준 데이터 -> pivot <br>
* 대표적인 pivot 설정 기준: 호어 분할 Hoare Partition <br>
                       <strong>리스트에서 가장 첫 번째 데이터를 pivot으로 정한다.</strong>
* 퀵 정렬이 끝나는 조건: 리스트의 데이터 갯수가 1개인 경우 (이미 정렬되어 있다고 간주하기 때문)
    
    
#### 동작 방식
1. 배열의 첫 번째 데이터를 pivot으로 설정함.
2. 배열에 투 포인터를 두고 앞과 뒤에서 진행하며, pivot보다 크거나 작은 값을 만난 경우 진행을 멈춘다.
3. 2에서 찾은 두 데이터를 서로 교체한다.
4. 만약 투 포인터의 위치가 서로 엇갈린 경우 (인덱스 대소가 바뀐 경우), 분할이 끝난 것이므로 <strong>작은 데이터와</strong> pivot을 교체한다.
5. pivot을 기준으로 분할된 두 배열에 대해서 다시 퀵 정렬을 실행한다.
    
      
#### 예시 in c++
```cpp
void quick_sort(vector<int> &vec, int start, int end)
{
    if (start >= end)
        return;
    
    int pivot = start;
    int left = start + 1;
    int right = end;
    
    while (left <= right)
    {
        while (left <= end && vec[pivot] >= vec[left])
            left++;
        while(right > start && vec[pivot] <= vec[right])
            right--;
        
        if (left > right)
            swap(vec[pivot], vec[right]);
        else
            swap(vec[left], vec[right]);
    }
    
    quick_sort(vec, start, right - 1);
    quick_sort(vec, right + 1, end);
}
```
    
    
#### 예시 in python
```python
array = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]

def quick_sort(array):
    # 리스트가 하나 이하의 원소만을 담고 있다면 종료
    if len(array) <= 1:
        return array

    pivot = array[0] # 피벗은 첫 번째 원소
    tail = array[1:] # 피벗을 제외한 리스트

    left_side = [x for x in tail if x <= pivot] # 분할된 왼쪽 부분
    right_side = [x for x in tail if x > pivot] # 분할된 오른쪽 부분

    # 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬을 수행하고, 전체 리스트를 반환
    return quick_sort(left_side) + [pivot] + quick_sort(right_side)

print(quick_sort(array))
```
    
    
#### 시간 복잡도
평균적으로 <img src="https://latex.codecogs.com/png.image?\dpi{110}O(NlogN)&space;" title="https://latex.codecogs.com/png.image?\dpi{110}O(NlogN) " />
    
    
    
## 계수 정렬 Counting Sort
특정 조건이 부합할 떄만 사용 가능하지만, 매우 빠른 알고리즘이다. <br>
* 데이터의 크기 범위가 제한되어 정수 형태로 표현 가능한 경우에만 사용 가능하다.
* 왜냐하면 모든 범위를 담을 수 있는 크기의 배열을 선언해야하기 때문, 즉 [abs(max - min) + 1] 크기의 배열이 필요하기 때문.
* 일반적으로 abs(max - min)이 1,000,000을 넘지 않는 경우에만 사용 가능하다.
    
    
#### 예시 in c++
```cpp
int MAX = 9;
void counting_sort(vector<int> vec)
{
    vector<int> v(MAX + 1, 0);
    
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
```
    
    
#### 예시 in python
```python
# 모든 원소의 값이 0보다 크거나 같다고 가정
array = [7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2]
# 모든 범위를 포함하는 리스트 선언 (모든 값은 0으로 초기화)
count = [0] * (max(array) + 1)

for i in range(len(array)):
    count[array[i]] += 1 # 각 데이터에 해당하는 인덱스의 값 증가

for i in range(len(count)): # 리스트에 기록된 정렬 정보 확인
    for j in range(count[i]):
        print(i, end=' ') # 띄어쓰기를 구분으로 등장한 횟수만큼 인덱스 출력
```
    
    
#### 시간 복잡도
모든 데이터가 양의 정수, 데이터의 개수가 N, 데이터의 최댓값이 K인 경우 <img src="https://latex.codecogs.com/png.image?\dpi{110}O(N&plus;K)&space;" title="https://latex.codecogs.com/png.image?\dpi{110}O(N+K) " />
     
     
#### 공간 복잡도
abs(max - min)의 차이가 100만을 넘어간다면 배열의 크기가 100만 + 1이 되기 때문에 매우 비효율적이다.<br>
따라서 데이터의 크기가 한정되어 있고, 데이터의 크기가 많이 중복되어 있을 수록 유리하다.
