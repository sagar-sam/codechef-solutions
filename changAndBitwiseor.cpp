#include <iostream>
#include <stdio.h>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		map<long long int,long long int> mp;
		long long int n;
		scanf("%lld",&n);
		long long int ans = 0;
		long long int x;
		for(long long int i=0;i<n;i++)
		{
			scanf("%lld",&x);
			ans=ans|x;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
