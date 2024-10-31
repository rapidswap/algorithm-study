#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include<string>
using namespace std;

long long gcd(long long a, long long b)
{
    
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;
        cout << (a * b) / gcd(a, b) << "\n";
  

    }
    return 0;
}
