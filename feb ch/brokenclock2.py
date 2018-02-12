import sys
import math

def solve(t):

	global d,l
	if t==1:
		return

	if t%2==0:
		solve(t/2)
		d = (2*d*d)-(l*l)
		l = l*l
#		print d,l
		d = d%1000000007
		l = l%1000000007
		mpd[t]=d
		mpl[t]=l
		cur=t/2
		sinx = 2*six[cur]*mpd[cur]
		siny = siy[cur]*mpl[cur]
		sinx = sinx%1000000007
		siny = siny%1000000007
		six[t]=sinx
		siy[t]=siny
#		print d,l
	else:
		solve(t/2)

		firstd = (2*d*d)-(l*l)
		firstd = firstd*oldd
		firstl = l*l
		firstl = firstl*oldl
		firstd = firstd %1000000007
		firstl = firstl%1000000007

		sam=t/2

		secondd = mpd[sam]
		secondl = mpl[sam]

		secondd = secondd*2*six[sam]
		secondl = secondl*siy[sam]

		secondd = secondd%1000000007
		secondl = secondl%1000000007

		d = (firstd * secondl) - (firstl * secondd)
		l = firstl * secondl
		d = d%1000000007
		l = l%1000000007
		mpd[t]=d
		mpl[t]=l

		firstd = 2*six[sam]*mpd[1]*mpd[sam]
		firstl = siy[sam]*mpl[1]*mpl[sam]
		firstd=firstd%1000000007
		firstl=firstl%1000000007
		secondd = six[1]
		secondl = siy[1]
		secondl = secondl*mpl[sam]*mpl[sam]
		secondd = secondd*(2*(mpd[sam]*mpd[sam])-(mpl[sam]*mpl[sam]))
		secondd%=1000000007
		secondl%=1000000007
		tempd = (firstd * secondl) + (firstl * secondd)
		templ = firstl * secondl
		tempd = tempd%1000000007
		templ = templ%1000000007
		six[t]=tempd
		siy[t]=templ


def gcd(d,l):
	if(l==0):
		return d
	else:
		return gcd(l, d % l)


def binaryExponentiation(x,n):
	if(n==0):
		return 1
	elif  n%2 == 0:
		return binaryExponentiation((x*x)%1000000007,n/2)
	else:
		return (x*binaryExponentiation((x*x)%1000000007,(n-1)/2))%1000000007

#n = sys.stdin.readline()
#n = int(n)
n = input()
mpd = {}
mpl = {}
six = {}
siy = {}

#print siy.get(2,0)

for i in xrange(0,n):

	mpd = {}
	mpl = {}
	siy = {}
	six = {}
	
	l, d, t = sys.stdin.readline().split()
	l = int(l)
	d = int(d)
	t = int(t)
	
	oldl = l
	oldd = d

	mpd[1] = d
	mpl[1] = l
	six[1] = (l*l)-(d*d)
	siy[1] = l*l
	six[1]%=1000000007
	siy[1]%=1000000007

	solve(t)

	d = d*oldl

	d=d%1000000007
	l=l%1000000007

#	gc = gcd(d,l)
#	d = d/gc
#	l = l/gc

	r = binaryExponentiation(l,1000000005)

	ans = d*r
	ans = ans%1000000007
#	sys.stdout.write(str(ans))
	print ans

#allx = six.get(7,0)
#print allx