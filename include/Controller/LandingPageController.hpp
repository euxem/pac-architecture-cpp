#ifndef __LANDINGPAGECONTROLLER_H__
#define __LANDINGPAGECONTROLLER_H__

#include "LandingPageAbstraction.hpp"
#include "ProductController.hpp"
#include "OrderController.hpp"
#include "Product.hpp"
#include "Order.hpp"

/**
 * @class LandingPageController
 * @brief Handles landing page interactions and coordinates between controllers.
 *
 * This class manages user retrieval, and delegates product and order handling
 * to their respective controllers.
 */
class LandingPageController {
private:
    /**  
     * @brief Abstraction layer for handling user retrieval.  
     */
    LandingPageAbstraction& landPageAbs;

    /**  
     * @brief Controller for handling product-related requests.  
     */
    ProductController& productController;

    /**  
     * @brief Controller for handling order-related requests.  
     */
    OrderController& orderController;

public:
    /**
     * @brief Constructs a LandingPageController.
     * @param landPageAbs Reference to the abstraction layer handling users.
     * @param productController Reference to the ProductController.
     * @param orderController Reference to the OrderController.
     */
    LandingPageController(LandingPageAbstraction& landPageAbs, ProductController& productController, OrderController& orderController) : landPageAbs(landPageAbs), productController(productController), orderController(orderController) {}

    /**
     * @brief Retrieves a user by ID.
     * @param id The user ID.
     * @return Reference to the retrieved User object.
     */
    User& getUser(int id);

    /**
     * @brief Notifies the OrderPresenter to handle order-related data.
     * @param data Pointer to the request data.
     */
    void getOrderPresenter(void* data);

    /**
     * @brief Notifies the ProductPresenter to handle product-related data.
     * @param data Pointer to the request data.
     */
    void getProductPresenter(void* data);

    /**
     * @brief Creates a new order.
     * @param order Reference to the Order object to be created.
     */
    void createOrder(Order& order);

    /**
     * @brief Creates a new product.
     * @param product Reference to the Product object to be created.
     */
    void createProduct(Product& product);
};


#endif