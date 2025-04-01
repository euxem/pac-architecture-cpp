#include "DummyDBData.hpp"

void DummyDBData::initOrders() {
    if (this->orders.empty()) {
        std::vector<Product> productsForOrder0 = {this->products[0], this->products[3]};
        this->orders.emplace_back(0, this->customers[0], productsForOrder0);

        std::vector<Product> productsForOrder1 = {this->products[1], this->products[3]};
        this->orders.emplace_back(1, this->customers[1], productsForOrder1);

        std::vector<Product> productsForOrder2 = {this->products[1], this->products[2]};
        this->orders.emplace_back(0, this->customers[1], productsForOrder2);
    }
}

void DummyDBData::initUsers() {
    if (this->customers.empty()) {
        this->customers.emplace_back(0, CUSTOMER, "John", 
                "Doe", "customer address 0", "123456");
        this->customers.emplace_back(1, CUSTOMER, "Serena", 
            "Williams", "customer address 1", "234567");
    }

    if (this->sellers.empty()) {
        this->sellers.emplace_back(2, SELLER, "Swift", 
            "Taylor", "seller address 2", "345678");
        this->sellers.emplace_back(3, SELLER, "Andrew", 
            "Wilson", "seller address 3", "456789");
    }

    if (this->users.empty()) {
        this->users.insert(this->users.end(), this->customers.begin(), this->customers.end());
        this->users.insert(this->users.end(), this->sellers.begin(), this->sellers.end());
    }
}

void DummyDBData::initProducts() {
    if (this->products.empty()) {
        this->products.emplace_back(0, "Product0", 100, this->sellers[0]);
        this->products.emplace_back(1, "Product1", 100, this->sellers[0]);
        this->products.emplace_back(2, "Product2", 100, this->sellers[1]);
        this->products.emplace_back(3, "Product3", 100, this->sellers[1]);
    }
}

DummyDBData::DummyDBData() {
    this->initUsers();
    this->initProducts();
    this->initOrders();
}

std::vector<User>& DummyDBData::getUser() {
    return this->users;
}

std::vector<User>& DummyDBData::getSellers() {
    return this->sellers;
}

std::vector<User>& DummyDBData::getCustomers() {
    return this->customers;
}

std::vector<Product>& DummyDBData::getProducts() {
    return this->products;
}

std::vector<Order>& DummyDBData::getOrder() {
    return this->orders;
}
