#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long sum = 0;
    string words;
    cin >> n >> words;

    map<char, int> hash;
    int nums = 1;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        hash[ch] = nums++;
    }

    long long power = 1; // 31^0
    for (int i = 0; i < words.size(); i++) {
        sum = (sum + hash[words[i]] * power) % 1234567891;
        power = (power * 31) % 1234567891; 
    }

    cout << sum;
    return 0;
}
