#include <iostream>
#include <map>

using namespace std;

long long int l,d,oldd,oldl;
map<long long int , long long int> mpd,mpl,six,siy;

long long int gcd(long long a,long long int b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a % b);
}

long long int binaryExponentiation(long long int x,long long int n)
{
	if(n==0)
		return 1;
	else if (n%2 == 0)
		return binaryExponentiation((x*x)%1000000007,n/2);
	else
		return (x*binaryExponentiation((x*x)%1000000007,(n-1)/2))%1000000007;
}

void solve(long long int t)
{
	if (t==1)
		return;

	if (t%2==0)
	{
		solve(t/2);
		d = (2*d*d)-(l*l);
		l = l*l;
		if(d<0)
			d=d+1000000007;
		d = d%1000000007;
		l = l%1000000007;
		mpl[t]=l;
		mpd[t]=d;
		long long int cur = t/2;
		long long int sinx = 2*six[cur];
		long long int siny = siy[cur];
		sinx = sinx%1000000007;
		siny = siny%1000000007;
		sinx*=six[1];
		siny*=siy[1];
		sinx = sinx%1000000007;
		siny = siny%1000000007;
		sinx*=mpd[cur];
		siny*=mpl[cur];
		sinx = sinx%1000000007;
		siny = siny%1000000007;
		six[t]=sinx;
		siy[t]=siny;
	}
	else
	{
		solve(t/2);

		long long int firstd = (2*d*d)-(l*l);
		if(firstd<0)
			firstd=firstd+1000000007;
		firstd = firstd%1000000007;
		firstd = firstd*oldd;
		firstd = firstd%1000000007;
		long long int firstl = l*l;
		firstl = firstl%1000000007;
		firstl = firstl*oldl;
		firstl = firstl%1000000007;

		long long int sam = t/2;
		long long int secondd = d;
		long long int secondl = l;
		secondd = secondd*2;
		secondd = secondd%1000000007;

		long long int y=siy[sam];
		long long int x=six[sam];

		secondd = secondd * x;
		secondd = secondd%1000000007;
		secondl = secondl*y;
		secondl = secondl%1000000007;
		d = (firstd * secondl) - (firstl * secondd);
		l = firstl * secondl;
		if(d<0)
			d=d+1000000007;
		d = d%1000000007;
		l = l%1000000007;
		mpd[t]=d;
		mpl[t]=l;

		firstd=firstl=secondd=secondl=1;

		firstd = six[1];
		firstl = siy[1];
		firstl = firstl*mpl[sam];
		firstl=firstl%1000000007;
		firstl = firstl*mpl[sam];
		firstl=firstl%1000000007;
		long long int tempd = (2*mpd[sam]*mpd[sam])-(mpl[sam]*mpl[sam]);
		if(tempd<0)
			tempd+=1000000007;
		tempd%=1000000007;
		firstd=firstd*tempd;
		firstd=firstd%1000000007;

		secondd*=six[sam];
		secondl*=siy[sam];
		secondd*=mpd[sam];
		secondd%=1000000007;
		secondl*=mpl[sam];
		secondl%=1000000007;
		secondd=secondd*2*mpd[1];
		secondd%=1000000007;
		secondl=secondl*mpl[1];
		secondl%=1000000007;

		tempd = (firstd * secondl) + (firstl * secondd);
		long long int templ = firstl * secondl; 

		tempd%=1000000007;
		templ%=1000000007;

		six[t]=tempd;
		siy[t]=templ;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int tim;
		scanf("%lld%lld%lld",&l,&d,&tim);
		oldd=d;
		oldl=l;

		mpd[1]=d;
		mpl[1]=l;

		six[1]=(l*l-d*d)%1000000007;
		siy[1]=(l*l)%1000000007;

		solve(tim);

		d = d*oldl;
		d%=1000000007;

	//	cout<<d<<" "<<l<<endl;

		long long int gc = gcd(d,l);
		d = d/gc;
		l = l/gc;

		long long int r = binaryExponentiation(l,1000000005);

		long long int ans = d*r;
		ans = ans%1000000007;
		if(ans<0)
		{
			ans=ans+1000000007;
			ans=ans%1000000007;
		}
		printf("%lld\n",ans);		
	}
}
