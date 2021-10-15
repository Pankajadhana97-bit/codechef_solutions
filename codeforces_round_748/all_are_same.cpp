#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (int &ai : A)
		cin >> ai;

	int mn = *min_element(A.begin(), A.end());

	int gcd = 0;
	for (int i = 0; i < n; i++)
	{
		A[i] = A[i] - mn;
		gcd = __gcd(gcd, A[i]);
	}
	(gcd == 0) ? cout << -1 : cout << gcd;
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