#!/usr/bin/python3
import sys
import requests


if __name__ == "__main__":
    if len(sys.argv) == 1:
        mydata = {'q': ""}
    else:
        mydata = {'q': sys.argv[1]}

    req = requests.post("http://0.0.0.0:5000/search_user", data=mydata)

    try:
        req = req.json()
        if req == {}:
            print("No result")
        else:
            print(f'[{response.get("id")}] {response.get("name")}')
    except ValueError:
        print("Not a valid JSON")
