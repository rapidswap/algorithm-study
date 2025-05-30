#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;


int tomato[101][101][101];
int dist[101][101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        unordered_map<string, int> clothes;
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            string clt, part;
            cin >> clt >> part;
            clothes[part]++;
        }

        int answer = 1;
        for (auto c:clothes) {
            answer *= clothes[c.first] + 1;
        }
        cout << answer - 1<<'\n';
    }


    return 0;
}
