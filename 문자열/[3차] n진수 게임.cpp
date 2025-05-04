#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string str="";
    
 
    int a=t*m;
    stack<int> bin;

    for(int i=0;str.size()<=a;i++){
        int num=i;
        while(1){
            bin.push(num%n);
            num/=n;
            if(num==0) break;
        }
        while(!bin.empty()){
            if(bin.top()<10)
                str+=to_string(bin.top());
            else
                str+=(char)(65+bin.top()-10);
            
            bin.pop();
        }
    }


    for(int i=p-1;t>0;i+=m){
        answer+=str[i];
        t--;
    }
    
    return answer;
}
