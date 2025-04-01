#ifndef __DUMMYDBDATA_H__
#define __DUMMYDBDATA_H__

#include <vector>
#include "User.hpp"
#include "Product.hpp"
#include "Order.hpp"

/**
 * Simulated database storage using in-memory lists.  
 * Provides initialization and access to dummy users, products, and orders.
 */
class DummyDBData {
private:
    /** List of customers in the system. */
    std::vector<User> customers;

    /** List of sellers in the system. */
    std::vector<User> sellers;

    /** Combined list of all users (customers and sellers). */
    std::vector<User> users;

    /** List of available products. */
    std::vector<Product> products;

    /** List of recorded orders. */
    std::vector<Order> orders;

    /**
     * Initializes dummy users (customers and sellers).
     */
    void initUsers();

    /**
     * Initializes dummy products associated with sellers.
     */
    void initProducts();

    /**
     * Initializes dummy orders made by customers.
     * Each order contains multiple products from different sellers.
     */
    void initOrders();

public:
    /**
     * Initializes the dummy database by populating users, products, and orders.
     */
    DummyDBData();

    /**
     * Retrieves the list of all users (customers and sellers).
     * 
     * @return A list of all users.
     */
    std::vector<User>& getUser();

    /**
     * Retrieves the list of sellers.
     * 
     * @return A list of sellers.
     */
    std::vector<User>& getSellers();

    /**
     * Retrieves the list of customers.
     * 
     * @return A list of customers.
     */
    std::vector<User>& getCustomers();

    /**
     * Retrieves the list of available products.
     * 
     * @return A list of products.
     */
    std::vector<Product>& getProducts();

    /**
     * Retrieves the list of recorded orders.
     * 
     * @return A list of orders.
     */
    std::vector<Order>& getOrder();
};

#endif