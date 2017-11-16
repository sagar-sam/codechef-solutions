#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		vector<int> vec(n);
		int a,b;
		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&a,&b);
			vec[a-1]=b;
		}
		vector<int> prev(n);
		vector<int> after(n);
		int x=-1;
		for(int i=0;i<n;i++)
		{
			if(vec[i]!=0)
				x=i;
			prev[i]=x;
		}
		x=n;
		for(int i=n-1;i>=0;i--)
		{
			if(vec[i]!=0)
				x=i;
			after[i]=x;
		}
		long long int count=0;
		for(int i=0;i<n;i++)
		{
			int x=i;
			int y=i;
			int z=i-prev[i];
			int s=after[i]-i;
			count+=min(z,s);
			while(z>=0 && s<n && z==s)
			{
				z=x-z;
				x=z;
				s=y+s;
				y=s;
				z=z-prev[z];
				s=after[s]-s;
				count+=min(z,s);
			}
		}
		printf("%lld\n",count);
	}
}