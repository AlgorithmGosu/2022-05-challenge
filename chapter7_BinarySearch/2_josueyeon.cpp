#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Binary_search(int target, vector<int> stock, int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if (stock[mid] == target)
        return 1;

    else if (stock[mid] > target)
        return Binary_search(target, stock, start, mid - 1);

    else
        return Binary_search(target, stock, mid + 1, end);
}

int main()
{
    // N(재고), M(주문)
    int N, M, temp;
    vector<int> stock;
    vector<int> customer;

    cin>>N;
    for(int i = 0;i < N;i++)
    {
        cin>>temp;
        stock.push_back(temp);
    }

    cin>>M;
    for(int i = 0;i < M;i++)
    {
        cin>>temp;
        customer.push_back(temp);
    }

    sort(stock.begin(), stock.end());

    for(auto iter : customer)
    {
        int result = Binary_search(iter, stock, 0, stock.size() - 1);

        if (result == -1)
            cout<<"no ";
        else
            cout<<"yes ";
    }

    cout<<endl;
    return 0;
}
/*
 5
 8 3 7 9 2
 3
 5 7 9
 */

