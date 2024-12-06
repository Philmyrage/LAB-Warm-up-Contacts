#include <iostream>
#include <string>

// Only had to add this line for the test's in the lab
using namespace std;

class ContactNode
{
public:
    // Constructors
    ContactNode()
    {
        contactName = "";
        contactPhoneNumber = "";
        nextNodePtr = nullptr;
    }
    ContactNode(std::string name, std::string phoneNumber)
    {
        contactName = name;
        contactPhoneNumber = phoneNumber;
        nextNodePtr = nullptr;
    }
    // The Big Three implementations...
    ContactNode(const ContactNode &other)
    {
        contactName = other.contactName;
        contactPhoneNumber = other.contactPhoneNumber;
        nextNodePtr = new ContactNode;
        *nextNodePtr = *other.nextNodePtr;
    }

    ~ContactNode()
    {
        delete nextNodePtr;
    }

    ContactNode &operator=(const ContactNode &other)
    {
        // Exit early if the object is being assigned to itself
        if (this == &other)
            return *this;

        // Deallocate the nextNodePtr
        delete nextNodePtr;
        // Allocate a new nextNodePtr
        nextNodePtr = new ContactNode;
        // copy the data held at the nextNodePtr address
        *nextNodePtr = *other.nextNodePtr;
        return *this;
    }

    // Accessors
    std::string GetName() const { return contactName; }
    std::string GetPhoneNumber() const { return contactPhoneNumber; }
    ContactNode *GetNext() const { return nextNodePtr; }

    // Mutators
    void SetName(std::string name) { contactName = name; }
    void SetPhoneNumber(std::string phoneNumber) { contactPhoneNumber = phoneNumber; }

    // Insertion
    void InsertAfter(ContactNode *Location)
    {
        ContactNode *temp = nullptr;
        temp = this->nextNodePtr;
        this->nextNodePtr = Location;
        Location->nextNodePtr = temp;
    }

    // output
    void PrintContactNode() const
    {
        std::cout << "Name: " << contactName << std::endl;
        std::cout << "Phone number: " << contactPhoneNumber << std::endl;
    }

private:
    /* Declare data members here */
    std::string contactName;
    std::string contactPhoneNumber;
    ContactNode *nextNodePtr;
};

/* Define member functions here */

int main()
{
    ContactNode *head = new ContactNode();
    ContactNode *tail = nullptr;
    ContactNode *current = nullptr;
    std::string tmp = "";

    // Initialize the head with user input...
    getline(std::cin, tmp);
    head->SetName(tmp);

    getline(std::cin, tmp);
    head->SetPhoneNumber(tmp);

    tail = head;

    // Get the user input and add it to the list
    for (int i = 0; i < 2; i++)
    {
        std::string tname = "";
        std::string tphone = "";
        getline(std::cin, tname);
        getline(std::cin, tphone);

        ContactNode *current = new ContactNode(tname, tphone);
        tail->InsertAfter(current);
        tail = current;
    }

    current = head;
    int count = 1;
    while (current != nullptr)
    {
        std::cout << "Person " << count << ": " << current->GetName() << ", " << current->GetPhoneNumber() << std::endl;
        current = current->GetNext();
        count++;
    }

    current = head;
    // print the contents of the list
    std::cout << "\nCONTACT LIST"
              << std::endl;
    while (current != nullptr)
    {
        current->PrintContactNode();
        current = current->GetNext();
        std::cout << std::endl;
    }

    return 0;
}