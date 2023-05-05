#include <iostream>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;

map<ll, ll>mp;
pair<ll, ll> arr[200005];
int main()
{
	int n, i, j;
	cin >> n;
	ll res = 0;
	ll k = 0;
	priority_queue<ll>q;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		q.push(arr[i].first);
		mp[arr[i].first]++;
	}
	for (i = 0; i < n; i++)
	{
		k += arr[i].second;
		mp[arr[i].first]--;
		if (arr[i].first == q.top())
		{
			res += k * arr[i].first;
			q.pop();
			k = 0;
			while (!q.empty())
			{
				if (mp[q.top()] != 0)
					break;
				q.pop();
			}
		}
	}
	cout << res << endl;

	return 0;
}
