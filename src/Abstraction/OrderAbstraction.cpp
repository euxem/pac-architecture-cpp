#include <vector>

#include "OrderAbstraction.hpp"
#include "DummyDBData.hpp"
#include "User.hpp"
#include "Order.hpp"
#include "Product.hpp"

/**
 * @brief Retrieves all orders placed by a specific customer.
 * 
 * This function filters through the list of orders in the database and returns
 * a list of orders placed by the specified customer.
 * 
 * @param customer The customer whose orders are to be retrieved.
 * @return A list of orders associated with the given customer.
 */
std::vector<Order> OrderAbstraction::getOrdersForCustomer(User& customer) {
    // Retrieve all orders from the database
    std::vector<Order>& order = this->dbConnection.getOrder();
    std::vector<Order> customerOrder;

    // Filter orders to find those that belong to the customer
    for (Order& o : order) {
        if (o.getCustomer().getId() == customer.getId()) {
            customerOrder.emplace_back(o);  // Add the order to the customer's order list
        }
    }

    return customerOrder;
}

/**
 * @brief Retrieves all orders that contain products sold by a specific seller.
 * 
 * This function filters through all the orders and checks if they contain products
 * sold by the specified seller. It returns a list of orders that contain products
 * sold by the seller.
 * 
 * @param seller The seller whose associated orders are to be retrieved.
 * @return A list of orders that contain products sold by the given seller.
 */
std::vector<Order> OrderAbstraction::getOrdersForSeller(User& seller) {
    // Retrieve all orders from the database
    std::vector<Order>& order = dbConnection.getOrder();
    std::vector<Order> sellerOrder;

    // Iterate through orders and check if any product in the order belongs to the seller
    for (Order& o : order) {
        std::vector<Product>& prodOrd = o.getProducts();  // Get the products in the order
        for (Product& p : prodOrd) {
            if (p.getSeller().getId() == seller.getId()) {  // Check if the seller is the one who sold the product
                sellerOrder.emplace_back(o);  // Add the order to the seller's order list
                break;  // No need to check other products in the order, one match is enough
            }
        }
    }

    return sellerOrder;
}

/**
 * @brief Adds a new order to the database.
 * 
 * This function takes an order object and adds it to the list of orders in the database.
 * 
 * @param order The order to be created and stored.
 */
void OrderAbstraction::createOrder(const Order& order) {
    // Add the new order to the database (DB connection is assumed to have a reference to the orders list)
    this->dbConnection.getOrder().emplace_back(order);
}
