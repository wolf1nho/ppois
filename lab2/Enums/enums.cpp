#include "enums.h"
#include <string>

std::string EnumToStr::to_string(Material m)
{
    switch (m)
    {
    case Material::Rubber:
        return "rubber";
    case Material::EVA:
        return "eva";
    case Material::Plastic:
        return "plastic";
    case Material::PVC:
        return "pvc";
    case Material::Leather:
        return "leather";
    case Material::Cotton:
        return "cotton";
    case Material::Polyester:
        return "polyester";
    case Material::Spandex:
        return "spandex";
    case Material::Microfiber:
        return "microfiber";
    case Material::Bamboo:
        return "bamboo";
    case Material::Steel:
        return "steel";
    case Material::Wood:
        return "wood";
    case Material::Textile:
        return "textile";
    case Material::Foam:
        return "foam";
    case Material::Mesh:
        return "mesh";
    case Material::Synthetic:
        return "syntetic";
    case Material::Nylon:
        return "nylon";
    case Material::Silicone:
        return "silicone";
    case Material::Latex:
        return "latex";
    case Material::Lycra:
        return "lycra";
    default:
        return "unknown";
    }
}

std::string EnumToStr::to_string(Size s)
{
    switch (s)
    {
    case Size::XS:
        return "XS";
    case Size::S:
        return "S";
    case Size::M:
        return "M";
    case Size::L:
        return "L";
    case Size::XL:
        return "XL";
    case Size::XXL:
        return "XXL";
    case Size::EU38:
        return "38";
    case Size::EU39:
        return "39";
    case Size::EU40:
        return "40";
    case Size::EU41:
        return "41";
    case Size::EU42:
        return "42";
    case Size::Universal:
        return "universal";
    case Size::Large:
        return "large";
    case Size::Child:
        return "child";
    default:
        return "unknown";
    }
}

std::string EnumToStr::to_string(BallType bt)
{
    switch (bt)
    {
    case BallType::Fitball:
        return "fitball";
    case BallType::Medball:
        return "medball";
    case BallType::Pilates:
        return "pilates";
    case BallType::Yoga:
        return "yoga";
    case BallType::Exercise:
        return "exercise";
    default:
        return "unknown";
    }
}

std::string EnumToStr::to_string(HandleType ht)
{
    switch (ht)
    {
    case HandleType::Foam:
        return "foam";
    case HandleType::Plastic:
        return "plastic";
    case HandleType::Wood:
        return "wood";
    case HandleType::Rubber:
        return "rubber";
    default:
        return "unknown";
    }
}

std::string EnumToStr::to_string(Color c)
{
    switch (c)
    {
    case Color::Black:
        return "black";
    case Color::White:
        return "white";
    case Color::Red:
        return "red";
    case Color::Blue:
        return "blue";
    case Color::Green:
        return "green";
    case Color::NeonGreen:
        return "neon green";
    case Color::Gray:
        return "gray";
    case Color::Pink:
        return "pink";
    default:
        return "unknown";
    }
}

std::string EnumToStr::to_string(WaterResistance wr)
{
    switch (wr)
    {
    case WaterResistance::High:
        return "high";
    case WaterResistance::Medium:
        return "medium";
    case WaterResistance::Low:
        return "low";
    default:
        return "unknown";
    }
}

std::string EnumToStr::to_string(Elasticity e)
{
    switch (e)
    {
    case Elasticity::High:
        return "high";
    case Elasticity::Medium:
        return "medium";
    case Elasticity::Low:
        return "low";
    default:
        return "unknown";
    }
}

std::string EnumToStr::to_string(LensColor lc)
{
    switch (lc)
    {
    case LensColor::Clear:
        return "clear";
    case LensColor::Blue:
        return "blue";
    case LensColor::Mirrored:
        return "mirrored";
    case LensColor::Smoke:
        return "smoke";
    case LensColor::Yellow:
        return "yellow";
    case LensColor::Pink:
        return "pink";
    case LensColor::ClubBranded:
        return "club";
    default:
        return "unknown";
    }
}

std::string EnumToStr::to_string(GoggleSize gs)
{
    switch (gs)
    {
    case GoggleSize::Adult:
        return "adult";
    case GoggleSize::Youth:
        return "youth";
    case GoggleSize::Child:
        return "child";
    default:
        return "unknown";
    }
}

std::string EnumToStr::to_string(LensType lt)
{
    switch (lt)
    {
    case LensType::Standard:
        return "standard";
    case LensType::UVProtection:
        return "uv protection";
    case LensType::Polarized:
        return "polarized";
    case LensType::Photochromic:
        return "photochromic";
    default:
        return "unknown";
    }
}

std::string EnumToStr::to_string(SwimwearStyle s)
{
    switch (s)
    {
    case SwimwearStyle::Briefs:
        return "briefs";
    case SwimwearStyle::Trunks:
        return "trunks";
    case SwimwearStyle::Jammers:
        return "jammers";
    case SwimwearStyle::OnePiece:
        return "one piece";
    case SwimwearStyle::Bikini:
        return "bikini";
    default:
        return "unknown";
    }
}

std::string EnumToStr::to_string(TowelSize ts)
{
    switch (ts)
    {
    case TowelSize::Small:
        return "small";
    case TowelSize::Medium:
        return "medium";
    case TowelSize::Large:
        return "large";
    case TowelSize::XLarge:
        return "xlarge";
    default:
        return "unknown";
    }
}

std::string EnumToStr::to_string(Absorbency a)
{
    switch (a)
    {
    case Absorbency::Low:
        return "low";
    case Absorbency::Medium:
        return "medium";
    case Absorbency::High:
        return "high";
    default:
        return "unknown";
    }
}