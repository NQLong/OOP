#include "../Header/BaseController.h"

Data *BaseController::data;

BaseController::~BaseController() {}

BaseController::BaseController()
{
    if (!data)
        data = new Data();
}

void BaseController::setData(Data *_data)
{
    data = _data;
}

Data *BaseController::getData()
{
    return data;
}

list<Author *> BaseController::getAuthorList()
{
    return data->getAuthors();
}