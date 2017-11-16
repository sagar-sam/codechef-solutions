#include <iostream>

using namespace std;

int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s,x,y,z;
		scanf("%d%d%d%d",&s,&x,&y,&z);
		int a=GCD(s,x);
		s=s/a;
		x=x/a;
		int b=GCD(y,z);
		y=y/b;
		z=z/b;
		int l=x*y/GCD(x,y);
		a=l/x;
		s=s*a;
		b=l/y;
		z=z*b;
		x=l;
		y=l;
		printf("%d %d %d\n",s,l,z);
	}
}