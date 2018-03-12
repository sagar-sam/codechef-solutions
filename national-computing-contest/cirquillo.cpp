#include <iostream>
#include <vector>
#include <algorithm>

#define err 0.000001

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long long int a;
		vector<pair<long long int,long long int>> vec(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a);
			vec[i].first=a;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			vec[i].second=a;
		}
		sort(vec.beign(),vec.end());
		for(int i=1;i<n;i++)
		{
			long long int low=vec[i-1].first;
			long long int high=vec[i].first;
			while(low<=high)
			{
				long long int mid = low+high/2;
				
			}
		}
	}
}