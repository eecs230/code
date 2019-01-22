"""More examples of data definitions (classes).

Two kinds:

  - Structs (named tuples)
  - Enums

Each class should have a purpose statement, and maybe some doctests.
"""


from enum import Enum, auto
from typing import NamedTuple, Optional


# Example 1: car share ride


# Example 2: cardinal directions


class CardinalDirection(Enum):
    NORTH = auto()
    SOUTH = auto()
    EAST = auto()
    WEST = auto()
