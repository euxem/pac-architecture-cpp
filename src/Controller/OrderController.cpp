#include <vector>

#include "OrderController.hpp"
#include "OrderAbstraction.hpp"
#include "IOrderPresenter.hpp"
#include "User.hpp"
#include "Order.hpp"

/**
 * @brief Retrieves a list of orders associated with a given user.
 * 
 * Depending on the type of user (CUSTOMER or SELLER), this function fetches
 * the orders either placed by the customer or those containing the seller's products.
 * 
 * @param user The user whose orders are to be retrieved.
 * @return A list of orders corresponding to the user's role.
 */
std::vector<Order> OrderController::getOrdersForUser(User& user) {
    switch (user.getUserType()) {
    case CUSTOMER:
        // Get orders placed by the customer
        return this->orderAbstraction.getOrdersForCustomer(user);
    default:
        // Get orders containing the seller's products
        return this->orderAbstraction.getOrdersForSeller(user);
    }
}

/**
 * @brief Creates a new order and adds it to the database.
 * 
 * This function passes the new order to the order abstraction layer, which
 * handles the actual creation and storage of the order.
 * 
 * @param order The order to be created.
 */
void OrderController::createOrder(Order& order) {
    this->orderAbstraction.createOrder(order);
}

/**
 * @brief Subscribes an order presenter to the controller.
 * 
 * The presenter will receive updates from the controller about orders and
 * will be responsible for displaying or processing them.
 * 
 * @param orderPresenter Pointer to an IOrderPresenter object that will handle the presentation of orders.
 */
void OrderController::subscribe(IOrderPresenter* orderPresenter) {
    this->orderPresenter = orderPresenter;
}

/**
 * @brief Notifies the subscribed presenter to display the orders.
 * 
 * This function calls the showOrder method on the presenter, passing the necessary
 * data (such as user orders) for it to render.
 * 
 * @param data Pointer to the data to be passed to the presenter for display.
 */
void OrderController::notify(void* data) {
    this->orderPresenter->showOrder(data);
}
