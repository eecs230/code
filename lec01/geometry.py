from typing import NamedTuple
from math import sqrt, pi


def sqr(x: float) -> float:
    """Computes the square of the given number."""
    return x * x


class Position(NamedTuple):
    """Represents a 2-D position."""
    x: float
    y: float


def distance(p: Position, q: Position) -> float:
    """Computes the Euclidean distance between two positions."""
    dx = p.x - q.x
    dy = p.y - q.y
    return sqrt(sqr(dx) + sqr(dy))


def manhattan_distance(p: Position, q: Position) -> float:
    """Computes the Manhattan distance between two positions."""
    dx = p.x - q.x
    dy = p.y - q.y
    return abs(dx) + abs(dy)


class Circle(NamedTuple):
    """Represents a circle positioned on a 2-D plane."""
    center: Position
    radius: float

    def area(self) -> float:
        """Computes the area of this circle."""
        return pi * sqr(self.radius)

    def circumference(self) -> float:
        """Computes the circumference of this circle"""
        return 2 * pi * self.radius

