#ifndef BUILDERFACTORY_H
#define BUILDERFACTORY_H

#include "IBuilder.h"

class BuilderFactory
{
public:
    BuilderFactory() {}
    builderptr createBuilder();
};

#endif // BUILDERFACTORY_H
