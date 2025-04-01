#include <vector>

#include "Product.hpp"
#include "User.hpp"

/**
 * Get the id of the products
 * 
 * @return the id
 */
int Product::getId() {
    return this->id;
}

/**
 * Get the name of the product
 * 
 * @return the name
 */
std::string& Product::getName() {
    return this->name;
}

/**
 * Get the quantity available of the product
 * 
 * @return the available quantity
 */
int Product::getQuantity() {
    return this->quantity;
}

/**
 * Get the Seller of the product
 * 
 * @return the seller
 */
User Product::getSeller() {
    return this->seller;
}
