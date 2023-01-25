#!/usr/bin/python3

def append_after(filename="", search_string="", new_string=""):
    new_text = ""
    with open(filename, encoding="utf-8") as f:
        for line in f:
            new_text += line
            if search_string in line:
                new_text += new_string

    with open(filename, 'w', encoding="utf-8") as f:
        f.write(new_text)
