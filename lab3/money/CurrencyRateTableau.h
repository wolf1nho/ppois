#ifndef CURRENCYRATETABLEAU_H
#define CURRENCYRATETABLEAU_H

#include "datamanager/DataManager.h"
#include "account/Currency.h"

class CurrencyRateTableau
{
public:
    static std::string getCurrencyTableau(DataManager *dataManager);
};

#endif
