#include <vector>

#include "ProductAbstraction.hpp"
#include "ProductController.hpp"
#include "IProductPresenter.hpp"
#include "Product.hpp"
#include "User.hpp"

/**
 * @brief Retrieves a list of products based on the user's role.
 * 
 * - If the user is a customer, it returns all available products.
 * - If the user is a seller, it returns only the products they own.
 * 
 * @param user The user requesting the product list.
 * @return A list of products corresponding to the user's role.
 */
std::vector<Product> ProductController::getProductsForUser(User& user) {
    switch (user.getUserType()) {
    case CUSTOMER:
        // Get all available products for the customer
        return this->productAbstraction.getAllProduct();
    default:
        // Get products owned by the seller
        return this->productAbstraction.getProductsForSeller(user);
    }
}

/**
 * @brief Creates a new product and adds it to the database.
 * 
 * This function passes the new product to the product abstraction layer, which
 * handles the actual creation and storage of the product.
 * 
 * @param product The product to be created.
 */
void ProductController::createProduct(Product& product) {
    this->productAbstraction.createProduct(product);
}

/**
 * @brief Subscribes a product presenter to the controller.
 * 
 * The presenter will receive updates from the controller about products and
 * will be responsible for displaying or processing them.
 * 
 * @param productPresenter Pointer to an IProductPresenter object that will handle the presentation of products.
 */
void ProductController::subscribe(IProductPresenter* productPresenter) {
    this->productPresenter = productPresenter;
}

/**
 * @brief Notifies the subscribed presenter to display the products.
 * 
 * This function calls the showProduct method on the presenter, passing the necessary
 * data (such as product information) for it to render.
 * 
 * @param data Pointer to the data to be passed to the presenter for display.
 */
void ProductController::notify(void* data) {
    this->productPresenter->showProduct(data);
}
