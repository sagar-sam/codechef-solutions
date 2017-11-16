#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int y;
		scanf("%lld",&y);
		long long int ans=0;
		for(long long int b=1;b<=700;b++)
		{
			long long int a=y-b;
			if(a>=1)
			{
			long long int x=sqrt(a);
			ans+=x;
			}
			else break;
		}
		printf("%lld\n",ans);
	}
}