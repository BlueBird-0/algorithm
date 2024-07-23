# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

def print_hi(numbers):
    answer = 0
    check = False
    scoville = [1, 2, 3, 9, 10, 12]
    K = 7
    scoville.sort()
    # print(scoville)

    while len(scoville)>=2:
        new = scoville[0] + scoville[1]*2
        scoville = scoville[2:]

        answer += 1
        if new >= K :
            check = True
            break

        for i in range(0, len(scoville)):
            if scoville[i] > new:
                scoville.insert(i, new)
                break

    if(len(scoville)==1):
        if(scoville[0]>=K):
            answer +=1

    if(check == False):
        return -1
    return answer
if __name__ == '__main__':
    print_hi('PyCharm')

