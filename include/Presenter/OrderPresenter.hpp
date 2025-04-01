#ifndef __ORDERPRESENTER_H__
#define __ORDERPRESENTER_H__

#include "IOrderPresenter.hpp"
#include "OrderController.hpp"

class OrderPresenter : public IOrderPresenter {
private:
    OrderController& orderController;
public:
    OrderPresenter(OrderController& orderController);

    void showOrder(void* data) override;
};

#endif