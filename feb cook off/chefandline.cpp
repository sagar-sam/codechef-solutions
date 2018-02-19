#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,k,b;
		scanf("%lld%lld%lld",&n,&k,&b);
		vector<pair<long long int,long long int>> vec;
		for(int i=0;i<n;i++)
		{
			long long int x;
			scanf("%lld",&x);
			long long int val=x*k+b;
			vec.push_back(make_pair(val,x));
		}
		sort(vec.begin(),vec.end());
		long long int ans=1;
		long long int prev=vec[0].first;
		for(int i=1;i<vec.size();i++)
		{
			if(vec[i].second>=prev)
			{
				ans++;
				prev=vec[i].first;
			}
		}
		printf("%d\n",ans);
	}
}