"""Bigrams are pairs of adjacent words."""

import random
from typing import List, Tuple

from lib230 import record


_Bigram = Tuple[str, str]


def _bigrams_in(corpus: List[str]) -> List[_Bigram]:
    """Turns a source of strings into a source of its bigrams. In particular,
    apply this to an iterable that produces the words in a corpus, and the
    resulting iterable produces the bigrams in the corpus.

    >>> list(_bigrams_in(['a', 'b', 'c', 'd']))
    [('a', 'b'), ('b', 'c'), ('c', 'd')]
    """
    result: List[_Bigram] = []
    previous = None
    for current in corpus:
        if previous is not None:
            result.append((previous, current))
        previous = current
    return result


# The `init=False` option to @record tells it not to define
# method __init__ for us, so we can define it ourselves. Method
# __init__ is called every time we create an object, so customizing
# lets us customize our construction behavior. In this case, the
# default would be to take `_all_bigrams` as an (optional) argument,
# but by defining our own __init__ we can choose to take no arguments
# instead.

@record(init=False)
class BigramModel:
    """A Markov model as a collection of bigrams."""

    _all_bigrams: List[_Bigram]

    def __init__(self) -> None:
        """Constructs a new, empty bigram model.

        >>> m = BigramModel()
        >>> len(m)
        0
        """
        self._all_bigrams = []

    def __len__(self) -> int:
        """Returns the number of bigrams (counting repeats) that this model
        is trained on.

        >>> m = BigramModel()
        >>> len(m)
        0
        >>> m.train(str(i) for i in range(4))
        >>> len(m)
        3
        """
        return len(self._all_bigrams)

    def train_one(self, fst: str, snd: str) -> None:
        """Adds one bigram (`fst`, `snd`) to the model.

        >>> m = BigramModel()
        >>> m.train_one('hello', 'world')
        >>> len(m)
        1
        >>> m.train_one('hello', 'world')
        >>> len(m)
        2
        """
        self._all_bigrams.append((fst, snd))

    def train(self, corpus: List[str]) -> None:
        """Trains the model using all bigrams in the given corpus.

        >>> m = BigramModel()
        >>> m.train(['a', 'b', 'c', 'd', 'e', 'a'])
        >>> len(m)
        5
        >>> m.next('e')
        'a'
        """
        for fst, snd in _bigrams_in(corpus):
            self.train_one(fst, snd)

    def check_one(self, fst: str, snd: str) -> bool:
        """Checks whether bigram (`fst`, `snd`) could be produced by
        this model.

        >>> m = BigramModel()
        >>> m.train(['a', 'b', 'a', 'c', 'a', 'd', 'a'])
        >>> m.check_one('a', 'b')
        True
        >>> m.check_one('b', 'a')
        True
        >>> m.check_one('b', 'c')
        False
        """
        return (fst, snd) in self._all_bigrams

    def check(self, text: List[str]) -> bool:
        """Checks whether the given text could be produced by this model.

        >>> m = BigramModel()
        >>> m.train(['a', 'b', 'a', 'c', 'a', 'd', 'a'])
        >>> m.check(['b', 'a', 'c', 'a', 'd'])
        True
        >>> m.check(['b', 'a', 'd'])
        True
        >>> m.check(['c', 'a', 'b'])
        True
        >>> m.check(['a', 'a'])
        False
        """
        for fst, snd in _bigrams_in(text):
            if not self.check_one(fst, snd):
                return False
        return True

    def next(self, fst: str) -> str:
        """Given the current state, returns the randomly selected
        next state.

        >>> m = BigramModel()
        >>> m.train_one('one', 'two')
        >>> m.train_one('two', 'three')
        >>> m.train_one('two', 'three')
        >>> m.next('two')
        'three'
        """
        return random.choice(self._possibilities(fst))

    def _possibilities(self, state: str) -> List[str]:
        """Returns a list of all possible next words at
        the appropriate frequencies.

        >>> m = BigramModel()
        >>> m.train('a bee a bee a bee a cow'.split())
        >>> list(m._possibilities('a'))
        ['bee', 'bee', 'bee', 'cow']
        >>> list(m._possibilities('cow'))
        []
        """
        return [snd for fst, snd in self._all_bigrams if fst == state]

    def babble(self, n: int, start: str = '', stop: str = '') -> List[str]:
        """Produces a sequence of words randomly from the model.

        >>> m = BigramModel()
        >>> m.train(['', 'a', 'b', 'c', ''])
        >>> list(m.babble(6))
        ['', 'a', 'b', 'c', '', 'a', 'b', 'c', '']
        """
        state = start
        result = [state]
        while state != stop or len(result) < n:
            state = self.next(state)
            result.append(state)
        return result
