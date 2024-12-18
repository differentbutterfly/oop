#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
using namespace std;

class Item {
public:
    int cost, quantity, code;
    string name;

    // Overloaded < operator for sorting by code
    bool operator<(const Item& i1) const {
        return code < i1.code;
    }

    // Overloaded == operator for searching by code
    bool operator==(const Item& i1) const {
        return code == i1.code;
    }

    // Display function to show item details
    void display() const {
        cout << left << setw(15) << name << setw(10) << quantity
             << setw(15) << cost << setw(15) << code << "\n";
    }
};

vector<Item> items;

// Function to insert an item
void insertItem() {
    Item i;
    cout << "Enter the name of the item: ";
    cin.ignore(); // Clear input buffer
    getline(cin, i.name); // Use getline for multi-word names

    cout << "Enter the quantity of the item: ";
    cin >> i.quantity;

    cout << "Enter the cost of the item: ";
    cin >> i.cost;

    cout << "Enter the code of the item: ";
    cin >> i.code;

    items.push_back(i);
    cout << "Item added successfully!\n";
}

// Function to display all items
void displayItems() {
    if (items.empty()) {
        cout << "No items to display.\n";
        return;
    }

    cout << left << setw(15) << "NAME" << setw(10) << "QUANTITY" << setw(15)
         << "COST" << setw(15) << "CODE" << "\n";
    for (const auto& item : items) {
        item.display();
    }
}

// Function to search for an item by code
void searchItem() {
    int searchCode;
    cout << "Enter item code to search: ";
    cin >> searchCode;

    Item searchItem;
    searchItem.code = searchCode; // Set only the code for comparison

    auto it = find(items.begin(), items.end(), searchItem); // Directly use std::find

    if (it != items.end()) {
        cout << "Item found:\n";
        cout << left << setw(15) << "NAME" << setw(10) << "QUANTITY" << setw(15)
             << "COST" << setw(15) << "CODE" << "\n";
        it->display();
    } else {
        cout << "Item with code " << searchCode << " not found.\n";
    }
}


// Function to sort items by code
void sortItems() {
    sort(items.begin(), items.end());
    cout << "Items sorted by code.\n";
    displayItems();
}

int main() {
    int choice;
    do {
        cout << "1. Insert item\n2. Display items\n3. Search item\n4. Sort items\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            insertItem();
            break;
        case 2:
            displayItems();
            break;
        case 3:
            searchItem();
            break;
        case 4:
            sortItems();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
