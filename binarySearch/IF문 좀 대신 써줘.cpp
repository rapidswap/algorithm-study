#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<string, int>> titles;

    for (int i = 0; i < N; i++) {
        string title;
        int num;
        cin >> title >> num;
        titles.push_back({ title,num });
    }

    vector<int> users;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        users.push_back(num);
    }

    for (int i = 0; i < users.size(); i++) {
        int st = 0;
        int end = N;
        int res = 0;
        while (st <= end) {
            int mid = (st + end) / 2;
            if (users[i] <= titles[mid].second) {
                end=mid-1;
                res = mid;
            }
            else {
                st = mid + 1;
            }
        }
        cout << titles[res].first<<'\n';
    }

  
    return 0;
}
