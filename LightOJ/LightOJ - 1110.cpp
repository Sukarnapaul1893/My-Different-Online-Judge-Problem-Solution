#include<bits/stdc++.h>
using namespace std;

string Minstring(string x, string y)
{
	if(x.length() < y.length()) {
		return y;
	}

	if(x.length() > y.length()) {
		return x;
	}

	for (int i = 0; i < x.length(); i++) {
		if(x[i] < y[i]) {
			return x;
		}

		if(x[i] > y[i]) {
			return y;
		}
	}
	return x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin>>t;
	for (int tt = 0; tt < t; tt++) {
        string x;
        string y;

		string dp[110][110];
        cin>>x>>y;

        int n;
        int m;
		n = x.length();
		m = y.length();

		for (int i = n; i >= 0; i--) {
			for (int j = m; j >= 0; j--) {
				if(i == n or j == m) {
					dp[i][j] = "";
					continue;
				}

				if(x[i] == y[j]) {
					dp[i][j] = x[i] + dp[i+1][j+1];
					continue;
				}

				dp[i][j] = Minstring(dp[i+1][j],dp[i][j+1]);
			}
		}

		if(dp[0][0].length() != 0) {
            cout<<"Case "<<tt+1<<": "<<dp[0][0]<<"\n";
		}

		else {
			cout<<"Case "<<tt+1<<": "<<":("<<"\n";
		}

	}

}
