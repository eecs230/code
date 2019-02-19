#!/usr/bin/env python3

"""
In a particular village (of n families), each family has a 75% chance of
wanting children, and when a family has one or more children, they have
a 25% chance of wanting another. Additionally, children are sorted into
boy-children and girl-children, and according to the village's rules,
no family may have more than one boy-child.

We want to model the village (given n) to answer questions like:

 - What is the total number of children, boys, girls?
 - What is the average number of children / boys / girls per family?
 - What percentage of families with children end with a girl child?
 - What is the ratio of one-boy families to one-girl families?
 - ...?
"""

from typing import Any, Iterator

from lib230 import record


@record(init=False)
class Village:
    """Models a village."""

    def __init__(self, n: int = 100, pfirst: float = 0.75, pmore: float = 0.25) -> None:
        """Constructs a new, random village of the given size and with the given
        reproduction probabilities.
        """
        pass

    def __len__(self) -> int:
        return 0  # TODO: in class

    def __iter__(self) -> Iterator[Any]:
        return [].__iter__()  # TODO: in class

    def __str__(self) -> str:
        return ''.join(str(family) + '\n' for family in self)


if __name__ == '__main__':
    print(Village())

