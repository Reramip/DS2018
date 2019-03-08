#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;

set<pair<int,string> > s;
map<string, int> m;

int main(void)
{
	int n, p, y;
	string x;
	cin >> n;
	while (n--)
	{
		cin >> p;
		if(p==1)
		{
			cin >> x >> y;
			if (m[x] != 0) continue;
			s.insert(make_pair(y, x));
			m[x] = y;
		}
		else if(p==2)
		{
			cin >> x;
			if (m[x] == 0 || s.empty()) continue;
			s.erase(make_pair(m[x], x));
			m[x] = 0;
		}
		else if(p==3)
		{
			cin >> x >> y;
			if (m[x] == 0 || s.empty()) continue;
			s.erase(make_pair(m[x], x));
			s.insert(make_pair(y, x));
			m[x] = y;
		}
		else if(p==4)
		{
			cin >> y;
			if (s.empty()) continue;
			set<pair<int, string> >::iterator it;
			if (y == 1)
			{
				it = s.begin();
				cout << it->second << endl;
			}
			else if (y == 2)
			{
				it = s.end();
				it--;
				cout << it->second << endl;
			}
		}
	}
	return 0;
}