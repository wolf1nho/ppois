#include <gtest/gtest.h>

#include "../Reception/clientsbase.h"
#include "../Human/receptionist.h"
#include "../Human/customer.h"

TEST(ClientsBaseTest, BasicsTest)
{
    Gym gym(10, 100, true, 50, 200, 10, 10, 10, 10);
    ClientsBase cb;
    Receptionist r("John", 30, 'm', "1995-01-01", true, nullptr, false,
                   400, 80.0, 180, 5, 3000, "+222222",
                   nullptr, &cb, nullptr);

    Customer c("Ivan", 28, 'm', "1997-03-12", true, nullptr, false, 1000.0, 70.0, 175, nullptr);

    EXPECT_THROW(r.add_client_to_clientsbase(c), ExceptionSubscriptionError);

    r.create_client_sub(c, 1, 1, nullptr, &gym, nullptr, nullptr, nullptr);
    r.add_client_to_clientsbase(c);
    r.change_remaining_days();
    EXPECT_EQ(c.get_remaining_days(), "0");
}
