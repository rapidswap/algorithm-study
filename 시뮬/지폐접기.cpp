#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
     if(bill[0]<=wallet[0] && bill[1]<=wallet[1])
     {
         return answer;
     }
    sort(wallet.begin(),wallet.end(),greater<int>());
    while(1)
    {
        sort(bill.begin(),bill.end(),greater<int>());
        bill[0]=bill[0]/2;
        sort(bill.begin(),bill.end(),greater<int>());
        if(bill[0]<=wallet[0] && bill[1]<=wallet[1])
        {
            answer++;
            break;
        }
        answer++;
    }
    return answer;
}
