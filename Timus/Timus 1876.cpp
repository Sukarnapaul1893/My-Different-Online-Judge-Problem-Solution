#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    cin>>a>>b;

    cout<<max(39*2+40+(a-40)*2+1, 80 + (b-40)*2 + 40)<<"\n";
}
