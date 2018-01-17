import random
# Change nums to run tests of "nums" length
nums = 500 
a = range(-10000, 10000)
for i in xrange(nums):
	b = a[random.randint(0, len(a)-i)]
	a.remove(b)
	print b
