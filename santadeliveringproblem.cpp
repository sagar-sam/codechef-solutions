#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

float euclid(int x1,int y1,int x2, int y2)
{
	return sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,g,cap,x,y;
		scanf("%d%d%d%d%d",&n,&g,&cap,&x,&y);
		vector<int> gift_volume(g);
		for(int i=0;i<g;i++)
		{
			scanf("%d",&gift_volume[i]);
		}
		vector<int> childx(n);
		vector<int> childy(n);
		vector<int> last(n);
		vector<int> present(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&childx[i],&childy[i],&last[i],&present[i]);
		}
		vector<pair<int,int>> ans;
//		queue<pair<int,int>> ans;
		//queue<int> q;
		vector<int> q;
		vector<int> taken(n);
		vector<int> back(n);
//		vector<int> count(g);
		for(int i=0;i<n;i++)
		{
			back[i]=0;
			taken[i]=0;
		}
		//for(int i=0;i<n;i++)
		//{
			//if(last[i]==present[i])
		//		taken[i]=1;
		//}
		int a=x;
		int b=y;
		while(true)
		{
			int ind;
			float min=INT_MAX;
			for(int i=0;i<n;i++)
			{
				if(euclid(a,b,childx[i],childy[i])<min && taken[i]==0)
				{
					min=euclid(a,b,childx[i],childy[i]);
					ind=i;
				}
			}
			taken[ind]=1;
			q.push_back(ind);
			a=childx[ind];
			b=childy[ind];
			int flag=0;
			for(int i=0;i<n;i++)
			{
				if(taken[i]==0)
					flag=1;
			}
			if(flag==0)
				break;
		}
//		vector<int> baggift;
//		int cap=b;
		int temp=0;
		int j=0;
		for(int i=0;i<q.size();i++)
		{
			if(temp+gift_volume[present[q[i]]-1]<=cap)
			{
				temp=temp+gift_volume[present[q[i]]-1];
				ans.push_back(make_pair(2, present[q[i]]));
//				pair<int,int> p=make_pair(2, present[q[i]]);
			}
			else
			{
				vector<int> lol;
				while(j<i)
				{
					ans.push_back(make_pair(1, q[j]+1));
					ans.push_back(make_pair(3, present[q[j]]));
					temp=temp-gift_volume[present[q[j]]-1];
					if(temp+gift_volume[last[q[j]]-1]<=cap)
					{
						temp=temp+gift_volume[last[q[j]]-1];
						ans.push_back(make_pair(2, last[q[j]]));
						lol.push_back(j);
						back[q[j]]=1;
					}
					j++;
				}
				ans.push_back(make_pair(1, 0));
				for(int sa=0;sa<lol.size();sa++)
				{
					ans.push_back(make_pair(3, last[q[lol[sa]]]));
					temp=temp-gift_volume[last[q[lol[sa]]]-1];
				}
				temp=gift_volume[present[q[i]]-1];
				ans.push_back(make_pair(2, present[q[i]]));
				lol.clear();
			}
		}
		vector<int> bshai;
		while(j<q.size())
		{
			ans.push_back(make_pair(1, q[j]+1));
			ans.push_back(make_pair(3, present[q[j]]));
			temp=temp-gift_volume[present[q[j]]-1];
			if(temp+gift_volume[last[q[j]]-1]<=cap)
			{
				temp=temp+gift_volume[last[q[j]]-1];
				ans.push_back(make_pair(2, last[q[j]]));
				bshai.push_back(j);
				back[q[j]]=1;
			}
			j++;
		}
		ans.push_back(make_pair(1,0));
		for(int sa=0;sa<bshai.size();sa++)
		{
			ans.push_back(make_pair(3, last[q[bshai[sa]]]));
			temp=temp-gift_volume[last[q[bshai[sa]]]-1];
		}
//		printf("a   %d",temp);
		temp=0;
		j=0;
		for(int i=0;i<q.size();i++)
		{
			if(back[q[i]]==0)
			{
				if(temp+gift_volume[last[q[i]]-1]<=cap)
				{
					temp=temp+gift_volume[last[q[i]]-1];
					ans.push_back(make_pair(1, q[i]+1));
					ans.push_back(make_pair(2, last[q[i]]));
				}
				else
				{
					ans.push_back(make_pair(1,0));
					while(j<i)
					{
						if(back[q[j]]==0)
							ans.push_back(make_pair(3, last[q[j]]));
						j++;
					}
					temp=gift_volume[last[q[i]]-1];
					ans.push_back(make_pair(1, q[i]+1));
					ans.push_back(make_pair(2, last[q[i]]));
				}
			}
		}
		ans.push_back(make_pair(1,0));
		for(int i=0;i<ans.size();i++)
		{
			printf("%d %d\n",ans[i].first,ans[i].second);
		}
		printf("0\n");
	}
}