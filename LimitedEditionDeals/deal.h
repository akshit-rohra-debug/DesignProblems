//
// Created by Akshit on 11-12-2021.
//

#ifndef UNTITLED_DEAL_H
#define UNTITLED_DEAL_H

#include <string>
#include <atomic>
#include <chrono>
#include <vector>
#include <mutex>

class Deal {
private:
    int deal_id_;
    std::string deal_name_;
    int product_id_;
    std::atomic<float> deal_price_;
    std::mutex end_time_mutex_;
    std::chrono::time_point<std::chrono::system_clock> end_time_;
    std::mutex items_left_mutex_;
    int items_left_;
    std::vector<int> claimed_users_;
    std::atomic<bool> deal_active_;

    bool has_user_claimed_deal(int user_id);
public:
    Deal() = delete;
    Deal(int id, std::string name, int product_id, float price, std::chrono::time_point<std::chrono::system_clock> end_time, int deal_items);

    bool end_deal();
    bool update_deal_price(float price);
    bool update_deal_time(std::chrono::time_point<std::chrono::system_clock> end_time);
    bool claim_deal(int user_id);

    int get_deal_id();
};


#endif //UNTITLED_DEAL_H
