#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int a, b, c;
	cin >> a >> b >> c;
	int mx = max(a, max(b, c));

	if (a == b and a != c and a == mx)
	{
		cout << 1 << " " << 1 << ' ' << mx - c + 1 << endl;
		return;
	}
	if (a != b and b == c and b == mx)
	{
		cout << mx - a + 1 << " " << 1 << " " << 1 << endl;
		return;
	}
	if (a == c and b != c and mx == c)
	{
		cout << 1 << " " << mx - b + 1 << " " << 1 << " " << endl;
		return;
	}
	if (a == b and b == c and c == a)
	{
		cout << 1 << " " << 1 << " " << 1 << endl;
		return;
	}
	(a == mx) ? a = 0 : a = mx - a + 1;
	(b == mx) ? b = 0 : b = mx - b + 1;
	(c == mx) ? c = 0 : c = mx - c + 1;

	cout << a << " " << b << " " << c << "\n";
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