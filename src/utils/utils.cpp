#include "utils.hpp"
#include <cstdlib>
#include <ctime>

void initRandom() { std::srand(static_cast<unsigned>(std::time(nullptr))); }
