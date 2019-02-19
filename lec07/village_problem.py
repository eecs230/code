#!/usr/bin/env python3

"""
In a particular village (of n families), each family has a 75% chance of
wanting children, and when a family has one or more children, they have
a 25% chance of wanting another. Additionally, children are sorted into
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


class Child(Enum):
    """Models a child."""
    GIRL = 'G'
    BOY = 'B'

    @classmethod
    def random(cls) -> 'Child':
        """Returns child with equal probability of each gender."""
        return r.choice([Child.GIRL, Child.BOY])

    def is_final(self) -> bool:
        """Checks whether this child is final, in the sense that no
        more children are allowed after.
        """
        return self is Child.BOY

    def __str__(self) -> str:
        return self.value


@record(init=False)
class Family:
    """Models a family.

     - _pfirst - probability of first child
     - _pmore - probability of each additional child
     - _children - list of children
    """
    _pfirst:   float
    _pmore:    float
    _children: List[Child]

    def __init__(self, pfirst: float, pmore: float) -> None:
        self._pfirst = pfirst
        self._pmore = pmore
        self._children = []
        while self._more_allowed() and r.random() < self._pwants_child():
            self._children.append(Child.random())

    def _pwants_child(self) -> float:
        """Determines the probability that this family wants a child."""
        return self._pmore if self._children else self._pfirst

    def _more_allowed(self) -> bool:
        """Determines whether this family is allowed an additional child."""
        return not (self._children and self._children[-1].is_final())

    def __len__(self) -> int:
        """Returns the number of children in the family."""
        return len(self._children)

    def __iter__(self) -> Iterator[Child]:
        """Allows iterating over the children of the family."""
        return self._children.__iter__()

    def __str__(self) -> str:
        return 'Family({})'.format(
            ''.join(str(child) for child in self._children))


@record(init=False)
class Village:
    """Models a village.

     - _families - the list of families
    """

    _families: List[Family]

    def __init__(self, n: int = 100, pfirst: float = 0.75, pmore: float = 0.25) -> None:
        """Constructs a new, random village of the given size and with the given
        reproduction probabilities.
        """
        self._families = [ Family(pfirst, pmore) for _ in range(n) ]

    def __len__(self) -> int:
        return len(self._families)

    def __iter__(self) -> Iterator[Family]:
        return self._families.__iter__()

    def __str__(self) -> str:
        return ''.join(str(family) + '\n' for family in self._families)


if __name__ == '__main__':
    print(Village())

