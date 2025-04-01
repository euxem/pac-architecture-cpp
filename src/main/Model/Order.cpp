#include <vector>

#include "Order.hpp"
#include "User.hpp"
#include "Product.hpp"

/**
 * Get the order ID
 * 
 * @return the order Id
 */
int Order::getId() {
    return this->id;
}

/**
 * Get the user
 * 
 * @return the user
 */
User& Order::getCustomer() {
    return this->customer;
}

/**
 * Get the list of products in the offer
 * 
 * @return the list of product
 */
std::vector<Product>& Order::getProducts() {
    return this->products;
}
