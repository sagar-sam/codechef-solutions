#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,r;
		scanf("%d%d",&n,&r);
		vector<int> vec(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&vec[i]);
		}
		if(n==1)
		{
			printf("YES\n");
		}
		else
		{
			int lo=0;
			int hi=INT_MAX;
			int flag=0;
			for(int i=0;i<n-1;i++)
			{
				if(vec[i]<hi && vec[i]>lo)
				{
					if(vec[i]>r)
					{
						hi=vec[i];
					}
					else if(vec[i]<r)
					{
						lo=vec[i];
					}
					else
					{
						flag=1;
						break;
					}
				}
				else
				{
					flag=1;
					break;
				}
			}
			if(flag)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
		}
	}
}