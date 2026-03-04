#include<iostream>
#include<string>
#include<stdlib.h>
#include<unordered_map>
#include<vector>
using namespace std;
unordered_map<string, int> umap;
int mx = -1;
string longest_bi;

void bi(string str){
    if(str.length() == 1) return;
    for(int i=0;i<str.length()-1;i++){
        string temp = str.substr(i,2);
        umap[temp]++;
        if(umap[temp] > mx){
            mx = umap[temp];
            longest_bi = temp;
        }
    }
}
vector<string> sep(string str, char del) {
    vector<string> res;
    string s;
    for(char c : str) {
        if(c != del) s += c;
        else {
            if(!s.empty()) {
                res.push_back(s);
                s.clear();
            }
        }
    }
    if(!s.empty()) {
        res.push_back(s);
    }
    return res;
}
int main()
{
    string s;
    vector<string> temp, v;
    while(getline(cin, s) and !s.empty()) temp.push_back(s);
    for(string i:temp){
        for(string j: sep(i, ' ')) v.push_back(j);
    }
    unordered_map<string, bool> printed;
    for(string s:v) bi(s);
    for(string s:v){
        if(printed.find(s) != printed.end()) continue;
        if(s.find(longest_bi) != string::npos and s.length() != 1){
            cout<<s<<'\n';
            printed[s] = true;
        }
    }
}