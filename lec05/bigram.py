"""Bigrams are pairs of adjacent words."""

import random
from enum import Enum, auto
from typing import List, Tuple, Iterable

from lib230 import record, Factory


def _bigrams_in(corpus: Iterable[str]) -> Iterable[Tuple[str, str]]:
    """Turns a source of strings into a source of its bigrams. In particular,
    apply this to an iterable that produces the words in a corpus, and the
    resulting iterable produces the bigrams in the corpus.

    >>> list(_bigrams_in(['a', 'b', 'c', 'd']))
    [('a', 'b'), ('b', 'c'), ('c', 'd')]
    """
    previous = None
    for current in corpus:
        if previous is not None:
            yield previous, current
        previous = current


@record
class BigramModel:
    """A Markov model as a collection of bigrams."""

    Bigram = Tuple[str, str]

    _all_bigrams: List[Bigram] = Factory(list)

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

    def train(self, corpus: Iterable[str]) -> None:
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

    def check(self, text: Iterable[str]) -> bool:
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
        options = [w2 for w1, w2 in self._all_bigrams if w1 == fst]
        return random.choice(options)

