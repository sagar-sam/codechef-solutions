#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a;
		scanf("%d%d",&n,&a);
		if(a==1)
		{
			printf("%d ",n);
			string s="";
			char ch = 'a';
			for(int i=0;i<n;i++)
				s=s+ch;
			cout<<s<<"\n";
		}
		else if(a>2)
		{
			printf("1 ");
			string s="";
			int x=0;
			for(int i=0;i<n;i++)
			{
				x=x%3;
				char ch='a'+x;
				s=s+ch;
				x++;
			}
			cout<<s<<"\n";
		}
		else if(a==2)
		{
			if(n==1)
			{
				printf("1 a\n");
			}
			else if(n==2)
			{
				printf("1 ab\n");
			}
			else if(n==3)
			{
				printf("2 abb\n");
			}
			else if(n==4)
			{
				printf("2 aabb\n");
			}
			else if(n==5)
			{
				printf("3 aabab\n");
			}
			else if(n==6)
			{
				printf("3 aaabab\n");
			}
			else if(n==7)
			{
				printf("3 aaababb\n");
			}
			else if(n==8)
			{
				printf("3 aaababbb\n");
			}
			else
			{
				string s="";
				int x=0;
				int z=1;
				int flag=0;
				int occ=0;
				for(int i=0;i<n;i++)
				{
					x=x%2;
					z=z%2;
					if(z==0)
					{
						char ch='a'+x;
						s=s+ch;
						x++;
						occ++;
						if(occ==2)
						{
							occ=0;
							z=1-z;
						}
					}
					else if(z==1 && flag==0)
					{
						char ch='a'+x;
						s=s+ch;
						flag=1;
					}
					else if(z==1 && flag==1)
					{
						char ch='a'+x;
						s=s+ch;
						flag=0;
						x++;
						occ++;
						if(occ==2)
						{
							occ=0;
							z=1-z;
						}
					}
				}
				printf("4 ");
				cout<<s<<"\n";
			}
		}
	}
}