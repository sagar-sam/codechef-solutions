#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string st;
		cin>>st;
		vector<int> vec(10);
		for(int i=0;i<st.length();i++)
		{
			vec[st[i]-'0']++;
		}
		set<char> s;
		if(vec[6]>0)
		{
			for(int i=5;i<=9;i++)
			{
				if(i==6)
				{
					if(vec[i]>1)
						s.insert((char)(66));
				}
				else if(vec[i]>0)
				{
					s.insert((char)(6*10+i));
				}
			}
		}
		for(int i=7;i<=8;i++)
		{
			if(vec[i]>0)
			{
				for(int j=0;j<=9;j++)
				{
					if(i==j)
					{
						if(vec[i]>1)
						{
							s.insert((char)(i*10+i));
						}
					}
					else if(vec[j]>0)
						{
							s.insert((char)(i*10+j));
						}
				}
			}
		}
		if(vec[9]>0 && vec[0]>0)
			s.insert((char)(90));
		for(set<char>::iterator it=s.begin();it!=s.end();it++)
		{
			printf("%c",*it);
		}
		printf("\n");
	}
}