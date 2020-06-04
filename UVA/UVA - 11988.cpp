#include<bits/stdc++.h>

using namespace std;

void solve(string s){
    deque<string>d;
    string cur = "";
    bool bl = true;

    for(int i=0;i<s.size();i++){
        if(s[i]=='['){
            if(cur.size()>0){
                if(bl){
                    d.push_back(cur);
                }
                else{
                    d.push_front(cur);
                }
            }
            cur="";
            bl=false;
        }
        else if(s[i]==']'){
            if(cur.size()>0){
                if(bl){
                    d.push_back(cur);
                }
                else{
                    d.push_front(cur);
                }
            }
            cur="";
            bl=true;
        }
        else{
            cur+=s[i];
        }
    }
    if(cur.size()>0){
        if(bl){
            d.push_back(cur);
        }
        else{
            d.push_front(cur);
        }
    }
    while(!d.empty()){
        string p = d.front();
        d.pop_front();
        cout<<p;
    }
    cout<<"\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;

    while(cin>>s){
        solve(s);
    }
}
