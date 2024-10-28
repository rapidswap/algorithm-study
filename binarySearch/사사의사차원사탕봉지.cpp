#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> candies(M);
    for (int i = 0; i < M; ++i) {
        cin >> candies[i];
    }

    vector<long long> prefixSum(M);
    prefixSum[0] = candies[0];
    for (int i = 1; i < M; ++i) {
        prefixSum[i] = prefixSum[i - 1] + candies[i];
    }

    vector<pair<long long, int>> children(N); 
    for (int i = 0; i < N; ++i) {
        cin >> children[i].first;
        children[i].second = i;
    }

    sort(children.begin(), children.end());

    vector<int> results(N, -1);
    int currentDraw = 0;

    for (const auto& child : children) {
        long long requiredCandy = child.first;
        int index = child.second;

        while (currentDraw < M && prefixSum[currentDraw] < requiredCandy) {
            ++currentDraw;
        }

        if (currentDraw < M && prefixSum[currentDraw] >= requiredCandy) {
            results[index] = currentDraw + 1;
        }
    }

    for (const auto& result : results) {
        if (result == -1) {
            cout << "Go away!\n";
        }
        else {
            cout << result << "\n";
        }
    }

    return 0;
}
