#include "Creatine.h"

Creatine::Creatine(double price, const std::string &brand, const std::string &product_name, const std::string &form,
                   const std::string &type, bool is_micronized, unsigned serving_size_grams,
                   unsigned creatine_per_serving_mg, unsigned total_servings, unsigned container_weight_grams,
                   const std::string &flavor, bool is_flavored,
                   const std::string &country_of_origin, bool third_party_tested)
    : Good(price), brand(brand), product_name(product_name), form(form), type(type), is_micronized(is_micronized),
      serving_size_grams(serving_size_grams), creatine_per_serving_mg(creatine_per_serving_mg), total_servings(total_servings),
      container_weight_grams(container_weight_grams), flavor(flavor),
      is_flavored(is_flavored), country_of_origin(country_of_origin), third_party_tested(third_party_tested)
{
}

std::string Creatine::get_brand() const { return brand; }
std::string Creatine::get_product_name() const { return product_name; }
std::string Creatine::get_form() const { return form; }
std::string Creatine::get_type() const { return type; }
bool Creatine::get_is_micronized() const { return is_micronized; }
unsigned Creatine::get_serving_size_grams() const { return serving_size_grams; }
unsigned Creatine::get_creatine_per_serving_mg() const { return creatine_per_serving_mg; }
unsigned Creatine::get_total_servings() const { return total_servings; }
unsigned Creatine::get_container_weight_grams() const { return container_weight_grams; }
std::string Creatine::get_flavor() const { return flavor; }
bool Creatine::get_is_flavored() const { return is_flavored; }
std::string Creatine::get_country_of_origin() const { return country_of_origin; }
bool Creatine::get_third_party_tested() const { return third_party_tested; }