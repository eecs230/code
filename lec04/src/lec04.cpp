#include "eecs230.h"

NEW_RUNTIME_ERROR(bad_widget_shape);
NEW_RUNTIME_ERROR(cannot_open_door);

int stamp_widget(int shape)
{
    if (shape == 3)
        throw bad_widget_shape{};

    return shape;
}

int open_door(int knob_state)
{
    if (! knob_state)
        throw runtime_error{"no knob state provided"};

    if (knob_state != 4)
        throw cannot_open_door{"can’t open door because knob state != 4"};

    return knob_state;
}

int stamp_widget_and_open_door(int specifier)
{
    int widget = stamp_widget(specifier);

    int door;
    try {
        door = open_door(specifier);
    } catch (cannot_open_door& e) {
        door = 0;
    }

    return door + widget;
}

int main()
try {
    int result = stamp_widget_and_open_door(5);
    cout << "result is " << result << "\n";
}

catch (runtime_error& e) {
    cout << "Caught in main: " << e.what() << "\n";
    exit(1);
}
