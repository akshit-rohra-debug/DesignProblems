//
// Created by Akshit on 11-12-2021.
//

#include "deal_maintainer.h"
#include <iostream>
#include <memory>

using namespace std;

DealMaintainer& DealMaintainer::get_instance() {
    static DealMaintainer deal{};
    return deal;
}

void DealMaintainer::add_deal(unique_ptr<Deal> deal) {
    int deal_id = deal->get_deal_id();
    if (all_deals_.find(deal_id)==all_deals_.end()) {
        all_deals_[deal_id] = move(deal);
    }
}

bool DealMaintainer::claim_deal(int deal_id, int user_id) {
    if (all_deals_.find(deal_id)==all_deals_.end()) {
        std::cout << "Deal not found" << std::endl;
        return false;
    }
    std::cout << "Found deal" << std::endl;
    return all_deals_.at(deal_id)->claim_deal(user_id);
}

DealMaintainer::DealMaintainer() {}

bool DealMaintainer::end_deal(int deal_id) {
    if (all_deals_.find(deal_id)==all_deals_.end()) {
        std::cout << "Deal not found" << std::endl;
        return false;
    }
    std::cout << "Found deal" << std::endl;
    return all_deals_.at(deal_id)->end_deal();
}

bool DealMaintainer::update_deal_price(int deal_id, float price) {
    if (all_deals_.find(deal_id)==all_deals_.end()) {
        std::cout << "Deal not found" << std::endl;
        return false;
    }
    std::cout << "Found deal" << std::endl;
    return all_deals_.at(deal_id)->update_deal_price(price);
}

bool DealMaintainer::update_deal_end_timestamp(int deal_id, chrono::time_point<chrono::system_clock> end_time) {
    if (all_deals_.find(deal_id)==all_deals_.end()) {
        std::cout << "Deal not found" << std::endl;
        return false;
    }
    std::cout << "Found deal" << std::endl;
    return all_deals_.at(deal_id)->update_deal_time(end_time);
}
