#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	vector<long long int> vec(n);
	for(int i=0;i<n;i++)
		scanf("%lld",&vec[i]);
	for(int i=0;i<q;i++)
	{
		int a;
		scanf("%d",&a);
		if(a==1)
		{
			int j,k;
			scanf("%d%d",&j,&k);
			int x=j-1;
			while(j<n && k>0)
			{
				if(vec[j]>vec[x])
				{
					k--;
					x=j;
				}
				j++;
				if(j-x>100)
					break;
			}
			printf("%d\n",x+1);
		}
		else if(a==2)
		{
			long long int l,r,x;
			scanf("%lld%lld%lld",&l,&r,&x);
			for(int j=l-1;j<r;j++)
				vec[j]=vec[j]+x;
		}
	}
}
