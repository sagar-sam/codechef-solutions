#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

struct node{
	int start;
	int end;
	map<int,int> mp;
	int x;
	int up;
};

vector<struct node> vec;

void update(int node, int start, int end, int x)
{
	if(vec[node].start>end || vec[node].end<start)
		return;
	if(vec[node].start>=start && vec[node].end<=end)
	{
		vec[node].x=vec[node].x^x;
		return;
	}
	update(2*node+1,start,end,x);
	update(2*node+2,start,end,x);
	vec[node].up=1;
}

int calculate(int node, int start, int end, int x)
{
	if(vec[node].start>end || vec[node].end<start)
		return 0;
	if(vec[node].start>=start && vec[node].end<=end && vec[node].up==0)
	{
		int z=x^vec[node].x;
		return vec[node].mp[z];
	}
	int ans = calculate(2*node+1,start,end,x^vec[node].x)+calculate(2*node+2,start,end,x^vec[node].x);
	return ans;
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	vector<int> data(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	int temp=0;
	for(int i=0;i<n;i++)
	{
		struct node p;
		p.up=0;
		p.start=i;
		p.end=i;
		temp=temp^data[i];
		p.mp[temp]++;
		p.x=0;
		vec.push_back(p);
	}
	int m=1;
	while(m<n)
	{
		m=m*2;
	}
	for(int i=n;i<m;i++)
	{
		struct node p;
		p.up=0;
		p.start=i;
		p.end=i;
		p.x=0;
		vec.push_back(p);
	}
	m--;
	int to=m;
	while(m!=0)
	{
		struct node p;
		p.up=0;
		p.x=0;
		p.start=vec[m-1].start;
		p.end=vec[m].end;
		for(map<int,int>::iterator it=vec[m].mp.begin();it!=vec[m].mp.end();it++)
		{
			p.mp[it->first]+=it->second;
		}
		for(map<int,int>::iterator it=vec[m-1].mp.begin();it!=vec[m-1].mp.end();it++)
		{
			p.mp[it->first]+=it->second;
		}
		vec.insert(vec.begin(),p);
//		vec.push_front(p);
		m--;
	}
	//for(int i=0;i<vec.size();i++)
	//{
	//	for(map<int,int>::iterator it=vec[i].mp.begin();it!=vec[i].mp.end();it++)
	//	{
	//		printf("%d %d\n",it->first,it->second);
	//	}
	//	printf("\n");
	//}
	while(q--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			b--;
			int x=data[b];
			x=x^c;
			update(0,b,to,x);
		}
		else if(a==2)
		{
			b--;
			int ans=calculate(0,0,b,c);
			printf("%d\n",ans);
		}
	}
}