#include "Drink.h"
#include "Exception/Exception.h"

Drink::Drink(double price, double volume, const std::string &drink_name,
             bool carbonated, bool milky, bool energy_drink, bool zero_sugar, bool fruity,
             const std::string &taste, bool plastic, bool glass, bool tin_can)
    : Good(price), volume(volume), drink_name(drink_name), carbonated(carbonated),
      milky(milky), energy_drink(energy_drink), zero_sugar(zero_sugar),
      fruity(fruity), taste(taste), plastic(plastic), glass(glass), tin_can(tin_can)
{
  if ((plastic && glass) || (plastic && tin_can) || (glass && tin_can))
    throw ExceptionIncorrectPackaging("Либо пластик, либо стекло, либо банка");
  else if (!plastic && !glass && !tin_can)
    throw ExceptionIncorrectPackaging("Либо пластик, либо стекло, либо банка");
  if (volume < 0 || volume > 5)
    throw ExceptionIncorrectVolume("Неверный объем (от 0 до 5 л)");
}

double Drink::get_volume() const { return volume; }
std::string Drink::get_drink_name() const { return drink_name; }
bool Drink::is_carbonated() const { return carbonated; }
bool Drink::is_milky() const { return milky; }
bool Drink::is_energy_drink() const { return energy_drink; }
bool Drink::is_zero_sugar() const { return zero_sugar; }
bool Drink::is_fruity() const { return fruity; }
std::string Drink::get_taste() const { return taste; }
bool Drink::is_plastic() const { return plastic; }
bool Drink::is_glass() const { return glass; }
bool Drink::is_tin_can() const { return tin_can; }