#ifndef PROTEINBAR_H
#define PROTEINBAR_H

#include <string>
#include "good.h"

class ProteinBar : public Good
{
private:
    std::string brand;
    std::string product_name;
    std::string flavor;
    double weight_grams;
    double total_calories;
    double protein_grams;
    double carbs_grams;
    double sugar_grams;
    double fat_grams;
    double fiber_grams;
    bool is_vegan;
    bool is_gluten_free;
    bool is_low_sugar;

public:
    ProteinBar(double price, const std::string &brand, const std::string &product_name, const std::string &flavor,
               double weight_grams, double total_calories, double protein_grams, double carbs_grams,
               double sugar_grams, double fat_grams, double fiber_grams,
               bool is_vegan, bool is_gluten_free, bool is_low_sugar);

    std::string get_brand() const;
    std::string get_product_name() const;
    std::string get_flavor() const;
    double get_weight_grams() const;
    double get_total_calories() const;
    double get_protein_grams() const;
    double get_carbs_grams() const;
    double get_sugar_grams() const;
    double get_fat_grams() const;
    double get_fiber_grams() const;
    bool get_is_vegan() const;
    bool get_is_gluten_free() const;
    bool get_is_low_sugar() const;
};

#endif