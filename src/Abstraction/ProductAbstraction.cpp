#include <vector>

#include "ProductAbstraction.hpp"
#include "DummyDBData.hpp"
#include "Product.hpp"
#include "User.hpp"

/**
 * @brief Retrieves all available products.
 * 
 * This function is used to retrieve all products available in the database. 
 * Customers can view all products, so it returns all products from the database.
 * 
 * @return A list of all available products.
 */
std::vector<Product>& ProductAbstraction::getAllProduct() {
    return this->dbConnection.getProducts();
}

/**
 * @brief Retrieves all products that belong to a specific seller.
 * 
 * This function returns only the products that belong to the given seller.
 * Sellers can only see their own products, so it filters the list based on the seller's ID.
 * 
 * @param seller The seller whose products are to be retrieved.
 * @return A list of products owned by the given seller.
 */
std::vector<Product> ProductAbstraction::getProductsForSeller(User seller) {
    std::vector<Product>& prodList = this->dbConnection.getProducts(); // Get all products from the DB connection

    std::vector<Product> sellerProdList; // A list to hold products that belong to the seller

    // Iterate through all products to find products that belong to the specified seller
    for (Product& p : prodList) {
        if (p.getSeller().getId() == seller.getId()) {
            sellerProdList.emplace_back(p);  // Add the product to the seller's product list
        }
    }

    return sellerProdList;
}

/**
 * @brief Adds a new product to the database.
 * 
 * This function creates a new product by adding it to the list of products in the database.
 * 
 * @param product The product to be created and stored.
 */
void ProductAbstraction::createProduct(Product product) {
    dbConnection.getProducts().emplace_back(product);  // Add the new product to the database's product list
}
