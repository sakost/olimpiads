from functools import lru_cache

mod = 1e9 + 7


@lru_cache()
def func(n, acc=0):
    if n == 1 or n == 2:
        return 0 + acc
    elif n == 3:
        return 1 + acc
    return (func(n-1) + 2*func(n-2) + bool(n >= 6 and n % 2 == 0)) % mod


print(func(int(input())))
