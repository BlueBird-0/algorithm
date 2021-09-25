# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import numpy as np
import copy

if __name__ == '__main__':
    answer = [2,1,2,4,5]
    people = [[1,2,3,4,5],
              [2,1,2,3,2,4,2,5],
              [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]
    index = 0

    k = 0
    currectArray = [0,0,0]
    for i in answer:
        for j in people:
            if i == j[index% len(j)] :
                currectArray[k%3] += 1
            k += 1
        index += 1

    topCurrect = copy.deepcopy(currectArray)
    topCurrect.sort()
    topCurrect = topCurrect[-1]
    answer.clear()
    x = 0
    for i in currectArray :
        x+=1
        if topCurrect == i :
            answer.append(x)

    # print(answer)