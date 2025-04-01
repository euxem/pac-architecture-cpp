#ifndef __PRODUCTPRESENTER_H__
#define __PRODUCTPRESENTER_H__

#include "IProductPresenter.hpp"
#include "ProductController.hpp"

class ProductPresenter : public IProductPresenter {
private:
    ProductController& productController;
public:
    ProductPresenter(ProductController& productController);

    void showProduct(void* data) override;
};

#endif