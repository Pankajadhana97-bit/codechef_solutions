#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n, k;
	cin >> n >> k;

	vector<int> A(k);
	for (int i = 0; i < k; i++)
		cin >> A[i];
	sort(A.begin(), A.end());

	int ans = 0;
	int sum = 0;
	for (int i = k - 1; i >= 0; i--)
	{
		sum += (n - A[i]);
		if (sum >= n)
			break;
		ans++;
	}
	cout << ans << endl;
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