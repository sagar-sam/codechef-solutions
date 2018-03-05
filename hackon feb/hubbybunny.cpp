#include <iostream>
#include <cmath>

#define ear 0.000001

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x1,y1,r1;
		int x2,y2,r2;
		scanf("%d%d%d",&x1,&y1,&r1);
		scanf("%d%d%d",&x2,&y2,&r2);
		int dis=r1+r2;
		int difx = abs(x2-x1);
		int dify = abs(y2-y1);
		float das = sqrt(dify*dify+difx*difx);
		if(das+ear>dis && das-ear<dis)
		{
			printf("tangential\n");
		}
		else if(das>dis)
		{
			printf("not overlapping\n");
		}
		else 
		{
			printf("overlapping\n");
		}
	}
}