#!/usr/bin/env python

def fibonacci(n):
	if n is 0 or n is 1:
		return n
		
	else:
		return fibonacci(n-1) + fibonacci(n-2)


file= open("/home/slingerriperxd/Desktop/fib1.txt", "rb")
file2= open("/home/slingerriperxd/Desktop/fib2.txt", "wb")

valor= int(file.read())
file2.write(str(fibonacci(valor)))

file.close()
file2.close()

# 0 1 1 2 3 5 8 13 21
