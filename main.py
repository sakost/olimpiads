import sys
import os
import time
__ONPC = os.getenv('SAKOSTONPC') is not None
if __ONPC:
    __now = time.time()
    sys.stdout = open('output.txt', 'w')
    sys.stdin = open('input.txt', 'r')
######################################
t = int(input())
for i in range(t):
    s = input()
    if s.endswith('po'):
        print('FILIPINO')
    elif s.endswith('desu') or s.endswith('masu'):
        print('JAPANESE')
    else:
        print('KOREAN')
######################################
if __ONPC:
    print("Elapsed time:", time.time() - __now, file=sys.stderr)
