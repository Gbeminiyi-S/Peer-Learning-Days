#!/usr/bin/python3
import sys
from model_state import Base, State
from sqlalchemy.orm import sessionmaker
from sqlalchemy import create_engine

if __name__ == "__main__":
    # creating the link to database
    engine = create_engine("mysql+mysqldb://{}:{}@localhost/{}"
                            .format(sys.argv[1], sys.argv[2], sys.argv[3]))

    # Creating table
    Base.metadata.create_all(engine)
    
    # Create a new Session instance bound to the engine that we created
    Session = sessionmaker(bind=engine)
    session = Session()

    # Query data
    state = session.query(State).filter(State.name == sys.argv[4]).first()

    # Print our result
    if state is None:
        print("Not Found")
    else:
        print(state.id)

    # Close the session
    session.close()
