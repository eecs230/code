#include <eecs230.h>

int main()
{
    string username;

    cout << "Please enter your name:\n> ";
    cin >> username;

    if (username == "Jesse") {
        simple_error("No greetings for you.");
    }

    cout << "Hello, " << username << "\n";
}