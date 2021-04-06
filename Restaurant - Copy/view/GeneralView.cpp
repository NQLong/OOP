#include "GeneralView.h"

void clearCin()
{
    cin.clear();
    cin.ignore(10000, '\n');
}

GeneralView::GeneralView() {}
GeneralView::GeneralView(Restaurant *controller)
{

    this->controller = controller;
}

GeneralView::GeneralView(const GeneralView &other)
{
    this->controller = other.controller;
}

Restaurant *GeneralView::getController()
{
    return this->controller;
}

void GeneralView::setController(Restaurant *controller)
{
    this->controller = controller;
}