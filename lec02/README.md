# Lecture 2: Expressions, Functions, and the Design Recipe

[Lab 1]:
    https://github.com/eecs230/lab1#testing-that-everything-works

This repository includes both lectures notes and code. You are encourage
to follow along by forking it to your own account and then cloning your
fork in PyCharm. Lab 1 includes [instructions][Lab 1] on how to do this,
so you should refer there if you do not remember how. (You can also
clone this repo without forking, but you won't be able to push any
changes you might make.)

Once you have opened the cloned Git repo in PyCharm, you may have to
edit a Python source file and wait a few seconds for PyCharm to
configure your Python environment. When it's settled down, you'll
be ready to move on.

## Python as (fancy) calculator

The first way will learn to use Python is as a calculator. In PyCharm,
go to the *Tools* menu and select *Python Console…*. This should open
a new pane, which contains some information about your Python
installation, followed by the Python console *prompt*:

```Python console
>>>
```

This means that Python is waiting for you to type something for it to
do.

### The arithmetic of number

One thing you can ask it to do is arithmetic:

```Python console
>>> 2 + 3
5
```

In the above, Python prints `>>>`. You type `2 + 3` and press enter. Python
responds with `5`.

Python knows a number of standard arithmetic operations:
 
```Python console
>>> 2 - 3
-1
>>> 2 * 3
6
>>> 2 ** 3   # exponentiation
8
```
 
Python knows the same order of operations you learned in elementary
school. As in math class, you can use parentheses to override the
standard order:

```Python console
>>> 10 - 2 * 3
4
>>> (10 - 2) * 3
24
```

But there are a few ways that Python diverges from math. You may
have noticed above that none of the examples demonstrated division.
This is because division often has a fractional result, and
computing with fractions gets weird. Watch:

```Python console
>>> 9 / 3
3.0
>>> 10 / 3
3.3333333333333335
>>> 4095.7 + 0.000000000001
4095.7000000000007
```

First, the result of division in Python is always a *floating point*
number (which Python calls a `float`). This is the typical way that
computers work with fractional numbers, and the key to making it work
is that the precision is limited. Not every possible real number can be
represented in floating point, and when you perform numeric operations,
the results are often rounded to the nearest representable `float`.
The examples above show, for example, that the number
4095.700000000001 is not exactly representable, and instead we get
a close approximation.

If you want integer division, or modulus (the remainder), Python
has those too:

```Python console
>>> 10 // 3
3
>>> 10 % 3
1
```

### The arithmetic of Booleans

That said, programming is not only about numbers. There are other
kinds of data as well. One very simple kind is the Boolean—`bool` in
Python parlance—which is used to represent truth values. In Python,
these are written as `True` and `False`, and there are a variety
of logical operations for combining them:

```Python console
>>> not True
False
>>> not False
True
>>> True and True
True
>>> False and True
False
>>> True and False
False
>>> True or False
True
>>> False or False
False
>>> (True or False) and True
True
>>> (True or False) and False
False
```

Booleans are useful mostly because our programs often have to make
decisions based on the answer to a yes-or-no question. There are
a lot of questions we can ask. For example, here are some questions
we can ask about numbers:

```Python console
>>> 5 == 5
True
>>> 5 == 6
False
>>> 3 < 5
True
>>> 3 <= 5
True
>>> 5 < 5
False
>>> 5 <= 5
True
>>> 1 < 4 and 6 > 8
False
>>> 1 < 4 or 6 > 8
False
```

### The algebra of strings

Booleans are important but pretty unexciting. How about something more
exciting, then: text! In most programming languages, a value that stores
text is known as a *string* (`str` in Python).  In Python, strings are
written between matching quotation marks. We'll discuss the details of
string *literal* syntax later.

Like numbers and Booleans, strings support a variety of operations:

```Python console
>>> 'hello' + 'world'
'helloworld'
>>> 'helloworld'[0]     # indexing, 0-based
'h'
>>> 'helloworld'[1]
'e'
>>> 'helloworld'[3:6]   # slicing, 0-based
'low'
>>> ('hello' + 'world')[3:6]
'low'
>>> len('helloworld')
10
>>> 'hello'.startswith('he')
True
>>> 'hello'.endswith('he')
False
>>> 'ell' in 'hello'
True
>>> 'heo' in 'hello'
False
>>> 'a' < 'b'           # lexicographic ordering
True
>>> 'arc' < 'arcade'
True
>>> 'arc' < 'aardvark'
False
```


### Details of string literals

String *literals* (meaning, literal text written in your program) in
Python are enclosed in either single (`'`) or double (`"`) quotation marks.
Between the matching quotation marks, most characters stand for themselves,
but the backslash character (`\`) is an *escape* character, which means
that instead of standing for itself, it gives special meaning to something
that comes after it. For example:

  - `\n` stands for a newline character
  
  - `\'` stands for a single quotation mark character (which can be
    used to include a single quotation mark within a single-quoted
    string)

  - `\"` stands for a double quotation mark character (which can be
    used to include a double quotation mark within a double-quoted
    string)

  - `\\` stands for a single backslash
  


