#include "ProteinBar.h"

ProteinBar::ProteinBar(double price, const std::string &brand, const std::string &product_name, const std::string &flavor,
                       double weight_grams, double total_calories, double protein_grams, double carbs_grams,
                       double sugar_grams, double fat_grams, double fiber_grams,
                       bool is_vegan, bool is_gluten_free, bool is_low_sugar)
    : Good(price), brand(brand), product_name(product_name), flavor(flavor), weight_grams(weight_grams), total_calories(total_calories),
      protein_grams(protein_grams), carbs_grams(carbs_grams), sugar_grams(sugar_grams), fat_grams(fat_grams), fiber_grams(fiber_grams),
      is_vegan(is_vegan), is_gluten_free(is_gluten_free), is_low_sugar(is_low_sugar) {}

std::string ProteinBar::get_brand() const { return brand; }
std::string ProteinBar::get_product_name() const { return product_name; }
std::string ProteinBar::get_flavor() const { return flavor; }
double ProteinBar::get_weight_grams() const { return weight_grams; }
double ProteinBar::get_total_calories() const { return total_calories; }
double ProteinBar::get_protein_grams() const { return protein_grams; }
double ProteinBar::get_carbs_grams() const { return carbs_grams; }
double ProteinBar::get_sugar_grams() const { return sugar_grams; }
double ProteinBar::get_fat_grams() const { return fat_grams; }
double ProteinBar::get_fiber_grams() const { return fiber_grams; }
bool ProteinBar::get_is_vegan() const { return is_vegan; }
bool ProteinBar::get_is_gluten_free() const { return is_gluten_free; }
bool ProteinBar::get_is_low_sugar() const { return is_low_sugar; }
