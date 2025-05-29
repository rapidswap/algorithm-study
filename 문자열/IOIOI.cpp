#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    string S;
    cin >> N >> M >> S;

    int answer = 0;
    int count = 0;  

    for (int i = 1; i < M - 1; i++) {

        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
            count++;
            i++;  

            if (count == N) {
                answer++;
                count--;  
            }
        }
        else {
            count = 0;  
        }
    }

    cout << answer << "\n";
    return 0;
}
