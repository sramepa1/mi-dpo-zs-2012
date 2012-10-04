#include "MyItems.h"

using namespace std;

Torch::Torch(const char* _descrition, bool _isMovable, bool _isLightened) : Item(_descrition, _isMovable), isLightened(_isLightened) {}
