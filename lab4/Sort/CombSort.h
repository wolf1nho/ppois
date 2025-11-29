#ifndef COMBSORT_H
#define COMBSORT_H

#include <vector>

template <typename T>
void combSort(std::vector<T> &data)
{
    int step = data.size();
    bool flag = false;
    while (step > 1 or flag)
    {
        if (step > 1)
        {
            step = step / 1.25;
        }
        flag = false;
        int i = 0;
        while (i + step < n)
        {
            if (data[i] > data[i + step])
            {
                flag = true;
                swap(data[i], data[i + step]);
            }
            i += step;
        }
    }
}

#endif
