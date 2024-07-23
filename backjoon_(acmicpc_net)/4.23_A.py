def print_hi(result):
    a = list()
    size = 0
    for i in range(0, 5):
        str = input()
        size += len(str)
        a.append(str)

    index = 0
    while len(result) != size:
        if (len(a[index%5]) > int(index/5)):
            result += a[index % 5][int(index / 5)]
        index += 1

    print(result)
    return result

if __name__ == '__main__':
    print_hi('')
