#include <cstdlib>
#include <ctime>
#include <emscripten.h>

// Choices: 0 = rock, 1 = paper, 2 = scissors
// Result: 0 = draw, 1 = win, 2 = lose
// Return: (result << 2) | computer_choice

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    int play(int userChoice) {
        // Seed random number generator
        static bool seeded = false;
        if (!seeded) {
            srand(time(NULL));
            seeded = true;
        }

        int computerChoice = rand() % 3;

        int result;
        if (userChoice == computerChoice) {
            result = 0; // draw
        } else if ((userChoice == 0 && computerChoice == 2) ||
                   (userChoice == 1 && computerChoice == 0) ||
                   (userChoice == 2 && computerChoice == 1)) {
            result = 1; // win
        } else {
            result = 2; // lose
        }

        return (result << 2) | computerChoice;
    }
}