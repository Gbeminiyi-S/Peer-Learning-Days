#!/usr/bin/python3

def inherits_from(obj, a_class):
    return issubclass(type(obj), a_class) and a_class != type(obj)
