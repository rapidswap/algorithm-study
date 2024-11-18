#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> num;
    int sum = 0;
    while (n--)
    {
        int a;
        cin >> a;
        if (a == 0)
        {
            num.pop();
            continue;
        } 
        num.push(a);
    }
    while (!num.empty())
    {
        sum += num.top();
        num.pop();
    }
    cout << sum;

    

    return 0;
}
