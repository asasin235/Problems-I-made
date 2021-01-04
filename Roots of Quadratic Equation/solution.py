'''

    Time Complexity: O(1)
    Space Complexity: O(1)

'''

from sys import stdin, setrecursionlimit
import sys
import math


def findRoots(a,  b,  c):

    # If a is 0, then equation is
    # not quadratic, but linear
    if a == 0:
        return -1, -1

    d = (b * b) - (4 * a * c)
    sqrt_val = int(math.sqrt(abs(d)))
    # print(d)
    # print(sqrt_val)

    if d > 0:
        return int((-b + sqrt_val)//(2 * a)), int((-b - sqrt_val)//(2 * a))

    elif d == 0:
        return int(-b // (2*a))
    else:  # d<0
        return -1, -1


# def freopen(filename, mode):
#     if mode == "r":
#         sys.stdin = open(filename, mode)

#     elif mode == "w":
#         sys.stdout = open(filename, mode)


# Main
# freopen("input.txt", "r")
# freopen("output.txt", "w")
t = int(input())
while t:
    a, b, c = list(map(int, input().strip().split(" ")))
    root1, root2 = findRoots(a, b, c)
    if root1 > root2:
        root1, root2 = root2, root1
    print(root1, root2)
    t = t - 1
