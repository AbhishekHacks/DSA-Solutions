#You are given an integer ‘N’. You have to print the value of Factorial of ‘N’. The Factorial of a number ‘N’ is defined as the product of all numbers from 1 to ‘N’.

#For Example:
#Consider if ‘N’ = 4, the Factorial of 4 will be the product of all numbers from 1 to 4, which is 1 * 2 * 3 * 4 = 24. Hence, the answer is 24.

#Time Complexity -- O(n)

def factorial(n):
    # Write your code here
    # Print the factorial value.
    fac=1
    for i in range(1,n+1):
        fac*=i
    print(fac)
