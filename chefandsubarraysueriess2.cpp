#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	int n,q,l,r;
	scanf("%d%d%d%d",&n,&q,&l,&r);
	map<int,int> mp;
	while(q--)
	{
		int type,x,y;
		if(type==1)
		{
			x--;
			if(y<l)
			{
				mp[x]=0;
			}
			else if(y>=l && y<=r)
			{
				mp[x]=1;
			}
			else if(y>r)
			{
				mp[x]=2;
			}
		}
		else if(type==2)
		{
			x--;
			y--;
			long long int ans=0;
			map<int,int>::iterator tempit=NULL;
			for(map<int,int>::iterator it=mp.begin;it!=mp.end();it++)
			{
				if(it->first>y)
				{
					break;
				}
				else if(it->first>=x && it->first<=y)
				{
					if(it->second==1)
					{
						if(tempit==NULL)
						{
							ans=ans+(long long int)(it->first-x+1);
						}
						map<int,int>::iterator it2=it;
						while(it2!=mp.end() && (it2->second==1 || it2->second==0))
						{
							it2++;
						}
						it2--;
						
						it=it2;
					}
					tempit=it;
				}
			}
		}
	}
}