#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K, Q, M;
    cin >> N >> K >> Q >> M;
    vector<int> sleepstd;
    for (int i = 0; i < K; i++)
    {
        int sleep;
        cin >> sleep;
        sleepstd.push_back(sleep);
    }
    unordered_map<int, int> students;
    vector<int> checkStd;
    for (int i = 0; i < Q; i++)
    {
        int check;
        cin >> check;
        checkStd.push_back(check);
    }

    for (int i = 0; i < sleepstd.size(); i++)
    {
        for (int j = 0; j < checkStd.size(); j++)
        {
            if (sleepstd[i] == checkStd[j])
            {
                checkStd.erase(checkStd.begin()+j);
            }
        }
    }
    
    for (int i = 3; i <= N+2; i++)
    {
        students[i]++;
    }
    for(int i=0;i<checkStd.size();i++)
    {
        for (int j = 3; j <= N+2; j++)
        {
            if (j % checkStd[i] == 0)
            {
                students[j] = 0;
            }
            
        }
    }
    for (int i = 0; i < sleepstd.size(); i++)
    {
        students[sleepstd[i]]=1;
    }
    //for (auto it:students)
    //{
    //    cout << it.first << " "<<it.second << endl;
    //}
    //int gugan[50000][2];
    //for (int i = 0; i < M; i++)
    //{
    //    int S, E;
    //    cin >> S >> E;
    //    gugan[i][0]=S;
    //    gugan[i][1]=E;
    //}
    int pSum[5003];
    for(int i=4;i<=N+2;i++)
    {
        students[i] += students[i - 1];
    }
    
    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        cout << students[end] - students[start - 1] << '\n';
    }

    return 0;
} //endl 쓰지말고 위에 입출력 시간 줄여주기
