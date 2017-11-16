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
		if(n%2==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(i%2!=0)
				{
					printf("%d ",i+1);
				}
				else
					printf("%d ",i-1);
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(i==n-1)
				{
					printf("%d %d ",n,n-2);
					break;
				}
				else if(i%2!=0)
					printf("%d ",i+1);
				else
					printf("%d ",i-1);
			}
		}
	}
}