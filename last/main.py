import matplotlib.pyplot as plt
import numpy as np


def out(path):
    x1, y1, z1 = np.loadtxt(f"rand_data_{path}_sort.txt", unpack=True)
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')

    x2, y2, z2 = np.loadtxt(f"sorted_{path}.txt", unpack=True)
    plt.plot(x2, y2, marker=".")
    plt.plot(x2, z2, marker='.')

    x3, y3, z3 = np.loadtxt(f"unsorted_{path}.txt", unpack=True)
    plt.plot(x3, y3, marker=".")
    plt.plot(x3, z3, marker='.')

    plt.title(f'Scatter Plot of Points {path}')
    plt.xlabel('The number of elements in the vector')

    plt.show()


out('bubble')
out('shaker')
out('comb')
