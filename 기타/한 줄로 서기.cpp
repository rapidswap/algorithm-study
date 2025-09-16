#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<map>
using namespace std;
typedef long long ll;

int n, m;
int answer[10] = { 0 };
int arr[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

   
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int j = 0;
        while (arr[i] != 0) {
            if (answer[j] == 0) {
                arr[i]--;
            }
            j++;
        }
        while (answer[j] != 0) j++;
        answer[j] = i + 1;
    }
    
    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }
    return 0;
}
