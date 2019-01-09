from position import *


def test_distance():
    a = Position(0, 0)
    b = Position(3, 4)
    assert distance(a, b) == 5

