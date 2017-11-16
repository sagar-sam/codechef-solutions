#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	char ch=getchar();
	while(t--)
	{
		string s;
		cin.clear();
		fflush(stdin);
		getline(cin,s);
		int x=0;
		vector<int> vec;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==' ')
			{
				vec.push_back(x);
				x=0;
			}
			else 
			{
				x=x*10+(s[i]-'0');
			}
		}
		vec.push_back(x);
		//for(int i=0;i<vec.size();i++)
		//	printf("%d   ",vec[i]);
		int ans=0;
		int n=vec.size()-1;
		int flag=0;
		for(int i=0;i<vec.size();i++)
		{
			if(flag==0)
			{
				if(vec[i]>ans && vec[i]!=n)
					ans=vec[i];
				else if(vec[i]==n)
					flag=1;
			}
			else if(flag==1)
			{
				if(vec[i]>ans)
					ans=vec[i];
			}
		}
		printf("%d\n",ans);
	}
}