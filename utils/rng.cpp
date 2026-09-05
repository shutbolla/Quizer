#include "utils/rng.h"
#include <random>

namespace rng {

	namespace {

		std::mt19937 s_generator(std::random_device{}());
	}

	int32_t get_int(int32_t min, int32_t max) {

		std::uniform_int_distribution<int32_t> distribution(min, max);

		return distribution(s_generator);
	}
}