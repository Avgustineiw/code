import numpy as np


def t_test(a, b, size):
    x = np.random.normal(a, 1, size)
    y = np.random.normal(b, 1, size)

    d = x - y

    t = np.abs(d.mean() / (d.std() / np.sqrt(d.shape[0])))

    return t


for i in range(10, 101, 10):
    print(f'size: {i}, t: {t_test(100, 110, i)}')
