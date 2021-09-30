from operator import itemgetter 

if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    total = 0
    #print(student_marks)
    
    for i in student_marks:
        if i == query_name:
            #print (student_marks.get(i))


            for score in student_marks.get(i):
                total += score
    
    
    print("{:.2f}".format(total/3))