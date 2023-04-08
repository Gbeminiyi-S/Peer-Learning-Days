#!/usr/bin/python3
import sys
import requests


if __name__ == "__main__":
    url = 'https://api.github.com/repos/Gbeminiyi-S/AirBnB_clone/commits'

    r = requests.get(url)
    commits = r.json()

    for commit in commits:
        sha = commit.get("sha")
        author = commit["commit"]["author"]["name"]
        print(f"{sha}: {author}")
