#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

void header()
{
    cout << "___________________________________________________";
    cout << "\n|                                                 |";
    cout << "\n|             HOTEL  MANAGEMENT SYSTEM            |";
    cout << "\n|                                                 |";
    cout << "\n___________________________________________________" << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
class MenuOfHotel
{
public:
    string item;
    int price;
    string price1;
    string items[100];
    int prices[100];
    int priceItems[100];

    void printMenu()
    {
        fstream menu1;
        menu1.open("menu.txt", ios::in);
        for (int i = 0; !menu1.eof(); i++)
        {
            getline(menu1, item);
            getline(menu1, price1);
            stringstream(price1) >> price;
            if (menu1.eof())
                break;
            items[i] = item;
            prices[i] = price;
        }
        cout << "\t\tMENU";
        cout << "\n___________________________________________________" << endl;
        cout << "\tNo."
             << "\tITEMS"
             << "\t\tPRICES" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << "\t" << i + 1 << ")\t" << items[i] << "\t\tRs. " << prices[i];
            cout << endl;
        }
        menu1.close();
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////
class Order : public MenuOfHotel
{
public:
    MenuOfHotel m;
    int bill;
    int choice;
    int quantity;

    Order()
    {
        bill = 0;
        choice = 0;
        quantity = 0;
    }

    void orderByCustomer()
    {
        int enter;
        char wish;
        int visitCount = 0;
        cout << "\nEnter the number of times the customer has visited: ";
        cin >> visitCount;
        cout << "Customer Type: ";
        if (visitCount >= 1 && visitCount < 5)
        {
            cout << "Simple Customer" << endl;
        }
        else if (visitCount >= 5 && visitCount < 10)
        {
            cout << "Gold Customer" << endl;
        }
        else
        {
            cout << "Platinum Customer" << endl;
        }

        do
        {

            header();
            m.printMenu();
            cout << "\n\tEnter your choice  : ";
            cin >> choice;

            while (choice <= 0 || choice > 10)
            {
                cout << "\n\tINVALID CHOICE ! ";
                cout << "\n\tYou did not enter a number between 1 and 10";
                cout << endl
                     << "\n\n\tEnter Your Choice  : ";
                cin >> choice;
            }

            cout << "\tEnter the quantity  : ";
            cin >> quantity;
            bill += m.prices[choice - 1] * quantity;
            header();
            cout << "\n\t\t1)Do want to do payment? "
                    "\n\t\t2)Do you want to continue shopping? "
                    "\n\t\tyour Choice : ";
            cin >> wish;

            while (wish != '1' && wish != '2')
            {
                cout << "\n\t\tINVALID CHOICE ! "
                        "\n\t\tEnter 1 or 2 : ";
                cin >> wish;
            }

        } while (wish == '2');
        cout << "Your bill is: Rs. " << bill << endl;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////
class Customer
{
private:
    int customerId = 0;
    string nameOfCostumer;

public:
    int detailOfCostumer(Order &obj)
    {
        fstream customersDetail;
        cout << "\t\tCustomer Details" << endl;
        cout << "Enter customer name:\n";
        cin.ignore();
        getline(cin, nameOfCostumer);
        customerId++;
        cout << "Enter customer id:\n";
        cout << customerId << endl;
        customersDetail.open("Details.txt", ios::app);
        customersDetail << " Name : " << nameOfCostumer << "\t"
                        << " ID : " << customerId << "\t"
                        << " Bill : " << obj.bill;
        return 0;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////

class Employee
{
protected:
    int salaryOfEmployee;
    string nameOfEmployee;

public:
    int noOfWaiter;
    int noOfChef;

    void setWaiter(int w)
    {
        noOfWaiter = w;
    }

    void setChef(int c)
    {
        noOfChef = c;
    }

    Employee()
    {
        salaryOfEmployee = 0;
    }

    Employee(int salaryOfEmployee)
    {
        this->salaryOfEmployee = salaryOfEmployee;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////
class Waiter : public Employee
{
public:
    void setWaiterInfo()
    {
        ofstream myFile;
        myFile.open("waiter.txt", ios::app);
        if (!myFile)
        {
            cout << "enable to open" << endl;
        }
        else
        {
            for (int i = 1; i <= noOfWaiter; i++)
            {
                cout << "Name of Waiter: ";
                cin >> nameOfEmployee;
                cout << "Waiter ID: " << i << endl;
                myFile << nameOfEmployee << "\t" << i << "\t" << salaryOfEmployee << endl;
            }
        }
        myFile.close();
    }

    void getWaiterDetails()
    {
        ifstream myFile;
        myFile.open("waiter.txt");
        if (!myFile)
        {
            cout << "enable to open" << endl;
        }
        else
        {
            for (int i = 1; i <= noOfWaiter; i++)
            {
                myFile >> nameOfEmployee;
                myFile >> i;
                myFile >> salaryOfEmployee;
                cout << "\t" << nameOfEmployee << "\t\t" << i << "\t\t" << salaryOfEmployee << endl;
            }
        }
        myFile.close();
    }

    void orderDetails(Order &obj)
    {
        cout << "\t\tORDER DETAILS" << endl;
        cout << "\tChoice Item no."
             << "\t\tquantity of Item" << endl;
        cout << "\t" << obj.choice << "\t\t\t" << obj.quantity << endl;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////
class Chef : public Employee
{
public:
    void setChefInfo()
    {
        ofstream myFile;
        myFile.open("chef.txt", ios::app);
        if (!myFile)
        {
            cout << "enable to open" << endl;
        }
        else
        {
            for (int i = 1; i <= noOfChef; i++)
            {
                cout << "Name of Chef: ";
                cin >> nameOfEmployee;
                cout << "Chef ID: " << i << endl;
                myFile << nameOfEmployee << "\t" << i << "\t" << salaryOfEmployee << endl;
            }
        }
        myFile.close();
    }

    void getChefDetails()
    {
        ifstream myFile;
        myFile.open("chef.txt");
        if (!myFile)
        {
            cout << "enable to open" << endl;
        }
        else
        {
            for (int i = 1; i <= noOfChef; i++)
            {
                myFile >> nameOfEmployee;
                myFile >> i;
                myFile >> salaryOfEmployee;
                cout << "\t" << nameOfEmployee << "\t\t" << i << "\t\t" << salaryOfEmployee << endl;
            }
        }
        myFile.close();
    }

    void orderDetails(Order &obj)
    {
        cout << "\t\tORDER DETAILS" << endl;
        cout << "\tChoice Item no:"
             << "\t\tquantity of Item:" << endl;
        cout << "\t" << obj.choice << "\t\t\t" << obj.quantity << endl;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////
class Payment
{
protected:
    int billAmount;

public:
    void set(Order *o)
    {
        billAmount = o->bill;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////
class Cash : public Payment
{
private:
    int receivedAmount;
    int returnAmount;

public:
    void userAmount()
    {
        cout << "\t\tBill Details" << endl;
        cout << "Bill Amount: " << billAmount << endl;
        cout << "RECEIVED AMOUNT: ";
        cin >> receivedAmount;
        if (receivedAmount >= billAmount)
        {
            returnAmount = receivedAmount - billAmount;
            cout << "Payment is successfully accepted" << endl;
            cout << "YOUR RETURNED AMOUNT: " << returnAmount << endl
                 << endl;
        }
        else
        {
            cout << "your money is not sufficient for this bill" << endl;
        }
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////
class log
{
public:
    void login()
    {
        int count = 0;
        string user, pass, u, p;
        cout << "Username:" << endl;
        cin >> user;
        cout << "Password:" << endl;
        cin >> pass;
        ifstream input("database.txt");
        while (input >> u >> p)
        {
            if (u == user && p == pass)
            {
                count = 1;
                break;
            }
        }
        input.close();
        if (count == 1)
        {
            cout << user << " Login successful:" << endl;
        }
        else
        {
            cout << "Login error!" << endl;
        }
    }

    void registration()
    {
        string reg_user, reg_pass, ru, pu;
        cout << "Enter username:" << endl;
        cin >> reg_user;
        cout << "Enter password:" << endl;
        cin >> reg_pass;
        ofstream reg("database.txt", ios::app);
        reg << reg_user << " " << reg_pass << endl;
        cout << "Registration successful!!!" << endl;
    }
    void forgot()
    {
        int ch;
        string search_user, su, sp;
        cout << "1.Search your id by username" << endl;
        cout << "2.Main menu" << endl;
        cout << "enter:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int count = 0;
            string search_user, su, sp;
            cout << "Enter your remembered username:" << endl;
            cin >> search_user;
            ifstream searchu("database.txt");
            while (searchu >> su >> sp)
            {
                if (su == search_user)
                {
                    count == 1;
                }
            }
            searchu.close();
            if (count == 1)
            {
                cout << "account found!" << endl;
                cout << "your password is" << sp;
                cin.get();
            }
            else
            {
                cout << "no user id found" << endl;
                cin.get();
            }
        }
        }
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////
void layout()
{
    header();
    log l;
    Waiter w;
    Chef ch;
    MenuOfHotel m;
    Order o;
    Cash cs;
    Customer c;
    char option;
    do
    {
        cout << "\t\t1) Employee"
                "\n\t\t2) Customer"
                "\n\t\t3)Login/Signup"
                "\n\t\tE) Exit "
                "\n\t\tYour option: ";
        cin >> option;
        switch (option)
        {
        case '1':
        {
            int check;

            header();
            cout << "\n\tCheck details of"
                    "\n\t1)Chef"
                    "\n\t2)Waiter"
                    "\n\tENTER: ";
            cin >> check;
            if (check == 1)
            {

                header();
                ch.setChef(5);
                cout << "\n\t\tDISPLAY CHEF DETAILS" << endl;
                cout << "\n___________________________________________________" << endl;
                cout << "\tName\t\tID\t\tSalary" << endl;
                ch.getChefDetails();
                cout << "\n___________________________________________________" << endl;
                ch.orderDetails(o);
                cout << "\n___________________________________________________" << endl;
            }
            else if (check == 2)
            {

                header();
                w.setWaiter(5);
                cout << "\n\t\tDISPLAY WAITER DETAILS" << endl;
                cout << "\n___________________________________________________" << endl;
                cout << "\tName\t\tID\t\tSalary" << endl;
                w.getWaiterDetails();
                cout << "\n___________________________________________________" << endl;
                w.orderDetails(o);
                cout << "\n___________________________________________________" << endl;
            }
            break;
        }
        case '2':
        {
            int enter;

            header();
            o.orderByCustomer();

            header();
            cout << "\nEnter the mode of payment you want: "
                    "\n1)Cash"
                    "\n\tEnter: ";
            cin >> enter;
            switch (enter)
            {
            case 1:
            {
                header();
                c.detailOfCostumer(o);
                cout << "\n___________________________________________________" << endl;
                cs.set(&o);
                cs.userAmount();
                cout << "\n___________________________________________________" << endl;
                break;
            }
            }
            break;
        }
        case '3':
        {
            cout << "a. Login" << endl;
            cout << "b. Register" << endl;
            cout << "c. Forgot username or password" << endl;
            cout << "d. Exit" << endl;

            char choice;
            cin >> choice;
            switch (choice)
            {
            case 'a':
                l.login();
                break;

            case 'b':
                l.registration();
                break;

            case 'c':
                l.forgot();
                break;

            case 'd':
                return;

            default:
                cout << "Invalid choice" << endl;
            }
        }
        break;
        }
    } while (option != 'e' && option != 'E');

    cout << "bye!" << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    layout();
    return 0;
}
