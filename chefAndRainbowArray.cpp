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
		for(int i=0;i<n;i++)
		{
			scanf("%d",&vec[i]);
		}
		vector<int> c(8);
		int flag=1;
		for(int i=0;i<n;i++)
		{
			while(i<n && vec[i]==flag)
			{
				i++;
				c[flag]++;
			}
			if(c[flag]==0)
			{
				flag=20;
				break;
			}
			i--;
			flag++;
			if(flag==8)
				break;
		}
		if(flag==20)
		{
			printf("no\n");
			continue;
		}
		for(int i=1;i<8;i++)
		{
			if(c[i]==0)
			{
				printf("no\n");
				flag=20;
				break;
			}
		}
		if(flag==20)
			continue;
		flag=1;
		for(int i=n-1;i>=0;i--)
		{
			int count=0;
			while(i>=0 && vec[i]==flag)
			{
				i--;
				count++;
			}
			if(c[flag]!=count)
			{
				//printf("%d  ",flag);
				flag=20;
				break;
			}
			flag++;
			if(flag==8)
				break;
			i++;
		}
		if(flag==20)
		{
			printf("no\n");
		}
		else
		{
			printf("yes\n");
		}
	}
}
