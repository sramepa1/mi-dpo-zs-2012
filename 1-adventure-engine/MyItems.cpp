#include "MyItems.h"

using namespace std;

Torch::Torch(char* _descrition, bool _isMovable = true, bool _isLightened = true) : Item(_descrition, _isMovable), isLightened(_isLightened) {}