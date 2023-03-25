#!/usr/bin/python3
""" Creating a model for City table
"""
from sqlalchemy import Column, Integer, String, ForeignKey
from model_state import Base


class City(Base):
    """ Represent the schematics for the City table
    __tablename__ (str): The name of the MySQL table to store Cities
    id (sqlalchemy.Integer): The city's id
    name (sqlalchemy.String): The city's name
    state_id (sqlalchemy.Integer): Foreign key to states
    """
    __tablename__ = "cities"
    id = Column(Integer, primary_key=True)
    name = Column(String(128), nullable=False)
    state_id = Column(Integer, ForeignKey('states.id'))
