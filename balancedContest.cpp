#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,p;
		scanf("%d%d",&n,&p);
		int x=p/2;
		int y=p/10;
		int countx=0,county=0;
		for(int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			if(a>=x)
				countx++;
			if(a<=y)
				county++;
		}
		if(countx==1 && county==2)
			printf("yes\n");
		else printf("no\n");
	}
}