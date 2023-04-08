#!/usr/bin/python3
import sys
import requests


if __name__ == "__main__":
    url = sys.argv[1]
    mydata = {'email': sys.argv[2]}

    response = requests.post(url, data=mydata)
    print(response.text)
