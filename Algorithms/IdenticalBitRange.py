#Program to calculate the number of values having identical number of bits as the user input number.

#Below is the function to calculate the number of values with identical number of bits as num.
#This function has the complexity of O(log n).
#where n that power of two that is less than or equal to the input number.

def BitRange(num):
    i = 0
    bitIncrementer = 2 ** i

    #Loop checks wether the bitIncrementer variable is less than or equal to num
    while (bitIncrementer <= num):
        i += 1
        bitIncrementer = 2 ** i

    #After loop execution bitIncrementer value is nearest power of two that is greater than num

    #Returns the integer Division of bitIncrementer by 2
    return (bitIncrementer // 2)

#calling the function bitRange and passing the user input number as argument
bitRange = BitRange(int(input()))
print(bitRange)