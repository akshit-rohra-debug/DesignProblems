//
// Created by Akshit on 11-12-2021.
//

#include "deal.h"
#include <iostream>

using namespace std;

bool Deal::claim_deal(int user_id) {
    if (has_user_claimed_deal(user_id)) {
        cout << "User has already claimed deal" << endl;
        return false;
    }
    cout << "User can claim the deal" << endl;

    unique_lock<mutex> time_lck(end_time_mutex_);
    auto interval = chrono::duration_cast<chrono::seconds>(end_time_ - chrono::system_clock::now());
    if (interval.count() <= 0) {
        cout << "Deal closed" << endl;
        return false;
    }
    time_lck.unlock();
    unique_lock<mutex> lck(items_left_mutex_);
    if (items_left_ <= 0) {
        cout << "No items remaining" << endl;
        return false;
    }
    cout << "Items remaining" << endl;
    items_left_--;
    cout << "Deal bought at: " << deal_price_.load() << endl;
    lck.unlock();

    claimed_users_.push_back(user_id);
}

bool Deal::has_user_claimed_deal(int user_id) {
    for (int i=0;i<claimed_users_.size();i++) {
        if (claimed_users_[i] == user_id) {
            cout << claimed_users_[i] << endl;
            cout << claimed_users_.size() << endl;
            return true;
        }
    }
    return false;
}

int Deal::get_deal_id() {
    return deal_id_;
}

Deal::Deal(int id, std::string name, int product_id, float price,
           std::chrono::time_point<std::chrono::system_clock> end_time, int deal_items) {
    deal_id_ = id;
    deal_name_ = name;
    deal_price_ = price;
    end_time_ = end_time;
    items_left_ = deal_items;
    claimed_users_.clear();
}
