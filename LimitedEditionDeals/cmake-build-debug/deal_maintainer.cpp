//
// Created by Akshit on 11-12-2021.
//

#include "deal_maintainer.h"
#include <iostream>

using namespace std;

DealMaintainer& DealMaintainer::get_instance() {
    static DealMaintainer deal = DealMaintainer();
    return deal;
}

void DealMaintainer::add_deal(Deal &deal) {
    int deal_id = deal.get_deal_id();
    if (all_deals_.find(deal_id)==all_deals_.end()) {
        all_deals_.insert({deal_id, deal});
    }
}

bool DealMaintainer::claim_deal(int deal_id, int user_id) {
    if (all_deals_.find(deal_id)==all_deals_.end()) {
        return false;
    }
    std::cout << "Found deal" << std::endl;
    return all_deals_.at(deal_id).claim_deal(user_id);
}

DealMaintainer::DealMaintainer() {}
