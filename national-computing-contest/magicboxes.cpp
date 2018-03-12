#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=ans+i+k;
		}
		ans=ans-k;
		printf("%d\n",ans);
	}
}