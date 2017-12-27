#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		vector<string> vec;
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			vec.push_back(s);
		}
		//red first
		int ansa=0;
		int ansb=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int x=i+j;
				if(x%2==0 && vec[i][j]!='R')
				{
					ansa+=3;
				}
				else if(x%2!=0 && vec[i][j]!='G')
				{
					ansa+=5;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int x=i+j;
				if(x%2==0 && vec[i][j]!='G')
				{
					ansb+=5;
				}
				else if(x%2!=0 && vec[i][j]!='R')
				{
					ansb+=3;
				}
			}
		}
		if(ansa>ansb)
		{
			printf("%d\n",ansb);
		}
		else printf("%d\n",ansa );
	}
}