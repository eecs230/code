#!/usr/bin/env python3
"""A program for detecting which positions are inside a target circle."""

from geometry import Circle, Position


def input_position(prompt: str = 'Enter a position: ') -> Position:
    """Reads a Position from the standard input."""
    x, y = input(prompt).split()
    return Position(float(x), float(y))


def input_circle() -> Circle:
    """Reads a Circle from the standard input."""
    center = input_position('Enter the circle’s center: ')
    radius = float(input('Enter the circle’s radius: '))
    return Circle(center, radius)


def main():
    target = input_circle()
    while True:
        candidate = input_position()
        if target.contains(candidate):
            print('Hit!')
        else:
            print('Miss!')


# This tells Python to call our main function when someone runs this
# file directly, but not when they load it, say, for testing.
if __name__ == '__main__':
    main()

