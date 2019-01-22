"""More examples of data definitions (classes).

Two kinds:

  - Structs (named tuples)
  - Enums

Each class should have a purpose statement, and maybe some doctests.
"""


from enum import Enum, auto
from typing import Optional
from lib230 import record


# Example 1: car share ride


@record
class Person:
    id:     int
    name:   str


# TODO
@record
class Location:
    pass


@record
class Ride:
    passenger:  Person
    driver:     Person
    start:      Location
    end:        Location


# Example 2: cardinal directions


class CardinalDirection(Enum):
    NORTH = auto()
    SOUTH = auto()
    EAST = auto()
    WEST = auto()


# Example 3: flowering plants



# Example 4: electronic medical records


