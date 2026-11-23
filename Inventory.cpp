#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    int id;
    string name;
    string category;
    float price;
    int quantity;
    Product* next;     // Master Linked List pointer
    Product* hashNext; // Hash Table chaining pointer
};

Product* head = NULL;
const int TABLE_SIZE = 10;
Product* hashTable[TABLE_SIZE] = { NULL };

int hashFunction(int id)
{
    return id % TABLE_SIZE;
}

void addProduct()
{
    Product* newProd = new Product();
    cout << "Enter Product ID: ";
    cin >> newProd->id;

    // Check duplicate ID in hash table
    int index = hashFunction(newProd->id);
    Product* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->id == newProd->id)
        {
            cout << "Product ID already exists. Cannot add." << endl;
            delete newProd;
            return;
        }
        temp = temp->hashNext;
    }

    cin.ignore();
    cout << "Enter Product Name: ";
    getline(cin, newProd->name);
    cout << "Enter Category: ";
    getline(cin, newProd->category);
    cout << "Enter Price: ";
    cin >> newProd->price;
    cout << "Enter Stock Quantity: ";
    cin >> newProd->quantity;

    // 1. Insert into Master Linked List
    newProd->next = head;
    head = newProd;

    // 2. Insert into Hash Table (Chaining)
    newProd->hashNext = hashTable[index];
    hashTable[index] = newProd;

    cout << "Product added successfully." << endl;
}

void searchProduct()
{
    int id;
    cout << "Enter Product ID to search: ";
    cin >> id;

    int index = hashFunction(id);
    Product* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nProduct Found:" << endl;
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Category: " << temp->category << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Quantity: " << temp->quantity << endl;
            return;
        }
        temp = temp->hashNext;
    }
    cout << "Product with ID " << id << " not found." << endl;
}

void updateProduct()
{
    int id;
    cout << "Enter Product ID to update: ";
    cin >> id;

    int index = hashFunction(id);
    Product* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Enter New Price: ";
            cin >> temp->price;
            cout << "Enter New Quantity: ";
            cin >> temp->quantity;
            cout << "Product updated successfully." << endl;
            return;
        }
        temp = temp->hashNext;
    }
    cout << "Product with ID " << id << " not found." << endl;
}

void removeProduct()
{
    int id;
    cout << "Enter Product ID to remove: ";
    cin >> id;

    // 1. Unlink from Hash Table
    int index = hashFunction(id);
    Product* hCurr = hashTable[index];
    Product* hPrev = NULL;

    while (hCurr != NULL && hCurr->id != id)
    {
        hPrev = hCurr;
        hCurr = hCurr->hashNext;
    }

    if (hCurr == NULL)
    {
        cout << "Product not found." << endl;
        return;
    }

    if (hPrev == NULL)
        hashTable[index] = hCurr->hashNext;
    else
        hPrev->hashNext = hCurr->hashNext;

    // 2. Unlink from Master Linked List
    Product* lCurr = head;
    Product* lPrev = NULL;

    while (lCurr != NULL && lCurr != hCurr)
    {
        lPrev = lCurr;
        lCurr = lCurr->next;
    }

    if (lCurr != NULL)
    {
        if (lPrev == NULL)
            head = lCurr->next;
        else
            lPrev->next = lCurr->next;
    }

    delete hCurr;
    cout << "Discontinued product removed successfully." << endl;
}

void displayProducts()
{
    Product* temp = head;
    if (temp == NULL)
    {
        cout << "Catalog is empty." << endl;
        return;
    }
    cout << "\n--- All Available Products ---" << endl;
    while (temp != NULL)
    {
        cout << "ID: " << temp->id
            << " | Name: " << temp->name
            << " | Category: " << temp->category
            << " | Price: " << temp->price
            << " | Qty: " << temp->quantity << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n=== E-Commerce Inventory System ===" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Search Product by ID" << endl;
        cout << "3. Update Product Details" << endl;
        cout << "4. Remove Discontinued Product" << endl;
        cout << "5. Display All Products" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addProduct(); break;
            case 2: searchProduct(); break;
            case 3: updateProduct(); break;
            case 4: removeProduct(); break;
            case 5: displayProducts(); break;
            case 6: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 6);

    return 0;
}
