#ifndef ROBOT_H
#define ROBOT_H

namespace robot {
	template<typename Type>
	struct Ordered_pair {
		Type x;
		Type y;
	};

	using Position = Ordered_pair<int>;

	class Robot {
	private:
		int **room;
		int dim;
		Position position;

	public:
		Robot(int **room, int dim, Position starting_position);
		virtual ~Robot();
		bool go_to(Position final_position);
	};
} // namespace robot

#endif // ROBOT_H
