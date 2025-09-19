#include <iostream>

using namespace std;
typedef long long ll;

ll X, Y, W, S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> X >> Y >> W >> S;
    ll answer = 0;

    ll sum1 = (X + Y) * W;
    ll sum2 = min(X, Y) * S;
    sum2 += min(abs(X - Y) * W, (abs(X - Y) % 2 == 1 ? (abs(X - Y) - 1) * S + W : abs(X - Y) * S));

    cout << min(sum1, sum2) << '\n';

    
    return 0;
}
