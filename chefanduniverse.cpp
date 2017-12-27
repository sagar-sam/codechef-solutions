#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		int x,y,z,a,b,c;
		scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
		int s=x+y+z;
		ans=s*a;
		int temp;
		if(2*a>b)
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
				if(tor%2==1)
				{
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
				ans=temp;
		}
		if(3*a>c)
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
				ans=temp;
		}
		if(a+b<c)
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
				ans=temp;
		}
		printf("%d\n",ans);
//		if(2*b<a+c)
//		{
//			
//		} 
	}
}