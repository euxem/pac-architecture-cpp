
#include <vector>

#include "OrderAbstraction.hpp"
#include "DummyDBData.hpp"
#include "User.hpp"
#include "Order.hpp"
#include "Product.hpp"

/**
 * Retrieves all orders placed by a specific customer.
 * 
 * @param customer The customer whose orders are to be retrieved.
 * @return A list of orders associated with the given customer.
 */
std::vector<Order> OrderAbstraction::getOrdersForCustomer(User& customer) {
    std::vector<Order>& order = this->dbConnection.getOrder();
    std::vector<Order> customerOrder;

    for (Order& o : order) {
        if (o.getCustomer().getId() == customer.getId()) {
            customerOrder.emplace_back(o);
        }
    }

    return customerOrder;
}

/**
 * Retrieves all orders that contain products sold by a specific seller.
 * 
 * @param seller The seller whose associated orders are to be retrieved.
 * @return A list of orders that contain products sold by the given seller.
 */
std::vector<Order> OrderAbstraction::getOrdersForSeller(User& seller) {
    std::vector<Order>& order = dbConnection.getOrder();
    std::vector<Order> sellerOrder;

    for (Order& o : order) {
        std::vector<Product>& prodOrd = o.getProducts();
        for (Product& p : prodOrd) {
            if (p.getSeller().getId() == seller.getId()) {
                sellerOrder.emplace_back(o);
                break;
            }
        }
    }

    return sellerOrder;
}

/**
 * Adds a new order to the database.
 * 
 * @param order The order to be created and stored.
 */
void OrderAbstraction::createOrder(const Order& order) {
    this->dbConnection.getOrder().emplace_back(order);
}
