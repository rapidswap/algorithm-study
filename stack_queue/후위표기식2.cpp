#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int number = 1;
    unordered_map<char, int> m;
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        m[ch] = number;
        number++;
    }
    //for (auto a : m)
    //{
    //    cout << a.first << " " << a.second << '\n';
    //}
    int n;
    cin >> n;
    string order;
    cin >> order;
    
    queue<char> od;
    for (char ch : order)
    {
        od.push(ch);
    }
    vector<int> num(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> num[i];   
    }

    stack<double> nums;
    
    while (!od.empty())
    {
        double sum = 0.0;
        char curod = od.front();
        od.pop();

        if (isalpha(curod))
            nums.push(num[m[curod]]);
        else
        {
            double b=nums.top();
            nums.pop();
            double a=nums.top();
            nums.pop();
            
            if (curod == '+')
            {
                sum += a + b;
            }
            if (curod == '-')
            {
                sum += a - b;
            }
            if (curod == '*')
            {
                sum += a * b;
            }
            if (curod == '/')
            {
                sum += a / b;
            }
            //cout << "sum: " << sum << '\n';
            //cout << "curod: " << curod << "\n";
            //cout << "a: " << a <<" " << "b: " << b << '\n';
            nums.push(sum);
        }


    }
    double answer = nums.top();
    printf("%.2f", answer);
    return 0;
}
