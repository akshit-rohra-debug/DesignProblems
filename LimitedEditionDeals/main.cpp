#include <iostream>
#include <string>
#include <chrono>
#include "cmake-build-debug/deal_maintainer.h"
#include "cmake-build-debug/deal_builder.h"
#include "cmake-build-debug/deal.h"
#include "cmake-build-debug/user.h"
#include "cmake-build-debug/product.h"

using namespace std;

int main() {
    DealMaintainer& deal_maintainer = DealMaintainer::get_instance();

    try {
        // Creating a deal
        DealBuilder dealBuilder;
        chrono::time_point<chrono::system_clock> end_time = chrono::system_clock::now() + chrono::seconds (100);
        Deal& deal = dealBuilder.create_deal(1).with_name("Festive Deal").with_product(1)
                .with_price(100).ending_at(end_time).has_stock(50).get_deal();

        // Adding deal
        deal_maintainer.add_deal(deal);

        // Claim a deal
        if (deal_maintainer.claim_deal(1,1)) {
            cout << "Deal successful" << endl;
        }
    } catch (std::exception e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
