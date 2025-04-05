#include <vector>

#include "Order.hpp"
#include "User.hpp"
#include "Product.hpp"

/**
 * @brief Retrieves the ID of the order.
 * 
 * @return The unique identifier of the order.
 */
int Order::getId() {
    return this->id;
}

/**
 * @brief Gets the customer who placed the order.
 * 
 * @return A reference to the User object representing the customer.
 */
User& Order::getCustomer() {
    return this->customer;
}

/**
 * @brief Retrieves the list of products included in the order.
 * 
 * @return A reference to the vector of Product objects in the order.
 */
std::vector<Product>& Order::getProducts() {
    return this->products;
}

/**
 * Set the id of the order
 * 
 * @param id the id of the order
 */
void Order::setId(int id) {
    this->id = id;
}

/**
 * Set the customer who made the offer
 * 
 * @param customer the customer
 */
void Order::setCustomer(User customer) {
    this->customer = customer;
}

/**
 * Set the list of product
 * 
 * @param products a vector of product
 */
void Order::setProducts(std::vector<Product>& products) {
    this->products = products;
}
