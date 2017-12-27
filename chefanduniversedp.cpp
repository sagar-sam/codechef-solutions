#include <iostream>
#include <climits>

using namespace std;

int dp[105][105][105];
int a,b,c;

int cal(int x1,int x2,int x3,int y1,int y2,int y3)
{
	if(dp[y1-x1][y2-x2][y3-x3]!=0)
		return dp[y1-x1][y2-x2][y3-x3];
	if(x1==y1 && x2==y2 && x3==y3)
		return 0;
	int ans=INT_MAX;
	int temp;
	if(x1+1<=y1){
		temp=cal(x1+1,x2,x3,y1,y2,y3)+a;
		if(temp<ans)
			ans=temp;
	}
	if(x2+1<=y2)
	{
		temp=cal(x1,x2+1,x3,y1,y2,y3)+a;
		if(temp<ans)
			ans=temp;
	}
	if(x3+1<=y3)
	{
		temp=cal(x1,x2,x3+1,y1,y2,y3)+a;
		if(temp<ans)
			ans=temp;
	}
	if(x1+1<=y1 && x2+1<=y2)
	{
		temp=cal(x1+1,x2+1,x3,y1,y2,y3)+b;
		if(temp<ans)
			ans=temp;
	}
	if(x1+1<=y1 && x3+1<=y3)
	{
		temp=cal(x1+1,x2,x3+1,y1,y2,y3)+b;
		if(temp<ans)
			ans=temp;
	}
	if(x2+1<=y2 && x3+1<=y3)
	{
		temp=cal(x1,x2+1,x3+1,y1,y2,y3)+b;
		if(temp<ans)
			ans=temp;
	}
	if(x1+1<=y1 && x3+1<=y3 && x2+1<=y2)
	{
		temp=cal(x1+1,x2+1,x3+1,y1,y2,y3)+c;
		if(temp<ans)
			ans=temp;
	}
	dp[y1-x1][y2-x2][y3-x3]=ans;
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<105;i++)
		{
			for(int j=0;j<105;j++)
			{
				for(int k=0;k<105;k++)
				{
					dp[i][j][k]=0;
				}
			}
		}
		int x,y,z;
		scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
		int ans=cal(0,0,0,x,y,z);
		printf("%d\n",ans);
	}
}