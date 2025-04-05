#include "LandingPageController.hpp"
#include "LandingPageAbstraction.hpp"
#include "ProductController.hpp"
#include "OrderController.hpp"
#include "Product.hpp"
#include "Order.hpp"

/**
 * @brief Retrieves a user by their ID.
 * 
 * This function calls the LandingPageAbstraction to fetch the user details
 * for the given user ID.
 * 
 * @param id The user ID.
 * @return Reference to the User object.
 */
User& LandingPageController::getUser(int id) {
    return this->landPageAbs.getUser(id);
}

/**
 * @brief Notifies the OrderController to update the OrderPresenter.
 * 
 * This function passes the request data to the OrderController, which
 * will handle updating the OrderPresenter with the necessary information.
 * 
 * @param data Pointer to the request data.
 */
void LandingPageController::getOrderPresenter(void* data) {
    this->orderController.notify(data);
}

/**
 * @brief Notifies the ProductController to update the ProductPresenter.
 * 
 * This function passes the request data to the ProductController, which
 * will handle updating the ProductPresenter with the necessary information.
 * 
 * @param data Pointer to the request data.
 */
void LandingPageController::getProductPresenter(void* data) {
    this->productController.notify(data);
}

/**
 * @brief Creates a new order by passing it to the OrderController.
 * 
 * This function invokes the createOrder method in the OrderController, 
 * providing it with the new order to be processed.
 * 
 * @param order Reference to the Order object.
 */
void LandingPageController::createOrder(Order& order) {
    this->orderController.createOrder(order);
}

/**
 * @brief Creates a new product by passing it to the ProductController.
 * 
 * This function invokes the createProduct method in the ProductController, 
 * providing it with the new product to be processed.
 * 
 * @param product Reference to the Product object.
 */
void LandingPageController::createProduct(Product& product) {
    this->productController.createProduct(product);
}
