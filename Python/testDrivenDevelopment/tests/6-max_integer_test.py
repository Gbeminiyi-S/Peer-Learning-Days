#!/usr/bin/python3
"""Unittest for max_integer([..])
"""
import unittest
max_integer = __import__('6-max_integer').max_integer

class TestMaxInteger(unittest.TestCase):
    """Tests different scenarios"""

    def test_end(self):
        """Tests for max if at end"""
        sample = [1, 3, 0, 5]
        self.assertEqual(max_integer(sample), 5)

    def test_beginning(self):
        """Tests for max if at beginning"""
        sample = [4, 3, 0, 1]
        self.assertEqual(max_integer(sample), 4)

    def test_middle(self):
        """Tests for max if at middle"""
        sample = [1, 3, 7, 5, 2]
        self.assertEqual(max_integer(sample), 7)

    def test_negative(self):
        """Tests for max one negative value exists"""
        sample = [1, 3, 0, -5]
        self.assertEqual(max_integer(sample), 3)

    def test_all_negative(self):
        """Tests for max if all negative numbers"""
        sample = [-1, -3, -7, -5]
        self.assertEqual(max_integer(sample), -1)
    
    def test_one_element(self):
        """Tests for max if only one element"""
        sample = [1]
        self.assertEqual(max_integer(sample), 1)

    def test_empty(self):
        """Tests for max if empty"""
        sample = []
        self.assertEqual(max_integer(sample), None)

