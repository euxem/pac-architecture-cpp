#ifndef __LANDINGPAGEPRESENTER_H__
#define __LANDINGPAGEPRESENTER_H__

#include <crow.h>
#include "LandingPageController.hpp"

class LandingPagePresenter {
private:
    LandingPageController& landingPageController;
public:
    LandingPagePresenter(LandingPageController& landingPageController) : landingPageController(landingPageController) {}

    void showPage(const crow::request& req, crow::response& res, int userId);
};

#endif
