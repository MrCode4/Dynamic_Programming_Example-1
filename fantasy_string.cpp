#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5;

int dp[maxn][2], n;

string s;

int is_lower(char c)
{
	return (c <= 'z' && c >= 'a');
}

int main()
{
	cin >> s;
	n = s.size();

	for(int i=n-1;i>=0;i--)
	{
		if(is_lower(s[i]))
		{
			dp[i][0] = dp[i+1][0];
			dp[i][1] = min(1+dp[i+1][1] , 1+dp[i+1][0]);			
		}
		else
		{
			dp[i][0] = 1+dp[i+1][0];
			dp[i][1] = min(dp[i+1][1] , dp[i+1][0]);	
		}
	}

	cout << min(dp[0][0], dp[0][1]);

	return 0;
}