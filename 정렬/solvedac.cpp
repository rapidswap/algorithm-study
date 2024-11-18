#include<iostream>
#include<vector>
#include<string>

#include<algorithm>
#include<stack>
#include<unordered_map>
#include<cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    float rm = round(n * 0.15);
    vector<int>op;
    while (n--)
    {
        int a;
        cin >> a;
        op.push_back(a);
    }
    sort(op.begin(), op.end());
    
    float sum = 0.0;
    for (int i=rm;i<op.size()-rm;i++)
    {
        sum += op[i];
    }
    if (sum > 0)
        cout << round(sum / (op.size()-(rm*2)));
    else
        cout << 0;
    

    return 0;
}
