#include "robot.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	cout << "***********************\n";
	cout << "*        ROBOT        *\n";
	cout << "***********************\n" << endl;

	int dim;

	if (argc == 2) { // 1 argument
		dim = stoi(argv[1]);
		if (dim <= 0) {
			cerr << "Error: I need a positive argument\n";
			return EXIT_FAILURE;
		}
	}
	else {
		cerr << "Error: I need 1 argument\n";
		cerr << "Usage: robot.exe [room dimension]" << endl;
		return EXIT_FAILURE;
	}

	int **room = new int*[dim];

	// Create room
	for (int i = 0; i < dim; i++) {
		room[i] = new int[dim];
		for (int j = 0; j < dim; j++) room[i][j] = 0;
	}

	robot::Position starting_position;
	starting_position.x = 0;
	starting_position.y = 0;

	robot::Position final_position;
	final_position.x = dim - 1;
	final_position.y = dim - 1;

	try {
		robot::Robot robot(room, dim, starting_position);

		// Print room
		cout << "Room:\n";
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) cout << room[i][j] << " ";
			cout << endl;
		}

		cout << "\nRobot starting position: (row, column) = (" << starting_position.x << ", " << starting_position.y << ")\n";
		cout << "Robot final position: (row, column) = (" << final_position.x << ", " << final_position.y << ")\n";

		cout << "\nRobot arrives in the final position: ";
		if (robot.go_to(final_position)) cout << "yes" << endl;
		else cout << "no" << endl;

		// Print room
		cout << "Room:\n";
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) cout << room[i][j] << " ";
			cout << endl;
		}
	} catch (const invalid_argument &ia) {
		cerr << "Error: invalid argument" << endl;
		return EXIT_FAILURE;
	}

	cout << "\nEnd" << endl;
	return EXIT_SUCCESS;
}
