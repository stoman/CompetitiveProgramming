#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    #read input
    n = int(input())
    grades = []#list of all grades achieved
    students = {}#maps a grade to a list of students having that grade
    for i in range(n):
        name = input()
        grade = float(input())
        grades.append(grade)
        if grade in students:
            students[grade].append(name)
        else:
            students[grade] = [name]
    #print result
    sortedgrades = list(set(grades))
    sortedgrades.sort()
    students[sortedgrades[1]].sort()
    for name in students[sortedgrades[1]]:
        print(name)
