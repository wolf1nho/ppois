#ifndef CREATINE_H
#define CREATINE_H
#include "Good.h"
#include <string>

class Creatine : public Good
{
private:
    std::string brand;
    std::string product_name;
    std::string form;
    std::string type;
    bool is_micronized;
    unsigned serving_size_grams;
    unsigned creatine_per_serving_mg;
    unsigned total_servings;
    unsigned container_weight_grams;
    std::string flavor;
    bool is_flavored;
    std::string country_of_origin;
    bool third_party_tested;

public:
    Creatine(double price, const std::string &brand, const std::string &product_name, const std::string &form,
             const std::string &type, bool is_micronized, unsigned serving_size_grams,
             unsigned creatine_per_serving_mg, unsigned total_servings, unsigned container_weight_grams,
             const std::string &flavor, bool is_flavored,
             const std::string &country_of_origin, bool third_party_tested);

    std::string get_brand() const;
    std::string get_product_name() const;
    std::string get_form() const;
    std::string get_type() const;
    bool get_is_micronized() const;
    unsigned get_serving_size_grams() const;
    unsigned get_creatine_per_serving_mg() const;
    unsigned get_total_servings() const;
    unsigned get_container_weight_grams() const;
    std::string get_flavor() const;
    bool get_is_flavored() const;
    std::string get_country_of_origin() const;
    bool get_third_party_tested() const;
};

#endif