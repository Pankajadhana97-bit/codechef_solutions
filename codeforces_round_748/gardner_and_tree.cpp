#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n, k;
	cin >> n >> k;

	if (n == 1)
	{
		cout << 0 << "\n";
		return;
	}

	vector<int> g[n + 1];
	vector<int> conn(n + 1, 0);
	vector<bool> vis(n + 1, false);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		conn[a]++;
		conn[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (conn[i] == 1)
		{
			q.push(i);
			vis[i] = true;
		}
	}

	for (int j = 2; j <= k and !q.empty(); j++)
	{
		int s = q.size();
		while (s-- > 0 && !q.empty())
		{
			int u = q.front();
			q.pop();
			for (auto v : g[u])
			{
				conn[v]--;
				if (conn[v] == 1)
					q.push(v), vis[v] = true;
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
			continue;
		else
			ans++;
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