#!/usr/bin/python3

def matrix_divided(matrix, div):
    if not isinstance(div, (int, float)):
        raise TypeError('div must be a number')
    if not div:
        raise ZeroDivisionError('division by zero')
    if not isinstance(matrix, list):
        raise TypeError('matrix must be a matrix (list of lists) '
                        'of integers/floats')

    for row in matrix:
        if not isinstance(row, list):
            raise TypeError('matrix must be a matrix (list of lists) '
                            'of integers/floats')
        if len(row) != len(matrix[0]):
            raise TypeError('Each row of the matrix must have the same size')
        for element in row:
            if not isinstance(element, (int, float)):
                raise TypeError('matrix must be a matrix (list of lists) '
                                'of integers/floats')

    m = matrix.copy()
    return list(map(lambda x: list(map(lambda y: round(y / div, 2), x)), m))
