#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int id, initialQuantity, currentQuantity;
    double price;

    // Constructor
    Item(int id, string name, double price, int initialQuantity) : id(id), name(name), price(price), initialQuantity(initialQuantity), currentQuantity(initialQuantity) {}

    // Display method
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << ", Initial Quantity: " << initialQuantity << ", Current Quantity: " << currentQuantity << endl;
    }

    // Method to calculate sales for the item
    double calculateSales() const {
        return price * (initialQuantity - currentQuantity);
    }
};

int main() {
    vector<Item> items;
    int numItems;
    bool edit = true;
    string decision;

    // Simulate the beginning of the day
    cout << "Good morning! Let's get started with entering the initial inventory for the day.\n";
    cout << "How many items do you want to enter? ";
    cin >> numItems;
    cin.ignore();  // To ignore the newline character left by cin

    for (int i = 0; i < numItems; ++i) {
        int id, quantity;
        string name;
        double price;

        cout << "Enter details for item " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Price: $";
        cin >> price;
        cout << "Quantity: ";
        cin >> quantity;

        items.emplace_back(id, name, price, quantity);
    }

    // Display all items
    cout << "\nItems entered:\n";
    for (const auto& item : items) {
        item.display();
    }

    // Simulate the end of the day
    cout << "\nIt's the end of the day. Let's update the inventory based on today's sales.\n";
    while (edit) {
        cout << "Would you like to edit the quantity of an item? Y/N: ";
        cin >> decision;
        edit = (decision == "Y" || decision == "y");

        if (edit) {
            int id, quantity;

            cout << "Enter the ID of the item you want to edit: ";
            cin >> id;
            cout << "Enter new quantity: ";
            cin >> quantity;
            cout << endl;

            // If ID already exists, update the current quantity
            if (id - 1 >= 0 && id - 1 < items.size()) {
                items.at(id - 1).currentQuantity = quantity;
            } else {
                cout << "Invalid ID. No changes made." << endl;
            }

            // Display updated items
            cout << "\nUpdated items:\n";
            for (const auto& item : items) {
                item.display();
            }
        }
    }

    // Display sales for each item at the end
    cout << "\nSales for each item at the end of the day:\n";
    for (const auto& item : items) {
        cout << "Sales for ID " << item.id << " (" << item.name << "): $" << item.calculateSales() << endl;
    }

    cout << "\nThank you for updating the inventory. Have a great evening!\n";

    return 0;
}