#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,b;
		scanf("%lld %lld",&n,&b);
		long long int ans;
		if(b>=n)
		{
			ans=0;
		}
		else
		{
			long long int m=n/2;
			if(b>=m)
			{
				ans=n-b;
			}
			else
			{
				long long int k=m%b;
				long long int l=m-k;
				long long int s=m+b-k;
				long long int x=(n-l)*(l/b);
				long long int y=(n-s)*(s/b);
				ans=(x>y)?x:y;
			}
		}
		printf("%lld\n",ans);
	}
}