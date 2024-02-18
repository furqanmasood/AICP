#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item {
    int itemNumber;
    string description;
    double reservePrice;
    int numBids;
    double highestBid;
};

// Task 1: Auction setup
void auctionSetup(vector<Item>& items) {
    int numItems;
    cout << "Enter the number of items in the auction (must be at least 10): ";
    cin >> numItems;

    if (numItems < 10) {
        cout << "Error: At least 10 items are required for the auction.\n";
        return;
    }

    items.resize(numItems);
    for (int i = 0; i < numItems; ++i) {
        cout << "Enter details for item " << i + 1 << ":\n";
        cout << "Item Number: ";
        cin >> items[i].itemNumber;
        cin.ignore(); // Clear newline character from the input buffer
        cout << "Description: ";
        getline(cin, items[i].description);
        cout << "Reserve Price: $";
        cin >> items[i].reservePrice;
        items[i].numBids = 0;
        items[i].highestBid = 0.0;
    }
}

// Task 2: Buyer bids
void buyerBids(vector<Item>& items) {
    int buyerNumber, itemNumber;
    double bidAmount;

    cout << "Enter your buyer number: ";
    cin >> buyerNumber;
    cout << "Items available for bidding:\n";
    for (const auto& item : items) {
        cout << "Item Number: " << item.itemNumber << ", Description: " << item.description;
        cout << ", Highest Bid: $" << item.highestBid << endl;
    }
    cout << "Enter the item number you want to bid for: ";
    cin >> itemNumber;

    // Find the item
    for (int i = 0; i < items.size(); ++i) {
        if (items[i].itemNumber == itemNumber) {
            cout << "Enter your bid amount: $";
            cin >> bidAmount;
            if (bidAmount > items[i].highestBid && bidAmount > items[i].reservePrice) {
                items[i].highestBid = bidAmount;
                items[i].numBids++;
                cout << "Bid successful.\n";
            } else {
                cout << "Error: Your bid must be higher than the current highest bid and the reserve price.\n";
            }
            return;
        }
    }

    cout << "Error: Item not found.\n";
}

// Task 3: End of auction
void endOfAuction(const vector<Item>& items) {
    double totalFee = 0.0;
    int numSold = 0, numNotMetReserve = 0, numNoBids = 0;

    cout << "End of auction results:\n";
    for (const auto& item : items) {
        if (item.numBids == 0) {
            cout << "Item " << item.itemNumber << " received no bids.\n";
            numNoBids++;
        } else if (item.highestBid >= item.reservePrice) {
            double fee = item.highestBid * 0.10;
            totalFee += fee;
            cout << "Item " << item.itemNumber << " sold for $" << item.highestBid << " with a fee of $" << fee << endl;
            numSold++;
        } else {
            cout << "Item " << item.itemNumber << " did not meet the reserve price.\n";
            numNotMetReserve++;
        }
    }

    cout << "Total fee for sold items: $" << totalFee << endl;
    cout << "Number of items sold: " << numSold << endl;
    cout << "Number of items that did not meet the reserve price: " << numNotMetReserve << endl;
    cout << "Number of items with no bids: " << numNoBids << endl;
}

int main() {
    vector<Item> items;

    auctionSetup(items);

    char choice;
    do {
        buyerBids(items);
        cout << "Do you want to place another bid? (Y/N): ";
        cin >> choice;
    } while (toupper(choice) == 'Y');

    endOfAuction(items);

    return 0;
}
