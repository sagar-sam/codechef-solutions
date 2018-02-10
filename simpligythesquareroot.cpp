#include <iostream>
//#include <set>
#include <vector>
#include <math.h>
//#include <iterator>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	long long int n;
	scanf("%lld",&n);
	long long int m=3*n;
	long long int x=sqrt(m);
	vector<long long int> vec;
	//set<long long int> s;
	map<long long int,int> mp;
	for(long long int i=4;i<=m;i=i+4)
	{
		vec.push_back(i);
		mp[i]++;
	}
	for(long long int i=3;i<=x;i=i+2)
	{
		long long int sa=i*i;
		if(mp[sa]==0)
		{
			for(long long int j=sa;j<=m;j=j+sa)
			{
				if(mp[j]==0)
				{
					mp[j]++;
//					s.insert(j);
					vec.push_back(j);
				//	printf(" %d ",j);
				}
	//			s.insert(j);
			}
		}
	}
	sort(vec.begin(),vec.end());
	printf("%lld\n",vec[n-1]);
//	set<long long int>::iterator it = s.begin();
//	while(n--)
//	{
//		it++;
//	}
//	it--;
//	printf("%lld\n",*it);
}