#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n;
int friends[15][15];

void Input();

void Solve(){
    for(int i=1;i<=5;i++){
        for(int j=i+1;j<=5;j++){
            for(int k=j+1;k<=5;k++){
                if(friends[i][j]==1 and friends[i][k]==1 and friends[j][k]==1){
                    cout<<"Happy Doggos!\n";
                    return;
                }
                if(friends[i][j]==0 and friends[i][k]==0 and friends[j][k]==0){
                    cout<<"Happy Doggos!\n";
                    return;
                }
            }
        }
    }

    cout<<"Sad Doggos...";
}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Input();
    Solve();
    Clear();

}

void Input(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        friends[a][b] = 1;
        friends[b][a] = 1;
    }
}
