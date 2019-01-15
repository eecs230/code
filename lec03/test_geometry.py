from math import isclose, pi

from geometry import *


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


def test_circumference():
    c = Circle(Position(3, 6), 2)
    assert isclose(c.circumference(), 4 * pi)


def test_contains():
    c = Circle(Position(0, 0), 5)
    assert c.contains(Position(0, 0))
    assert c.contains(Position(2.9, 3.9))
    assert not c.contains(Position(3, 4))
    assert c.contains(Position(4.9, 0))
    assert c.contains(Position(-4.9, 0))
    assert not c.contains(Position(5, 0))
    assert not c.contains(Position(-5, 0))

