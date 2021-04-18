# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
from itertools import permutations

def print_hi(numbers):
    numbers = "011"
    answer = 0
    diction = {}

    array = []
    #순열사용
    for i in range(1, len(numbers)+1):
        array.extend(list(map(''.join, permutations(numbers, i))))
    # print(array)

    for i in range(0, len(array)):
        check = False
        for j in range(2, int(array[i])-1):
            if (int(array[i])%j)==0 :
                check = True
                break

        if(check== False):
            diction[int(array[i])] = True

    if diction.get(0):
        diction.pop(0)
    if diction.get(1):
        diction.pop(1)
    else:
        print("ㄴㄴ")
    # print(diction)
    answer = len(diction)

if __name__ == '__main__':
    print_hi('PyCharm')

