#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    int zero = 0, one = 0;
    for (char c : s) {
        if (c == '0') zero++;
        else one++;
    }

    int remove_zero = zero / 2;
    int remove_one = one / 2;

    string result;

    for (char c : s) {
        if (c == '1' && remove_one > 0) {
            remove_one--;
        }
        else {
            result += c;
        }
    }

    string final_result;
    for (int i = result.size() - 1; i >= 0; i--) {
        if (result[i] == '0' && remove_zero > 0) {
            remove_zero--;
        }
        else {
            final_result += result[i];
        }
    }

    reverse(final_result.begin(), final_result.end());
    cout << final_result;

    return 0;
}
