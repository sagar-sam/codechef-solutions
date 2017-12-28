#include <iostream>
#include <map>
#include <iterator>

using namespace std;

struct node{
	map<int,int> mp;
	int x;
};

void build(struct node *tree, int *arr, int index, int s, int e)
{
	if(s>e)
		return;
	if(s==e)
	{
		tree[index].mp[arr[s]]++;
		tree[index].x=0;
	}
	int mid=(s+e)/2;
	build(tree, arr, 2*index, s, mid);
	build(tree, arr, 2*index+1, mid+1, end);
	for(map<int,int>::iterator it=tree[2*index].mp.begin();it!=tree[2*index].mp.end();it++)
	{
		tree[index].mp[it->first]+=it->second;
	}
	for(map<int,int>::iterator it=tree[2*index+1].mp.begin();it!=tree[2*index+1].mp.end();it++)
	{
		tree[index].mp[it->first]+=it->second;
	}
	tree[index].x=0;
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<n;i++)
	{
		arr[i]=arr[i]^arr[i-1];
//		printf("%d ",arr[i]);
	}

	struct node *tree = new struct node[4*n+1];
	build(tree, arr, 1, 0, n-1);

	while(q--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			
		}
		else if(a==2)
		{

		}
	}
}
