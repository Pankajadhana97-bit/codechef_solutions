#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	int ans = 1e9 + 10;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int value = (s[i] - '0') * 10 + (s[j] - '0');
			if (value % 25 == 0)
			{
				ans = min(ans, n - i - 2);
			}
		}
	}
	cout << ans << "\n";
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 1;
	cin >> T;
	while (T--)
		solve();
	cerr << "[Time elapsed : " << (double)clock() / CLOCKS_PER_SEC << "]\n";
}