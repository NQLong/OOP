#include "TableView.h"

TableView::TableView() {}

TableView::TableView(Restaurant *controller) : GeneralView(controller) {}

bool TableView::createTableView()
{
    int id, capacity;
    Table *table_ptr;

    cout << "Create table:" << endl;
    cout << "id : ";
    cin >> id;
    cout << "max capacity : ";
    cin >> capacity;
    table_ptr = new Table(id, capacity);
    this->controller->addTable(table_ptr);
    cout << "Successful create table " << table_ptr->toString() << endl;
    return true;
}

void TableView::listTableView()
{
    vector<Table *> list = this->controller->getTableList();
    vector<Table *>::iterator it = list.begin();
    int count = 0;
    cout << "table list: " << endl;
    for (it = it; it != list.end(); it++)
    {
        cout << ++count << "." << endl;
        this->DetailView(*it);
    }
}

void TableView::filterTableView()
{
    int id;
    Table *table_ptr;

    cout
        << "Search for a table: " << endl
        << "Input table id :";
    cin >> id;
    table_ptr = this->controller->filterTable(id);
    if (!table_ptr)
        cout << "no result found";
    else
        this->DetailView(table_ptr);
}

void TableView::DetailView(Table *ptr)
{
    cout << setw(5) << "" << setw(20) << "Table's id: " << ptr->getId() << endl;
    cout << setw(5) << "" << setw(20) << "Table's capcity: " << ptr->getMaxCapacity() << endl;
}
