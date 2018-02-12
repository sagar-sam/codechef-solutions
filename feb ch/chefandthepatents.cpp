#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,x,k;
		scanf("%d%d%d%d",&n,&m,&x,&k);
		string s;
		cin>>s;
		int even=0;
		int odd=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='E')
				even++;
			else odd++;
		}
		int cur=0;
		for(int i=1;i<=m;i++)
		{
			if(i%2==0)
			{
				if(even<x)
				{
					cur=cur+even;
					even=0;
				}
				else
				{
					cur=cur+x;
					even=even-x;
				}
			}
			else
			{
				if(odd<x)
				{
					cur=cur+odd;
					odd=0;
				}
				else
				{
					cur=cur+x;
					odd=odd-x;
				}
			}
		}
		if(cur>=n)
			printf("yes\n");
		else printf("no\n");
	}
}