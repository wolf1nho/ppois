#include "Customer.h"
#include "Trainer.h"
#include "Exception/Exception.h"
#include "Reception/Subscription.h"

Customer::Customer(std::string name,
                   unsigned age, char gender, std::string date_of_birth,
                   bool can_link_passkey_and_locker, PassKey *passkey, bool sub_is_taken, double money,
                   double weight, unsigned height, Trainer *personal_trainer)
    : Human(name, age, gender, date_of_birth,
            can_link_passkey_and_locker, passkey,
            sub_is_taken, money, weight, height),
      personal_trainer(personal_trainer)
{
}

std::string Customer::get_personal_trainer_name()
{
      if (personal_trainer)
            return personal_trainer->get_name();
      else
            throw ExceptionPersonalTrainerError("Нет персонального тренера");
}

void Customer::set_personal_trainer(Trainer *trainer)
{
      personal_trainer = trainer;
}