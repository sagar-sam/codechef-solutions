#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	vector<int> vec(n);
	map<int,int> mp[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&vec[i]);
		int a=vec[i];
		int j=0;
		while(j<31)
		{
			if(a%2==1)
			{
				mp[i][j]++;
			}
			a=a/2;
			if(i!=0)
			mp[i][j]+=mp[i-1][j];
			j++;
		}
	}
	while(q--)
	{
		int l,r;
		int ans=0;
		scanf("%d%d",&l,&r);
		l--;
		r--;
		for(int i=0;i<31;i++)
		{
			int c=mp[r][i];
			if(l!=0)
			{
				c=c-mp[l-1][i];
			}
			int s=r-l+1;
			s=s-c;
			if(c<s)
			{
				ans=ans+(1<<i);
			}
		}
		printf("%d\n",ans);
	}
}