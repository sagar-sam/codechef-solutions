#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,v1,v2;
		scanf("%d%d%d",&n,&v1,&v2);
		double ans1=(double)(n)*(double)(sqrt(2))/(double)(v1);
		double ans2=(double)(n)*(double)(2)/(double)(v2);
		if(ans1>ans2)
			printf("Elevator\n");
		else
			printf("Stairs\n");
	}
}