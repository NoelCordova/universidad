#!/usr/bin/env python

file= open("/home/slingerriperxd/Desktop/arch1.txt", "rb")
file2= open("/home/slingerriperxd/Desktop/arch2.txt", "wb")

contfile= int(file.read())
imprime= ' '
cnt= 0

while cnt < contfile:
	imprime= '*' + imprime
	file2.write(imprime)
	file2.write('\n')
	cnt+=1
	
while cnt >= 1:
	cnt2=0
	imprime= ' '
	
	while cnt2 < cnt-1:
		imprime= '*' + imprime
		cnt2+=1
		
	file2.write(imprime)
	file2.write('\n')
	cnt-=1
	
file.close()
file2.close()
