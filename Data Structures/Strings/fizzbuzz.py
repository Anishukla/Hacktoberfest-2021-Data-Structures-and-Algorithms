#Write a program that outputs the string representation of numbers from 1 to n
#But for multiples of three it should output “Fizz” instead of the number and 
#for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”
import sys

inputs = sys.argv
inputs.pop(0)
coke='fizz'
sound='buzz'

def fizzbuzz(n):
    if n % 3 == 0 and n % 5 == 0:
        print (coke+sound)
    elif n % 3 == 0:
        print (coke)
    elif n % 5 == 0:
        print (sound)
    else:
        print(n)

# inputs = input().split()
for input in inputs:
    input = int(input)
    fizzbuzz(input)
    
    
# Run: python fizzbuzz.py <enter number you need to check>
