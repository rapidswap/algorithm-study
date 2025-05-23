#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int n,m;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n>>m;

    vector<vector<int>> planet(n,vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> planet[i][j];
        }
    }
    
    vector<vector<int>> uni(planet.begin(), planet.end());
    for (int i = 0; i < n; i++) {
        sort(uni[i].begin(), uni[i].end());
    }
    for (int i = 0; i < n; i++) {
        uni[i].erase(unique(uni[i].begin(), uni[i].end()), uni[i].end());
    }

    vector<vector<int>> zip(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            zip[i][j] = lower_bound(uni[i].begin(), uni[i].end(), planet[i][j]) - uni[i].begin();
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (equal(zip[i].begin(), zip[i].end(), zip[j].begin())) {
                answer++;
            }
        }
    }
    
    cout << answer;


    return 0;
}
