#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		int count1=0,count2=0;
		int ans=1;
		int flag=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='<')
			{
/*				flag=0;
				count1++;
				if(count2==0)
				{
				//	count1++;
					ans++;
				}
				else count2--;
*/				int count=1;
				while((i<s.length()) && (s[i]=='<' || s[i]=='='))
				{
					if(s[i]=='<')
						count++;
					i++;
				}
				if(count>ans)
					ans=count;
				i--;
			}
			else if(s[i]=='>')
			{
/*				flag=1;
				count2++;
				if(count1==0)
				{
				//	count2++;
					ans++;
				}
				else count1--;
*/				int count=1;
				while((i<s.length()) && (s[i]=='>' || s[i]=='='))
				{
					if(s[i]=='>')
					count++;
					i++;
				}
				if(count>ans)
					ans=count;
				i--;
			}
		}
		printf("%d\n",ans);
	}
}
