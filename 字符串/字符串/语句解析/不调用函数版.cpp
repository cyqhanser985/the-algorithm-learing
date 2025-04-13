#include <bits/stdc++.h>
using namespace std;

int main(){
    map<char,int> s;
    string s1;
    cin>>s1;
    int l = s1.length();
    int n = l/4;
    for(int i=0;i<n;i++){
        char c1 = s1[5*i];
        char c2 = s1[5*i+3];
        if(c2>='0' && c2<='9') s[c1]=c2-'0';
        else{
            if(s.find(c2)!=s.end()) s[c1]=s[c2];
            else {
                s[c1]=0;
                s[c2]=0;
            }
        }
    }
    cout<<s['a']<<" "<<s['b']<<" "<<s['c']<<endl;
}
