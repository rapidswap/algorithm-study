#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n,m;
    cin >> n>>m;

    map<string,int> poke;
    vector<string> pokeStr(n + 1);
    
    for (int i = 1; i <= n; i++) {
        
        cin >> pokeStr[i];
        poke[pokeStr[i]]=i;
    }

    for (int i = 0; i < m; i++) {
        string order;
        cin >> order;
        if (isdigit(order[0])) {
            cout << pokeStr[stoi(order)]<<"\n";
        }
        else {
            cout << poke[order]<<"\n";
        }

    }
    

    return 0;
}
