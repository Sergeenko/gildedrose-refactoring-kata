#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}


void updateBrie()
{

}

void GildedRose::updateQuality()
{
    for (auto&& item : items)
    {
        if (item.name != "Aged Brie" and item.name != "Backstage passes to a TAFKAL80ETC concert")
        {
            if (item.quality > 0 and item.name != "Sulfuras, Hand of Ragnaros")
            {
                item.quality = item.quality - 1;
            }
        }
        else if (item.quality < 50)
        {
            item.quality = item.quality + 1;

            if (item.name == "Backstage passes to a TAFKAL80ETC concert")
            {
                if (item.sellIn < 11 and item.quality < 50)
                {
                        item.quality = item.quality + 1;
                }

                if (item.sellIn < 6 and item.quality < 50)
                {
                    item.quality = item.quality + 1;
                }
            }
        }

        if (item.name != "Sulfuras, Hand of Ragnaros")
        {
            item.sellIn = item.sellIn - 1;
        }

        if (item.sellIn < 0)
        {
            if (item.name == "Aged Brie")
            {
                if (item.quality < 50)
                    {
                        item.quality = item.quality + 1;
                    }

            }
            else if (item.name == "Backstage passes to a TAFKAL80ETC concert")
            {
                item.quality = item.quality - item.quality;
            }
            else if (item.quality > 0 and item.name != "Sulfuras, Hand of Ragnaros")
            {
                item.quality = item.quality - 1;
            }
        }
    }
}
