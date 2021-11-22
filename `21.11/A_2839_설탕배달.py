global result
result = False

def solution(q, r, count=0):
    global result
    if r % 3 == 0:
        tmp = int(r/3)
        print(q+tmp)
        result = True
        return
    else:
        if q <= 0:
            return
        q -= 1
        r += 5
        solution(q, r)



if __name__ == '__main__':
    k = int(input())
    q = int(k/5)
    r = k % 5

    solution(q, r)


    if result == False:
        print(-1)
