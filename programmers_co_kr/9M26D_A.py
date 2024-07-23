
from itertools import permutations

def checkDecimal(num) :
    if num <= 1 :
        return False
    if num == 2 :
        return True
    for i in range(2, num):
        if num % i == 0 :
            return False
    return True

if __name__ == '__main__':
    numbers = '011'
    answer = 0

    pNums = set()

    for length in range(0, len(numbers)) :
        permute = set(permutations(numbers, length+1))

        for i in permute :
            pList = list(i)
            str = ''
            for j in range(0, len(pList)):
                str += pList[j]

            pNums.add(int(str))

    # print(pNums)
    for i in pNums :
        if checkDecimal(i):
            answer+= 1
    # print(answer)
