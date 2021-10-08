# ADDING ALL NUMBERS IN A STRING.


st = input("Enter a string:   ")
number = ""
total = 0
for i in st:
    if i.isdigit():
        a += i
    else:
        total += int(a)
        number = "0"
print(total + int(number ))

# INPUT:
# Enter a string: 567hdon2

# OUTPUT:
# 569
