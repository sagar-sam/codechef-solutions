#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> vec(n);
		vector<int> mod(4);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&vec[i]);
			mod[vec[i]%4]++;
		}
		int flag=0;
		int ans=0;
		if(mod[3]<mod[1])
		{
			mod[1]=mod[1]-mod[3];
			ans=mod[3];
			mod[3]=0;
			//printf("-1\n");
			//continue;
			//flag=1;
			if(mod[1]%2!=0)
			{
				printf("-1\n");
				continue;
			}
			mod[1]=mod[1]/2;
			ans+=mod[1];
			mod[2]=mod[2]+mod[1];
			if(mod[2]%2!=0)
			{		
				printf("-1\n");
				continue;
			}
		}
		else
		{
			mod[3]=mod[3]-mod[1];
			ans=mod[1];
			mod[1]=0;
//			mod[1]=mod[1]-mod[3];
			if(mod[3]%2!=0)
			{
				printf("-1\n");
				continue;
			}
			mod[3]=mod[3]/2;
			ans+=mod[3];
			mod[2]=mod[2]+mod[3];
			if(mod[2]%2!=0)
			{
				printf("-1\n");
				continue;
			}
		}
//		int ans=mod[3];
		ans=ans+mod[2]/2;
		printf("%d\n",ans);
	}
}