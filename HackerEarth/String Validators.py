if __name__ == '__main__':
    S = raw_input()
        
    print(any(map(str.isalnum, S)))
    print(any(map(str.isalpha, S)))
    print(any(map(str.isdigit, S)))
    print(any(map(str.islower, S)))
    print(any(map(str.isupper, S)))