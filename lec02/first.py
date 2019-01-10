# The number of inches in a foot.
FT_TO_IN = 12


def ft_to_in(ft: float) -> float:
    """Converts feet to inches.

    >>> ft_to_in(3)
    36
    >>> ft_to_in(10)
    120
    """
    return FT_TO_IN * ft

