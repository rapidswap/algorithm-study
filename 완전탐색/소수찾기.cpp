#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
set<int> numberSet;

void re(string comb, string others)
{
    
    if (comb != "")
        numberSet.insert(stoi(comb));
    for (int i = 0; i < others.size(); i++)
    {
        re(comb + others[i], others.substr(0, i) + others.substr(i + 1));
    }
}

bool isPrime(int number)
{
    if (number == 0 || number == 1)
    {
        return false;
    }
    int lim = sqrt(number);
    for (int i = 2; i <= lim; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    re("", numbers);
    for (int number : numberSet)
    {
        if (isPrime(number))
        {
            answer++;
        }
    }
    return answer;
}//https://coding-grandpa.tistory.com/91
