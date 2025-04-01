#ifndef __PRODUCTCONTROLLER_H__
#define __PRODUCTCONTROLLER_H__

#include <vector>

#include "ProductAbstraction.hpp"
#include "IProductPresenter.hpp"
#include "Product.hpp"
#include "User.hpp"


/**
 * Controller responsible for managing products,  
 * providing methods to retrieve and create products based on user roles.
 */
class ProductController {
private:
    /**  
     * Abstraction layer for handling product-related operations.  
     */
    ProductAbstraction& productAbstraction;

    IProductPresenter* productPresenter = nullptr;

public:
    ProductController(ProductAbstraction& productAbstraction) : productAbstraction(productAbstraction) {}

    /**
     * Retrieves a list of products based on the user's role.  
     * If the user is a customer, it returns all available products.  
     * If the user is a seller, it returns only the products they own.
     * 
     * @param user The user requesting the product list.
     * @return A list of products corresponding to the user's role.
     */
    std::vector<Product> getProductsForUser(User& user);

    /**
     * Creates a new product and adds it to the database.
     * 
     * @param product The product to be created.
     */
    void createProduct(Product& product);

    /**
     * Presenter need to subscribe
     */
    void subscribe(IProductPresenter* productPresenter);

    /**
     * Notify the presenter he need to print
     */
    void notify(void* data);
};

#endif