import timeit
import os

D = 'x' * 10**9  

s = timeit.default_timer()
with open('file.txt', 'w') as file:
    file.write(D)
e = timeit.default_timer()
print(f"Time for I/O: {e - s} seconds")

os.remove('file.txt')

f_list = [0] * 1000
def fac(n):
    if n == 0:
        f_list[n] = 1
        return 0
    if n == 1:
        f_list[n] = 1
        return 1
    f_list[n] = n*fac(n-1)
    return f_list[n]

s = timeit.default_timer()
fac(300)
e = timeit.default_timer()
print(f"Time for CPU: {e - s} seconds")
