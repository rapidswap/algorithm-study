#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> word;
    int num=1;
    for (char C = 'A'; C <= 'Z'; C++){
        string str = ""; str += C;
        word[str] = num++;	
        }
    
    string str="";
    for(int i=0;i<msg.size();i++){
        str+=msg[i];
        
        if(word[str]==0){
            word[str]=num++;
            str=str.substr(0,str.size()-1);
            answer.push_back(word[str]);
            str="";
            i--;
        } 
    }
    answer.push_back(word[str]);
    
    return answer;
}
