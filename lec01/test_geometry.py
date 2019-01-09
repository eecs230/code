from geometry import *
from math import pi, isclose


def test_distance():
    a = Position(0, 0)
    b = Position(3, 4)
    assert distance(a, b) == 5


def test_manhattan_distance():
    a = Position(0, 0)
    b = Position(3, 4)
    assert manhattan_distance(a, b) == 7


def test_area():
    c = Circle(Position(3, 6), 2)
    assert isclose(c.area(), 4 * pi)
