#include <bits/stdc++.h>

using namespace std;


#define mod 1000000007ll
#define inf 1000000000
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define ins insert


typedef long long ll;
typedef unsigned long long ull;

typedef string st;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<st> vs;

typedef map<int,int> mii;
typedef map<st,int> msi;
typedef map<char,int> mci;

typedef set<int> si;
typedef set<st> ss;

typedef pair<int,int> pii;
typedef vector<pii> vpii;


map<int,int> parent;

int bfs(vector<int> edge[],int n,int s,int e)
{
	vector<int> visited(n);
	queue<pair<int,int>> q;
	int x=s;
	visited[x]=1;
	q.push(make_pair(x,0));
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		x=p.first;
		int y=p.second;
		if(x==e)
			return y-1;
	//	printf("%d  ",x);
		q.pop();
		for(int i=0;i<edge[x].size();i++)
		{
			if(visited[edge[x][i]]==0)
			{
				q.push(make_pair(edge[x][i],y+1));
				visited[edge[x][i]]=1;
				parent[edge[x][i]]=x;
		//		printf("%d %d\n",edge[x][i],parent[edge[x][i]]);
			}
		}
	}
	return -1;
}



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> edge[n];
		int m=n-1;
		scanf("%d",&m);
		int s,e;
		scanf("%d%d",&s,&e);
		s--;
		e--;
		fr(i,0,m)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			b--;
			edge[a].pb(b);
			edge[b].pb(a);
		}

		//for(int i=0;i<edge[0].size();i++)
		//	printf(" %d ",edge[0][i]);
		//printf("\n");
		int ans=bfs(edge, n,s,e);
		if(ans==-1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES %d\n",ans);
		}
	}
	//printf("\n%d %d %d\n",parent[4],parent[0],parent[5]);

}
