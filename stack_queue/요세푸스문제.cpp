#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> answer;
    queue<int> q;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        for (int i = 0; i < k; i++)
        {
            int a = q.front();
            if (i == k - 1)
            {
                answer.push_back(a);
                q.pop();
            }
            else
            {
                q.pop();
                q.push(a);
            }
        }
    }
    
    cout << "<";
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
        if (i == answer.size() - 1)
        {
            cout << ">";
        }
        else
        {
            cout << ", ";
        }
    }

    

    return 0;
}
