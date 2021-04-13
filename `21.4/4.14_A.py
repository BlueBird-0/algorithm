# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
from numpy.core import long

def print_hi(name):
    answer = True
    phone_book = ["113333","115555","345555","555555", "345444"]    #이런 test에서 틀림

    key = 0
    while len(phone_book)>0:
        check1 = 0
        check2 = 0

        for i in range(0, len(phone_book)):
            bit = 2**int(phone_book[i][key])
            if(bit == 0) : bit = 1

            if(check1 & bit == 0):
                check1 += bit
            elif ((check1 & bit > 0) & (check2 & bit == 0)):
                check2 += bit
        # print(phone_book)

        i=0
        while i<len(phone_book):
            bit = 2**int(phone_book[i][key])
            if (bit == 0): bit = 1
            if( check2 & bit == 0):
                phone_book.pop(i)
            else :
                i+=1
        print(phone_book)

        for i in range(0, len(phone_book)):
            if len(phone_book[i]) == key+1:
                answer = False
                break
        if answer == False:
            break
        else :
            key+=1
    print(answer)


if __name__ == '__main__':
    print_hi('PyCharm')
