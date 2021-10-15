#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int sz = (int)2e6 + 10;

	vector<int> A(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x]++;
		A[i] = x + sz;
	}

	for (auto &[a, b] : mp)
	{
		if (b * 2 >= n)
		{
			cout << -1 << "\n";
			return;
		}
	}
	sort(A.begin(), A.end());
	int ans = 0;
	vector<int> hsh(sz);
	vector<int> str(n);
	for (int itr = sz; itr >= 0; --itr)
	{
		for (int j = 0; j < n; j++)
		{
			str[j] = A[j] % itr;
			hsh[str[j]]++;
		}
		int mx = 0;
		for (int j = 0; j < n; j++)
		{
			mx = max(mx, hsh[str[j]]);
			hsh[str[j]]--;
		}
		if (mx * 2 >= n)
		{
			ans = itr;
			break;
		}
	}
	(ans == sz) ? cout << -1 : cout << ans;
	cout << "\n";
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