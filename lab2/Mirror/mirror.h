#ifndef MIRROR_H
#define MIRROR_H
#include <string>

class Cleaner;

class Mirror
{
    friend class Cleaner;

    bool cleaned;
    double size;

public:
    Mirror(bool cleaned, double size);
    Mirror();
    bool is_cleaned();
};

#endif