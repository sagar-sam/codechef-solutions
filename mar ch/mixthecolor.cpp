#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		map<int,int> mp;
		for(int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			mp[a]++;
		}
		int ans=0;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			ans=ans+(it->second-1);
		}
		printf("%d\n",ans);
	}
}