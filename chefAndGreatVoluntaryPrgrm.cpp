#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		int a=0,b=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='a')
				a++;
			else if(s[i]=='b')
				b++;
		}
		int x,y;
		scanf("%d%d",&x,&y);
		int groupa=a/x;
		int groupb=b/y;
		if(groupa*x<a)
			groupa++;
		if(groupb*y<b)
			groupb++;
		int rema=a%x;
		int remb=b%y;
		string ans="";
		if(groupb==groupa)
		{
			for(int i=0;i<groupa;i++)
			{
				if(i==groupa-1 && rema!=0)
				{
					for(int j=0;j<rema;j++)
					ans+='a';
				}
				else{
					for(int j=0;j<x;j++)
						ans+='a';
				}
				if(i==groupb-1 && remb!=0)
				{
					for(int j=0;j<remb;j++)
						ans+='b';
				}
				else
				{
					for(int j=0;j<y;j++)
						ans+='b';
				}
			}
		}
		else if(groupa>groupb)
		{
			if(groupa>b+1)
			{
				int star = groupa-b-1;
				for(int i=0;i<groupa;i++)
				{
					if(i==groupa-1 && rema!=0)
					{
						for(int j=0;j<rema;j++)
							ans+='a';
					}
					else
					{
						for(int j=0;j<x;j++)
						{
							ans+='a';
						}
					}
					if(b>0)
					{
						ans+='b';
						b--;
					}
					else if(star>0)
					{
						ans+='*';
						star--;
					}
				}
			}
			else
			{
				int s=b/(groupa+1);
				int r=b%(groupa+1);
				for(int j=0;j<s;j++)
					ans+='b';
				for(int i=0;i<groupa;i++)
				{
					if(i==groupa-1 && rema!=0)
					{
						for(int j=0;j<rema;j++)
							ans+='a';
					}
					else
					{
						for(int j=0;j<x;j++)
							ans+='a';
					}
					for(int j=0;j<s;j++)
						ans+='b';
					if(r>0)
					{
						ans+='b';
						r--;
					}
				}
			}
		}
		else
		{
			if(groupb>a+1)
			{
				int star=groupb-a-1;
				for(int i=0;i<groupb;i++)
				{
					if(i==groupb-1 && remb!=0)
					{
						for(int j=0;j<remb;j++)
							ans+='b';
					}
					else
					{
						for(int j=0;j<y;j++)
						{
							ans+='b';
						}
						if(star>0)
						{
							ans+='*';
							star--;
						}
						else if(a>0)
						{
							ans+='a';
							a--;
						}
					}
				}
			}
			else
			{
				int s=a/(groupb+1);
				int r=a%(groupb+1);
				for(int j=0;j<s;j++)
					ans+='a';
				for(int i=0;i<groupb;i++)
				{
					if(i==groupb-1 && remb!=0)
					{
						for(int j=0;j<remb;j++)
							ans+='b';
					}
					else
					{
						for(int j=0;j<y;j++)
							ans+='b';
					}
					for(int j=0;j<s;j++)
						ans+='a';
					if(r>0)
					{
						ans+='a';
						r--;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
