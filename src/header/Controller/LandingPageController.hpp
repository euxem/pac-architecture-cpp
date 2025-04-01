#ifndef __LANDINGPAGECONTROLLER_H__
#define __LANDINGPAGECONTROLLER_H__

#include "LandingPageAbstraction.hpp"
#include "ProductController.hpp"
#include "OrderController.hpp"


class LandingPageController {
private:
    /**  
     * Abstraction layer for handling user retrieval.  
     */
    LandingPageAbstraction& landPageAbs;

    /**  
     * Controller for handling product-related requests.  
     */
    ProductController& productController;

    /**  
     * Controller for handling order-related requests.  
     */
    OrderController& orderController;

public:
    LandingPageController(LandingPageAbstraction& landPageAbs, ProductController& productController, OrderController& orderController) : landPageAbs(landPageAbs), productController(productController), orderController(orderController) {}

    User& getUser(int id);

};


#endif