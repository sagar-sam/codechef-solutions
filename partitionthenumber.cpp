#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int x,n;
		scanf("%lld%lld",&x,&n);
		long long int sa=n*(n+1)/2;
		sa=sa-x;
		if(n<4)
		{
			printf("impossible\n");
		}
		else if(sa%2!=0)
		{
			printf("impossible\n");
		} 
		else if(n%2!=0)
		{
			char ans[n+1];
			int ind=0;
//			string ans="";
			int i=1;
			int a=0;
			int b=0;
			int flag=0;
			int flag2=0;
			for(int j=1;j<=n;j++)
			{
				if(j==x)
				{
					ans[ind]='2';
					ind++;
//					ans=ans+"2";
				}
				else 
				{
					if(flag==0)
					{
						ans[ind]='0';
						ind++;
//						ans=ans+"0";
						a=a+j;
					}
					else {
						ans[ind]='1';
						ind++;
//						ans=ans+"1";
						b=b+j;
					}
					flag2++;
					if(flag2%2!=0)
					flag=1-flag;
				}
			}
			if(b!=a)
			{
				for(int j=0;j<n-1;j++)
				{
					if(ans[j]=='0' && ans[j+1]=='1')
					{
						ans[j]='1';
						ans[j+1]='0';
						break;
					}
				}
			}
			ans[ind]='\0';
			printf("%s\n",ans);
//			cout<<ans<<"\n";
		}
		else
		{
			char ans[n+1];
			int ind=0;
//			string ans="";
			int a=0;
			int b=0;
			int flag=0;
			int flag2=0;
			for(int j=1;j<=n;j++)
			{
				if(j==x)
				{
					ans[ind]='2';
					ind++;
//					ans=ans+"2";
				}
				else if(j==1)
				{
					ans[ind]='0';
					ind++;
//					ans=ans+"0";
					a=a+j;
				//	flag=1;
				//	flag2=2;
				}
				else if(j==2 && x==1)
				{
					ans[ind]='0';
					ind++;
//					ans=ans+"0";
					a=a+j;
				//	flag=1;
				//	flag2=2;
				}
				else
				{
					if(flag==0)
					{
						ans[ind]='0';
						ind++;
//						ans=ans+"0";
						a=a+j;
					}
					else {
						ans[ind]='1';
						ind++;
//						ans=ans+"1";
						b=b+j;
					}
					flag2++;
					if(flag2%2!=0)
					flag=1-flag;
				}
			}
			if(a<b)
			{
				for(int j=0;j<n-1;j++)
				{
					if(ans[j]=='0' && ans[j+1]=='1')
					{
						ans[j]='1';
						ans[j+1]='0';
						a++;
						b--;
						break;
					}
				}
				if(a!=b)
				{
					if(ans[0]=='1')
						ans[0]='0';
				}
			}
			else if(b<a)
			{
				for(int j=0;j<n-1;j++)
				{
					if(ans[j]=='1' && ans[j+1]=='0')
					{
						ans[j]='0';
						ans[j+1]='1';
						b++;
						a--;
						break;
					}
				}
				if(a!=b)
				{
					if(ans[0]=='0')
						ans[0]='1';
				}
			}
			ans[ind]='\0';
			printf("%s\n",ans);
//			cout<<ans<<"\n";
		}
	}
}