"""our first loop!

This file demonstates two design strategies:

 - Iteration over a range of ints

 - Composing smaller functions into larger ones

"""

from typing import Optional
from typing import Callable, Iterable


# "Helper function" for str_index. The idea is to move some of the work
# out into a smaller function that we can understand more easily and
# maybe test separately.
def _matches_at(needle: str, haystack: str, base: int) -> bool:
    """Returns whether `needle` matches the substring of the same
    length starting at index `base` of `haystack`.
    """
    if len(needle) > len(haystack) - base:
        return False
    for i in range(len(needle)):
        if needle[i] != haystack[base + i]:
            return False
    return True


def str_index(needle: str, haystack: str) -> Optional[int]:
    """Returns the first index in `haystack` where `needle` may be
    found, or None if `needle` is not a substring of `haystack`.

    >>> str_index('a', 'apple')
    0
    >>> str_index('l', 'apple')
    3
    >>> str_index('g', 'apple')
    >>> str_index('pl', 'apple')
    2
    """
    for i in range(len(haystack)):
        if _matches_at(needle, haystack, i):
            return i
    return None


def find_satisfies(haystack: Iterable[int],
                   needle: Callable[[int], bool]) -> Optional[int]:
    """Searches `haystack` for an `int` `i` such that `needle(i)` is
    true.

    >>> def divides(a: int, b: int) -> bool:
    ...     return b % a == 0
    >>> find_satisfies(range(1, 50),
    ...                lambda x: divides(3, x) and divides(5, x))
    15
    >>> find_satisfies(range(1, 50),
    ...                lambda x: divides(30, x) and divides(45, x))
    >>> find_satisfies(range(1, 100),
    ...                lambda x: divides(30, x) and divides(45, x))
    90
    """
    for i in haystack:
        if needle(i):
            return i
    return None


def str_index2(needle: str, haystack: str) -> Optional[int]:
    """Returns the first index in `haystack` where `needle` may be
    found, or None if `needle` is not a substring of `haystack`.

    >>> str_index('a', 'apple')
    0
    >>> str_index('l', 'apple')
    3
    >>> str_index('g', 'apple')
    >>> str_index('pl', 'apple')
    2
    """
    return find_satisfies(range(len(haystack)),
                          lambda i: _matches_at(needle, haystack, i))

