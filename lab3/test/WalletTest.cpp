#include <gtest/gtest.h>
#include <vector>
#include "../money/Wallet.h"
#include "../money/Money.h"
#include "../exception/Exception.h"

TEST(WalletTest, Exceptions)
{
    Wallet w;
    std::vector<Money> sum;
    sum.emplace_back(Nominal::N50, Currency::USD);
    w.bringMoneyToWallet(sum);
    EXPECT_THROW(w.takeMoney(40, Currency::USD), Exception);
}
