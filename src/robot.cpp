#include "robot.h"
#include <stdexcept>

using namespace std;

namespace robot {
	Robot::Robot(int **room, int dim, Position starting_position) {
		if (starting_position.x < 0 || starting_position.x >= dim ||
			starting_position.y < 0 || starting_position.y >= dim) throw invalid_argument("invalid Robot argument");

		this->room = room;
		this->dim = dim;
		this->position = starting_position;

		this->room[this->position.x][this->position.y] = 1;
	}

	Robot::~Robot() = default;

	bool Robot::go_to(Position final_position) {
		if (final_position.x < 0 || final_position.x >= this->dim ||
			final_position.y < 0 || final_position.y >= this->dim) return false;

		int distance_x = final_position.x - this->position.x; // Distance between rows
		int distance_y = final_position.y - this->position.y; // Distance between columns

		if (distance_x == 0 && distance_y == 0) return true; // The robot is arrived

		// Move the robot in a balanced way between horizontal and vertical movement
		if (abs(distance_y) >= abs(distance_x)) {
			if (distance_y > 0) {
				this->position.y++; // Move right
				this->room[this->position.x][this->position.y] = 1;
				return go_to(final_position);
			}

			if (distance_y < 0) {
				this->position.y--; // Move left
				this->room[this->position.x][this->position.y] = 1;
				return go_to(final_position);
			}

			if (distance_x > 0) {
				this->position.x++; // Move down
				this->room[this->position.x][this->position.y] = 1;
				return go_to(final_position);
			}

			if (distance_x < 0) {
				this->position.x--; // Move up
				this->room[this->position.x][this->position.y] = 1;
				return go_to(final_position);
			}
		}
		else {
			if (distance_x > 0) {
				this->position.x++; // Move down
				this->room[this->position.x][this->position.y] = 1;
				return go_to(final_position);
			}

			if (distance_x < 0) {
				this->position.x--; // Move up
				this->room[this->position.x][this->position.y] = 1;
				return go_to(final_position);
			}

			if (distance_y > 0) {
				this->position.y++; // Move right
				this->room[this->position.x][this->position.y] = 1;
				return go_to(final_position);
			}

			if (distance_y < 0) {
				this->position.y--; // Move left
				this->room[this->position.x][this->position.y] = 1;
				return go_to(final_position);
			}
		}

		return false;
	}
} // namespace robot
