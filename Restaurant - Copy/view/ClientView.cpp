#include "ClientView.h"

ClientView::ClientView() {}

ClientView::ClientView(Restaurant *controller) : GeneralView(controller) {}

bool ClientView::createClientView()
{

    Client *client_ptr;
    string name, address, taxId;

    cout << "Create Client : " << endl;

    cout << "name :";
    getline(cin, name);
    cout << "address";
    getline(cin, address);
    cout << "taxId :";
    getline(cin, taxId);

    client_ptr = new Client(name, address, taxId);
    this->controller->addClient(client_ptr);

    cout << "Successfully created client " << client_ptr->toString();
    return true;
}
void ClientView::filterClientView()
{
    string name;
    Client *ptr;

    cout << "Seacrch a Client" << endl;
    cout << "Client name: ";
    // clearCin();
    getline(cin, name);
    cout << "Result :" << endl;
    ptr = this->controller->filterClient(name);

    if (!ptr)
        cout << setw(5) << "No result found";
    else
        this->DetailView(ptr);
}

void ClientView::listClientView()
{
    vector<Client *> list = this->controller->getClientList();
    vector<Client *>::iterator it = list.begin();
    int count = 0;
    cout << "Client list: " << endl;
    for (it = it; it != list.end(); it++)
    {
        cout << ++count << "." << endl;
        this->DetailView(*it);
    }
}

void deleteClientView()
{
}

void ClientView::DetailView(Client *ptr)
{
    cout << setw(5) << "" << setw(20) << "Client's name: " << ptr->getName() << endl;
    cout << setw(5) << "" << setw(20) << "Client's Address: " << ptr->getAddress() << endl;
    cout << setw(5) << "" << setw(20) << "Client's taxId: " << ptr->getTaxID() << endl;
}