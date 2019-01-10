"""Some computational geometry.

Includes definitions for points and circles, and some operations
thereupon.
"""

from math import pi, sqrt
from typing import NamedTuple


def sqr(x: float) -> float:
    """Computes the square of the given number.

    >>> sqr(0)
    0
    >>> sqr(5)
    25
    """
    return x * x


class Position(NamedTuple):
    """Represents a 2-D position."""
    x: float
    y: float


def distance(p: Position, q: Position) -> float:
    """Computes the Euclidean distance between two positions.

    >>> a = Position(0, 0)
    >>> b = Position(3, 4)
    >>> distance(a, a)
    0.0
    >>> distance(a, b)
    5.0
    """
    dx = p.x - q.x
    dy = p.y - q.y
    return sqrt(sqr(dx) + sqr(dy))


def manhattan_distance(p: Position, q: Position) -> float:
    """Computes the Manhattan distance between two positions.

    >>> a = Position(0, 0)
    >>> b = Position(3, 4)
    >>> manhattan_distance(a, a)
    0
    >>> manhattan_distance(a, b)
    7
    """
    dx = p.x - q.x
    dy = p.y - q.y
    return abs(dx) + abs(dy)


class Circle(NamedTuple):
    """Represents a circle positioned on a 2-D plane."""
    center: Position
    radius: float

    def area(self) -> float:
        """Computes the area of this circle.

        >>> Circle(Position(2, 7), 1).area() - pi
        0.0
        >>> Circle(Position(2, 7), 3).area() - 9 * pi
        0.0
        """
        return pi * sqr(self.radius)

    def circumference(self) -> float:
        """Computes the circumference of this circle

        >>> Circle(Position(2, 7), 1).circumference() - 2 * pi
        0.0
        >>> Circle(Position(2, 7), 3).circumference() - 6 * pi
        0.0
        """
        return 2 * pi * self.radius

