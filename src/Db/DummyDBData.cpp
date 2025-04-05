#include "DummyDBData.hpp"

/**
 * @brief Initializes sample orders if the orders list is empty.
 * 
 * Populates the orders vector with predefined orders using existing products and customers.
 */
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

/**
 * @brief Initializes sample users (customers and sellers) if not already populated.
 * 
 * Fills separate vectors for customers and sellers, then merges them into a combined user list.
 */
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

    // Merge customers and sellers into one unified user list
    if (this->users.empty()) {
        this->users.insert(this->users.end(), this->customers.begin(), this->customers.end());
        this->users.insert(this->users.end(), this->sellers.begin(), this->sellers.end());
    }
}

/**
 * @brief Initializes sample products if the products list is empty.
 * 
 * Each product is assigned to one of the predefined sellers.
 */
void DummyDBData::initProducts() {
    if (this->products.empty()) {
        this->products.emplace_back(0, "Product0", 100, this->sellers[0]);
        this->products.emplace_back(1, "Product1", 100, this->sellers[0]);
        this->products.emplace_back(2, "Product2", 100, this->sellers[1]);
        this->products.emplace_back(3, "Product3", 100, this->sellers[1]);
    }
}

/**
 * @brief Constructor that initializes all mock data (users, products, orders).
 */
DummyDBData::DummyDBData() {
    this->initUsers();
    this->initProducts();
    this->initOrders();
}

// Getters for each internal dataset

/**
 * @brief Retrieves the complete list of users.
 * @return Reference to vector of users.
 */
std::vector<User>& DummyDBData::getUser() {
    return this->users;
}

/**
 * @brief Retrieves the list of sellers.
 * @return Reference to vector of sellers.
 */
std::vector<User>& DummyDBData::getSellers() {
    return this->sellers;
}

/**
 * @brief Retrieves the list of customers.
 * @return Reference to vector of customers.
 */
std::vector<User>& DummyDBData::getCustomers() {
    return this->customers;
}

/**
 * @brief Retrieves the list of products.
 * @return Reference to vector of products.
 */
std::vector<Product>& DummyDBData::getProducts() {
    return this->products;
}

/**
 * @brief Retrieves the list of orders.
 * @return Reference to vector of orders.
 */
std::vector<Order>& DummyDBData::getOrder() {
    return this->orders;
}
