#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <cmath>
#include <windows.h>
using namespace std;

// Funtion Prototypes
void startingScreen(); // startingpage
void header();         // print header
string menu();         // print main menu
string Admin_menu();
string customer_menu();
bool isvalid_user_name(string name);
bool isvalid_admin_name(string name);
void signup_user(string username, string password, string role);
void signup_admin(string username, string password, string role);
string sign_in_user(string username, string password);
string sign_in_admin(string username, string password);
void store_user_data(string username, string password, string role);
void store_admin_data(string username, string password, string role);
void read_admin_data_from_file();
void read_user_data_from_file();
void stock();
void remaining_stock();
void add_products(string product, float price, float quantity);
void store_add_Items();
void read_total_items_from_file();
bool del_product(string);
void edit_product(string update_product, float new_price, float new_quantity);
void select_Items();
bool check_item();
bool search(string item);
void display_search_item(string item);
void calculate_user_bill();
void display_user_bill();
void total_bill();
void show_totalbill(float);
void validate_price();
void validate_quantity();
void view_users();
void display_admins();
void view_admins();
bool check_quantity();
string getField(string record, int field);
void add_feedback();
void view_feedback();
bool validate_feedback_user_name(string user_name);
void store_feedback();
void read_feedback();
void press();
void gotoxy(float x, float y);
void color1(int color1);
void help();

const int size = 400;
// Arrays
string userName[size];
string adminName[size];
string userPassword[size];
string adminPassword[size];
string userRole[size];
string adminRole[size];
string Items[size];
float Prices[size];
float Quantity[size];
string user_selected_Items[size];
float user_Items_quantity[size];
float bill[size];
string user_feedback[size];
string FeedbackName[size];

// variables
string admin_default_key = "lock123";
string Role;
int count_user = 0;
int count_admin = 0;
int total_add_items = 0;
int user_select_items = 0;
string admin_opinion = "0";
string user_opinion = "0";
char suggestion;
int count_feedback = 0;

char ch = 244;
main()
{
    read_user_data_from_file();
    read_admin_data_from_file();
    read_feedback();
    read_total_items_from_file();
    startingScreen();
    string option = "0";
    bool decision;
    string  choice;
    string name, password, role;

    while (option != "3")
    {

        system("cls");
        header();
        option = menu();
        system("cls");
        header();
        if (option == "1")
        {
            color1(6);
            cout << "  Sign up Menu" << endl;
            color1(7);
            color1(9);
            cout << "--------------------->>>" << endl
                 << endl;
            color1(7);
            cout << "Enter your Name:";
            cin.clear();
            cin.sync();
            getline(cin, name);
            cout << "Enter password:";
            cin.clear();
            cin.sync();
            getline(cin, password);
            cout << "Enter role:(admin or user)";
            cin.clear();
            cin.sync();
            getline(cin, role);
            if (role == "user")
            {
                decision = isvalid_user_name(name);

                if (decision == true)
                {
                    signup_user(name, password, role);
                    store_user_data(name, password, role);
                    color1(6);
                    cout << "signup user_succssfully:" << endl;
                    color1(7);
                    press();
                }
                else
                {
                    color1(4);
                    cout << "user already exits:" << endl;
                    color1(7);
                    press();
                }
            }
            else if (role == "admin")
            {
                decision = isvalid_admin_name(name);

                if (decision == true)
                {
                    string check_key;
                    color1(8);
                    cout << "Enter Admin Special Login Key:";
                    color1(7);
                    cin.clear();
                    cin.sync();
                    getline(cin, check_key);
                    if (check_key == admin_default_key)
                    {
                        signup_admin(name, password, role);
                        store_admin_data(name, password, role);
                        color1(6);
                        cout << "signup admin_succssfully:" << endl;
                        color1(7);
                        press();
                    }
                    else
                    {
                        color1(4);
                        cout << "You are not Admin sign_up as user:" << endl;
                        color1(7);
                        press();
                    }
                }
                else
                {
                    color1(4);
                    cout << "admin already exits:" << endl;
                    color1(7);
                    press();
                }
            }

            else
            {
                color1(4);
                cout << "Wrong role:" << endl;
                color1(7);
                press();
            }
        }

        else if (option == "2")
        {
            color1(12);
            cout << "  Sign in Menu" << endl;
            color1(7);
            color1(9);
            cout << "--------------------->>>" << endl
                 << endl;
            color1(7);
            cout << "Enter your Name:";
            cin.clear();
            cin.sync();
            getline(cin, name);
            cout << "Enter password:";
            cin.clear();
            cin.sync();
            getline(cin, password);
            color1(9);
            cout << "press 0 For Admin and 1 For User:";
            color1(7);
            cin.clear();
            cin.sync();
            getline(cin, choice);
            if (choice == "0")
            {
                Role = sign_in_admin(name, password);
            }
            else if (choice == "1")
            {
                Role = sign_in_user(name, password);
            }

            if (Role == "admin")
            {
                color1(6);
                cout << "Admin Login successfully:" << endl;
                color1(7);
                press();
                while (admin_opinion != "9")
                {
                    system("cls");
                    admin_opinion = Admin_menu();
                    system("cls");
                    header();
                    if (admin_opinion == "1")
                    {
                        stock();
                    }
                    else if (admin_opinion == "2")
                    {
                        color1(12);
                        cout << "  Add Menu" << endl;
                        color1(7);
                        color1(9);
                        cout << "--------------------->>>" << endl
                             << endl;
                        color1(7);
                        string product;
                        float price, quantity;
                        while (suggestion != 'n')
                        {
                            cout << "Enter name of Product:";
                            cin.clear();
                            cin.sync();
                            getline(cin, product);
                            bool result = search(product);
                            if (result == false)
                            {
                                while (true)
                                {
                                    cout << "Enter Price:";
                                    cin >> price;
                                    if (cin.fail() || price <= 0)
                                    {
                                        validate_price();
                                    }
                                    else
                                        break;
                                }
                                cin.sync();
                                while (true)
                                {
                                    cout << "Enter Quantity:";
                                    cin >> quantity;
                                    if (cin.fail() || quantity <= 0)
                                    {
                                        validate_quantity();
                                    }
                                    else
                                        break;
                                }
                                cin.sync();
                                add_products(product, price, quantity);
                            }
                            else
                            {
                                color1(4);
                                cout << "Item already Exits" << endl;
                                color1(7);
                            }
                            color1(3);
                            cout << "\n";
                            cout << "Do you want to add more Items:(n to exit press any key to cotinue):";
                            color1(7);
                            cin >> suggestion;
                        }
                        press();
                        suggestion = ' ';
                        store_add_Items();
                    }

                    else if (admin_opinion == "3")
                    {
                        color1(12);
                        cout << "  Delete Menu" << endl;
                        color1(7);
                        color1(9);
                        cout << "--------------------->>>" << endl
                             << endl;
                        color1(7);
                        string delete_product;
                        cout << "Enter name of Product you want to Delete:";
                        cin.clear();
                        cin.sync();
                        getline(cin, delete_product);
                        bool present = del_product(delete_product);

                        if (present == true)
                        {
                            color1(6);
                            cout << "item deleted successfully" << endl;
                            color1(7);
                        }
                        else
                        {
                            color1(4);
                            cout << "item does not exist:" << endl;
                            color1(7);
                        }
                        press();
                        store_add_Items();
                    }
                    else if (admin_opinion == "4")
                    {
                        color1(12);
                        cout << "  Edit Menu" << endl;
                        color1(7);
                        color1(9);
                        cout << "--------------------->>>" << endl
                             << endl;
                        color1(7);
                        string update_product;
                        bool result;
                        float new_price, new_quantity;

                        cout << "Enter name of product you want to update : ";
                        cin.clear();
                        cin.sync();
                        getline(cin, update_product);
                        result = search(update_product);
                        if (result == true)
                        {
                            while (true)
                            {
                                cout << "Enter new price:";
                                cin >> new_price;
                                if (cin.fail())
                                {
                                    validate_price();
                                }
                                else
                                {
                                    break;
                                }
                            }
                            cin.sync();
                            while (true)
                            {
                                cout << "Enter_new Quantity:";
                                cin >> new_quantity;
                                if (cin.fail())
                                {
                                    validate_quantity();
                                }
                                else
                                {
                                    break;
                                }
                            }
                            cin.sync();
                            edit_product(update_product, new_price, new_quantity);
                            color1(6);
                            cout << "Item updated successfully" << endl;
                            color1(7);
                            press();
                            store_add_Items();
                        }
                        else
                        {
                            color1(4);
                            cout << "item does not exist" << endl;
                            color1(7);
                            press();
                        }
                    }
                    else if (admin_opinion == "5")
                    {
                        color1(2);
                        cout << "   Search Menu" << endl;
                        color1(7);
                        color1(9);
                        cout << "--------------------->>>" << endl
                             << endl;
                        color1(7);
                        string search_item;
                        cout << "Enter Item You Want to Search:";
                        cin.clear();
                        cin.sync();
                        getline(cin, search_item);
                        bool present = search(search_item);
                        if (present == true)
                        {

                            display_search_item(search_item);
                        }
                        else
                        {
                            color1(4);
                            cout << "Item does not exist:" << endl;
                            color1(7);
                            press();
                        }
                    }

                    else if (admin_opinion == "6")
                    {
                        view_users();
                    }
                    else if (admin_opinion == "7")
                    {
                        display_admins();
                    }
                    else if (admin_opinion == "8")
                    {
                        view_feedback();
                    }
                    else if (admin_opinion == "9")
                    {
                        admin_opinion = "0";
                        break;
                    }
                }
            }

            else if (Role == "user")
            {
                color1(6);
                cout << "User_Login successfully:" << endl;
                color1(7);
                press();
                while (user_opinion != "8")
                {
                    system("cls");
                    user_opinion = customer_menu();
                    system("cls");
                    header();
                    if (user_opinion == "1")
                    {
                        stock();
                    }
                    else if (user_opinion == "2")
                    {
                        color1(2);
                        cout << "  Select Menu" << endl;
                        color1(7);
                        color1(9);
                        cout << "--------------------->>>" << endl
                             << endl;
                        color1(7);
                        select_Items();
                    }
                    else if (user_opinion == "3")
                    {
                        color1(2);
                        cout << "   Search Menu" << endl;
                        color1(7);
                        color1(9);
                        cout << "--------------------->>>" << endl
                             << endl;
                        color1(7);
                        string search_item;
                        cout << "Enter Item You Want to Search:";
                        cin.clear();
                        cin.sync();
                        getline(cin, search_item);
                        bool present = search(search_item);
                        if (present == true)
                        {

                            display_search_item(search_item);
                        }
                        else
                        {
                            color1(4);
                            cout << "Item does not exist:" << endl;
                            color1(7);
                            press();
                        }
                    }
                    else if (user_opinion == "4")
                    {
                        display_user_bill();
                    }
                    else if (user_opinion == "5")
                    {
                        add_feedback();
                        store_feedback();
                    }
                    else if (user_opinion == "6")
                    {
                        view_admins();
                    }
                    else if (user_opinion == "7")
                    {
                        help();
                    }
                    else if (user_opinion == "8")
                    {
                        store_add_Items();
                        user_opinion = "0";
                        user_select_items = 0;
                        break;
                    }
                }
            }
            else
            {
                color1(4);
                cout << "Something went wrong:" << endl;
                color1(7);
                press();
            }
        }
        else if (option == "3")
        {
            system("cls");
            color1(6);
            cout << "Thanks For Using this Application:";
            color1(7);
        }
    }
}
void startingScreen()
{
    system("cls");
    color1(2);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t  __|HM\\         " << endl;
    cout << "\t\t\t/HH\\.M|                  " << endl;
    cout << "\t\t\tHMHH\\.|                         " << endl;
    cout << "\t\t\t\\HMHH\\|                         " << endl;
    cout << "\t\t\t\\\\HMHH\\                         " << endl;
    cout << "\t\t\tHH\\HMHH\\                        " << endl;
    cout << "\t\t\tHHH\\HMHH\\                       " << endl;
    cout << "\t\t\t    \\HMHH\\-HHH\\                 " << endl;
    cout << "\t\t\t     \\HMHH\\.HHM\\                " << endl;
    cout << "\t\t\t      \\HMHH\\.HMH\\               " << endl;
    cout << "\t\t\t      |\\HMHH\\\\HMH\\              " << endl;
    cout << "\t\t\t      |H\\HHH| \\HMH\\             " << endl;
    cout << "\t\t\t      |MH\\H/   \\HMH\\            " << endl;
    cout << "\t\t\t      |MH\\      \\HMH\\           " << endl;
    cout << "\t\t\t      \\HMH\\      \\HMH\\          " << endl;
    cout << "\t\t\t       \\HMH\\    __|HM|          " << endl;
    cout << "\t\t\t        \\HMH\\  /HH\\.M|          " << endl;
    cout << "\t\t\t         \\HMH\\ |MHH\\.|          " << endl;
    cout << "\t\t\t          \\HMH\\\\HMHH\\|          " << endl;
    cout << "\t\t\t           \\HMH\\\\HMHH\\          " << endl;
    cout << "\t\t\t            \\HMHH\\HMHH\\         " << endl;
    cout << "\t\t\t             \\HHHH\\HMHH\\        " << endl;
    cout << "\t\t\t                   \\HMHH\\-HHH\\  " << endl;
    cout << "\t\t\t                    \\HMHH\\.HHM\\ " << endl;
    cout << "\t\t\t                     \\HMHH\\.HMH\\" << endl;
    cout << "\t\t\t                     |\\HMHH|\\HMH" << endl;
    cout << "\t\t\t                     |H\\HMH/ \\HM" << endl;
    cout << "\t\t\t                     |MH\\H/   \\H" << endl;
    cout << "\t\t\t                     |MH\\      \\" << endl;
    cout << "\t\t\t                     \\HMH\\      " << endl;
    cout << "\t\t\t                      \\HMH\\     " << endl;
    cout << "\t\t\t                       \\HMH\\   " << endl;
    color1(7);
    color1(6);
    gotoxy(55, 20 - 2);
    cout << "  ____                         __        " << endl;
    gotoxy(55, 21 - 2);
    cout << "/\\  _`\\                    __/\\ \\__          " << endl;
    gotoxy(55, 22 - 2);
    cout << "\\ \\,\\L\\_\\     __      ___ /\\_\\ \\ ,_\\    __     _ __   __  __" << endl;
    gotoxy(55, 23 - 2);
    cout << " \\/_\\__ \\   /'__`\\  /' _ `\\/\\ \\ \\ \\/  /'__`\\  /\\`'__\\/\\ \\/\\ \\" << endl;
    gotoxy(55, 24 - 2);
    cout << "   /\\ \\L\\ \\/\\ \\L\\.\\_/\\ \\/\\ \\ \\ \\ \\ \\_/\\ \\L\\.\\_\\ \\ \\/ \\ \\ \\_\\ \\" << endl;
    gotoxy(55, 25 - 2);
    cout << "   \\ `\\____\\ \\__/.\\_\\ \\_\\ \\_\\ \\_\\ \\__\\ \\__/.\\_\\\\ \\_\\  \\/`____ \\ " << endl;
    gotoxy(55, 26 - 2);
    cout << "    \\/_____/\\/__/\\/_/\\/_/\\/_/\\/_/\\/__/\\/__/\\/_/ \\/_/   `/___/> \\" << endl;
    gotoxy(55, 27 - 2);
    cout << "                                                          /\\___/" << endl;
    gotoxy(55, 28 - 2);
    cout << "                                                          \\/__/ " << endl;
    gotoxy(55, 29 - 2);
    color1(7);
    color1(9);
    cout << "                                  &                                                      " << endl;
    color1(7);
    color1(5);
    gotoxy(55, 55 - 2);
    cout << "__  __                     __                                       " << endl;
    gotoxy(55, 31 - 2);
    cout << "/\\ \\/\\ \\                   /\\ \\                                      " << endl;
    gotoxy(55, 32 - 2);
    cout << "\\ \\ \\_\\ \\     __     _ __  \\_\\ \\  __  __  __     __     _ __    __   " << endl;
    gotoxy(55, 33 - 2);
    cout << " \\ \\  _  \\  /'__`\\  /\\`'__\\/'_` \\/\\ \\/\\ \\/\\ \\  /'__`\\  /\\`'__\\/'__`\\" << endl;
    gotoxy(55, 34 - 2);
    cout << "  \\ \\ \\ \\ \\/\\ \\L\\.\\_\\ \\ \\//\\ \\L\\ \\ \\ \\_/ \\_/ \\/\\ \\L\\.\\_\\ \\ \\//\\  __/" << endl;
    gotoxy(55, 35 - 2);
    cout << "   \\ \\_\\ \\_\\ \\__/.\\_\\\\ \\_\\\\ \\___,_\\ \\___~___/'\\ \\__/.\\_\\\\ \\_\\\\ \\____\\" << endl;
    gotoxy(55, 36 - 2);
    cout << "    \\/_/\\/_/\\/__/\\/_/ \\/_/ \\/__,_ /\\/__//__/   \\/__/\\/_/ \\/_/ \\/____/" << endl;
    gotoxy(55, 40 - 2);
    color1(7);
    color1(12);
    cout << "                      ITEMS MANAGEMENT SYSTEM                                      " << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl;
    color1(7);
    color1(1);
    cout << "---------------------->>>>" << endl;
    color1(7);
    press();
}

string menu()
{
    string choice;
    color1(2);
    cout << "  Main Menu" << endl;
    color1(7);
    color1(9);
    cout << "-------------------->>>" << endl
         << endl
         << endl;
    color1(7);
    cout << "  1: sign up" << endl;
    cout << "  2: sign in" << endl;
    cout << "  3: Exit" << endl;
    cout << "  Enter choice:";
    cin.clear();
    cin.sync();
    getline(cin, choice);

    return choice;
}
void header()
{
    color1(9);
    cout << "\t\t\t_________________________________________________________________________________________________________" << endl;
    color1(7);
    cout << "\t\t\t    ____ ____ _  _ _ ___ ____ ____ _   _    ____ _  _ ___     _  _ ____ ____ ___  _ _ _ ____ ____ ____" << endl;
    cout << "\t\t\t    [__  |__| |\\ | |  |  |__| |__/  \\_/     |__| |\\ | |  \\    |__| |__| |__/ |  \\ | | | |__| |__/ |___ " << endl;
    cout << "\t\t\t    ___] |  | | \\| |  |  |  | |  \\   |      |  | | \\| |__/    |  | |  | |  \\ |__/ |_|_| |  | |  \\ |___ " << endl;
    cout << endl;
    color1(4);
    cout << "\t\t\t                                    ITEMS   MANAGEMENT   SYSTEM                     " << endl;
    color1(7);
    color1(9);
    cout << "\t\t\t_________________________________________________________________________________________________________" << endl;
    color1(7);
    cout << "                                                                                         " << endl;
    cout << "                                                                                         " << endl;
}
bool isvalid_admin_name(string username)
{
    bool flag = true;
    for (int indx = 0; indx < count_admin; indx++)
    {
        if (adminName[indx] == username)
        {

            flag = false;
        }
    }
    return flag;
}
void signup_admin(string username, string password, string role)
{
    adminName[count_admin] = username;
    adminPassword[count_admin] = password;
    adminRole[count_admin] = role;
    count_admin++;
}
string sign_in_admin(string name, string password)
{

    for (int i = 0; i < count_admin; i++)
    {
        if (name == adminName[i] && password == adminPassword[i])
        {
            return adminRole[i];
        }
    }
    return "wrong";
}
void store_admin_data(string username, string password, string role)
{
    fstream file;
    file.open("admin.txt", ios::app);
    file << username << ch << password << ch << role << endl;
    file.close();
}
void read_admin_data_from_file()
{
    string record;
    fstream file;
    file.open("admin.txt", ios ::in);
    while (getline(file, record))
    {
        if (record == "0")
        {
            continue;
        }
        try
        {
            adminName[count_admin] = getField(record, 1);
            adminPassword[count_admin] = getField(record, 2);
            adminRole[count_admin] = (getField(record, 3));
            count_admin++;
        }
        catch (const std::invalid_argument &e)
        {
            // handle the exception here
        }
    }
    file.close();
}
string Admin_menu()
{
    header();
    string opinion;
    color1(2);
    cout << "  Admin Menu" << endl;
    color1(7);
    color1(9);
    cout << "-------------------->>>" << endl
         << endl
         << endl;
    color1(7);
    cout << "  1-View Stock:" << endl;
    cout << "  2-Add new Items:" << endl;
    cout << "  3-Delete Item:" << endl;
    cout << "  4-Update Item:" << endl;
    cout << "  5-Search Item:" << endl;
    cout << "  6-View Users:" << endl;
    cout << "  7-View Admins:" << endl;
    cout << "  8-View Feedback:" << endl;
    cout << "  9-Back to main Menu:" << endl;
    cout << "  Enter your opinion:";
    cin.clear();
    cin.sync();
    getline(cin, opinion);
    return opinion;
}

bool isvalid_user_name(string username)
{
    bool flag = true;
    for (int indx = 0; indx < count_user; indx++)
    {
        if (userName[indx] == username)
        {
            flag = false;
        }
    }
    return flag;
}
void signup_user(string username, string password, string role)
{
    userName[count_user] = username;
    userPassword[count_user] = password;
    userRole[count_user] = role;
    count_user++;
}
string sign_in_user(string name, string password)
{

    for (int indx = 0; indx < count_user; indx++)
    {
        if (name == userName[indx] && userPassword[indx] == password)
        {
            return userRole[indx];
        }
    }
    return "wrong";
}
void store_user_data(string username, string password, string role)
{
    fstream file;
    file.open("user.txt", ios::app);
    file << username << ch << password << ch << role << endl;
    file.close();
}
void read_user_data_from_file()
{
    string record;
    fstream file;
    file.open("user.txt", ios ::in);
    while (getline(file, record))
    {
        if (record == "0")
        {
            continue;
        }
        try
        {
            userName[count_user] = getField(record, 1);
            userPassword[count_user] = getField(record, 2);
            userRole[count_user] = (getField(record, 3));
            count_user++;
        }
        catch (const std::invalid_argument &e)
        {

            // handle the exception here
        }
    }
    file.close();
}

string customer_menu()
{
    header();
    string opinion;
    color1(2);
    cout << "  User Menu" << endl;
    color1(7);
    color1(9);
    cout << "----------------------->>>" << endl
         << endl
         << endl;
    color1(7);
    cout << "  1-View items with price:" << endl;
    cout << "  2-Select require items:" << endl;
    cout << "  3-Search item:" << endl;
    cout << "  4-View bill:" << endl;
    cout << "  5-Give feedback:" << endl;
    cout << "  6-View Admins:" << endl;
    cout << "  7-Get Help:" << endl;
    cout << "  8-Back to main menu:" << endl;
    cout << "  Enter your opinion:";
    cin.clear();
    cin.sync();
    getline(cin, opinion);
    return opinion;
}
void stock()
{
    color1(6);
    cout << "STOCK Menu" << endl;
    color1(7);
    color1(9);
    cout << "---------------------->>>" << endl
         << endl;
    color1(7);
    color1(2);
    cout << "Product Id\t\tItemName\t\tPrice\t\tQuantity" << endl;
    color1(7);
    for (int indx = 0; indx < total_add_items; indx++)
    {
        if (Items[indx] == "0" && Prices[indx] == 0 && Quantity[indx] == 0)

        {
            continue;
        }
        cout << " " << indx + 1 << "\t\t\t" << Items[indx] << "\t\t\t" << Prices[indx] << "\t\t" << Quantity[indx] << endl;
    }
    press();
}

void add_products(string product, float price, float quantity)
{

    Items[total_add_items] = product;
    Prices[total_add_items] = price;
    Quantity[total_add_items] = quantity;
    total_add_items++;
}
void store_add_Items()
{
    fstream file;
    file.open("add_Items.txt", ios::out);
    for (int indx = 0; indx < total_add_items; indx++)
    {
        file << Items[indx] << ch << Prices[indx] << ch << Quantity[indx] << endl;
    }
    file.close();
}
void read_total_items_from_file()
{
    string record;
    fstream file;
    file.open("add_items.txt", ios ::in);
    while (getline(file, record))
    {
        if (record == "0")
        {
            continue;
        }
        try
        {
            Items[total_add_items] = getField(record, 1);
            Prices[total_add_items] = stof(getField(record, 2));
            Quantity[total_add_items] = stof(getField(record, 3));
            total_add_items++;
        }
        catch (const std::invalid_argument &e)
        {
            // handle the exception here
        }
    }
    file.close();
}

void validate_price()
{

    color1(4);
    cout << "Wrong input Re.enter price:" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    color1(7);
}
void validate_quantity()
{

    color1(4);
    cout << "Wrong input Re.enter quantity:" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    color1(7);
}
bool del_product(string delete_product)
{
    bool present = false;
    for (int indx = 0; indx < total_add_items; indx++)
    {
        if (Items[indx] == delete_product)
        {
            Items[indx] = "0";
            Prices[indx] = 0;
            Quantity[indx] = 0;
            present = true;
        }
    }
    return present;
}

string getField(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ch)
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

void edit_product(string update_product, float new_price, float new_quantity)
{
    for (int indx = 0; indx < total_add_items; indx++)
    {
        if (update_product == Items[indx])
        {
            Prices[indx] = new_price;
            Quantity[indx] = new_quantity;
        }
    }
}
void select_Items()
{
    color1(7);
    while (suggestion != 'n')
    {

        cout << "Name of product:";
        cin.clear();
        cin.sync();
        getline(cin, user_selected_Items[user_select_items]);
        bool validate = check_item();
        if (validate == true)
        {
            while (true)
            {
                cout << "Enter Quantity:";
                cin >> user_Items_quantity[user_select_items];
                if (cin.fail() || user_Items_quantity[user_select_items] <= 0)
                {
                    validate_quantity();
                }
                else
                {
                    break;
                }
            }
            cin.sync();
            bool validates = check_quantity();
            if (validates == true)
            {
                color1(6);
                cout << "Item selected successfully" << endl;
                color1(7);

                remaining_stock();
                user_select_items++;
            }
            else
            {
                color1(4);
                cout << "quantity exceeds" << endl;
                color1(7);
            }
        }
        else
        {
            color1(4);
            cout << "Item does not exit:" << endl;
            color1(7);
        }
        color1(3);
        cout << "\n";
        cout << "Do you want to select more Items:(n to exit & press any key to continue):";
        color1(7);
        cin >> suggestion;
    }
    press();
    suggestion = ' ';
}
bool check_item()
{
    bool ispresent = false;

    for (int indx = 0; indx < total_add_items; indx++)
    {
        if (user_selected_Items[user_select_items] == Items[indx])
        {

            ispresent = true;
        }
    }
    return ispresent;
}
bool check_quantity()
{
    bool ispresent = false;
    for (int indx = 0; indx < total_add_items; indx++)
    {
        if (user_selected_Items[user_select_items] == Items[indx] && user_Items_quantity[user_select_items] <= Quantity[indx])
        {
            ispresent = true;
        }
    }
    return ispresent;
}
void calculate_user_bill()
{
    for (int indx = 0; indx < user_select_items; indx++)
    {
        for (int i = 0; i < total_add_items; i++)
        {
            if (user_selected_Items[indx] == Items[i])
            {
                bill[indx] = Prices[i] * user_Items_quantity[indx];
            }
        }
    }
}
void remaining_stock()
{

    for (int i = 0; i < total_add_items; i++)
    {
        if (user_selected_Items[user_select_items] == Items[i] && user_Items_quantity[user_select_items] <= Quantity[i])
        {

            Quantity[i] = Quantity[i] - user_Items_quantity[user_select_items];
        }
    }
}
bool search(string item)
{
    bool present = false;
    for (int i = 0; i < total_add_items; i++)
    {
        if (item == Items[i])
        {
            present = true;
        }
    }
    return present;
}
void display_search_item(string item)
{
    cout << endl
         << endl
         << endl;

    color1(12);
    cout << "Id NO\t\tName\t\tQuantity\tPrice" << endl;
    color1(7);
    for (int i = 0; i < total_add_items; i++)
    {
        if (item == Items[i])
        {
            cout << " " << i + 1 << "\t\t" << Items[i] << "\t\t" << Quantity[i] << "\t\t" << Prices[i] << endl
                 << endl
                 << endl;
        }
    }
    press();
}
void display_user_bill()
{
    calculate_user_bill();
    color1(5);
    cout << " Bill Menu" << endl;
    color1(7);
    color1(9);
    cout << "-------------------->>>" << endl
         << endl;
    color1(7);
    if (user_select_items != 0)
    {
        color1(2);
        cout << "Product Id\t\tItemName\t\tQuantity\t\tPrice\t\tbill" << endl;
        color1(7);
        for (int indx = 0; indx < user_select_items; indx++)
        {
            for (int i = 0; i < total_add_items; i++)
            {
                if (user_selected_Items[indx] == Items[i])
                {
                    cout << " " << indx + 1 << "\t\t\t" << user_selected_Items[indx] << "\t\t\t" << user_Items_quantity[indx] << "\t\t\t"
                         << Prices[i] << "\t\t" << bill[indx] << endl;
                }
            }
        }
    }
    else
    {
        color1(6);
        cout << "Please First Select Require items:" << endl;
        color1(7);
    }
    total_bill();
    press();
}
void total_bill()
{
    float user_total_bill = 0;
    for (int i = 0; i < user_select_items; i++)
    {
        user_total_bill = user_total_bill + bill[i];
    }

    show_totalbill(user_total_bill);
}

void show_totalbill(float user_total_bill)
{
    if (user_select_items != 0)
    {
        color1(6);
        cout << endl
             << endl
             << "  Total bill is:" << user_total_bill << endl;
        color1(7);
    }
}

void add_feedback()
{
    color1(2);
    cout << "  Feedback Menu" << endl;
    color1(7);
    color1(9);
    cout << "--------------------->>>" << endl
         << endl;
    color1(7);
    string user_name;
    cout << "Enter Name:";
    cin.clear();
    cin.sync();
    getline(cin, user_name);
    bool present = validate_feedback_user_name(user_name);
    if (present == true)
    {
        cout << "Enter feedback:";
        cin.clear();
        cin.sync();
        getline(cin, user_feedback[count_feedback]);
        count_feedback++;
        color1(6);
        cout << "Thanks For Your Feedback:" << endl;
        color1(7);
    }
    else
    {
        color1(4);
        cout << "please enter valid name:" << endl;
        color1(7);
    }
    press();
}
bool validate_feedback_user_name(string user_name)
{
    bool present = false;
    for (int indx = 0; indx < count_user; indx++)
    {
        if (user_name == userName[indx])
        {
            FeedbackName[count_feedback] = user_name;
            present = true;
        }
    }
    return present;
}
void view_feedback()
{
    color1(13);
    cout << " Feedback Menu" << endl;
    color1(7);
    color1(9);
    cout << "-------------------->>>" << endl
         << endl;
    color1(7);
    if (count_feedback != 0)
    {
        color1(2);
        cout << "Id NO\t\tUserName\t\tFeedBack" << endl;
        color1(7);
        for (int i = 0; i < count_feedback; i++)
        {
            cout << " " << i + 1 << "\t\t" << FeedbackName[i]
                 << "\t\t\t" << user_feedback[i] << endl;
        }
    }
    else
    {
        color1(6);
        cout << "No one has add any feedback:";
        color1(7);
    }
    press();
}
void store_feedback()
{
    fstream file;
    file.open("feedback.txt", ios::out);
    for (int i = 0; i < count_feedback; i++)
    {
        file << FeedbackName[i] << ch << user_feedback[i] << endl;
    }
    file.close();
}
void read_feedback()
{
    string record;
    fstream file;
    file.open("feedback.txt", ios ::in);
    while (getline(file, record))
    {
        if (record == "0")
        {
            continue;
        }

        FeedbackName[count_feedback] = getField(record, 1);
        user_feedback[count_feedback] = getField(record, 2);
        count_feedback++;
    }
    file.close();
}
void view_users()
{

    color1(2);
    cout << "  Users" << endl;
    color1(7);
    color1(9);
    cout << "-------------------->>>" << endl
         << endl;
    color1(7);
    color1(2);
    cout << "Id NO\t\tUserName\t\tPassword " << endl;
    color1(7);
    for (int indx = 0; indx < count_user; indx++)
    {
        cout << " " << indx + 1 << "\t\t" << userName[indx] << "\t\t\t" << userPassword[indx] << endl;
    }
    press();
}

void view_admins()
{
    color1(2);
    cout << "  Admins" << endl;
    color1(7);
    color1(9);
    cout << "-------------------->>>" << endl
         << endl;
    color1(7);
    color1(2);
    cout << "Id NO\t\tAdminName" << endl;
    color1(7);
    for (int indx = 0; indx < count_admin; indx++)
    {
        cout << " " << indx + 1 << "\t\t " << adminName[indx] << endl;
    }
    press();
}
void display_admins()
{
    color1(2);
    cout << "  Admins" << endl;
    color1(7);
    color1(9);
    cout << "-------------------->>>" << endl
         << endl;
    color1(7);
    color1(2);
    cout << "Id NO\t\tUserName\t\tPassword " << endl;
    color1(7);
    for (int indx = 0; indx < count_admin; indx++)
    {
        cout << " " << indx + 1 << "\t\t" << adminName[indx] << "\t\t\t" << adminPassword[indx] << endl;
    }
    press();
}
void help()
{
    color1(2);
    cout << "  Help Menu" << endl;
    color1(7);
    color1(9);
    cout << "-------------------->>>" << endl
         << endl;
    cout << "\n";
    color1(8);
    cout << "  * Please Follow the instructions given on each page:" << endl;
    cout << "  * Try to Use Lowercase letters:" << endl;
    cout << "  * Do not Add spaces in items name:" << endl;
    cout << "  * Thanks For using this Application:" << endl
         << endl;
    color1(7);
    color1(4);
    cout << "  --->IF you need any other help kindly contact us:" << endl
         << endl;
    color1(7);
    color1(6);
    cout << "   Name              M.Awais Ashraf  " << endl;
    cout << "   Gmail             mhawais431@gmail.com" << endl;
    cout << "   Contact Number    03154193750" << endl;
    color1(7);
    press();
}
void press()
{
    cout << "\n";
    color1(11);
    cout << "Press any key to continue:";
    getch();
    color1(7);
}
void gotoxy(float x, float y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void color1(int color1)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
}
