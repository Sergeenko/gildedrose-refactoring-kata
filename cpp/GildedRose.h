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

struct LimitedQuality
{
    int& operator++()
    {
        if (quality < 50) ++quality;
        return quality;
    }

    int& operator--()
    {
        if (quality > 0) --quality;
        return quality;
    }

    int quality;
};

class GildedRose
{

public:
    ::std::vector<Item> items;
    explicit GildedRose(::std::vector<Item> && items);
    explicit GildedRose(::std::vector<Item> const& items);

    void updateQuality();

private:
    static void increaseQualityIfSellInLessThan(LimitedQuality& itemQuality, int itemSellIn, int threshold);
};

