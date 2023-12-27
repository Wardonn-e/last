import matplotlib.pyplot as plt
import numpy as np


def print_graphic(path):
    x1, y1, z1 = np.loadtxt(f"rand_data_{path}_sort.txt", unpack=True)

    plt.plot(x1, y1, marker='o', linestyle='-')
    plt.plot(x1, z1, marker='o', linestyle=':')
    plt.title(f'{path} rand_data')
    plt.show()
    x2, y2, z2 = np.loadtxt(f"sorted_{path}.txt", unpack=True, )

    plt.plot(x2, y2, marker='o', linestyle=':')
    plt.plot(x2, z2, marker='o', linestyle='-')
    plt.title(f'{path} sorted')
    plt.show()
    x3, y3, z3 = np.loadtxt(f"unsorted_{path}.txt", unpack=True, )

    plt.plot(x3, y3, marker='o', linestyle=':')
    plt.plot(x3, z3, marker='o', linestyle='-')
    plt.title(f'{path} unsorted')
    plt.show()



print_graphic('bubble')
print_graphic('shaker')
print_graphic('comb')
