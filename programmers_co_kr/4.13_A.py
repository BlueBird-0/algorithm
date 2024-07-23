# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def print_hi(name):
    a = ['a', 'd', 'b', 'c']
    b = ['a', 'b', 'c']

    A=0
    B=0
    for i in range(0, len(b)):
        A += a[i].__hash__()
        B += b[i].__hash__()
    A+= a[-1].__hash__()

    print('hash:',A-B)

    for i in range(0, len(a)):
        if a[i].__hash__() == A-B:
            print(a[i])
            break






    # for i in range(0, len(a)):


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi('PyCharm')