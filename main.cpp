#include <iostream> // Print to terminal
#include <string>   // Store a row of characters
#include <vector>   // Store a collection of rows
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


    int rowOffset[] = {-1, 1, 0, 0};
    int colOffset[] = {0, 0, -1, 1};

    std::vector<std::vector<bool>> visitied(
        grid.size(),
        std::vector<bool>(grid[0].size(), false)
        );

    std::queue<Position> frontier;

    frontier.push({0, 0});
    visitied[0][0] = true;

    while (!frontier.empty()) {
        Position current = frontier.front();
        frontier.pop();

        std::cout << "Taken from queue: ("
        << current.row << ", " << current.col << ")\n";

        for (int direction = 0; direction < 4; direction++) {
            int nextRow = current.row + rowOffset[direction];
            int nextCol = current.col + colOffset[direction];

            if (nextRow >= 0 && nextRow < grid.size() &&
                nextCol >= 0 && nextCol < grid[nextRow].size()) {

                if (grid[nextRow][nextCol] != '#' &&
                    !visitied[nextRow][nextCol]) {

                    visitied[nextRow][nextCol] = true;
                    frontier.push({nextRow, nextCol});

                    std::cout << "(" << nextRow << ", " << nextCol << ")" << '\n';
                }
                }
        }

    }
    return 0;

}

