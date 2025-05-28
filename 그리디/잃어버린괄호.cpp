#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    queue<string> q;
    string a;

    for (auto c : str) {
        if (isdigit(c)) {
            a += c;
        }
        else {
            q.push(a);      
            a = "";
            a += c;
            q.push(a);      
            a = "";
        }
    }
    q.push(a);  

    bool isMinus = false;
    int sum = 0;

    while (!q.empty()) {
        string numStr = q.front();
        q.pop();
        int num = stoi(numStr);

        if (isMinus) {
            sum -= num;
        }
        else {
            sum += num;
        }

        if (!q.empty()) {
            string op = q.front();
            q.pop();
            if (op == "-") {
                isMinus = true;
            }
        }
    }

    cout << sum;
    return 0;
}
