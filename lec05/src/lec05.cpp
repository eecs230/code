#include "eecs230.h"

// Ways to deal with errors in a simple area function:

// Bugs are undetected; garbage-in, garbage-out.
int area_gigo(int width, int height)
{
    return width * height;
}

// Returns a distinguished sentinel value to indicate error. Caller
// must check every time and decide what to do, otherwise the sentinel
// value gets treated like a proper answer.
int area_sentinel(int width, int height)
{
    if (width <= 0 || height <= 0) return -1;

    return width * height;
}

// Note that the sentinel approach doesn’t work when there are no
// invalid values in the result that we can designate as sentinels.

// Exits the program on error. This relieves the caller from having to
// detect or deal with errors, but the caller has no chance to recover
// and deal with the error.
int area_die(int width, int height)
{
    if (width <= 0 || height <= 0) {
        // This is what simple_error("negative area") does:
        cerr << "error: negative area\n";
        std::exit(1);
    }

    return width * height;
}

// Here we throw an exception, which gets us some advantages of both
// previous approaches: the caller can catch the exception if we want to
// deal with the error there, or the caller can allow the exception to
// propagate to some more appropriate place to deal with it, or we have
// the option of not dealing with it at all in which case the program
// exits.
int area_exception(int width, int height) {
    if (width <= 0 || height <= 0)
        throw runtime_error("area: negative distance");

    return width * height;
}

void print_area(int width, int height)
{
    // area_exception will throw fail if print_area is given bad
    // parameters, which it then passes on to area_exception.
    // print_area doesn't need to check for errors, however, since
    // by doing nothing it allows the exception to propagate to its
    // caller.
    auto the_area = area_exception(width, height);
    cout << "The area of a " << width << "-by-" << height <<
        " rectangle is " << the_area << "\n";
}

int main()
try {
    int width, height;
    cin >> width >> height;
    print_area(width, height);
}
catch (runtime_error e) {
    cout << "caught in main: " << e.what() << "\n";
}
