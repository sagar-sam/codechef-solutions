#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct segment{
	int left;
	int right;
	int value;
};

vector<struct segment> seg(1);
map<int,int> mp;

void build(int curent, int left, int right)
{
	seg[curent].left=left;
	seg[curent].right=right;
	seg[curent].value=0;
	if(left==right)
	{
		mp[left]=curent;
		seg[curent].left=left;
		seg[curent].right=right;
		seg[curent].value=0;
		return;
	}
	int mid=(left+right)/2;
	build(2*curent,left,mid);
	build(2*curent+1,mid+1,right);
}

void update(int node, int left, int right)
{
	if(seg[node].left>=left && seg[node].right<=right)
	{
		seg[node].value++;
		return;
	}
	if(seg[node].left>right || seg[node].right<left)
		return;
	update(2*node, left, right);
	update(2*node+1, left, right);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<long long int> vec(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&vec[i]);
		}
		vector<long long int> prefixSum(n);
		prefixSum[0]=vec[0];
		for(int i=1;i<n;i++)
		{
			prefixSum[i]=prefixSum[i-1]+vec[i];
		}
		seg.clear();
		seg.resize(4*n);
		mp.clear();
		build(1,0,n-1);
		for(int i=0;i<n;i++)
		{
			int left;
			int right;
			if(i!=0)
			{
				int ans;
				int low=0;
				int high=i-1;
				while(low<=high)
				{
					int mid=(low+high)/2;
					long long int cur=prefixSum[i-1]-prefixSum[mid];
					if(vec[i]>=cur)
					{
						ans=mid;
						high=mid-1;
					}
					else
					{
						low=mid+1;
					}
				}
				update(1,ans,i-1);
				left=ans;
			}
			if(i!=n-1)
			{
				int ans;
				int low=i+1;
				int high=n-1;
				while(low<=high)
				{
					int mid=(low+high)/2;
					long long int cur=prefixSum[mid-1]-prefixSum[i];
					if(vec[i]>=cur)
					{
						ans=mid;
						low=mid+1;
					}
					else
					{
						high=mid-1;
					}
				}
				update(1,i+1,ans);
				right=ans;
			}
		//	printf("%d %d\n",left,right);
		}
		vector<int> ans(n);
		for(int i=0;i<n;i++)
		{
			int node=mp[i];
			while(node!=0)
			{
				ans[i]=ans[i]+seg[node].value;
				node=node/2;
			}
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
}


