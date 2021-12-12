//
// Created by Akshit on 11-12-2021.
//

#ifndef UNTITLED_PRODUCT_H
#define UNTITLED_PRODUCT_H

#include <string>
#include <atomic>

class Product {
private:
    int id_;
    std::string name_;
    std::atomic<float> price_;
    std::atomic<int> stock_;
public:
    Product() = delete;
    Product(int id, std::string name, float price, int stock);
};


#endif //UNTITLED_PRODUCT_H
