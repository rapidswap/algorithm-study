#include <iostream>
#include <vector>
#include <cmath>
#include<string>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false; 
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B;
    string D;
    vector<string> num;
    int answer = 0;
    cin >> A >> B >> D;

    for (int i = A; i <= B; ++i)
    {
        if (isPrime(i))
        {
            num.push_back(to_string(i));
        }
    }

    for (int i = 0; i < num.size(); i++)
    {
        if (num[i].find(D) != string::npos) {
            
            answer++;
        }
    }

    cout << answer;
    return 0;
}
