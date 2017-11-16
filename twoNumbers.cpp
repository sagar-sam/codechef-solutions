#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a,b,n;
		scanf("%lld %lld %lld",&a,&b,&n);
		long long int ans;
		if(n%2==0)
		{
			ans=(a>b)?(a/b):(b/a);
			printf("%lld\n",ans);
		}
		else 
		{
			a=2*a;
			ans=(a>b)?(a/b):(b/a);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
