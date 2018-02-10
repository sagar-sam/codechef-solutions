#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		int flag1=0;
		int flag2=0;
		int temp;
		scanf("%d",&temp);
		a=temp;
		scanf("%d",&temp);
		if(temp==a)
		{
			flag1=1;
			scanf("%d%d",&a,&b);
			if(a==b)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else
		{
			b=temp;
			int x,y;
			scanf("%d%d",&x,&y);
			if(a==x && b==y)
			{
				printf("YES\n");
			}
			else if(a==y && b==x)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
}