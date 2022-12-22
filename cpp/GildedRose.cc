#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
    for (auto&& item : items)
    {
        LimitedQuality itemQuality {item.quality};

        if (item.name == "Sulfuras, Hand of Ragnaros")
        {
            continue;
        }
        if (item.name == "Aged Brie")
        {
            ++itemQuality;
        }

        if (item.name != "Aged Brie" and item.name != "Backstage passes to a TAFKAL80ETC concert")
        {
            --itemQuality;
        }

        if (item.name == "Backstage passes to a TAFKAL80ETC concert")
        {
            ++itemQuality;

            if (item.sellIn < 11)
            {
                ++itemQuality;
            }

            if (item.sellIn < 6)
            {
                ++itemQuality;
            }
        }

        if (--item.sellIn < 0)
        {
            if (item.name == "Aged Brie")
            {
                ++itemQuality;
            }
            else if (item.name == "Backstage passes to a TAFKAL80ETC concert")
            {
                itemQuality.quality = 0;
            }
            else if (itemQuality.quality > 0)
            {
                --itemQuality;
            }
        }
        item.quality = itemQuality.quality;
    }
}
