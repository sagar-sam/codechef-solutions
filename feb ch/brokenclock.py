import sys

def si(sam):
	lmaoy = siy.get(sam,0)
	if lmaoy!=0:
		lmaox = six.get(sam)
		return lmaox, lmaoy
	x=1
	y=1
	if sam==1:
		y = oldl*oldl
		x = (oldl*oldl)-(oldd*oldd)
		x = x%1000000007
		y = y%1000000007
	elif sam%2==0:
		x=x*2
		cur = sam/2
		x = x*mpd[cur]
		y = y*mpl[cur]
		aly = siy.get(cur,0)
		if aly!=0:
			alx = six.get(cur)
		else:
			alx, aly = si(cur)
		x = x*alx
		y = y*aly
		x = x%1000000007
		y = y%1000000007
	else:
		fird = oldd
		firl = oldl
		fird = fird * 2
		cur = sam/2
		fird = fird * mpd[cur]
		firl = firl * mpl[cur]

		fird = fird%1000000007
		firl = firl%1000000007
		
		aly = siy.get(cur,0)
		if aly!=0:
			alx = six.get(cur)
		else:
			alx, aly = si(cur)
		fird = fird*alx
		firl = firl*aly

		fird = fird%1000000007
		firl = firl%1000000007

		secd = (oldl*oldl)-(oldd*oldd)
		secl = oldl*oldl
		cur = sam/2
		curd = mpd[cur]
		curl = mpl[cur]
		secd = secd * ((2*curd*curd)-(curl*curl))
		secl = secl * curl * curl

		secd = secd%1000000007
		secl = secl%1000000007
		y = firl * secl
		x = fird * secl + firl * secd
		x = x%1000000007
		y = y%1000000007
	siy[sam] = y
	six[sam] = x
	return x,y

def solve(t):

	global d,l
	if t==1:
		return

	if t%2==0:
		solve(t/2)
		d = (2*d*d)-(l*l)
		l = l*l
		d = d%1000000007
		l = l%1000000007
	else:
		solve(t/2)

		firstd = (2*d*d)-(l*l)
		firstd = firstd*oldd
		firstl = l*l
		firstl = firstl*oldl
		firstd = firstd %1000000007
		firstl = firstl%1000000007

		sam = t-1
		secondd = d
		secondl = l
		secondd = secondd*2

		sam = sam/2

		y = siy.get(sam,0)
		if y!=0:
			x=six.get(sam)
		else:
			x,y = si(sam)

		secondd = secondd * x
		secondd = secondd%1000000007
		secondl = secondl * y
		secondl = secondl%1000000007

		d = (firstd * secondl) - (firstl * secondd)
		l = firstl * secondl
		d = d%1000000007
		l = l%1000000007

	mpd[t]=d
	mpl[t]=l

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
