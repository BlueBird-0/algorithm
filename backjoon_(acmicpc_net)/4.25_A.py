minNum = 1
maxNum = 10
def print_hi(result):
    global minNum, maxNum
    minNum, maxNum = input().split()
    minNum = int(minNum)
    maxNum = int(maxNum)

    result = 0
    result += funAttach("", 4)
    result += funAttach("", 7)
    print(result)
    return result

def funAttach(seedStr, attachNum):
    sumStr = seedStr+str(attachNum)

    result = 0
    if (int(sumStr) >= minNum and int(sumStr) <= maxNum):
        result += 1
    if(len(sumStr) >= len(str(maxNum))) :
        return result

    result += funAttach(sumStr, 4)
    result += funAttach(sumStr, 7)
    return result

if __name__ == '__main__':
    print_hi('')
