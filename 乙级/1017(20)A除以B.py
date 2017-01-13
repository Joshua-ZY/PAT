#Python可以实现任意精度的计算，所以用Python做这个题就非常容易
a, b = map(int, input().split())
q = a // b
r = a % b
print(str(q) + " " + str(r))
#print("%d %d" % (q, r))
