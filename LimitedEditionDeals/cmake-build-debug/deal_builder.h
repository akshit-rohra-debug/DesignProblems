//
// Created by Akshit on 11-12-2021.
//

#ifndef UNTITLED_DEAL_BUILDER_H
#define UNTITLED_DEAL_BUILDER_H

#include <string>
#include <atomic>
#include <chrono>
#include <vector>
#include "deal.h"

class DealBuilder {
private:
    int deal_id_;
    std::string deal_name_;
    int product_id_;
    float deal_price_;
    std::chrono::time_point<std::chrono::system_clock> end_time_;
    int items_left_;
public:
    DealBuilder();
    DealBuilder create_deal(int id);
    DealBuilder with_name(std::string name);
    DealBuilder with_product(int id);
    DealBuilder with_price(float price);
    DealBuilder ending_at(std::chrono::time_point<std::chrono::system_clock> end_time);
    DealBuilder has_stock(int items);
    Deal& get_deal();

};


#endif //UNTITLED_DEAL_BUILDER_H
