#include <vector>

#include "ProductAbstraction.hpp"
#include "DummyDBData.hpp"
#include "Product.hpp"
#include "User.hpp"

/**
 * Retrieves all available products.
 * Customers have access to all products in the database.
 * 
 * @return A list of all available products.
 */
std::vector<Product>& ProductAbstraction::getAllProduct() {
    return this->dbConnection.getProducts();
}

/**
 * Retrieves all products that belong to a specific seller.
 * Sellers can only view their own products.
 * 
 * @param seller The seller whose products are to be retrieved.
 * @return A list of products owned by the given seller.
 */
std::vector<Product> ProductAbstraction::getProductsForSeller(User seller) {
    std::vector<Product>& prodList = this->dbConnection.getProducts();

    std::vector<Product> sellerProdList;

    for (Product& p: prodList) {
        if (p.getSeller().getId() == seller.getId()) {
            sellerProdList.emplace_back(p);
        }
    }

    return sellerProdList;
}

/**
 * Adds a new product to the database.
 * 
 * @param product The product to be created and stored.
 */
void ProductAbstraction::createProduct(Product product) {
    dbConnection.getProducts().emplace_back(product);
}
