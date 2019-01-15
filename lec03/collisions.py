#!/usr/bin/env python3
"""A program for detecting which positions are inside a target
circle.

No error handling, so crashes on bad input.
"""

from geometry import Circle, Position


def input_position(prompt: str) -> Position:
    """Reads a Position from the standard input.

    Expects two numbers (x, y) on one line separated by space.
    """
    x, y = input(prompt).split()
    return Position(float(x), float(y))


def input_circle() -> Circle:
    """Reads a Circle from the standard input.

    Reads the center position on one line, then the radius on the next.
    """
    center = input_position("Enter the circle's center: ")
    radius = float(input("Enter the circle's radius: "))
    return Circle(center, radius)


def main():
    pass  # TODO


# This tells Python to call our main function when someone runs this
# file directly, but not when they load it, say, for testing.
if __name__ == '__main__':
    main()

