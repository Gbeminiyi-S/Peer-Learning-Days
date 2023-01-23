#!/usr/bin/python3

def add_attribute(obj, attr, value):
    if '__dict__' not in dir(obj):
        raise TypeError("can't add new attribute")
    setattr(obj, attr, value)
