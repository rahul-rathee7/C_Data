// Super market application

#include <iostream>
#include <fstream>
using namespace std;

// Main Class
class shopping
{
    int code;
    float price;
    float discount;
    string name;

public:
    // These are the function which we declare below
    void menu();
    void administration();
    void buyer();
    void add();
    void edit();
    void Remove();
    void list();
    void receipt();
};

// Main Screen Menu function
void shopping::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\n\t\t\t\t______________________________________\n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t        Supermarket Main Menu         \n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t______________________________________\n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t| 1. Administrator                    |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t| 2. Buyer                            |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t| 3. Exit                             |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\n\t\t\t\t Select the option: ";
    cin >> choice;

    // Check condition
    switch (choice)
    {
    case 1:
        system("cls");
        // Taking username and password
        cout << "\n\t\t\t\t________________LOGIN__________________\n";
        cout << "\t\t\t\t Enter Email: ";
        cin >> email;
        cout << "\t\t\t\t Enter Password: ";
        cin >> password;

        // Set Username and Password
        if (email == "abc@gmail.com" && password == "1234")
        {
            system("cls");
            cout << "\n\t\t\t\tYou have logged in successfully";
            administration();
        }
        else
        {
            // When user enterd wrong username and password
            system("cls");
            cout << "\n\t\t\t\tInvalid email/ Password";
        }
        break;

    case 2:
        system("cls");
        // Call buy function
        buyer();

    case 3:
        system("cls");
        // Exit
        cout << "\n\n\t\t\t\t_______________THANK YOU_______________\n";
        exit(0);

    default:
        system("cls");
        // When user enterd wrong key
        cout << "\n\t\t\t\tPlease select from the given options";
    }
    goto m;
}

// Administration function
void shopping::administration()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t\t__________Administrator Menu____________\n";
    cout << "\n\t\t\t\t| 1. Add the product                    |";
    cout << "\n\t\t\t\t|                                       |";
    cout << "\n\t\t\t\t| 2. Modify the product                 |";
    cout << "\n\t\t\t\t|                                       |";
    cout << "\n\t\t\t\t| 3. Delete the product                 |";
    cout << "\n\t\t\t\t|                                       |";
    cout << "\n\t\t\t\t| 4. Back to main menu                  |";
    cout << "\n\t\t\t\t|                                       |";

    cout << "\n\n\t\t\t\tChoose the option: ";
    cin >> choice;

    // Checking above condition
    switch (choice)
    {
    case 1:
        system("cls");
        // call add function for adding product
        add();
        break;

    case 2:
        system("cls");
        // call edit funtion for modify product
        edit();
        break;

    case 3:
        system("cls");
        // call Remove function for delete product
        Remove();
        break;

    case 4:
        system("cls");
        // call menu function for go back to main menu
        menu();
        break;

    default:
        // When user enterd wrong key
        system("cls");
        cout << "\n\t\t\t\tInvalid choice! Please try again";
    }
    goto m;
}

// Buyer function for buy product
void shopping::buyer()
{
m:
    int choice;
    cout << "\n\n\t\t\t\t_______________Buy Product______________\n";
    cout << "\n\n\t\t\t\t 1. Buy Product  \n";
    cout << "\n\t\t\t\t 2. Go back      \n";
    cout << "\n\t\t\t\tChoose the option: ";
    cin >> choice;

    // Check condition
    switch (choice)
    {
    case 1:
        system("cls");
        // call receipt function for taking order
        receipt();
        break;

    case 2:
        system("cls");
        // call menu for go back to main menu
        menu();
        break;

    default:
        system("cls");
        // when user enterd wrong key
        cout << "\n\t\t\t\tInvalid choice!";
    }
    goto m;
}

// Add function for Add new product
void shopping::add()
{
m:
    fstream data;
    int addCode, token = 0;
    float addPrice, addDiscount;
    string addName;

    cout << "\n\n\n\t\t\t\t____________Add New Product_____________\n";
    cout << "\n\n\t\t\t\t Code of the product: ";
    cin >> code;
    cout << "\n\n\t\t\t\t Name of the Product: ";
    cin >> name;
    cout << "\n\n\t\t\t\t Price of the Product: ";
    cin >> price;
    cout << "\n\n\t\t\t\t Discount on Product: ";
    cin >> discount;

    // Read database.txt file
    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << code << " " << name << " " << price << " " << discount
             << "\n";
        data.close();
    }
    else
    {
        data >> addCode >> addName >> addPrice >> addDiscount;

        while (!data.eof())
        {
            if (addCode == code)
            {
                token++;
            }
            data >> addCode >> addName >> addPrice >> addDiscount;
        }
        data.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << code << " " << name << " " << price << " " << discount
                 << "\n";
            data.close();
        }
    }
    system("cls");
    cout << "\n\n\t\t\t\t\tRecord successfully inserted! ";
}

// edit function for modify record
void shopping::edit()
{
    fstream data, data1;
    int token = 0;
    int editProdKey, editCode;
    float editPrice, editDiscout;
    string editName;

    cout << "\n\n\n\t\t\t\t____________Modify the Record_____________\n";
    cout << "\n\t\t\t\t Product code: ";
    cin >> editProdKey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t\t\t\tFile dosn't exist! ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> code >> name >> price >> discount;
        while (!data.eof())
        {
            if (editProdKey == code)
            {
                cout << "\n\t\t\t\t Product new code: ";
                cin >> editCode;
                cout << "\n\t\t\t\t Name of the product: ";
                cin >> editName;
                cout << "\n\t\t\t\t Price of the product: ";
                cin >> editPrice;
                cout << "\n\t\t\t\t Discount of the product: ";
                cin >> editDiscout;
                data1 << " " << editCode << " " << editName << " " << editPrice << " " << editDiscout << "\n";
                system("cls");
                cout << "\n\n\t\t\t\t\tRecord edited successfully";
                token++;
            }
            else
            {
                data1 << " " << code << " " << name << " " << price << " " << discount << "\n";
            }
            data >> code >> name >> price >> discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            system("cls");
            cout << "\n\n\t\t\t\t\tRecord not found!";
        }
    }
}

// Remove function for delete product
void shopping::Remove()
{
    fstream data, data1;
    int removeProdKey, token = 0;
    cout << "\n\n\n\t\t\t\t____________Delete the Record_____________\n";
    cout << "\n\n\t\t\t\tProduct code: ";
    cin >> removeProdKey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t\t\tFile doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> code >> name >> price >> discount;
        while (!data.eof())
        {
            if (code == removeProdKey)
            {
                system("cls");
                cout << "\n\n\t\t\t\t\tProduct deleted successfully";
                token++;
            }
            else
            {
                data1 << " " << code << " " << name << " " << price << " " << discount << "\n";
            }
            data >> code >> name >> price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            system("cls");
            cout << "\n\n\t\t\t\t\t     Record not found! ";
        }
    }
}

// list function for display product list
void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n\t\t\t\t_______________Product List_______________\n";
    cout << "\n\n\t\t\t\t Product Code\t  Product Name\t     Price \n\n";
    data >> code >> name >> price >> discount;
    while (!data.eof())
    {
        cout << "\t\t\t\t     " << code << "\t\t    " << name << "\t      " << price << " \n";
        data >> code >> name >> price >> discount;
    }
    data.close();
}

// receipt function for display receipt after order
void shopping::receipt()
{
    fstream data;
    int arrCode[100];
    int arrQty[100];
    char choice;
    int counter = 0;
    float amount = 0;
    float disc = 0;
    float total = 0;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t\t\tEmpty database";
    }
    else
    {
        data.close();
        list();
        cout << "\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t                 PLACE ORDER               \n";
        do
        {
        m:
            cout << "\n\t\t\t\tEnter the product code: ";
            cin >> arrCode[counter];
            cout << "\n\t\t\t\tEnter the product quantity: ";
            cin >> arrQty[counter];

            for (int i = 0; i < counter; i++)
            {
                if (arrCode[counter] == arrCode[i])
                {
                    system("cls");
                    cout << "\n\n\t\t\t\tDuplicate product code. Please try again!";
                    goto m;
                }
            }
            counter++;
            system("cls");
            cout << "\n\t\t\t\tDo you want to buy another product? if you then press y else no: ";
            cin >> choice;
        } while (choice == 'y');

        // Final Receipt
        system("cls");
        cout << "\n\n\t\t\t_______________________________RECEIPT_________________________________\n";
        cout << "\n\t\tProduct No\tProduct Name\tProduct Quantity\tPrice  \tAmount\t  Amount with Discount\n";

        for (int i = 0; i < counter; i++)
        {
            data.open("database.txt", ios::in);
            data >> code >> name >> price >> discount;

            while (!data.eof())
            {
                if (code == arrCode[i])
                {
                    amount = price * arrQty[i];
                    disc = amount - (amount * discount / 100);
                    total = total + disc;
                    cout << "\n\t\t  " << code << "\t\t  " << name << "\t\t\t" << arrQty[i] << "\t\t " << price << "  \t " << amount << "  \t\t" << disc << "\n";
                }
                data >> code >> name >> price >> discount;
            }
        }
        data.close();
    }
    cout << "\n\t\t\t_________________________________________________________________________";
    cout << "\n\t\t\t\tTotal Amount: " << total << "\n";
}

int main()
{
    // class object
    shopping obj;
    obj.menu();
    return 0;
}