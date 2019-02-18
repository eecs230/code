#!/usr/bin/env python3

from enum import Enum, auto
from typing import List, Iterator
import random as r

from lib230 import record, Factory


class Child(Enum):
    GIRL = 'G'
    BOY = 'B'

    @classmethod
    def random(cls) -> 'Child':
        return r.choice([Child.GIRL, Child.BOY])

    def is_final(self) -> bool:
        return self is Child.BOY

    def __str__(self) -> str:
        return self.value


@record(init=False)
class Family:
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
        return self._pmore if self._children else self._pfirst

    def _more_allowed(self) -> bool:
        return not (self._children and self._children[-1].is_final())

    def __len__(self) -> int:
        return len(self._children)

    def __iter__(self) -> Iterator[Child]:
        return self._children.__iter__()

    def __str__(self) -> str:
        return 'Family({})'.format(
            ''.join(str(child) for child in self._children))


@record(init=False)
class Village:
    _families: List[Family]

    def __init__(self, n: int = 100, pfirst: float = 0.5, pmore: float = 0.75) -> None:
        self._families = [ Family(pfirst, pmore) for _ in range(n) ]

    def __len__(self) -> int:
        return len(self._families)

    def __iter__(self) -> Iterator[Family]:
        return self._families.__iter__()

    def __str__(self) -> str:
        return ''.join(str(family) + '\n' for family in self._families)


if __name__ == '__main__':
    print(Village())

