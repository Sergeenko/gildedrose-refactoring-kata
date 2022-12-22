#include <string>
#include <vector>

class Item
{
public:
    ::std::string name;
    int sellIn;
    int quality;
    Item(::std::string name, int sellIn, int quality) : name(::std::move(name)), sellIn(sellIn), quality(quality)
    {}
};

class GildedRose
{

public:
    ::std::vector<Item> items;
    explicit GildedRose(::std::vector<Item> && items);
    explicit GildedRose(::std::vector<Item> const& items);

    void updateQuality();

private:
};

struct LimitedQuality
{
    int& operator++()
    {
        if (quality < 50)
            ++quality;
        return quality;
    }

    int operator++(int)
    {
        if (quality < 50)
            ++quality;
        return quality;
    }

    int& operator--()
    {
        if (quality > 0)
            --quality;
        return quality;
    }

    int operator--(int)
    {
        if (quality > 0)
            --quality;
        return quality;
    }
    int quality;
};