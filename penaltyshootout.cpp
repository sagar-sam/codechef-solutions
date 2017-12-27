#include <iostream>

using namespace std;

int main()
{
	//string s;
	while(!cin.eof())
	{
		string s;
		cin>>s;
		if(s.length()!=20)
			break;
//		scanf(" %s",s);
		int a=0;
		int b=0;
		int counta=5;
		int countb=5;
		int flag=0;
		for(int i=0;i<10;i++)
		{
			if(i%2==0)
			{
				counta--;
				if(s[i]=='1')
				{
					a++;
					if(a>b+countb)
					{
						printf("TEAM-A %d\n",i+1);
						flag=1;
						break;
					}
				}
				else if(s[i]=='0')
				{
					if(b>a+counta)
					{
						printf("TEAM-B %d\n",i+1);
						flag=1;
						break;
					}
				}
			}
			else if(i%2!=0)
			{
				countb--;
				if(s[i]=='1')
				{
					b++;
					if(b>a+counta)
					{
						printf("TEAM-B %d\n",i+1);
						flag=1;
						break;
					}
				}
				else if(s[i]=='0')
				{
					if(a>b+countb)
					{
						printf("TEAM-A %d\n",i+1);
						flag=1;
						break;
					}
				}
			}
		}
		if(!flag)
		{

			for(int i=10;i<20;i=i+2)
			{
				if(s[i]=='1')
				{
					a++;
				}
				if(s[i+1]=='1')
				{
					b++;
				}
				if(a>b)
				{
					printf("TEAM-A %d\n",i+2);
					flag=1;
					break;
				}
				else if(b>a)
				{
					printf("TEAM-B %d\n",i+2);
					flag=1;
					break;
				}
			}
		}
		if(!flag)
		{
			printf("TIE\n");
		}
	}
}