#.!/usr/bin/env python3
import sys
import time

def rotX(fileRead,fileWrite, transform):
    lcBound = 122 - transform
    ucBound = 90 - transform
    tLine = ""
    for line in open(fileRead,'r').readlines():
        for i in line:
            if (ord(i) >= lcBound and ord(i) >= 97) or (ord(i) >= ucBound and ord(i) <=90):
                tLine+=chr(ord(i) - (26 - transform))
            elif (ord(i) > 97 and (ord(i) <=122)) or (ord(i)>=65 and (ord(i) <=90)):
                tLine+=chr(ord(i) + transform)
            else:
                tLine+=i
    rotText = open(fileWrite,'w+')
    rotText.write(tLine)
    rotText.close()

def main():
    rotX(sys.argv[1],sys.argv[2],int(sys.argv[3]))
if __name__ == "__main__":
    main()
