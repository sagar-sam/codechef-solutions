#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		vector<int> vec;
		cin>>s;
		int n=s.length()-1;
		int sumdigits=0;
		for(int i=0;i<s.length();i++)
		{
			sumdigits=(sumdigits+s[i]-'0');
		}
		int x=sumdigits%3;
		if(s[n]%2==0)
		{
			int flag=0;
			int ind;
			for(int i=0;i<s.length();i++)
				{
					if((s[i]-'0')%3==x)
				}
				if(flag==0)
				{
					printf("-1\n");
				}
				else 
				{
					set<string> se;
					for(int i=0;i<vec.size();i++)
					{
						int l=vec[i];
						string ass="";
						for(int j=0;j<s.length();j++)
						{
							if(j!=l)
							{
								ass+=s[j];
							}
						}
						se.insert(ass);
					}
					set<string>::iterator it =se.end();
					it--;
					cout<<*it;
					printf("\n");
				}
		}
		else 
		{
			if(s[n-1]%2==0 && (s[n]-'0')%3==x)
			{
				for(int i=0;i<s.length()-1;i++)
				{
					printf("%c",s[i]);
				}
				printf("\n");
			}
			else
				printf("-1\n");
		}
	}
}