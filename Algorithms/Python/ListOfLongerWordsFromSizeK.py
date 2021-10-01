# Sweta Snigdha Sahoo
# author-swetasahoo29
# question
#  Write a Python program to find the list of words that are longer than n from a given list of words. 
def long_words(n, str):
    word_len = []
    txt = str.split(" ")
    for x in txt:
        if len(x) > n:
            word_len.append(x)
    return word_len	
print(long_words(3, "The quick brown fox jumps over the lazy dog"))
