#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<map>
using namespace std;
typedef long long ll;

int N,K;
int arr[200002];
int vist[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = -1;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }


    int ed = 0;
    for (int st = 0; st < N; st++) {
        while (ed < N && vist[arr[ed]] < K) {
            vist[arr[ed]]++;
            ed++;
        }
        answer = max(answer, ed - st);
        if (ed == N)break;
        vist[arr[st]]--;
    }

    cout << answer;
    return 0;
}
