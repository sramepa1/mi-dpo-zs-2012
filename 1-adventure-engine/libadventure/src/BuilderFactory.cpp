#include "BuilderFactory.h"
#include "Builder.h"

builderptr BuilderFactory::createBuilder() {
    return builderptr(new Builder());
}
