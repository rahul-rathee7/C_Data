#include <fstream>
#include <iostream>

using namespace std;

const string DATABASE_FILE = "database.txt";
const string ADMIN_EMAIL = "abc@gmail.com";
const string ADMIN_PASSWORD = "1234";

class Shopping {
private:
    int productCode;
    float productPrice;
    float productDiscount;
    string productName;

public:
    void displayMenu();
    void handleAdministrator();
    void handleBuyer();
    void addProduct();
    void editProduct();
    void removeProduct();
    void listProducts();
    void generateReceipt();
    bool authenticateAdministrator(const string& email, const string& password);
};

bool Shopping::authenticateAdministrator(const string& email, const string& password)
{
    return (email == ADMIN_EMAIL && password == ADMIN_PASSWORD);
}

void Shopping::displayMenu()
{
    int userChoice;
    string userEmail;
    string userPassword;

    cout << "\t\t\t\t_____________________\n";
    cout << "\t\t\t\t													\n";
    cout << "\t\t\t\t			Supermarket Main Menu					\n";
    cout << "\t\t\t\t													\n";
    cout << "\t\t\t\t_____________________\n";
    cout << "\t\t\t\t													\n";
    cout << "\t\t\t\t 1) ADMINISTRATOR								   	\n";
    cout << "\t\t\t\t													\n";
    cout << "\t\t\t\t 2) BUYER										   	\n";
    cout << "\t\t\t\t													\n";
    cout << "\t\t\t\t 3) EXIT										   	\n";
    cout << "\t\t\t\t													\n";
    cout << "\t\t\t\t PLEASE SELECT :								   	\n";
    cout << "\n\n";
    cin >> userChoice;

    switch (userChoice) {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email \n";
        cin >> userEmail;
        cout << "\t\t\t Password \n";
        cin >> userPassword;

        if (authenticateAdministrator(userEmail, userPassword)) {
            handleAdministrator();
        } else {
            cout << "Invalid email / password";
        }
        break;

    case 2:
        handleBuyer();
        break;

    case 3:
        cout << "Exiting the program ...\nExited!" << endl;
        exit(0);
    default:
        cout << "Please select from the given options !";
    }
    displayMenu();
}

void Shopping::handleAdministrator()
{
    int adminChoice;
    cout << "\n\n\n\t\t\t Administrator Menu";
    cout << "\n";
    cout << "\n\t\t\t 1) Add the product		";
    cout << "\n";
    cout << "\n\t\t\t 2) Modify the product		";
    cout << "\n";
    cout << "\n\t\t\t 3) Delete the product		";
    cout << "\n";
    cout << "\n\t\t\t 4) Back to Main Menu		";
    cout << "\n";
    cout << "Please enter your choice !";
    cin >> adminChoice;

    switch (adminChoice) {
    case 1:
        addProduct();
        break;

    case 2:
        editProduct();
        break;

    case 3:
        removeProduct();
        break;

    case 4:
        displayMenu();
        break;

    default:
        cout << "Invalid choice !";
    }

    handleAdministrator();
}

void Shopping::handleBuyer()
{
    int buyerChoice;
    cout << "\n\n\n\t\t\t Buyer";
    cout << "\n\t\t\t| 						|";
    cout << "\n\t\t\t| 1) Buy product			|";
    cout << "\n\t\t\t|					  	|";
    cout << "\n\t\t\t| 2) Go Back !			|";
    cout << "Please enter your choice !";
    cin >> buyerChoice;

    switch (buyerChoice) {
    case 1:
        generateReceipt();
        break;

    case 2:
        displayMenu();
        break;

    default:
        cout << "Invalid choice !";
    }

    handleBuyer();
}

void Shopping::addProduct()
{
    fstream productData;
    int existingProductCode;
    int token = 0;
    float existingProductPrice;
    float existingProductDiscount;
    string existingProductName;

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product ";
    cin >> productCode;
    cout << "\n\n\t Name of the product ";
    cin >> productName;
    cout << "\n\n\t Price of the product";
    cin >> productPrice;
    cout << "\n\n\t Discount on product";
    cin >> productDiscount;

    productData.open(DATABASE_FILE, ios::in);

    if (!productData) {
        productData.open(DATABASE_FILE, ios::app | ios::out);
        productData << " " << productCode << " " << productName << " " << productPrice << " " << productDiscount << "\n";
        productData.close();
    } else {
        productData >> existingProductCode >> existingProductName >> existingProductPrice >> existingProductDiscount;

        while (!productData.eof()) {
            if (existingProductCode == productCode) {
                token++;
            }
            productData >> existingProductCode >> existingProductName >> existingProductPrice >> existingProductDiscount;
        }
        productData.close();

        if (token == 1)
            addProduct();
        else {
            productData.open(DATABASE_FILE, ios::app | ios::out);
            productData << " " << productCode << " " << productName << " " << productPrice << " " << productDiscount << "\n";
            productData.close();
        }
    }
    cout << "\n\n\t\t Record inserted !";
}

void Shopping::editProduct()
{
    fstream data, data1;
    int productKey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code:";
    cin >> productKey;

    data.open(DATABASE_FILE, ios::in);
    if (!data) {
        cout << "\n\nFile doesn't exist! ";
    } else {

        data1.open("database1.txt", ios::app | ios::out);

        data >> productCode >> productName >> productPrice >> productDiscount;
        while (!data.eof()) {
            if (productKey == productCode) {
                cout << "\n\t\t Product new code:";
                cin >> c;
                cout << "\n\t\t Name of the product :";
                cin >> n;
                cout << "\n\t\t Price:";
                cin >> p;
                cout << "\n\t\t Discount:";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record edited ";
                token++;
            } else {
                data1 << " " << productCode << " " << productName << " " << productPrice << " " << productDiscount << "\n";
            }
            data >> productCode >> productName >> productPrice >> productDiscount;
        }
        data.close();
        data1.close();

        remove(DATABASE_FILE.c_str());
        rename("database1.txt", DATABASE_FILE.c_str());

        if (token == 0) {
            cout << "\n\n Record not found sorry!";
        }
    }
}

void Shopping::removeProduct()
{
    fstream data, data1;
    int productKey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code :";
    cin >> productKey;
    data.open(DATABASE_FILE, ios::in);
    if (!data) {
        cout << "File doesn't exist";
    } else {
        data1.open("database1.txt", ios::app | ios::out);
        data >> productCode >> productName >> productPrice >> productDiscount;
        while (!data.eof()) {
            if (productCode == productKey) {
                cout << "\n\n\t Product deleted successfully";
                token++;
            } else {
                data1 << " " << productCode << " " << productName << " " << productPrice << " " << productDiscount << "\n";
            }
            data >> productCode >> productName >> productPrice >> productDiscount;
        }
        data.close();
        data1.close();
        remove(DATABASE_FILE.c_str());
        rename("database1.txt", DATABASE_FILE.c_str());

        if (token == 0) {
            cout << "\n\n Record not found !";
        }
    }
}

void Shopping::listProducts()
{
    fstream data;
    data.open(DATABASE_FILE, ios::in);
    cout << "\t\t\t\t___________________\n";
    cout << "ProductNo\t\tName\t\tPrice\n";
    cout << "\t\t\t\t___________________\n";
    data >> productCode >> productName >> productPrice >> productDiscount;
    while (!data.eof()) {
        cout << productCode << "\t\t" << productName << "\t\t" << productPrice << "\n";
        data >> productCode >> productName >> productPrice >> productDiscount;
    }
    data.close();
}

void Shopping::generateReceipt()
{
    fstream data;

    int productCodes[100];
    int productQuantities[100];
    char userChoice;
    int productsCount = 0;
    float productAmount = 0;
    float totalAmount = 0;

    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open(DATABASE_FILE, ios::in);
    if (!data) {
        cout << "\n\n Empty database";
    } else {
        data.close();

        listProducts();
        cout << "\t\t\t\t____________________\n";
        cout << "\t\t\t\t|													|\n";
        cout << "\t\t\t\t|			Please place the order					|\n";
        cout << "\t\t\t\t|__________________|\n";
        do {
            cout << "\n\nEnter Product code :";
            cin >> productCodes[productsCount];
            cout << "\n\nEnter the product quantity :";
            cin >> productQuantities[productsCount];
            for (int i = 0; i < productsCount; i++) {
                if (productCodes[productsCount] == productCodes[i]) {
                    cout << "\n\n Duplicate product code. Please try again!";
                }
            }
            productsCount++;
            cout << "\n\n Do you want to buy another product? if yes then press y else no";
            cin >> userChoice;
        } while (userChoice == 'y');

        cout << "\n\n\t\t\t\t__________RECEIPT__________\n";
        cout << "\nProduct No\t Product Name\t Product quantity\tprice\tAmount \tAmount with discount\n";

        for (int i = 0; i < productsCount; i++) {
            data.open(DATABASE_FILE, ios::in);
            data >> productCode >> productName >> productPrice >> productDiscount;
            while (!data.eof()) {
                if (productCode == productCodes[i]) {
                    productAmount = productPrice * productQuantities[i];
                    totalAmount = totalAmount + productAmount;
                    cout << "\n"
                         << productCode << "\t\t" << productName << "\t\t" << productQuantities[i] << "\t\t" << productPrice << "\t" << productAmount << "\t\t" << productDiscount;
                    data >> productCode >> productName >> productPrice >> productDiscount;
                }
                data >> productCode >> productName >> productPrice >> productDiscount;
            }
        }
        data.close();
        cout << "\n\n_____________________";
        cout << "\nTotal Amount : " << totalAmount;
    }
}

int main()
{
    Shopping s;
    s.displayMenu();
    return 0;
}