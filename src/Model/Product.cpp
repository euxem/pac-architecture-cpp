#include <vector>

#include "Product.hpp"
#include "User.hpp"

/**
 * @brief Retrieves the product's unique identifier.
 * 
 * @return The ID of the product.
 */
int Product::getId() {
    return this->id;
}

/**
 * @brief Gets the name of the product.
 * 
 * @return A reference to the product's name as a string.
 */
std::string& Product::getName() {
    return this->name;
}

/**
 * @brief Retrieves the available quantity of the product.
 * 
 * @return The quantity in stock.
 */
int Product::getQuantity() {
    return this->quantity;
}

/**
 * @brief Gets the seller associated with the product.
 * 
 * @return A copy of the User object representing the seller.
 */
User Product::getSeller() {
    return this->seller;
}
