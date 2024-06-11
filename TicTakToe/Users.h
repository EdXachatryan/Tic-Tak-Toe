#ifndef GAMEUSERS_H
#define GAMEUSERS_H

namespace gameUser {

	enum class GameUsers {
		Non = -1,
		User1 = 0,
		User2 = 1
	};

	enum gameElements {
		Empty = '#',
		X = 'X',
		Y = 'O'
	};


	inline GameUsers getUserFromInt(const int i) {
		switch (i)
		{
		case 1:
			return GameUsers::User1;
		case 2:
			return GameUsers::User2;
		default:
			return GameUsers::Non;
		}
	}

	inline const char* getUserNameFromInt(const int i) {
		switch (i)
		{
		case 0:
			return "User1";
		case 1:
			return "User2";
		default:
			return "No one";
		}
	}
}
#endif // !GAMEUSERS_H
