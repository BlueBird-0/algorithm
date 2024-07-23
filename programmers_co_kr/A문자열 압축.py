def solutionFuc(s, carrier):
    i = 1
    str = s[:carrier]

    answer = ''

    for index in range(carrier, len(s), carrier):
        if str == s[index:index + carrier]:
            i += 1
        else:
            if i != 1: answer += i.__str__()
            i = 1
            answer += str
            str = s[index:index + carrier]

    if i != 1: answer += i.__str__()
    answer += str
    # print(answer)
    return len(answer)


def solution(s):
    min = 1000
    if(len(s) == 1 ):
        return 1
    for i in range(1, len(s)):
        result = solutionFuc(s, i)
        if result <= min:
            min = result

    # print(min)
    return min


if __name__ == '__main__':
    solution('a')
