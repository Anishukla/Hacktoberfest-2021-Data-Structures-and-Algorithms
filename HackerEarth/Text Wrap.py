import textwrap


def wrap(string, max_width):
    count = 0
    s = ""  
    for i in range(0,len(string)):
        count += 1
        s += string[i]
        if count == max_width:
            print(s)
            s = ""
            count = 0
        
        if i+1 == len(string):
            print(s)
            exit(0)   
    

if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)