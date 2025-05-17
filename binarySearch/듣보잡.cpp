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


    vector<string> noHear(n + 1);
    vector<string> noSee(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> noHear[i];
    }
    sort (noHear.begin(), noHear.end());

    int cnt = 0;

    vector<string> noHearSee;
    for (int i = 0; i < m; i++) {
        cin >> noSee[i];
        if (binary_search(noHear.begin(), noHear.end(), noSee[i])) {
            cnt++;
            noHearSee.push_back(noSee[i]);
        }
    }
    sort(noHearSee.begin(), noHearSee.end());
    cout << cnt << '\n';
    for (string str : noHearSee) {
        cout << str << '\n';
    }
    

    return 0;
}
