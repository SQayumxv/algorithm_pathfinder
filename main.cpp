#include <iostream> #print to  terminal
#include <string> #store row of chars
#include <vector> #store collection of rows
#include <queue>

struct Position {
    int row;
    int col;
};

int main() {
    std::vector<std::string> grid = {
        "S...........",
        ".###........",
        "...#........",
        "...#..####..",
        "......#.....",
        ".####.#.....",
        "......#.....",
        "..#####.....",
        "............",
        "....#######.",
        "............",
        "...........G"
    };

    for (const std::string& row : grid) {
        std::cout << row << '\n';
    }

    std::cout << "Start:" << grid[0][0] << '\n';
    std::cout << "Wall:" << grid[1][1] << '\n';
    std::cout << "Goal:" << grid[11][11] << '\n';

    int currentRow = 0;
    int currentCol = 0;

    int rowOffset[] = {-1, 1, 0, 0};
    int colOffset[] = {0, 0, -1, 1};

    for (int direction = 0; direction < 4; direction++) {
        int nextRow = currentRow + rowOffset[direction];
        int nextCol = currentCol + colOffset[direction];

        if (nextRow >= 0 && nextRow < grid.size() &&
            nextCol >= 0 && nextCol < grid[nextRow].size()) {

            if (grid[nextRow][nextCol] != '#') {
                std::cout << "(" << nextRow << ", " << nextCol << ")" << '\n';
            }
            }
    }

    std::queue<Position> frontier;

    frontier.push({0, 0});

    Position current = frontier.front();
    frontier.pop();

    std::cout << "Taken from queue: ("
    << current.row << ", " << current.col << ")\n";

    return 0;

}

