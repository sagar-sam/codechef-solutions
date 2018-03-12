#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	if(b==0)
		return a;
	else return gcd(b,a%b);
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		scanf("%d",&vec[i]);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--;
			vec[x]=y;
		}
		else
		{
			int l,r,g;
			scanf("%d%d%d",&l,&r,&g);
			l--;
			r--;
			int count=0;
			for(int i=l;i<=r;i++)
			{
				if(gcd(g,vec[i])==1)
					count++;
			}
			printf("%d\n",count);
		}
	}
}