#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		long long int ans=0;
		for(int i=0;i<n;i++)
		{
			long long int min;
			long long int max;
			long long int a;
			scanf("%lld",&a);
			max=a;
			min=a;
			for(int i=1;i<n;i++)
			{
				scanf("%lld",&a);
				if(a>max)
					max=a;
				if(a<min)
					min=a;
			}
			ans=ans+(max-min);
		}
		printf("%lld\n",ans);
	}
}