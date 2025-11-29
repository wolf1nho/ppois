#include <gtest/gtest.h>
#include <vector>

#include "Human.h"
#include "CombSort.h"

TEST(CombSortTest, test1){
    std::vector<Human> a({Human("1", 19, 190), Human("2", 17, 170), Human("3", 13, 150)});
    combSort(a);
}