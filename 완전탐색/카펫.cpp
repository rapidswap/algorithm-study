#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector <pair<int, int>> factors;

void findFactors(int target)
{

    for (int i = 1; i <= target; i++)
    {
        if(target%i == 0)
        { 
            int a = target / i;
            factors.push_back({ a, i });
        }
    }
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    findFactors(total);
    for (auto pair : factors)
    {
        if (yellow == (pair.first - 2) * (pair.second - 2))
        {
            answer.push_back(pair.first);
            answer.push_back(pair.second);
            break;
        }
    }

    return answer;
}
