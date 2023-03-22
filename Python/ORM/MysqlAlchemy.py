#!/usr/bin/python3
from sqlalchemy import create_engine

engine = create_engine('mysql+mysqldb://root:@localhost/PLD')

engine.connect()
print(engine)
