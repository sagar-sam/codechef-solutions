import sys

def binaryExponentiation(x,n):
	if(n==0):
		return 1
	elif  n%2 == 0:
		return binaryExponentiation((x*x)%1000000007,n/2)
	else:
		return (x*binaryExponentiation((x*x)%1000000007,(n-1)/2))%1000000007

def matmul(t):
	global upfir,upsec,dofir,dosec
	if t==1:
		return
	matmul(t/2)
	tempupfir = upfir
	tempupsec = upsec
	tempdofir = dofir
	tempdosec = dosec
	upfir = (tempupfir*tempupfir)+(tempupsec*tempdofir)
	upsec = (tempupfir*tempupsec)+(tempupsec*tempdosec)
	dofir = (tempdofir*tempupfir)+(tempdosec*tempdofir)
	dosec = (tempdofir*tempupsec)+(tempdosec*tempdosec)
	upfir = upfir%1000000007
	upsec = upsec%1000000007
	dofir = dofir%1000000007
	dosec = dosec%1000000007
	if t%2==1:
		tempupfir = upfir
		tempupsec = upsec
		tempdofir = dofir
		tempdosec = dosec
		upfir = (tempupfir*2*oldd)+(tempupsec)
		upsec = (tempupfir*(-oldl*oldl))
		dofir = (tempdofir*2*oldd)+(tempdosec)
		dosec = (tempdofir*(-oldl*oldl))
		upfir = upfir%1000000007
		upsec = upsec%1000000007
		dofir = dofir%1000000007
		dosec = dosec%1000000007

def gcd(d,l):
	if(l==0):
		return d
	else:
		return gcd(l, d % l)

n = input()
for i in xrange(0,n):
	l, d, t = sys.stdin.readline().split()
	l = int(l)
	d = int(d)
	t = int(t)
	upfir = 2*d
	upsec = -l*l
	dofir = 1
	dosec = 0
	oldl = l
	oldd = d
	upfir = upfir%1000000007
	upsec = upsec%1000000007
	matmul(t)
	num = dofir*oldd+dosec
	num = num%1000000007
	den = binaryExponentiation(l, t)
	num = num*oldl
	num = num%1000000007
	gc = gcd(num, den)
	num = num/gc
	den = den/gc
	r = binaryExponentiation(den, 1000000005)
	num = num*r
	num = num%1000000007

	print num
