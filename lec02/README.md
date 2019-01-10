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

### The arithmetic of numbers

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
classes of data as well. One very simple kind is the Boolean—`bool` in
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
written between matching quotation marks.

> String *literals* (meaning, literal text written in your program) in
> Python are enclosed in either single (`'`) or double (`"`) quotation marks.
> Between the matching quotation marks, most characters stand for themselves,
> but the backslash character (`\`) is an *escape* character, which means
> that instead of standing for itself, it gives special meaning to something
> that comes after it. For example:
> 
>   - `\n` stands for a newline character
>   
>   - `\'` stands for a single quotation mark character (which can be
>     used to include a single quotation mark within a single-quoted
>     string)
> 
>   - `\"` stands for a double quotation mark character (which can be
>     used to include a double quotation mark within a double-quoted
>     string)
> 
>   - `\\` stands for a single backslash
>
> If you don't quite get this, try printing some strings:
>
> ```Python console
> >>> print('hello')
> hello
> >>> print("hello")
> hello
> >>> print('hello\nworld')
> hello
> world
> >>> print("Can't stop, won't stop.")
> Can't stop, won't stop.
> >>> print('"Cannot stop, will not stop," she said.')
> "Cannot stop, will not stop," she said.
> >>> print('"Can\'t stop, won\'t stop," she said.')
> "Can't stop, won't stop," she said.
> >>> print("\"Can't stop, won't stop,\" she said.")
> "Can't stop, won't stop," she said.
> ```

Like numbers and Booleans, strings support a variety of operations:

```Python console
>>> 'hello' + 'world'
'helloworld'
>>> 'a' + 'b' + 'c'
'abc'
>>> len('helloworld')
10
>>> 'helloworld'[0]     # indexing, 0-based
'h'
>>> 'helloworld'[1]
'e'
>>> 'helloworld'[3:6]   # slicing, 0-based
'low'
>>> ('hello' + 'world')[3:6]
'low'
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
>>> 3 * 'ab'
'ababab'
```

One thing you may have started to notice above is that the syntax for
string operations is fairly irregular. It includes:

  - Infix operators: `• + •`, `• * •`, `• < •`, `• in •`, etc.
  
  - Prefix function call syntax: `len(•)`
  
  - Postfix indexing syntax: `•[•]`
  
  - “Mix-fix” slicing syntax: `•[•:•]`
  
  - *Method call* syntax: `•.startswith(•)`, `•.endswith(•)`.

There are languages with syntax that is more regular than Python's (like,
say, only one way to notation applying an operation to operands). Keeping
track of which syntax you need in which case may make Python a bit harder
to learn, but its designer believes that varied syntax makes it easier
to read. You'll get used to it.

Another thing you might have noticed is that we used the same operator,
`+`, both to add numbers and to concatenate strings. These are not at
all the same operation! But the designer of Python (as well as many other)
languages thought that `+` for string concatenation would make sense to
people, and indeed it does. When the same operation applies to different
classes of data, and does different things for each, this is known as
*overloading*. Python offers some overloading, but not every operation
applies to every class of data:

```Python console
>>> 3 + 5
8
>>> '3' + '5'
'35'
>>> '3' + 5
Traceback (most recent call last):
  File "<input>", line 1, in <module>
TypeError: unsupported operand type(s) for +: 'int' and 'str'
```

When you try to apply an operation to a class of data for which it
doesn't make sense, this is often known as a *type error*. We know
what `+` means for numbers—add them. And we know what `+` means means
for strings—concatenate them. But Python does not define what `+`
means when given one string and one number; when such a computation is
attempted, Python stops your program and reports a type error.

Later, we will learn some techniques to avoid type errors in our
programs.

## Named values and reusable calculations

Now that we've seen how Python does elementary school arithmetic, let's
move on to middle school algebra. A central idea of algebra is that
we can make generic statements about potentially large categories of
things, rather than limiting our statements to talking about individual
things.

The key *mechanism* of algebra is that we can use names to to refer to
the things we really care about: values (*e.g.,* numbers, Booleans,
strings, etc.).

The easiest kind of named value is a *defined constant*. This happens
when there is a particular value that you frequently care about, but
the value itself is inconvenient. This includes mathematical constants
such as π and Euler's number *e*; dimensionless physical constants
such as Avogadro's number and the fine structure constant α; and
physical constants that requires units, such as Newton's gravitational
constant, the charge of an electron, the speed of light, and many more.

We can define constants in Python as well, and once defined, we can use
them in place of their values:

```Python console
>>> FT_TO_IN = 12
>>> 3 * FT_TO_IN
36
>>> PI = 3.14159265359
>>> PI
3.14159265359
>>> 4 * PI
12.56637061436
```

(Note that you do not need to define π in Python, but we aren't quite
ready to learn how to access the definition that Python provides.)

> This is a good place to mention that in Python, `==` means equality,
> whereas `=` means *definition* (and something else we'll see later).
> The Python phrase `a == b` is an *expression*, which computes a value,
> whereas the Python phrase `a = b` is a *statement*, which tells Python
> to do something. The expression `a == b` *evalutes* to a Boolean telling
> us whether `a` is equal to `b`. (They both must be defined already.)
> The statement `a = b` *defines* a new variable `a`, giving it the same
> value as `b`. (Variable `b` must already be defined, and variable `a`
> must not already be defined [1].)

The other kind of named value that we see in algebra class is the
*variable*. Variables are a bit more complicated than defined constants,
for a couple reasons:

 1. Instead of standing for one value, a variable usually stands for
    many possible values.
    
 2. Most programming languages' notions of “variable,” including
    Python’s, are quite different from what happens in mathematics.

We'll deal with 1 now and put off 2 for a while.

So, why is it useful for a variable to stand for many possible values?
What does that even mean? Well, variables allow us to express rules,
such as relationships between values. For example, in Python notation
(but not actually useful Python code),

```python
        inches == FT_TO_IN * feet
```

That is to say, the number of inches in some length is always equal
to 12 (the number of inches in a foot) times the number of feet in the
same length.

The most common type of rule want to write down in Python (and most
programming language) is a *function*, which specifies the rule
for computing some result that is related to some inputs in some useful
way. For example, we might write the rule for how to convert a length
in feet to a length in inches. How to do that conversion may seem to
you to follow directly from the equation above, but in most programming
languages, you need to be more explicit about the “direction” of the
computation.

Here's how you might write the function in traditional mathematical
notation: *i*(*f*) = 12*f*. This says that *i* (the number of inches)
is a function of one parameter *f* (the number of feet), and the result
is 12 times *f*.

Here's how you could define and then use the same function in Python:

```Python_console
>>> def ft_to_in(ft): return FT_TO_IN * ft
...

>>> ft_to_in(3)
36
>>> ft_to_in(10)
120
```

The point where we start writing functions, though, is the point where
we should advance beyond the Python console. Definitions typed in the
console are ephemeral—they go away when the console is closed. When we
want to write code that we can use multiple times, or even edit multiple
times while figuring it out, it's time to write it in a file.

## The Design Recipe

See `first.py` for our first example of a Python source file. It contains
definitions of the constant `FT_TO_IN` and the function `ft_to_in`. You may
notice that `ft_to_in` has grown quite a bit in length. The reason for this
is that when we design a function, we will actually go through a very specific
process along the way. The process (for now) has 4 steps:

 1. Header (name, signature, purpose): In this portion of the function
    (in this case, the first two lines), we specify:
     
       - the name of the function (`ft_to_in`);
       
       - its signature, which tells us the classes of its parameter(s)
         and result (`(ft: float) -> float`, because in Python, `float`
         includes `int`); and
         
       - a purpose statement, describing succinctly what the function is
         for (not how it works!).
         
    Note that the purpose statement is actually just the first part of
    a special string called a *docstring*.
 
 2. Functional examples: In the remainder of the docstring, we write
    a hypothetical console interaction with our function. This shows
    someone reading our code how to use the function and what to
    expect.
 
 3. Body: Here is where you fill in the part of the function that does
    the actual computation. For now, this will be a return statement
    consisting of the keyword `return` followed by an expression to
    compute the function's result.
 
 4. Testing: The console interaction that you wrote for your examples
    is actually an *automated test* that Python can run and check for
    you. However, first you will need to set up PyCharm to run it for you.
    
    From the configuration drop-down (in the toolbar, just to the left of
    the run button), choose either “Add Configuration…” or “Edit
    Configurations…” (whichever is available). In the window that opens,
    click the + sign in the upper left, find the “Python Tests” submenu,
    and select the “pytest” option. It's possible to configuration is to
    change the Target to “Custom.” Leave all the blank fields blank, and
    click OK. Now, the configuration you just created (probably named
    “pytest”) show appear in the configuration drop-down. Select and run
    it. If all goes well, you will see a summary of the passed tests,
    but if a test fails, pytest will print more information about what
    went wrong. Try modifying the examples in `ft_to_in` to see what
    a failing test looks like.
    
    
[1] This is not true. If the variable is already defined, then something
else happens that we'll talk about later.
