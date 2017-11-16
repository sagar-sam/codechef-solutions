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
		int ans;
		int max=10000000;
		int a;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a<max)
			{
				max=a;
				ans=i+1;
			}
		}
		printf("%d\n",ans);
	}
}