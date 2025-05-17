#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <stack>
#include <cmath>
#include <unordered_set>
#include <map>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.first > b.first;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a[1001];
    vector<int> two;

    int n;
    cin >> n;

    map<string, int> emp;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (b == "enter") emp[a] = 1;
        else if (b == "leave") emp[a] = 0;
    }

    vector<pair<string, int>> emps(emp.begin(), emp.end());
    sort(emps.begin(), emps.end(), cmp);
    for (auto a : emps) {
        if (a.second == 1) cout << a.first<<"\n";
    }
    

    return 0;
}
