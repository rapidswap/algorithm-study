#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;
typedef long long ll;

int N, L;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<float> w;
    cin >> N>>L;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        w.push_back(a);
    }

    sort(w.begin(), w.end());

    float range = 0;
    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (range < w[i] + 0.5) {
            range = w[i] - 0.5 + L;
            answer++;
        }
    }

    cout << answer;



    return 0;
}
