import attr


def record(*args, **kwargs):
    if 'auto_attribs' in kwargs:
        return attr.s(*args, **kwargs)
    else:
        return attr.s(*args, auto_attribs=True, **kwargs)


Factory = attr.Factory
