#ifndef __IORDERPRESENTER_H__
#define __IORDERPRESENTER_H__

class IOrderPresenter {
public:
    virtual void showOrder(void* data) = 0;
};

#endif