#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    map<char,int> m;
    m['a']=0; m['b']=0; m['c']=0;
    while(s.length()!=0){
        size_t pos1 = s.find_first_of(':');
        size_t pos2 = s.find_first_of(';');
        char c1 = s[pos1-1];
        char c2 = s[pos2-1];
        if(isdigit(c2)) m[c1]=c2-'0';
        else m[c1]=m[c2];
        s = s.substr(pos2+1);
    }
    cout<<m['a']<<" "<<m['b']<<" "<<m['c']<<endl;
    return 0;
}
