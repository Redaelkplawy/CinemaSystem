#include "initializeSeats.h"

std::vector<std::vector<char>> initializeSeats(int rows, int cols) {
    return std::vector<std::vector<char>>(rows, std::vector<char>(cols, 'O'));
}
