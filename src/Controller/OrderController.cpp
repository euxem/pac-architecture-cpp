#include <vector>

#include "OrderController.hpp"
#include "OrderAbstraction.hpp"
#include "IOrderPresenter.hpp"
#include "User.hpp"
#include "Order.hpp"

/**
 * Retrieves a list of orders associated with a given user.  
 * If the user is a customer, it returns their placed orders.  
 * If the user is a seller, it returns orders containing their products.
 * 
 * @param user The user whose orders are to be retrieved.
 * @return A list of orders corresponding to the user's role.
 */
std::vector<Order> OrderController::getOrdersForUser(User& user) {
    switch (user.getUserType()) {
    case CUSTOMER:
        return this->orderAbstraction.getOrdersForCustomer(user);
    default:
        return this->orderAbstraction.getOrdersForSeller(user);
    }
}

/**
 * Creates a new order and adds it to the database.
 * 
 * @param order The order to be created.
 */
void OrderController::createOrder(Order& order) {
    this->orderAbstraction.createOrder(order);
}


/**
 * Presenter need to subscribe
 */
void OrderController::subscribe(IOrderPresenter* orderPresenter) {
    this->orderPresenter = orderPresenter;
}

/**
 * Notify the presenter he need to print
 */
void OrderController::notify(void* data) {
    this->orderPresenter->showOrder(data);
}
