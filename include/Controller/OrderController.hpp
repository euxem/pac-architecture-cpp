#ifndef __ORDERCONTROLLER_H__
#define __ORDERCONTROLLER_H__

#include <vector>
#include "OrderAbstraction.hpp"
#include "IOrderPresenter.hpp"
#include "User.hpp"
#include "Order.hpp"

/**
 * Controller responsible for managing orders,  
 * providing methods to retrieve and create orders for users.
 */
class OrderController {
private:
    /**  
     * Abstraction layer for handling order-related operations.  
     */
    OrderAbstraction& orderAbstraction;

    /**
     * Function Pointer to notify OrderPresenter
     */
    IOrderPresenter* orderPresenter = nullptr;

public:
    OrderController(OrderAbstraction& orderAbstraction) : orderAbstraction(orderAbstraction) {}

    /**
     * Retrieves a list of orders associated with a given user.  
     * If the user is a customer, it returns their placed orders.  
     * If the user is a seller, it returns orders containing their products.
     * 
     * @param user The user whose orders are to be retrieved.
     * @return A list of orders corresponding to the user's role.
     */
    std::vector<Order> getOrdersForUser(User& user);

    /**
     * Creates a new order and adds it to the database.
     * 
     * @param order The order to be created.
     */
    void createOrder(Order& order);

    /**
     * Presenter need to subscribe
     */
    void subscribe(IOrderPresenter* orderPresenter);

    /**
     * Notify the presenter he need to print
     */
    void notify(void* data);
};

#endif
