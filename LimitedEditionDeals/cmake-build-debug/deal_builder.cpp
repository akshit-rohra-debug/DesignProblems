//
// Created by Akshit on 11-12-2021.
//

#include "deal_builder.h"
#include <iostream>
using namespace std;

DealBuilder DealBuilder::create_deal(int id) {
    deal_id_ = id;
    return *this;
}

DealBuilder DealBuilder::with_name(std::string name) {
    deal_name_ = name;
    return *this;
}

DealBuilder DealBuilder::with_product(int id) {
    product_id_ = id;
    return *this;
}

DealBuilder DealBuilder::with_price(float price) {
    deal_price_ = price;
    return *this;
}

DealBuilder DealBuilder::ending_at(std::chrono::time_point<std::chrono::system_clock> end_time) {
    end_time_ = end_time;
    return *this;
}

DealBuilder DealBuilder::has_stock(int items) {
    items_left_ = items;
    return *this;
}

Deal &DealBuilder::get_deal() {
    if (deal_name_.empty()) {
        throw std::exception();
    }
    if (deal_price_<0) {
        throw std::exception();
    }
    auto interval = std::chrono::duration_cast<std::chrono::seconds>(end_time_ - std::chrono::system_clock::now());
    if (interval.count()<=0) {
        throw std::exception();
    }
    if (items_left_<1) {
        throw std::exception();
    }

    Deal deal(deal_id_, deal_name_, product_id_, deal_price_, end_time_, items_left_);
    return deal;
}

DealBuilder::DealBuilder() {}
