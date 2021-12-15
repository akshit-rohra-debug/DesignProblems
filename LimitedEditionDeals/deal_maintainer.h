//
// Created by Akshit on 11-12-2021.
//

#ifndef UNTITLED_DEAL_MAINTAINER_H
#define UNTITLED_DEAL_MAINTAINER_H

#include <string>
#include <unordered_map>
#include "deal.h"
#include <memory>

using namespace std;

class DealMaintainer {
private:
    std::unordered_map<int, unique_ptr<Deal>> all_deals_;
    DealMaintainer();

    DealMaintainer& operator=(const DealMaintainer&) = delete;
public:
    static DealMaintainer& get_instance();
    void add_deal(unique_ptr<Deal> deal);
    bool claim_deal(int deal_id, int user_id);
    bool end_deal(int deal_id);
    bool update_deal_price(int deal_id, float price);
    bool update_deal_end_timestamp(int deal_id, chrono::time_point<chrono::system_clock> end_time);
};


#endif //UNTITLED_DEAL_MAINTAINER_H
