"""More examples of data definitions (classes).

Two kinds:

  - Structs (named tuples)
  - Enums

Each class should have a purpose statement, and maybe some doctests.
"""


from enum import Enum, auto
from typing import NamedTuple, Optional


# Example 1: car share ride


class Person(NamedTuple):
    id:     int
    name:   str


# TODO
class Location(NamedTuple):
    pass


class Ride(NamedTuple):
    passenger:  Person
    driver:     Person
    start:      Location
    end:        Location


# Example 2: cardinal directions


class CardinalDirectin(Enum):
    NORTH = auto()
    SOUTH = auto()
    EAST = auto()
    WEST = auto()


