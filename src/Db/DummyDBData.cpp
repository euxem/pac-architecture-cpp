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
        this->customers.emplace_back(0, CUSTOMER, "custFName0", 
                "custLName0", "custAddr0", "custAccNo0");
        this->customers.emplace_back(2, CUSTOMER, "custFName1", 
            "custLName1", "custAddr1", "custAccNo1");
    }

    if (this->sellers.empty()) {
        this->sellers.emplace_back(1, SELLER, "sellerFName0", 
            "sellerLName0", "sellerAddr0", "sellerAccNo0");
        this->sellers.emplace_back(3, SELLER, "sellerFName1", 
            "sellerLName1", "sellerAddr1", "sellerAccNo1");
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
