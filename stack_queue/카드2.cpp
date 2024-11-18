#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);
    queue<int> card;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        card.push(i);
    if (card.size() == 1)
    {
        cout << card.front();
        return 0;
    }

    while (!card.empty())
    {
        card.pop();
        int cur = card.front();
        if (card.size() == 1)
        {
            cout << cur;
            break;
        }
        card.push(cur);
        card.pop();
    }
    
    return 0;

}
