#ifndef __PRODUCTABSTRACTION_H__
#define __PRODUCTABSTRACTION_H__

#include <vector>

#include "DummyDBData.hpp"
#include "Product.hpp"
#include "User.hpp"

/**
 * Provides abstraction for handling products,  
 * allowing retrieval and creation of products for both customers and sellers.
 */
class ProductAbstraction {
private:

    /**  
     * Database connection providing access to product data.  
     */
    DummyDBData& dbConnection;

public:
    ProductAbstraction(DummyDBData& dbConnection) : dbConnection(dbConnection) {}

    /**
     * Retrieves all available products.
     * Customers have access to all products in the database.
     * 
     * @return A list of all available products.
     */
    std::vector<Product>& getAllProduct();

    /**
     * Retrieves all products that belong to a specific seller.
     * Sellers can only view their own products.
     * 
     * @param seller The seller whose products are to be retrieved.
     * @return A list of products owned by the given seller.
     */
    std::vector<Product> getProductsForSeller(User seller);

    /**
     * Adds a new product to the database.
     * 
     * @param product The product to be created and stored.
     */
    void createProduct(Product product);
};

#endif
