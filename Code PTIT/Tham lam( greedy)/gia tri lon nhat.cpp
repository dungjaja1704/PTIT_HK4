#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long x, s = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x + abs(x);
	}
	cout << s;
}