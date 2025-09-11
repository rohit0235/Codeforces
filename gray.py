n = int(input())

for i in range (0,pow(2,n)):
    print(bin(i ^ (i >> 1))[2:].zfill(n))

