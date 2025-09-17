#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <stack>
#include <string>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    string find;

    getline(cin, word);
    getline(cin, find);

    if (find.size() > word.size()) {
        cout << 0;
        return 0;
    }

    int st = 0;
    int answer = 0;
    while (st <= word.size() - find.size()) {
        int cnt = 0;
        for (int i = st; i < st+find.size(); i++) {
            if (word[i] != find[i - st]) {
                st++;
                break;
            }
            cnt++;
            if (cnt == find.size()) {
                answer++;
                st = i + 1;
            }
        }

    }
    cout << answer;

    return 0;
}
