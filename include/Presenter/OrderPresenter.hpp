#ifndef __ORDERPRESENTER_H__
#define __ORDERPRESENTER_H__

#include "IOrderPresenter.hpp"
#include "OrderController.hpp"

/**
 * @class OrderPresenter
 * @brief Handles the presentation logic for displaying orders.
 *
 * This class is responsible for displaying orders by interacting with the
 * OrderController and formatting the output into an HTML response.
 */
class OrderPresenter : public IOrderPresenter {
private:
    OrderController& orderController; ///< Reference to the order controller.
public:
    /**
     * @brief Constructs an OrderPresenter and subscribes to the OrderController.
     *
     * This constructor initializes the presenter and subscribes it to receive order updates.
     *
     * @param orderController Reference to the OrderController.
     */
    OrderPresenter(OrderController& orderController);

    /**
     * @brief Displays the orders in an HTML format.
     * @param data Pointer to a Message object containing request information.
     */
    void showOrder(void* data) override;
};

#endif