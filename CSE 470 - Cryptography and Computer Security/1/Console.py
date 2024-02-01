import random
from math import isqrt
import time
die = random.SystemRandom() #A single dice


def primality_test(n, a):
	exp = n-1
	while not exp & 1: #means while exp is even
		exp >>= 1 #same as exp//=2 but faster

	#now exp is (n-1)/2^k  and it is odd
	if pow(a, exp, n) == 1:
		return True

	#we have checked the first term
	#now we need to check all of the rest of the terms
	while exp < n-1:
		if pow(a, exp, n) == n-1: #Checking terms, there are +1 at terms so equality is -1 this time and it means n-1 (bc it should be positive remainder)
			return True #Term is divisible by n
		exp <<= 1 #multiply exponent by 2

	return False

#we need random values of a
#random.rand numbers are generated with an algorithm, it is not truly random so its a bit easier to hack the system
#system uses stuff from the system and environment etc. so it is a bit harder to crack
def miller_rabin(n, k=40): # k is number of values of a we are gonna check
	#we are not gonna check if a hasnt been done before in previous iterations of loop bc n is very large, chances of getting same a is very low
	if n == 2 or n == 3:
		return True
	for i in range(k):
		a = die.randrange(2, n-1)
		if not primality_test(n, a):
			return False #number is composite
	return True

#print(miller_rabin(7474967))

##################################################################################################################################################################

#array of booleans, trues are prime
# iterate through array, number that is still marked true has to be prime
def eratosthenes(n):
	n += 1
	if n <= 2:
		return []
	is_prime = [True] * n

	#0 and 1 are not prime
	is_prime[0] = False
	is_prime[1] = False

	if n >= 10:
		is_prime[9] = False
	if n >= 5:
		is_prime[4] = False
	if n >= 7:
		is_prime[6] = False

	#we dont have to go up to n
	#if you have composite number, it has at least 2 factors, at least one of the two factors needs to be less than the square root of n
	for i in range(2, isqrt(n)+1):
		if is_prime[i]:
			#mark all of the multiples of the number i
			#i can start at the square of that number because if number is 3, we start from 3*3, not assume 3*2 because multiples of 2 is already handled
			for j in range(i*i, n, i): #jump i each time, n is not included
				is_prime[j] = False

	result = [i for i in range(n) if is_prime[i]]
	return result

######################################################################################################################################################################

def atkin(number):
	if (number == 2):
		return [2]
	if (number == 3):
		return [2, 3]

	sieve = [False] * (number + 1)

	if number > 2:
		sieve[2] = True
	if number > 3:
		sieve[3] = True

	x = 1
	while x * x <= number:
		y = 1
		while y * y <= number:

			n = (4 * x * x) + (y * y)
			if (n <= number and (n % 12 == 1 or n % 12 == 5)):
				sieve[n] = not sieve[n]

			n = (3 * x * x) + (y * y)
			if n <= number and n % 12 == 7:
				sieve[n] = not sieve[n]

			n = (3 * x * x) - (y * y)
			if (x > y and n <= number and
					n % 12 == 11):
				sieve[n] = not sieve[n]
			y += 1
		x += 1

	r = 5
	while r * r <= number:
		if sieve[r]:
			for i in range(r * r, number+1, r * r):
				sieve[i] = False

		r += 1


	return [i for i in range(number+1) if sieve[i]]

print("---------------------------1901042646 MERT GÜRŞİMŞİR---------------------------")
print("Welcome! Please choose: \n1 -> Miller-Rabin\n2 -> Eratosthenes\n3 -> Atkin\n\nSelection: ", end="")
selection = int(input())
while selection < 1 or selection > 3:
	selection = int(input("Please select between 1 and 3: "))
number = int(input("\nPlease enter the number: "))


if selection == 1:
	start=time.perf_counter()
	test = miller_rabin(number)
	elapsed = time.perf_counter() - start

	if test:
		print(f"{number} is prime!")
	else:
		print(f"{number} is composite!")

	print(f"Done in {elapsed}")

elif selection == 2:
	flag = int(input("Do you want to see list? (1: yes, 0: no): "))
	start = time.perf_counter()
	result = eratosthenes(number)
	elapsed = time.perf_counter() - start

	if (flag):
		print(result)

	if result[-1] == number:
		print(f"{number} is prime!")
	else:
		print(f"{number} is not prime!")

	print(f"Done in {elapsed}")

else:
	flag = int(input("Do you want to see list? (1: yes, 0: no): "))
	start = time.perf_counter()
	result = atkin(number)
	elapsed = time.perf_counter() - start

	if (flag):
		print(result)

	if result[-1] == number:
		print(f"{number} is prime!")
	else:
		print(f"{number} is not prime!")

	print(f"Done in {elapsed}")

input("\n\nPress Enter to exit...")
