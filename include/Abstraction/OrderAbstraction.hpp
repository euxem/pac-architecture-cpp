#ifndef __ORDERABSTRACTION_H__
#define __ORDERABSTRACTION_H__

#include <vector>

#include "DummyDBData.hpp"
#include "User.hpp"
#include "Order.hpp"

/**
 * Provides abstraction for handling orders,  
 * allowing retrieval and creation of orders for customers and sellers.
 */
class OrderAbstraction {
private:
    /**  
     * Database connection providing access to order data.  
     */
    DummyDBData& dbConnection;
public:
    OrderAbstraction(DummyDBData& dbConnection) : dbConnection(dbConnection) {}

    /**
     * Retrieves all orders placed by a specific customer.
     * 
     * @param customer The customer whose orders are to be retrieved.
     * @return A list of orders associated with the given customer.
     */
    std::vector<Order> getOrdersForCustomer(User& customer);

    /**
     * Retrieves all orders that contain products sold by a specific seller.
     * 
     * @param seller The seller whose associated orders are to be retrieved.
     * @return A list of orders that contain products sold by the given seller.
     */
    std::vector<Order> getOrdersForSeller(User& seller);

    /**
     * Adds a new order to the database.
     * 
     * @param order The order to be created and stored.
     */
    void createOrder(const Order& order);
};

#endif