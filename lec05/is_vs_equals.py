"""Examples of `==` versus `is`.

`==` tells us about *structural equality*; it asks whether two
objects are of the same class, with all equal field values?

`is` tells us about *object identity*; it asks whether two objects
are one an the same, as in created by the same call to the constructors.

Usually for comparing objects, you want structural equality
(`==`/`!=`), but there are a few cases where you want object identity
(`is`/`is not`):

  - For comparing `None` and enumerators (`Enum` values).

  - When you actually care about object identity, either because you are
    mutating objects (assigning new values to their fields), or you have
    a function or method that takes and returns in particular objects.
    For example, when sorting a list, you usually want to know that you
    get back a list containing the very same objects that you put in, not
    copies of them.
"""

from lib230 import record


@record
class IntPair:
    """A pair of ints.

    >>> f1 = IntPair(3, 4)
    >>> f2 = IntPair(3, 4)
    >>> f3 = IntPair(4, 5)
    >>> f4 = f1
    >>> f1 is f1
    True
    >>> f2 is f2
    True
    >>> f1 is f4
    True
    >>> f1 is f2
    False
    >>> f1 == f2
    True
    """
    a: int
    b: int

