import doctest
def print_abc():
    """
    >>> print_abc()
    aaa
    b4b
    ccc
    """
    print("aaa\nccc\nddd")

doctest.testmod(optionflags=doctest.REPORT_NDIFF)
