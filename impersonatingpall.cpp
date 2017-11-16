#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s,m;
		scanf("%d%d",&s,&m);
		string a;
		cin>>a;
		map< char , vector<char> > mp;
		for(int i=0;i<m;i++)
		{
			int x;
			scanf("%d",&x);
			vector<char> vec(x);
			for(int j=0;j<x;j++)
				scanf(" %c",&vec[j]);
			//for(int j=0;j<x;j++)
			//	printf("%c   ",vec[j]);
			for(int j=0;j<x;j++)
			{
				for(int k=j+1;k<x;k++)
				{
					mp[vec[j]].push_back(vec[k]);
					mp[vec[k]].push_back(vec[j]);
				}
			}
		}
		int i=0;
		int j=a.length()-1;
		int flag=0;
		while(i<j)
		{
			if(a[i]!=a[j])
			{
				if(find(mp[a[i]].begin(),mp[a[i]].end(),a[j])==mp[a[i]].end())
				{
					flag=1;
					break;
				}
			}
			i++;
			j--;
		}
		if(flag==0)
		{
			printf("Impersonating\n");
		}
		else
		{
			printf("Not Impersonating\n");
		}
	}
}