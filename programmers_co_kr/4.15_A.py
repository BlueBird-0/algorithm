# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
from numpy.core import long
import numpy as np

def print_hi(name):
    answer = 0
    bridge_length = 100
    weight = 100
    truck_weights=		[10,10,10,10,10,10,10,10,10,10]

    Q = list(np.zeros((bridge_length), dtype=int))
    Q_sum = 0
    point = 0
    while point < len(truck_weights):
        Q_sum -= Q.pop()

        if(Q_sum+truck_weights[point] <= weight):
            Q.insert(0, truck_weights[point])
            Q_sum+= truck_weights[point]
            point+=1
        else:
            Q.insert(0, 0)

        answer+=1
    answer+=bridge_length
    print(answer)
if __name__ == '__main__':
    print_hi('PyCharm')
