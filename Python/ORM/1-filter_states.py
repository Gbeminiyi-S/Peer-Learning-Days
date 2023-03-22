#!/usr/bin/python3
import MySQLdb

if __name__ == "__main__":
    db = MySQLdb.connect(user="root", passwd="", db="hbtn_0e_0_usa")
    cursor = db.cursor()
    cursor.execute("SELECT * FROM states WHERE BINARY name LIKE 'N%'")
    states = cursor.fetchall()

    for state in states:
        print(state)

cursor.close()
db.close()
