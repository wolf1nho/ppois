#include "Mirror.h"

Mirror::Mirror(bool cleaned, double size) : cleaned(cleaned), size(size) {}

Mirror::Mirror() : cleaned(true), size(0) {}

bool Mirror::is_cleaned()
{
    return cleaned;
}