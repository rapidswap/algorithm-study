#include<bits/stdc++.h>
void minimumBribes(vector<int> q) {
    int cnt=0;
    bool ischao =false;
    for(int i = 0; i< q.size(); i++)
    {
        if(q[i]>i+3){ 
            cout<<"Too chaotic"<<endl;
            ischao=true;
            break;
        }
        else{
            for(int j = q[i]-2 > 0? q[i]-2:0; j<i; j++)
                if(q[j]>q[i]) cnt++;
        }
    }
    if(!ischao)
        cout<<cnt<<endl;
    
}
