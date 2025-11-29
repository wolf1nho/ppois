// enums.h
#ifndef ENUMS_H
#define ENUMS_H

#include <string>

enum class Material
{
    Rubber,
    EVA,
    Plastic,
    PVC,
    Leather,
    Cotton,
    Polyester,
    Spandex,
    Microfiber,
    Bamboo,
    Steel,
    Wood,
    Textile,
    Foam,
    Synthetic,
    Mesh,
    Nylon,
    Silicone,
    Latex,
    Lycra
};

enum class Size
{
    XS,
    S,
    M,
    L,
    XL,
    XXL,
    EU38,
    EU39,
    EU40,
    EU41,
    EU42,
    Universal,
    Large,
    Child
};

enum class BallType
{
    Fitball,
    Medball,
    Pilates,
    Yoga,
    Exercise
};

enum class HandleType
{
    Foam,
    Plastic,
    Wood,
    Rubber
};

enum class Color
{
    Black,
    White,
    Red,
    Blue,
    Green,
    NeonGreen,
    Gray,
    Pink
};

enum class WaterResistance
{
    High,
    Medium,
    Low
};

enum class Elasticity
{
    High,
    Medium,
    Low
};

enum class LensColor
{
    Clear,
    Blue,
    Mirrored,
    Smoke,
    Yellow,
    Pink,
    ClubBranded
};

enum class GoggleSize
{
    Adult,
    Youth,
    Child
};

enum class LensType
{
    Standard,
    UVProtection,
    Polarized,
    Photochromic
};

enum class Absorbency
{
    Low,    // например, декоративные или очень тонкие
    Medium, // стандартные спортивные
    High    // микрофибра, бамбук — быстро сохнут и впитывают
};

// Специфичный enum для размера полотенца (опционально, но лучше отделить от одежды)
enum class TowelSize
{
    Small,  // 50x80 см — для лица/йоги
    Medium, // 70x140 см — стандарт
    Large,  // 90x160 см — пляжное
    XLarge  // 100x180 см — большое пляжное или для спа
};

enum class SwimwearStyle
{
    Briefs,
    Trunks,
    Jammers,
    OnePiece,
    Bikini
};

class EnumToStr
{
public:
    static std::string to_string(Material m);

    static std::string to_string(Size s);

    static std::string to_string(BallType bt);

    static std::string to_string(HandleType ht);

    static std::string to_string(Color c);

    static std::string to_string(WaterResistance wr);

    static std::string to_string(Elasticity e);

    static std::string to_string(LensColor lc);

    static std::string to_string(GoggleSize gs);

    static std::string to_string(LensType lt);

    static std::string to_string(SwimwearStyle s);

    static std::string to_string(TowelSize ts);

    static std::string to_string(Absorbency a);
};

#endif