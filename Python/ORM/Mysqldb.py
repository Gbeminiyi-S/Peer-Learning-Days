#!/usr/bin/python3
import MySQLdb

db = MySQLdb.connect(user="root", passwd="", db="PLD")
cursor = db.cursor()
songs = ('Purple Haze', 'All Along the Watch Tower', 'Foxy Lady')
for song in songs:
    cursor.execute("INSERT INTO song (title) VALUES (%s)", (song,))
print("Auto Increment ID: %s" % cursor.lastrowid)
print(cursor.description);

cursor.execute("SELECT * FROM song")
