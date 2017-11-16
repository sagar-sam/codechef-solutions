#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		vector<long long int> vec[n];
		for(long long int i=0;i<n;i++)
		{
			long long int m;
			scanf("%lld",&m);
			for(int j=0;j<m;j++)
			{
				long long int a;
				scanf("%lld",&a);
				vec[i].push_back(a);
			}
			sort(vec[i].begin(),vec[i].end());
		}
		long long int curmin=0;
		long long int curmax=0;
		long long int prevmin=0;
		long long int prevmax=0;
		for(long long int i=1;i<n;i++)
		{
			long long int mintomax = abs(vec[i][vec[i].size()-1]-vec[i-1][0])*i;
			long long int maxtomax = abs(vec[i][vec[i].size()-1]-vec[i-1][vec[i-1].size()-1])*i;
			long long int maxtomin = abs(vec[i][0]-vec[i-1][vec[i-1].size()-1])*i;
			long long int mintomin = abs(vec[i][0]-vec[i-1][0])*i;
			long long int min2tomax;
			long long int max2tomax;
			long long int max2tomin;
			long long int min2tomin;
			if(prevmax+mintomin>prevmin+maxtomin)
			{
				curmin=prevmax+mintomin;
			}
			else curmin = prevmin + maxtomin;
			if(vec[i-1].size()>=2)
			{
				max2tomin = abs(vec[i][0]-vec[i-1][vec[i-1].size()-2])*i;
				min2tomin = abs(vec[i][0]-vec[i-1][1])*i;
				if(curmin < prevmin + max2tomin)
					curmin = prevmin + max2tomin;
				if(curmin < prevmin + min2tomin)
					curmin = prevmin + min2tomin;
				if(curmin < prevmax + max2tomin)
					curmin = prevmax + max2tomin;
				if(curmin < prevmax + min2tomin)
					curmin = prevmax + min2tomin;
			}
			if(prevmin + maxtomax > prevmax+mintomax)
				curmax = prevmin + maxtomax;
			else curmax = prevmax + mintomax;
			if(vec[i-1].size()>=2)
			{
				min2tomax = abs(vec[i][vec[i].size()-1]-vec[i-1][1])*i;
				max2tomax = abs(vec[i][vec[i].size()-1]-vec[i-1][vec[i-1].size()-2])*i;
				if(curmax < prevmin + min2tomax)
					curmax = prevmin + min2tomax;
				if(curmax < prevmin + max2tomax)
					curmax = prevmin + max2tomax;
				if(curmax < prevmax + min2tomax)
					curmax = prevmax + min2tomax;
				if(curmax < prevmax + max2tomax)
					curmax = prevmax + max2tomax;
			}
			prevmax=curmax;
			prevmin=curmin;
			printf("%lld %lld\n",curmin,curmax );
		}
		if(curmax>curmin)
			printf("%lld\n",curmax);
		else printf("%lld\n",curmin);
	}
}