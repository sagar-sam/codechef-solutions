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
		int ans=0;
		for(int i=0;i<s.size();i++)
		{
			int countc=0,counth=0,counte=0,countf=0;
			for(int j=i;j<i+4 && j<s.size();j++)
			{
				if(s[j]=='c')
					countc++;
				else if(s[j]=='h')
					counth++;
				else if(s[j]=='e')
					counte++;
				else if(s[j]=='f')
					countf++;
			}
			if(countf==1 && counte==1 && counth==1 && countc==1)
				ans++;
		}
		if(ans==0)
			printf("normal\n");
		else printf("lovely %d\n",ans);
	}
}