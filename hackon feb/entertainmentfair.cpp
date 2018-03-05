#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		long long int count=0;
		count=n/7;
		long long int ans=0;
		long long int current=7;
		while(count--)
		{
			ans=ans+current;
			current=current+7;
		}
		printf("%lld\n",ans);
	}
}