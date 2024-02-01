import tkinter as tk
from tkinter import ttk
import random
from math import isqrt
import time
die = random.SystemRandom() #A single dice for MILLER-RABIN


#####################################################################################################################################
#############################################################MILLER-RABIN############################################################
#####################################################################################################################################

def primality_test(n, a):
    exp = n-1
    while not exp & 1: #means while exp is even
        exp >>= 1 #son biti silmek, exp//=2 ile aynı şey ama faster

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
    start = time.perf_counter()

    #we are not gonna check if a hasnt been done before in previous iterations of loop bc n is very large, chances of getting same a is very low
    if (n == 2 or n == 3):
        return miller_rabin_helper(True, n, start)
    if (n <= 1):
        result_label.config(text="Enter number bigger than 1.")
        return

    for i in range(k):
        a = die.randrange(2, n-1)
        if not primality_test(n, a):
            miller_rabin_helper(False, n, start) #number is composite
            return
    
    miller_rabin_helper(True, n, start)

def miller_rabin_helper(flag, n, start):
    result=""
    if flag:
        result = str(n) + " is prime."
    else:
        result = str(n) + " is composite."
    elapsed = time.perf_counter() - start
    result_label.config(text=result + "\nDone in " + str(elapsed))


#####################################################################################################################################
#############################################################ERATOSTHENES############################################################
#####################################################################################################################################

#array of booleans, trues are prime
# iterate through array, number that is still marked true has to be prime
def eratosthenes(n):
    n+=1

    start = time.perf_counter()

    if n < 2:
        result_label.config(text="[]")
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

    
    elapsed = time.perf_counter() - start

    result = [i for i in range(n) if is_prime[i]]
    
    resText = ""
    if result[-1] == n-1:
        if (boolean_value.get()):
            resText = str(n-1) + " is prime!\n Resultant array is printing to console."
        else:
            resText = str(n-1) + " is prime!"
    else:
        if (boolean_value.get()):
            resText = str(n-1) + " is composite!\n Resultant array is printing to console."
        else:
            resText = str(n-1) + " is composite!"
    result_label.config(text=resText+"\nDone in " + str(elapsed))

    if(boolean_value.get()):
        print(result) 

#####################################################################################################################################
################################################################ATKIN################################################################
#####################################################################################################################################

def atkin(number):
    start = time.perf_counter()

    if (number == 2 or number == 3):
        if (boolean_value.get()):
            resText = str(number) + " is prime!\n Resultant array is printing to console."
        else:
            resText = str(number) + " is prime!"

        elapsed = time.perf_counter() - start
        result_label.config(text=resText+"\nDone in " + str(elapsed))

        if (number == 2 and boolean_value.get()):
            print("[2]")
        elif (number == 3 and boolean_value.get()):
            print("[2, 3]")

        return

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
            if (n <= number and (n % 12 == 1 or
                                n % 12 == 5)):
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

    elapsed = time.perf_counter() - start
    result = [i for i in range(number+1) if sieve[i]]

    
    
    resText = ""
    if result[-1] == number:
        if (boolean_value.get()):
            resText = str(number) + " is prime!\n Resultant array is printing to console."
        else:
            resText = str(number) + " is prime!"
    else:
        if (boolean_value.get()):
            resText = str(number) + " is composite!\n Resultant array is printing to console."
        else:
            resText = str(number) + " is composite!"
    result_label.config(text=resText+"\nDone in " + str(elapsed))

    if(boolean_value.get()):
        print(result) 


#####################################################################################################################################
############################################################USER INTERFACE###########################################################
#####################################################################################################################################

root = tk.Tk()
root.title("1901042646 MERT GÜRŞİMŞİR")

root.geometry("800x400")

style = ttk.Style()

style.configure("TFrame", background="#303f9f", foreground="white")

style.map("TButton",
          background=[('active', '#36C9A2'), ('pressed', '#36C9A2')],
          foreground=[('pressed', 'white'), ('active', '#303f9f')])
#303f9f

frame = ttk.Frame(root, style="TFrame")
frame.place(relwidth=1, relheight=1)

entry = tk.Entry(frame, width=30)
entry.pack(pady=10)

button_width = 10
first_button = ttk.Button(frame, text="Miller-Rabin", command=lambda: miller_rabin(int(entry.get())), width=button_width)
second_button = ttk.Button(frame, text="Eratosthenes", command=lambda: eratosthenes(int(entry.get())), width=button_width)
third_button = ttk.Button(frame, text="Atkin", command=lambda: atkin(int(entry.get())), width=button_width)

first_button.pack(side=tk.TOP, pady=5, fill=tk.BOTH, expand=True)
second_button.pack(side=tk.TOP, pady=5, fill=tk.BOTH, expand=True)
third_button.pack(side=tk.TOP, pady=5, fill=tk.BOTH, expand=True)

result_label = tk.Label(frame, text="", background="#303f9f", foreground="white")
result_label.pack(side=tk.BOTTOM, pady=10)

boolean_value = tk.BooleanVar()

# Create a check button with text "Toggle"
check_button = tk.Checkbutton(root, text="Print List to console", variable=boolean_value, background="white")
check_button.grid(row=0, column=0)

root.mainloop()