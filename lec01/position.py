from typing import NamedTuple
from math import sqrt


class Position(NamedTuple):
    """Represents a 2-D position."""
    x: float
    y: float


def distance(p: Position, q: Position) -> float:
    """Computes the Euclidean distance between two positions."""
    dx = p.x - q.x
    dy = p.y - q.y
    return sqrt(dx * dx + dy * dy)


