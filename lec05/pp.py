from enum import Enum, auto
from typing import List, Iterable


def extract_ints(lines: Iterable[str]) -> List[int]:
    """Extracts all natural numbers in the given text into a list.

    >>> extract_ints(["hello 6", "goodbye 75"])
    [6, 75]
    >>> extract_ints(["hello6"])
    []
    >>> extract_ints(["hello,6"])
    [6]
    """
    class State(Enum):
        START = auto()
        IN_WORD = auto()
        IN_NUMBER = auto()

    result = []
    token = ''
    state = State.START

    for line in lines:
        for c in line:
            if state is State.START:
                if c.isalpha():
                    state = State.IN_WORD
                elif c.isdigit():
                    token = c
                    state = State.IN_NUMBER
                else:
                    pass  # stays in START state
            elif state is State.IN_WORD:
                if c.isalnum():
                    pass  # stays in IN_WORD state
                else:
                    state = State.START
            else:
                if c.isalpha():
                    state = State.IN_WORD
                elif c.isdigit():
                    token += c
                    # stays in IN_NUMBER state
                else:
                    result.append(int(token))
                    state = State.START
        if state is State.IN_NUMBER:
            result.append(int(token))
        state = State.START
    return result


TURING_QUOTE = '''Mathematical reasoning may be regarded rather
                  schematically as the exercise of a combination of two
                  facilities , which we may call intuition and ingenuity .
                  The activity of the intuition consists in making
                  spontaneous judgements which are not the result of
                  conscious trains of reasoning .'''.split() \
               + [''] + \
               '''The exercise of ingenuity in mathematics consists in
                  aiding the intuition through suitable arrangements of
                  propositions , and perhaps geometrical figures or drawings .
               '''.split()


def wrap_text(tokens: Iterable[str], width: int = 72) -> List[str]:
    """Iterates over the words in the input, constructing a list
    of lines of length <= `width`.

    For more examples, see `print_text`, as those are easier to read.

    >>> wrap_text(['a', 'bc', 'def', 'ghij', 'k'], 6)
    ['a bc', 'def', 'ghij k']
    >>> wrap_text(['a', 'bc', 'def', ',', 'ghij', 'k'], 6)
    ['a bc', 'def,', 'ghij k']
    """
    result: List[str] = []
    pass  # TODO: Homework 3
    return result


def print_text(words: List[str], width: int = 72) -> None:
    """Line-wraps the given list of tokens and prints it.

    >>> print_text(TURING_QUOTE, 40)
    Mathematical reasoning may be regarded
    rather schematically as the exercise of
    a combination of two facilities, which
    we may call intuition and ingenuity. The
    activity of the intuition consists in
    making spontaneous judgements which are
    not the result of conscious trains of
    reasoning.
    <BLANKLINE>
    The exercise of ingenuity in mathematics
    consists in aiding the intuition through
    suitable arrangements of propositions,
    and perhaps geometrical figures or
    drawings.
    >>> print_text(TURING_QUOTE, 60)
    Mathematical reasoning may be regarded rather schematically
    as the exercise of a combination of two facilities, which we
    may call intuition and ingenuity. The activity of the
    intuition consists in making spontaneous judgements which
    are not the result of conscious trains of reasoning.
    <BLANKLINE>
    The exercise of ingenuity in mathematics consists in aiding
    the intuition through suitable arrangements of propositions,
    and perhaps geometrical figures or drawings.
    """
    for line in wrap_text(words, width):
        print(line)


def tokenize_text(lines: List[str]) -> List[str]:
    """Given a list of lines, tokenizes the text into words, individual
    punctuation marks, and paragraph separators (represented as ''). The
    result never starts nor ends with a paragraph separator, and there
    is never more than one paragraph separator in a row.

    >>> tokenize_text(['Mathematical reasoning may be regarded'])
    ['Mathematical', 'reasoning', 'may', 'be', 'regarded']
    >>> tokenize_text(['two facilities, which we may call'])
    ['two', 'facilities', ',', 'which', 'we', 'may', 'call']
    >>> tokenize_text(['graf one', '', 'graf two'])
    ['graf', 'one', '', 'graf', 'two']
    >>> tokenize_text(['', 'a', '', '', 'b', ''])
    ['a', '', 'b']
    >>> tokenize_text(["Don't forget about apostrophes."])
    ["Don't", 'forget', 'about', 'apostrophes', '.']
    """
    result: List[str] = []
    pass  # TODO: Homework 3
    return result

