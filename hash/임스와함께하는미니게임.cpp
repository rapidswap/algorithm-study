#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include <limits.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string gameName;
    cin >> n >> gameName;
    unordered_map<string, int> player;
    int canPlay = 0;
    for (int i = 0; i < n; i++)
    {
        string playerName;
        cin >> playerName;
        if (player[playerName] == 0)
        {
            player[playerName] = 1;
            canPlay++;
        }
    }
    

    if (gameName == "Y")
    {
        cout << canPlay / 1;
    }
    else if (gameName == "F")
    {
        cout << canPlay / 2;
    }
    else if (gameName == "O")
    {
        cout << canPlay / 3;
    }
    
    return 0;
}
