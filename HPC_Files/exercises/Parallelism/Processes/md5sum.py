#!/usr/bin/env python3

import hashlib
import string
import random

def createRandomString(length):
    randString = ''.join(random.choices(string.ascii_uppercase + string.digits, k=length))
    return(randString)

def main():
    myPassword = hashlib.md5("mySuperSecretPassword".encode('utf-8')).hexdigest()
    count = 0
    while count < 50000:
        isMatch = createRandomString(10)
        checkHash = hashlib.md5(isMatch.encode('utf-8')).hexdigest()
        if myPassword == checkHash:
            print("mySuperSecretPassword" + " = " + isMatch)
            print(myPassword + " = " + checkHash)
        if count % 10000 == 0:
            print("Checking: " + str(count) + ", Hash: " + checkHash)
        count+=1

if __name__ == "__main__":
    main()
