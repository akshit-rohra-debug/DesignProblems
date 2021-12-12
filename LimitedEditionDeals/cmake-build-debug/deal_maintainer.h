//
// Created by Akshit on 11-12-2021.
//

#ifndef UNTITLED_DEAL_MAINTAINER_H
#define UNTITLED_DEAL_MAINTAINER_H

#include <string>
#include <unordered_map>
#include "deal.h"


class DealMaintainer {
private:
    std::unordered_map<int, Deal&> all_deals_;
    DealMaintainer();

    DealMaintainer& operator=(const DealMaintainer&) = delete;
public:
    static DealMaintainer& get_instance();
    void add_deal(Deal& deal);
    bool claim_deal(int deal_id, int user_id);
};


#endif //UNTITLED_DEAL_MAINTAINER_H
