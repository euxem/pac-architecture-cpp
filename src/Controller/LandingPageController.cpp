#include "LandingPageController.hpp"
#include "LandingPageAbstraction.hpp"
#include "ProductController.hpp"
#include "OrderController.hpp"
#include "Product.hpp"
#include "Order.hpp"

/**
 * @brief Retrieves a user by their ID.
 * @param id The user ID.
 * @return Reference to the User object.
 */
User& LandingPageController::getUser(int id) {
    return this->landPageAbs.getUser(id);
}

/**
 * @brief Notifies the OrderController to update the OrderPresenter.
 * @param data Pointer to the request data.
 */
void LandingPageController::getOrderPresenter(void* data) {
    this->orderController.notify(data);
}

/**
 * @brief Notifies the ProductController to update the ProductPresenter.
 * @param data Pointer to the request data.
 */
void LandingPageController::getProductPresenter(void* data) {
    this->productController.notify(data);
}

/**
 * @brief Creates a new order by passing it to the OrderController.
 * @param order Reference to the Order object.
 */
void LandingPageController::createOrder(Order& order) {
    this->orderController.createOrder(order);
}

/**
 * @brief Creates a new product by passing it to the ProductController.
 * @param product Reference to the Product object.
 */
void LandingPageController::createProduct(Product& product) {
    this->productController.createProduct(product);
}
