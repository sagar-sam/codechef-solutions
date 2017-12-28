#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int normal(int x, int y, int z, int a, int b, int c)
{
	int s=x+y+z;
		int ans=s*a;
		int temp;
		//if(2*a>b)
		if(1)
		{
			temp=0;
			vector<int> vec(3);
			vec[0]=x;
			vec[1]=y;
			vec[2]=z;
			sort(vec.begin(),vec.end());
			int mi=vec[0];
			int ma=vec[2];
			int th=vec[1];
			int torcopy=2;
			if(mi+th<=ma)
			{
				temp=b*(mi+th);
				ma=ma-mi-th;
				temp+=(a*ma);
			}
			else
			{
				int s=mi+th;
				int tor=s-ma;
				if(3*a>c && 3*b>2*c)
				{
					temp+=(tor*c);
				//	tor=0;
					mi=mi-tor;
					th=th-tor;
					ma=ma-tor;
					s=s-tor-tor;
					tor=0;
				//	printf("%d\n",temp);
				}
				if(tor%2==1)
				{
					torcopy=tor;
					tor--;
					temp+=a;
				}
				tor=tor/2;
				temp+=(b*ma);
				temp+=(b*tor);
				int lo=mi-tor;
				int li=th-tor;
			}
			if(temp<ans)
			{
//				printf("1 %d",temp);
				ans=temp;
			}
			if(torcopy%2==1)
			{
				temp=temp-a;
				temp=temp+c;
				temp=temp-b;
				if(temp<ans)
					ans=temp;
			}
		}
		//if(3*a>c)
		if(1)
		{
			temp=0;
			vector<int> vec(3);
			vec[0]=x;
			vec[1]=y;
			vec[2]=z;
			sort(vec.begin(),vec.end());
			int mi=vec[0];
			temp+=(mi*c);
			int tempx=vec[0]-mi;
			int tempy=vec[1]-mi;
			int tempz=vec[2]-mi;
			int fir=tempy,sec=tempz;
			if(2*a>b)
			{
				if(fir<sec)
				{
					temp+=(b*fir);
					sec=sec-fir;
					temp+=(a*sec);
				}
				else
				{
					temp+=(b*sec);
					fir=fir-sec;
					temp+=(a*fir);
				}
			}
			else
			{
				temp+=(a*(fir+sec));
			}
			if(temp<ans)
			{
//				printf("2 %d",temp);
				ans=temp;
			}
		}
		//if(a+b<c)
		if(1)
		{
			vector<int> vec(3);
			vec[0]=x;
			vec[1]=y;
			vec[2]=z;
			sort(vec.begin(),vec.end());
			int tempx=vec[0];
			int tempy=vec[1];
			int tempz=vec[2];
			temp=0;
			int mi=tempx;
			temp=temp+(mi*(a+b));
			tempx=tempx-mi;
			tempy=tempy-mi;
			tempz=tempz-mi;
			int fir = tempy,sec = tempz;
			if(2*a>b)
			{
				if(fir<sec)
				{
					temp+=(b*fir);
					sec=sec-fir;
					temp+=(a*sec);
				}
				else
				{
					temp+=(b*sec);
					fir=fir-sec;
					temp+=(a*fir);
				}
			}
			else
			{
				temp+=(a*(fir+sec));
			}
			if(temp<ans)
			{
//				printf("3 %d",temp);
				ans=temp;
			}
		}
		//if(2*b<a+c)
/*		if(1)
		{
			temp=0;
			vector<int> vec(3);
			vec[0]=x;
			vec[1]=y;
			vec[2]=z;
			sort(vec.begin(),vec.end());
			int tempx=vec[0];
			int tempy=vec[1];
			int tempz=vec[2];
			temp+=(2*b*(tempx));
			tempy=
		}*/
//		printf("%d\n",ans);
		return ans;
}

int dp[105][105][105];

int cal(int x1,int x2,int x3,int y1,int y2,int y3, int a, int b, int c)
{
	if(dp[y1-x1][y2-x2][y3-x3]!=0)
		return dp[y1-x1][y2-x2][y3-x3];
	if(x1==y1 && x2==y2 && x3==y3)
		return 0;
	int ans=INT_MAX;
	int temp;
	if(x1+1<=y1){
		temp=cal(x1+1,x2,x3,y1,y2,y3,a,b,c)+a;
		if(temp<ans)
			ans=temp;
	}
	if(x2+1<=y2)
	{
		temp=cal(x1,x2+1,x3,y1,y2,y3,a,b,c)+a;
		if(temp<ans)
			ans=temp;
	}
	if(x3+1<=y3)
	{
		temp=cal(x1,x2,x3+1,y1,y2,y3,a,b,c)+a;
		if(temp<ans)
			ans=temp;
	}
	if(x1+1<=y1 && x2+1<=y2)
	{
		temp=cal(x1+1,x2+1,x3,y1,y2,y3,a,b,c)+b;
		if(temp<ans)
			ans=temp;
	}
	if(x1+1<=y1 && x3+1<=y3)
	{
		temp=cal(x1+1,x2,x3+1,y1,y2,y3,a,b,c)+b;
		if(temp<ans)
			ans=temp;
	}
	if(x2+1<=y2 && x3+1<=y3)
	{
		temp=cal(x1,x2+1,x3+1,y1,y2,y3,a,b,c)+b;
		if(temp<ans)
			ans=temp;
	}
	if(x1+1<=y1 && x3+1<=y3 && x2+1<=y2)
	{
		temp=cal(x1+1,x2+1,x3+1,y1,y2,y3,a,b,c)+c;
		if(temp<ans)
			ans=temp;
	}
	dp[y1-x1][y2-x2][y3-x3]=ans;
	return ans;
}

int dpsol(int x, int y, int z, int a, int b, int c)
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
	int ans=cal(0,0,0,x,y,z,a, b, c);
//	printf("%d\n",ans);
	return ans;
}


int maina()
{
	int count=0;
	for(int i=10;i<=20;i++)
	{
		for(int j=20;j<=30;j++)
		{
			for(int k=30;k<=40;k++)
			{
				int x=normal(i,j,k,12,12,34);
				int y=dpsol(i,j,k,12,12,34);
				printf("%d %d\n",x,y);
				if(x!=y)
				{
					count++;
					printf("%d %d %d\n",i,j,k);
					if(count!=0)
						break;
				}
			}
			if(count!=0)
				break;
		}
		if(count!=0)
			break;
	}
	printf("%d\n",count);
	return count;
}

int main()
{
//	printf("\n%d %d\n",normal(10, 21, 30, 10, 1, 5),dpsol(10,21,30,10,1,5));
//	maina();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y,z,a,b,c;
		scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
		int ans=normal(x,y,z,a,b,c);
		printf("%d\n",ans);
	}
}

//20 20 23
//10 1 5