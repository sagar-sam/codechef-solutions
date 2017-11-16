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
		int counta=0;
		int countb=0;
		char current=0;
		char prev=0;
		int count=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='A')
			{
				current='A';
				counta++;
				if(prev==current)
				{
					counta+=count;
				}
				count=0;
				prev='A';
			}
			else if(s[i]=='B')
			{
				current = 'B';
				countb++;
				if(prev==current)
				{
					countb+=count;
				}
				count=0;
				prev='B';
			}
			else if(s[i]=='.')
			{
				count++;
			}
		}
		printf("%d %d\n",counta,countb);
	}
}