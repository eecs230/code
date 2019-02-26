from __future__ import annotations
from abc import abstractmethod
from typing import Generic, Optional, TypeVar


from lib230 import record


T = TypeVar('T')


@record(init=False)
class _Node(Generic[T]):
    """Private helper class from which trees are built."""
    key:    str
    value:  T
    left:   Optional[_Node[T]]
    right:  Optional[_Node[T]]

    def __init__(self, key: str, value: T):
        self.key = key
        self.value = value
        self.left = None
        self.right = None


class _NodeRef(Generic[T]):
    """Attempt to simplify insertion (and removal?) by hiding whether
    the current node is a root, left child, or right child, and letting
    us update it without worrying about which kind it is. The way this
    works is that this class defines the protocol for working with such
    a thing, and then other classes define the behavior for the three
    specific cases.
    """
    @abstractmethod
    def get_optional(self) -> Optional[_Node[T]]:
        """Returns the current node, which may be `None`."""
        raise NotImplementedError

    @abstractmethod
    def set(self, replacement: Optional[_Node[T]]) -> None:
        """Replaces the current node with the given node or `None`."""
        raise NotImplementedError

    def __bool__(self) -> bool:
        """Returns whether the current node is not `None`."""
        return self.get_optional() is not None

    def get(self) -> _Node[T]:
        """Gets the non-None value of the current node. Raises if it's None."""
        node = self.get_optional()
        if node is None:
            raise AttributeError
        return node

    def key(self) -> str:
        """Gets the key of the current (non-None) node."""
        return self.get().key

    def value(self) -> T:
        """Gets the value of the current (non-None) node."""
        return self.get().value

    def set_value(self, value: T) -> None:
        """Sets the value of the current (non-None) node."""
        self.get().value = value

    def left(self) -> _NodeRef[T]:
        """Gets a reference to the left child of the current (non-None) node."""
        return _LeftRef(self.get())

    def right(self) -> _NodeRef[T]:
        """Gets a reference to the right child of the current (non-None) node."""
        return _RightRef(self.get())


class _NodeRefBase(_NodeRef[T]):
    """Common functionality for _LeftRef and _RightRef below."""
    _node: _Node[T]

    def __init__(self, node: _Node[T]) -> None:
        self._node = node


class _LeftRef(_NodeRefBase[T]):
    """Reference to a node that is a left child."""
    def get_optional(self) -> Optional[_Node[T]]:
        return self._node.left

    def set(self, replacement: Optional[_Node[T]]) -> None:
        self._node.left = replacement


class _RightRef(_NodeRefBase[T]):
    """Reference to a node that is a right child."""
    def get_optional(self) -> Optional[_Node[T]]:
        return self._node.right

    def set(self, replacement: Optional[_Node[T]]) -> None:
        self._node.right = replacement


@record(init=False)
class Bst(Generic[T]):
    """A dictionary mapping strings to `T`s, represented as a binary
    search tree."""

    _root: Optional[_Node[T]]
    _len:  int

    def __init__(self) -> None:
        """Constructs the empty BST.

        >>> b = Bst()
        >>> len(b)
        0
        >>> not b
        True
        """
        self._root = None
        self._len = 0

    def __len__(self) -> int:
        return self._len

    def __bool__(self) -> bool:
        return self._len != 0

    def insert_rec(self, key: str, value: T) -> None:
        """Recursive insertion. Relatively simple, but doesn't work for
        big trees.

        >>> b = Bst()
        >>> len(b)
        0
        >>> b.insert_rec('hello', 5)
        >>> len(b)
        1
        >>> b.insert_rec('goodbye', 7)
        >>> len(b)
        2
        """
        def helper(curr: Optional[_Node[T]]) -> _Node[T]:
            if curr is None:
                self._len += 1
                return _Node(key, value)
            elif key < curr.key:
                curr.left = helper(curr.left)
            elif key > curr.key:
                curr.right = helper(curr.right)
            else:
                curr.value = value
            return curr
        self._root = helper(self._root)

    def __contains__(self, key: str) -> bool:
        """Implements the `in` operator -- key membership.

        >>> b = Bst()
        >>> b['hello'] = 5
        >>> 'hello' in b
        True
        >>> 'goodbye' in b
        False
        """
        return False  # TODO

    def __getitem__(self, key: str) -> T:
        """Implements indexing -- lookup. Raises `KeyError` if not found.

        >>> b = Bst()
        >>> b['hello'] = 5
        >>> b['hello']
        5
        >>> b['hello'] = 7
        >>> b['hello']
        7
        """
        raise KeyError(key)  # TODO

    def __setitem__(self, key: str, value: T) -> None:
        """Implements index-assignment -- insertion. This is more complicated
        that the recursive insertion above, but also more efficient.

        >>> b = Bst()
        >>> len(b)
        0
        >>> b['a'] = 97
        >>> b['b'] = 98
        >>> len(b)
        2
        >>> b['c'] = 99
        >>> len(b)
        3
        """
        if self._root is None:
            self._root = _Node(key, value)
            self._len = 1
        else:
            curr = self._root
            while True:
                if key < curr.key:
                    if curr.left is None:
                        curr.left = _Node(key, value)
                        self._len += 1
                        return
                    curr = curr.left
                elif key > curr.key:
                    if curr.right is None:
                        curr.right = _Node(key, value)
                        self._len += 1
                        return
                    curr = curr.right
                else:
                    curr.value = value
                    return

    def insert_alt2(self, key: str, value: T) -> None:
        """A different way to try to simplify insertion."""
        prev = None
        curr = self._root

        while curr is not None:
            if key < curr.key:
                prev = (curr, True)
                curr = curr.left
            elif key > curr.key:
                prev = (curr, False)
                curr = curr.right
            else:
                curr.value = value
                return

        self._len += 1
        new_node = _Node(key, value)
        if prev is None:
            self._root = new_node
        elif prev[1]:
            prev[0].left = new_node
        else:
            prev[0].right = new_node

    class _RootRef(_NodeRef[T]):
        """Helper class for simplifying insertion."""
        _bst: Bst

        def __init__(self, bst: Bst[T]) -> None:
            self._bst = bst

        def get_optional(self) -> Optional[_Node]:
            return self._bst._root

        def set(self, replacement: Optional[_Node]) -> None:
            self._bst._root = replacement

    def insert_ref(self, key: str, value: T) -> None:
        """Simplifies insertion with a helper class (or five)."""
        curr: _NodeRef[T] = self._RootRef(self)
        while curr:
            if key < curr.key():
                curr = curr.left()
            elif key > curr.key():
                curr = curr.right()
            else:
                curr.set_value(value)
                return
        self._len += 1
        curr.set(_Node(key, value))

    def __delitem__(self, key: str) -> None:
        raise KeyError(key)  # TODO


