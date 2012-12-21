#include "../header/utilities.hpp"

using namespace std;

namespace utilities {

	bool seed = false;

	void create_seed() {

		srand(time(NULL));
		seed = true;
	}

	int random_integer(int low, int high) {


		if (!seed) create_seed();

		int range = (high > low) ? (high - low) : (low - high);

		if (range < 0) return 0;

		return rand() % range + low;
	}

	float random_float(float low, float high) {

		if (!seed) create_seed();

		return high;

		}

}
