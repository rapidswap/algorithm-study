#include <string>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
int answer = INT_MAX;
// void func(int x, int n, int cnt,int y){
    
//     if(x>y){
//         return;
//     }
//     else if(x==y){
//         answer=min(answer,cnt);
//         return;
//     }
//     func(x+n,n,cnt+1,y);
//     func(x*2,n,cnt+1,y);
//     func(x*3,n,cnt+1,y);
// }


int solution(int x, int y, int n) {
    // func(x,n,0,y);
    // if(answer==INT_MAX) answer=-1;
    
    vector<int> vist(1000001,0);
    queue<int> q;
    q.push(x);
    
    while(!q.empty()){
        int cur=q.front();q.pop();
        
        if(cur==y) return vist[cur];
        
        int dn[]={cur+n,cur*2,cur*3};
        
        for(int i=0;i<3;i++){
            int nn=dn[i];
            if(nn>y||vist[nn]!=0) continue;
            vist[nn]=vist[cur]+1;
            q.push(nn);
        }
    }
    return -1;
}
