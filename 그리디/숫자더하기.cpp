#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include<string>
using namespace std;
vector<int> answer;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        vector<int> numbers;

        int N;
        int zero = 0;
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            if (num == 0) zero++;
            numbers.push_back(num);
        }
        sort(numbers.begin(), numbers.end());
        if (zero == 1)
        {
            swap(numbers[0], numbers[2]);
        }
        if (zero >= 2)
        {
            swap(numbers[0], numbers[zero]);
            swap(numbers[1], numbers[zero + 1]);
        }

        string l = "", r = "";
        for (int i = 0; i < numbers.size(); i++)
        {

            string now = to_string(numbers[i]);
            if (i % 2 == 0) l += now;
            else r += now;
        }

        cout << stoi(l) + stoi(r) << "\n";
    }
    return 0;
}//https://technicolour.tistory.com/20
