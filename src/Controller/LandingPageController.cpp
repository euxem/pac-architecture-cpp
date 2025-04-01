#include "LandingPageController.hpp"

User& LandingPageController::getUser(int id) {
    return this->landPageAbs.getUser(id);
}

void LandingPageController::getOrderPresenter(void* data) {
    this->orderController.notify(data);
}

void LandingPageController::getProductPresenter(void* data) {
    this->productController.notify(data);
}
