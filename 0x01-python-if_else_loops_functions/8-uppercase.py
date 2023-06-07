#!/usr/bin/python3
def uppercase(str):
    for c in str:
        c = chr(ord(c) - 32)
        print("{}".format(c), end='')
    print("")
