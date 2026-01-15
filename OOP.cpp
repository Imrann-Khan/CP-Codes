#include <iostream>

class ResourceUser
{
public:
    // Constructor
    ResourceUser()
    {
        std::cout << "ResourceUser constructor: acquiring resource...\n";
    }

    // Destructor
    ~ResourceUser()
    {
        std::cout << "ResourceUser destructor: releasing resource...\n";
    }
};

int main()
{
    std::cout << "Entering main...\n";
    {
        ResourceUser ru; // Constructor called here
    } // ru goes out of scope, so destructor is called automatically
    std::cout << "Exiting main...\n";

    return 0;
}

