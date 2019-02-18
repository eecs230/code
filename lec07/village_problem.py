#!/usr/bin/env python3

"""
In a particular village (of n families), each family has a 50% chance of
wanting children, and when a family has one or more children, they have
a 75% chance of wanting another. Additionally, children are sorted into
boy-children and girl-children, and according to the village's rules,
no family may have more than one boy-child.

We want to model the village (given n) to answer questions like:

 - What is the average number of children per family?
 - What is the average number of boy children per family?
 - What is the average number of girl children per family?
 - What percentage of families with children end with a girl child?
 - ...?
"""

from enum import Enum, auto
from typing import List, Iterator
import random as r

from lib230 import record, Factory


class Village:
    """Models a village."""

    def __init__(self, n: int = 100, pfirst: float = 0.5, pmore: float = 0.75) -> None:
        """Constructs a new, random village of the given size and with the given
        reproduction probabilities.
        """
        pass

    def __len__(self) -> int:
        pass

    def __iter__(self) -> Iterator[Family]:
        pass

    def __str__(self) -> str:
        pass


if __name__ == '__main__':
    print(Village())

