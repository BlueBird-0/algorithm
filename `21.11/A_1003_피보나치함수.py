global result
arr = [[1, 0], [0, 1]]
def solution(n):
    for i in range(len(arr), n+1):
        tmp = [arr[i - 2][j] + arr[i - 1][j] for j in range(0, 2)]
        arr.append(tmp)
    return arr[n]

if __name__ == '__main__':
    T = int(input())
    for i in range(0, T):
        N = int(input())
        result = solution(N)
        print(str(result[0]) + " " + str(result[1]))
