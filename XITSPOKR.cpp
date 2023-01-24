#include <iostream>
using namespace std;
typedef long long ll;

bool a[100005];
int main()
{
	int i, j, k, n;
	ll x;
	cin >> n >> x;
	ll res = 1;
	for (i = 0; i < n; i++)
		cin >> a[i];
	k = a[0];
	i = 0;
	j = 0;
	if (x == 1)
	{
		res = 0;
		for (i = 0; i < n; i++)
			res += !a[i];
		cout << res << endl;
		return 0;
	}
	while (true)
	{
		if (i == n - 1)
		{
			break;
		}
		if ((k << 1) + a[i + 1] < x)
		{
			k <<= 1;
			k += a[i + 1];
			res += (i - j + 2);
			i++;
		}
		else
		{
			k -= (1 << (i - j)) * a[j];
			j++;
		}
	}
	cout << res;

	return 0;
}