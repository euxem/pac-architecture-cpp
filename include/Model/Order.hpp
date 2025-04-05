#ifndef __ORDER_H__
#define __ORDER_H__

#include <vector>

#include "User.hpp"
#include "Product.hpp"

/**
 * Represents an order placed by a customer, containing information about the order's ID, customer, and products.
 */
class Order {
private:
    /** The unique identifier for the order. */
    int id;
    
    /** The customer who placed the order. */
    User customer;

    /** The list of products included in the order. */
    std::vector<Product> products;
public:
    Order() {}

    Order(int id, User& customer, const std::vector<Product>& products) : id(id), customer(customer) {
        for (const Product& p : products) {
            this->products.emplace_back(p);
        }
    }

    /**
     * Get the order ID
     * 
     * @return the order Id
     */
    int getId();

    /**
     * Get the user
     * 
     * @return the user
     */
    User& getCustomer();

    /**
     * Get the list of products in the offer
     * 
     * @return the list of product
     */
    std::vector<Product>& getProducts();

    /**
     * Set the id of the order
     * 
     * @param id the id of the order
     */
    void setId(int id);

    /**
     * Set the customer who made the offer
     * 
     * @param customer the customer
     */
    void setCustomer(User customer);

    /**
     * Set the list of product
     * 
     * @param products a vector of product
     */
    void setProducts(std::vector<Product>& products);
};


#endif