#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

map<int,int> mp,fin;
vector<int> ne;

void factorize(int n) {
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n != 1) {
        mp[n]++;
    }
}

void to(int pro, map<int,int>::iterator it)
{
	it++;
	if(it==mp.end())
	{
		fin[pro]++;
		ne.push_back(pro);
		return;
	}
	int j=1;
	for(int i=0;i<=it->second;i++)
	{
		to(pro*j, it);
		j=j*it->first;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		mp.clear();
		ne.clear();
		fin.clear();
		int n,a,b,c;
		scanf("%d%d%d%d",&n,&a,&b,&c);
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		factorize(n);
		map<int,int>::iterator it = mp.begin();
		int j=1;
		for(int i=0;i<=it->second;i++)
		{
			to(j, it);
			j=j*it->first;
		}
		sort(ne.begin(),ne.end());
		int ans=0;
		for(int i=0;i<ne.size();i++)
		{
			if(ne[i]>a)
				break;
			for(int j=0;j<ne.size();j++)
			{
				if(ne[j]>b)
					break;
				long long int pro = (long long int)(ne[i])*(long long int)(ne[j]);
				if(n%pro!=0)
					continue;
				int f=n/pro;
				if(fin[f]!=0 && f<=c)
				{
//					printf("%d %d %d\n",ne[i],ne[j],f);
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}