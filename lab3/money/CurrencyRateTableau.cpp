#include "CurrencyRateTableau.h"

#include "getter/TimeGetter.h"
#include "getter/Getter.h"

std::string CurrencyRateTableau::getCurrencyTableau(DataManager *dataManager)
{
    std ::string str = "";
    for (auto it : dataManager->getConverter()->converter)
    {
        if (it.first != dataManager->getConverter()->getBaseCurrency())
        {
            str += Getter::getCurrency(it.first);
            str += " = ";
            str += std::to_string(it.second);
            str += "\n";
        }
    }
    return str;
}