#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main()
{
	int n,qu;
	scanf("%d%d",&n,&qu);
	vector<int> vec[n];
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	queue<int> q;
	vector<int> acc(n);
	acc[0]=1;
	map<int,int> mp;
	for(int i=0;i<vec[0].size();i++)
	{
		q.push(vec[0][i]);
		acc[vec[0][i]]=1;
		mp[vec[0][i]]=0;
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<vec[x].size();i++)
		{
			if(!acc[vec[x][i]])
			{
				q.push(vec[x][i]);
				acc[vec[x][i]]=1;
				mp[vec[x][i]]=x;
			}
		}
	}
	vector<long long int> count(n);
	for(int i=1;i<n;i++)
	{
		int y=mp[i];
		while(y)
		{
			y=mp[y];
			count[i]++;
		}
		//printf("%lld   ",count[i]);
	}
	vector<long long int> elem(n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&elem[i]);
	}
	int arr[501][501];
	for(int i=0;i<=500;i++)
	{
		for(int j=0;j<=500;j++)
		{
			if(i==0)
				arr[i][j]=0;
			else if(i==1)
				arr[i][j]=1;
			else if(j==0)
				arr[i][j]=i%2;
			else arr[i][j]=(arr[i-1][j]+arr[i][j-1])%2;
		}
	}
	/*for(int i=0;i<=4;i++)
	{
		for(int j=0;j<10;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}*/
	for(int i=0;i<qu;i++)
	{
		long long int a;
		scanf("%lld",&a);
		long long int ans=elem[0];
		for(int i=1;i<n;i++)
		{
			if(arr[a][count[i]]%2!=0)
				ans=ans^elem[i];
		}
		printf("%lld\n",ans);
	}
}