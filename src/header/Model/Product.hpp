#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <string>

#include "User.hpp"
/**
 * Represents a product being sold by a seller, containing information about the product's ID, name, quantity, and the seller.
 */
class Product {
    private:
        /** The unique identifier for the product. */
        int id;

        /** The name of the product. */
        std::string name;

        /** The quantity available for the product. */
        int quantity;

        /** The seller offering the product for sale. */
        User seller;
    public:
        Product(int id, std::string& name, int quantity, User& seller) : id(id), name(name), quantity(quantity), seller(seller) {}

        /**
         * Get the id of the products
         * 
         * @return the id
         */
        int getId();

        /**
         * Get the name of the product
         * 
         * @return the name
         */
        std::string& getName();

        /**
         * Get the quantity available of the product
         * 
         * @return the available quantity
         */
        int getQuantity();

        /**
         * Get the Seller of the product
         * 
         * @return the seller
         */
        User getSeller();
};

#endif