#include "LandingPageController.hpp"
#include "LandingPageAbstraction.hpp"
#include "ProductController.hpp"
#include "OrderController.hpp"
#include "Product.hpp"
#include "Order.hpp"

User& LandingPageController::getUser(int id) {
    return this->landPageAbs.getUser(id);
}

void LandingPageController::getOrderPresenter(void* data) {
    this->orderController.notify(data);
}

void LandingPageController::getProductPresenter(void* data) {
    this->productController.notify(data);
}

void LandingPageController::createOrder(Order& order) {
    this->orderController.createOrder(order);
}

void LandingPageController::createProduct(Product& product) {
    this->productController.createProduct(product);
}
