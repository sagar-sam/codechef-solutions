#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	vector<int> vec(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&vec[i]);
	}
	while(q--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			vec[b-1]=c;
		}
		if(a==2)
		{
			int x=0;
			int ans=0;
			for(int i=0;i<b;i++)
			{
				x=x^vec[i];
				if(x==c)
					ans++;
			}
			printf("%d\n",ans);
		}
	}
}