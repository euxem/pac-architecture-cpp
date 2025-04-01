#include <vector>

#include "ProductController.hpp"
#include "ProductAbstraction.hpp"
#include "Product.hpp"
#include "User.hpp"

/**
 * Retrieves a list of products based on the user's role.  
 * If the user is a customer, it returns all available products.  
 * If the user is a seller, it returns only the products they own.
 * 
 * @param user The user requesting the product list.
 * @return A list of products corresponding to the user's role.
 */
std::vector<Product> ProductController::getProductsForUser(User& user) {
    switch (user.getUserType()) {
    case CUSTOMER:
        return this->productAbstraction.getAllProduct();
    default:
        return this->productAbstraction.getProductsForSeller(user);
    }
}

/**
 * Creates a new product and adds it to the database.
 * 
 * @param product The product to be created.
 */
void ProductController::createProduct(Product& product) {
    this->productAbstraction.createProduct(product);
}
