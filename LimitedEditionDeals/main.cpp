#include <iostream>
#include <string>
#include <chrono>
#include "deal_maintainer.h"
#include "deal_builder.h"
#include "deal.h"
#include "user.h"
#include "product.h"

using namespace std;

int main() {
    try {
        DealMaintainer& deal_maintainer = DealMaintainer::get_instance();
        // Creating a deal
        DealBuilder dealBuilder;
        chrono::time_point<chrono::system_clock> end_time = chrono::system_clock::now() + chrono::seconds (100);
        unique_ptr<Deal> deal = dealBuilder.create_deal(1).with_name("Festive Deal").with_product(1)
                .with_price(100).ending_at(end_time).has_stock(50).get_deal();

        // Adding deal
        deal_maintainer.add_deal(move(deal));

        // Claim a deal
        if (deal_maintainer.claim_deal(1,1)) {
            cout << "Deal successful" << endl;
        }
        if (deal_maintainer.update_deal_price(1, 150)) {
            cout << "Deal price updated" << endl;
        }
        if (deal_maintainer.update_deal_end_timestamp(1, chrono::system_clock::now() + chrono::seconds(1000))) {
            cout << "Deal time updated" << endl;
        }
        if (deal_maintainer.claim_deal(1,1)) {
            cout << "Deal successful" << endl;
        }
        if (deal_maintainer.claim_deal(1,2)) {
            cout << "Deal successful" << endl;
        }
        if (deal_maintainer.end_deal(1)) {
            cout << "Deal ended" << endl;
        }
        if (deal_maintainer.claim_deal(1,3)) {
            cout << "Deal successful" << endl;
        }
    } catch (std::exception e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
