#ifndef __PRODUCTPRESENTER_H__
#define __PRODUCTPRESENTER_H__

#include "IProductPresenter.hpp"
#include "ProductController.hpp"

/**
 * @class ProductPresenter
 * @brief Handles the presentation logic for displaying products.
 *
 * This class is responsible for displaying products by interacting with the
 * ProductController and formatting the output into an HTML response.
 */
class ProductPresenter : public IProductPresenter {
private:
    ProductController& productController; ///< Reference to the product controller.
public:
    /**
     * @brief Constructs a ProductPresenter and subscribes to the ProductController.
     *
     * This constructor initializes the presenter and subscribes it to receive product updates.
     *
     * @param productController Reference to the ProductController.
     */
    ProductPresenter(ProductController& productController);

    /**
     * @brief Displays the products in an HTML format.
     * @param data Pointer to a Message object containing request information.
     */
    void showProduct(void* data) override;
};

#endif