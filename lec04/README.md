# Lecture 3: Designing and Testing Functions

A *library* a collection of reusable code for some purpose, which you
might import into another program.

In `geometry.py`, you will find a small library for doing computational
geometry. It defines two new kinds of data, `Position`s and `Circle`s
and a few operations on that data.

In `test_geometry.py` are tests for `geometry.py`. The functions defined
in `geometry.py` include some doctests, but usually we will want
additional tests to be kept out of the way somewhere.

In `collisions.py` is a *program* that depends on the `geometry` library
to do its work. It interacts with the user by performing I/O.

