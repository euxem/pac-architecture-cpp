#ifndef __IPRODUCTPRESENTER_H__
#define __IPRODUCTPRESENTER_H__

class IProductPresenter {
public:
    virtual void showProduct(void* data) = 0;
};

#endif