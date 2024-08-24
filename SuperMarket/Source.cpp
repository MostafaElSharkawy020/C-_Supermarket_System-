#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<cmath>
#include<iomanip>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;
const int arr_size = 100; //--> Array for size of Categories.

int arr_for[6] = { 10,10,10,10,10,10 };  //--> Array for size of Products.

int numOFuser;            //--> Number of user in project (index).

string entername, enterpassword, enterphone; bool enter = false; //--> This Variables to login and forget password functions.
bool modifycheck = true;

fstream user; //--> Object of file. 
fstream orders;

// Struct for Product
struct Product {
    string Code;
    string Name;
    int Quantity;
    float Price;
    string Proddate;
    string Expiredate;

}Fruits_Vegtables[arr_size], Meat[arr_size], Poultry[arr_size], Canned_Food[arr_size], Food_Legumes[arr_size], Drinks[arr_size];//--> Categories.

//Struct for Costomer
struct user
{
    int id;
    string name;
    string phone;
    string location;
    string password;
}u, u1[100];

//Struct for Order
struct order
{
    int id;
    string code[100];
    string list[100];
    double quantity[100];
    double price[100];
    string Proddate[100];
    string Expiredate[100];
    double totalprice;
    double Total;
}order, orders_a[100];

int z = 0;                       //--> counter for order.

string choicex, choicey, code;   //--> product code that the user choose.

bool Egyptian_PhoneNumber(const string& phoneNumber); //--> Check the phonenumber is Egyptian PhoneNumber.

void login();            //--> Log in.

void sign();             //--> Sign up.

void forget_password();  //--> forget the password.

void profile();          //--> View profile of user.

void edit();             //--> Editing information of user.

void admin();            //--> Main menu of adminstrator.

void admin_add();        //--> Adding the products to categories by administrator.

void admin_remove();     //-->Removing products from categories by adminstrator.

void admin_change_q();   //--> Changing the quantity of the product by administrator.

void admin_price();      //-->Changing the price of a product by adminstrator.

void admin_date();       //-->Changing production and expiry date by adminstrator.

void menu();             //--> Menu Main.

void Buyer();            //--> Choosing Category and display Menu of the products in this Category.

void buy(string choice); //--> Buying the products.

void view();             //--> Displing order.

void choose();           //--> Choosing any products in order to modify it.

void remove();           //--> Removing any products in order.

void totalprice();       //--> Calculating total price for order.

void change();           //--> Changing the quantity of the products in order.

void logout();           //--> Log out.

void discount();         //--> Discount for orders above 2000.  

void gift();             //--> Gifts for orders above 6000.

void view_orders();      //--> View all orders that have been sold.

void credit();           //--> Credits  about who make project.

int main()
{
    srand(time(0));
    // Category Name:  /   Code:  / Name: / Quantity:/ Price:/ Pdate: /   Exdate:

  //Fruits_Vegtables Category :
    Fruits_Vegtables[0] = { "1" , "Pepper__" , 70 , 10.00 , "05/4/2023" , "05/5/2023" };
    Fruits_Vegtables[1] = { "2" , "Tomatoes" , 15 , 4.00  , "20/4/2023" , "27/4/2023" };
    Fruits_Vegtables[2] = { "3" , "Potatoes" , 40 , 3.50  , "25/4/2023" , "25/7/2023" };
    Fruits_Vegtables[3] = { "4" , "Onion___" , 50 , 9.00  , "15/4/2023" , "15/3/2024" };
    Fruits_Vegtables[4] = { "5" , "Cucumber" , 30 , 15.00 , "05/4/2023" , "11/4/2023" };
    Fruits_Vegtables[5] = { "6" , "Apples__" , 35 , 11.00 , "12/4/2023" , "12/6/2023" };
    Fruits_Vegtables[6] = { "7" , "Oranges_" , 45 , 12.50 , "18/4/2023" , "21/5/2023" };
    Fruits_Vegtables[7] = { "8" , "Guava___" , 15 , 6.00  , "01/4/2023" , "07/4/2023" };
    Fruits_Vegtables[8] = { "9" , "Bananes_" , 65 , 13.00 , "01/4/2023" , "03/4/2023" };
    Fruits_Vegtables[9] = { "10", "Grapes__" , 15 , 30.00 , "01/4/2023" , "07/4/2023" };
    //Meat Category :
    Meat[0] = { "11" ,"Veal____" , 70 , 95.00  , "25/4/2023" , "25/4/2024" };
    Meat[1] = { "12" ,"Lamb____" , 15 , 285.00 , "14/4/2023" , "10/4/2024" };
    Meat[2] = { "13" ,"Camel___" , 40 , 220.00 , "08/4/2023" , "06/4/2024" };
    Meat[3] = { "14" ,"Sausage_" , 50 , 170.00 , "01/3/2023" , "01/5/2024" };
    Meat[4] = { "15" ,"Pastirma" , 30 , 97.49  , "07/4/2023" , "14/4/2023" };
    Meat[5] = { "16" ,"Pepperon" , 35 , 229.95 , "25/3/2023" , "25/9/2024" };
    Meat[6] = { "17" ,"Hotdog__" , 45 , 85.95  , "04/4/2023" , "04/6/2023" };
    Meat[7] = { "18" ,"Luncheon" , 15 , 53.95  , "01/4/2023" , "15/4/2023" };
    Meat[8] = { "19" ,"Salami__" , 65 , 195.00 , "30/4/2023" , "30/3/2024" };
    Meat[9] = { "20" ,"Beefy___" , 30 , 50.00  , "28/4/2023" , "27/7/2023" };
    //Poultry Category :
    Poultry[0] = { "21" ,"Chickens__" , 70 , 100.00 , "28/3/2023" , "28/6/2023" };
    Poultry[1] = { "22" ,"C.Breasts_" , 15 , 50.00  , "19/4/2023" , "19/6/2023" };
    Poultry[2] = { "23" ,"Hips______" , 40 , 63.50  , "10/4/2023" , "10/6/2023" };
    Poultry[3] = { "24" ,"Livers____" , 45 , 45.00  , "11/4/2023" , "11/6/2023" };
    Poultry[4] = { "25" ,"Wings_____" , 80 , 48.50  , "01/3/2023" , "28/6/2023" };
    Poultry[5] = { "26" ,"drumsticks" , 98 , 55.00  , "17/4/2023" , "17/6/2023" };
    Poultry[6] = { "27" ,"Turkey____" , 13 , 1799.50, "06/4/2023" , "05/6/2023" };
    Poultry[7] = { "28" ,"Thighs____" , 20 , 80.00  , "14/4/2023" , "30/4/2023" };
    Poultry[8] = { "29" ,"Pigeons___" , 40 , 75.00  , "03/4/2023" , "03/5/2023" };
    Poultry[9] = { "30" ,"Quail_____" , 90 , 30.00  , "25/4/2023" , "28/6/2023" };
    //Canned Food Category :
    Canned_Food[0] = { "31" ,"Tuna_____" , 100 , 18.75 , "01/4/2023" , "01/7/2023" };
    Canned_Food[1] = { "32" ,"Indomie__" , 110 , 6.35  , "10/3/2023" , "25/9/2023" };
    Canned_Food[2] = { "33" ,"Bean_____" , 60  , 13.70 , "19/3/2023" , "19/9/2024" };
    Canned_Food[3] = { "34" ,"Cheese___" , 100 , 18.70 , "13/4/2023" , "13/8/2023" };
    Canned_Food[4] = { "35" ,"Pickle___" , 50  , 17.00 , "17/2/2023" , "17/8/2024" };
    Canned_Food[5] = { "36" ,"Ketchup__" , 150 , 15.80 , "18/3/2023" , "18/9/2023" };
    Canned_Food[6] = { "37" ,"mayonaise" , 70  , 31.85 , "02/4/2023" , "02/6/2023" };
    Canned_Food[7] = { "38" ,"Bee_Honey" , 40  , 119.95, "05/4/2023" , "Unexpired" };
    Canned_Food[8] = { "39" ,"Vanilla__" , 30  , 68.95 , "09/4/2023" , "Unexpired" };
    Canned_Food[9] = { "40" ,"Jelly____" , 30  , 26.95 , "08/4/2023" , "08/4/2025" };
    //Food and Legumes Category:
    Food_Legumes[0] = { "41" ,"Ghee&Oil" , 50  , 54.85 , "10/4/2023" , "10/4/2028" };
    Food_Legumes[1] = { "42" ,"Sugar___" , 60  , 28.00 , "20/4/2023" , "20/4/2024" };
    Food_Legumes[2] = { "43" ,"Flour___" , 80  , 28.15 , "30/4/2023" , "30/4/2024" };
    Food_Legumes[3] = { "44" ,"Butter__" , 90  , 200.00, "25/4/2023" , "25/7/2023" };
    Food_Legumes[4] = { "45" ,"Rice____" , 100 , 23.62 , "14/4/2023" , "14/4/2025" };
    Food_Legumes[5] = { "46" ,"Lentils_" , 70  , 40.50 , "15/4/2023" , "15/4/2024" };
    Food_Legumes[6] = { "47" ,"Hummus__" , 40  , 52.95 , "17/4/2023" , "17/4/2024" };
    Food_Legumes[7] = { "48" ,"Thermos_" , 75  , 36.95 , "18/4/2023" , "18/5/2023" };
    Food_Legumes[8] = { "49" ,"Macaroni" , 65  , 24.60 , "19/4/2023" , "19/4/2025" };
    Food_Legumes[9] = { "50" ,"Bean____" , 45  , 43.95 , "21/4/2023" , "Unexpired" };
    //Drinks Category:
    Drinks[0] = { "51" ,"Coffee___" , 100 , 100.00 , "09/4/2023" , "09/4/2025" };
    Drinks[1] = { "52" ,"Tea______" , 90  , 37.50  , "20/4/2023" , "20/4/2024" };
    Drinks[2] = { "53" ,"Cocoa____" , 80  , 33.55  , "24/4/2023" , "24/4/2027" };
    Drinks[3] = { "54" ,"Coffeemix" , 90  , 40.60  , "21/3/2023" , "21/9/2024" };
    Drinks[4] = { "55" ,"Anise____" , 80  , 20.25  , "19/4/2023" , "19/4/2024" };
    Drinks[5] = { "56" ,"Mint_____" , 70  , 14.95  , "07/4/2023" , "07/4/2024" };
    Drinks[6] = { "57" ,"Hibiscus_" , 60  , 41.25  , "10/4/2023" , "10/4/2024" };
    Drinks[7] = { "58" ,"Fenugreek" , 85  , 50.00  , "11/4/2023" , "11/4/2024" };
    Drinks[8] = { "59" ,"Pepsi(1L)" , 97  , 11.75  , "13/4/2023" , "13/2/2024" };
    Drinks[9] = { "60" ,"Water(1L)" , 92  , 5.50   , "18/4/2023" , "18/4/2025" };

    menu();

    system("pause");
}

bool Egyptian_PhoneNumber(const string& phoneNumber) //--> Check the phonenumber is Egyptian PhoneNumber.  
{
    if (phoneNumber.length() != 11) {
        return false;
    }
    if (phoneNumber[0] != '0' || phoneNumber[1] != '1') {
        return false;
    }
    for (int i = 0; i < 11; i++) {
        if (!isdigit(phoneNumber[i])) {
            return false;
        }
    }
    return true;
}
void login()  //--> Log in.
{
    bool test = false;     //check 
    user.open("log.txt", ios::in);
    for (int i = 0; i < 100; i++)
    {
        user >> u1[i].id >> u1[i].name >> u1[i].phone >> u1[i].location >> u1[i].password;
    }
    user.close();
Y:
    cout << "\n\033[36mEnter Name:\033[0m \n";
    cin >> entername;             //name to compare.
    cin.ignore();
    cout << "\n\033[36mEnter Password:\033[0m\n\t\t\t\t\t\t\t\t\t\t   \033[4m\033[36m-> I forget your password ? Press [y]\033[0m\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t\t\t   \033[4m\033[36m-> Create a new account   : Press [c]\033[0m\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t\t\t   \033[4m\033[31m-> Exit from this page    : Press [e]\033[0m\033[0m\n";
    cin >> enterpassword;
    cin.ignore();
    if (enterpassword == "y" || enterpassword == "Y")
        forget_password();
    else if (enterpassword == "c" || enterpassword == "C") {
        sign();
        login();
    }
    else if (enterpassword == "e" || enterpassword == "E")
    {
        menu();
    }
    else
    {
        for (int i = 0; i < 100; i++)
        {
            if (u1[i].name == "")
                break;
            if (u1[i].name == entername && u1[i].password == enterpassword)        //check name and password in the array.
            {
                test = true;
                numOFuser = i;          // index of user.       
            }
        }
        if (test == true)
        {
            cout << "\n\t\t      \033[32m(: Login successfully :)\033[0m\n";
        }
        else
        {
            cout << "\n\033[31mInvalid username or password :(\033[0m\n\n";
            goto Y;
        }
    }
}
void sign()   //--> Sign up.
{
    user.open("log.txt", ios::app | ios::out);
    cout << "\n\033[36mEnter Name:\033[0m \n";
    cin >> u.name;                   //name 
    cin.ignore();
    cout << "\n\033[36mCreate a password:\033[0m \n";
    cin >> u.password;                   // password
    cin.ignore();
    do {
        cout << "\n\033[36mEnter your phone number:\n" << "+20|\033[0m\t";
        cin >> u.phone;
        cin.ignore();
        if (!Egyptian_PhoneNumber(u.phone)) {                   //check egyptian number.
            cout << "\033[31m\nInvalid phone number:)\033[0m \n\n";
            cout << "\033[36mPlease enter a valid Egyptian phone number\033[0m\n";
        }
    } while (!Egyptian_PhoneNumber(u.phone));
    cout << "\n\033[36mLocation:\033[0m \n";
    cin >> u.location;                    //location
    cin.ignore();
    u.id = 600000 + rand() % 9000;
    user << u.id << "\t" << u.name << "\t" << u.phone << "\t" << u.location << "\t" << u.password << "\t" << endl;
    user.close();
    cout << "\n  \033[32m(:.....your account has been created successfully.....:)\033[0m\n\n";
    cout << "\033[36m              Now please log in to strart :)\033[0m \n\n";
}
void profile()  //--> View profile of user.
{
    string choice1, choice2;
    cout << "|---------------------------------------------------------|            \n";
    cout << "|            (:       Your  Profile        :)             |            \n";
    cout << "|_________________________________________________________|            \n";
    cout << "|   Name:        |   " << u1[numOFuser].name << "\t\t\t\t  |           \n";
    cout << "|                |                                        |            \n";
    cout << "|   ID:          |   " << u1[numOFuser].id << "\t\t\t\t  |             \n";
    cout << "|                |                                        |            \n";
    cout << "|   Password:    |   " << u1[numOFuser].password << "\t\t\t\t  |       \n";
    cout << "|                |                                        |            \n";
    cout << "|   Phone number:|   " << "+20| " << u1[numOFuser].phone << "\t\t\t  | \n";
    cout << "|                |                                        |            \n";
    cout << "|   Location:    |   " << u1[numOFuser].location << "\t\t\t\t  |       \n";
    cout << "|                |                                        |            \n";
    cout << "|________________|________________________________________|          \n\n";
x:
    cout << "\n";
    cout << "\033[36m 1)\033[4m Edit Profile\033[0m\033[0m \n\n";
    cout << "\033[31m 2)\033[4m Back\033[0m\n\n";
    cout << "\033[36mEnter choice: \033[0m";
    cin >> choice1;
    cin.ignore();
    if (choice1 == "1")
    {
        edit();
    }
    else if (choice1 == "2")
    {
    l:
        cout << "\n";
        cout << "\033[33m -------------------------------------------------------------------------\033[0m \n\n";
        cout << "\033[36m 1)\033[4m View Profile\033[0m\033[0m     \n\n";
        cout << "\033[33m 2)\033[4m Supermarket Menu\033[0m\033[0m \n\n";
        cout << "\033[31m 3)\033[4m Exit\033[0m\033[0m\n\n";
        cout << "\033[36mEnter choice: \033[0m";
        cin >> choice2;
        cin.ignore();
        if (choice2 == "1")
        {
            cout << "\n";
            profile();
        }
        else if (choice2 == "2")
        {
            Buyer();
        }
        else if (choice2 == "3")
        {
            logout();
        }
        else
        {
            cout << "\033[31m\nInvalid Value! :(\033[0m\n";
            cout << "\033[36mRe-enter your choice\033[0m\n\n";
            goto l;
        }
    }
    else
    {
        cout << "\033[31m\nInvalid Value! :(\033[0m\n";
        cout << "\033[36mRe-enter your choice\033[0m\n\n";
        goto x;
    }
    cout << "\033[33m -----------------------------------------------------------------------------\033[0m \n\n";
}
void edit()   //--> Editing information of user.
{
    string confirm_password, choice, choice2;
v:
    cout << "\n\033[36m\033[4m Which data you want to edit ?\033[0m\033[0m \n\n";
    cout << " 1)\033[4m Name\033[0m         \n\n";
    cout << " 2)\033[4m Password\033[0m     \n\n";
    cout << " 3)\033[4m Phone number\033[0m \n\n";
    cout << " 4)\033[4m Location\033[0m     \n\n";
    cout << "\033[31m 5)\033[4m Back\033[0m\033[0m         \n\n";
    cout << "\033[36mEnter choice:\033[0m";
    cin >> choice;
    cin.ignore();
    if (choice == "1") {
        cout << "\n\033[36mEnter New Name:\033[0m   ";
        cin >> u1[numOFuser].name;
        cin.ignore();
    }
    else if (choice == "2") {
    r:
        cout << "\n\033[36mEnter New Password:\033[0m   ";
        cin >> u1[numOFuser].password;
        cin.ignore();
        cout << "\n\033[36mEnter password again to confirm:\033[0m   ";
        cin >> confirm_password;
        cin.ignore();
        if (u1[numOFuser].password != confirm_password) {  //--> Condition to check password.
            cout << "\033[31mPasswords do not match :(\033[0m\n";
            goto r;
        }
        else
        {
            cout << "\033[32mPassword changed successfully :)\033[0m \n\n";
        }
    }
    else if (choice == "3") {
        do {
            cout << "\n\033[33mEnter New Phone number:\n" << "+20|\033[0m\t";
            cin >> u1[numOFuser].phone;
            cin.ignore();
            if (!Egyptian_PhoneNumber(u1[numOFuser].phone)) {
                cout << "\033[31mInvalid phone number:)\033[0m\n";
                cout << "\033[36mPlease enter a valid Egyptian phone number\033[0m\n";
            }
        } while (!Egyptian_PhoneNumber(u1[numOFuser].phone));
    }
    else if (choice == "4") {
        cout << "\n\033[36mEnter New Location:\033[0m\n ";
        cin >> u1[numOFuser].location;
    }
    else if (choice == "5")
    {
        cout << "\n\033[33m -----------------------------------------------------------------------\033[0m \n\n";
        profile();
    }
    else
    {
        cout << "\033[31m\nInvalid Value! :(\033[0m\n";
        cout << "\033[36mRe-enter your choice\033[0m\n\n";
        goto v;
    }
S:
    cout << "\n\033[36mDo you want to edit another information ? \033[0m (\033[32mY\033[0m/\033[31mN\033[0m) \n";
    string choice1;
    cin >> choice1;
    cin.ignore();
    if (choice1 == "y" || choice1 == "Y" || choice1 == "Yes" || choice1 == "yes" || choice1 == "YES")
        goto v;
    else if (choice1 == "N" || choice1 == "n" || choice1 == "No" || choice1 == "no" || choice1 == "NO")
    {
        cout << "                       \033[33m     Thank you\033[0m\n";
        cout << "\033[33m -----------------------------------------------------------------------\033[0m \n";
        remove("log.txt");
        user.open("log.txt", ios::app | ios::out);
        for (int i = 0; i < 100; i++)
        {
            if (u1[i].name == "")
                break;
            user << u1[i].id << "\t" << u1[i].name << "\t" << u1[i].phone << "\t" << u1[i].location << "\t" << u1[i].password << "\t" << endl;
        }
        user.close();
    m:
        cout << "\n";
        cout << "\033[36m 1)\033[4m View Profile\033[0m\033[0m     \n\n";
        cout << "\033[33m 2)\033[4m Supermarket Menu\033[0m\033[0m \n\n";
        cout << "\033[31m 3)\033[4m Exit\033[0m\033[0m\n\n";
        cout << "\033[36mEnter choice: \033[0m";
        cin >> choice2;
        cin.ignore();
        if (choice2 == "1")
        {
            cout << "\n";
            profile();
        }
        else if (choice2 == "2")
        {
            cout << "\n";
            Buyer();
        }
        else if (choice2 == "3")
        {
            cout << "\n";
            logout();
        }
        else
        {
            cout << "\n\033[31mInvalid Value!!\033[0m\n";
            cout << "\033[36mRe-enter your choice\033[0m\n\n";
            goto m;
        }
    }
    else
    {
        cout << "\n\033[31mInvalid Value!!\033[0m\n";
        cout << "\033[36mRe-enter your choice\033[0m\n\n";
        goto S;
    }
}
void forget_password()
{
    bool test3 = false;
    user.open("log.txt", ios::in);
    for (int i = 0; i < 100; i++)
    {
        user >> u1[i].id >> u1[i].name >> u1[i].phone >> u1[i].location >> u1[i].password;
    }
    user.close();
j:
    cout << "\033[36mPlease enter your name:\033[0m\n";
    cin >> entername;
    cin.ignore();
    for (int i = 0; i < 100; i++)
    {
        if (u1[i].name == "")
            break;
        if (u1[i].name == entername) {       //--> find user name
            numOFuser = i;                   //--> numbeer of the user in project
            test3 = true;
        }
    }
    if (test3 == false) {


        cout << "\n\033[31mUser name not found\033[0m\n";
        goto j;
    }
f:
    cout << "\n\033[36mEnter your Phone number:\n" << "+20|\033[0m\t";
    do {
        cin >> enterphone;
        cin.ignore();
        if (!Egyptian_PhoneNumber(enterphone)) {     //--> check egyptian phone number
            cout << "\033[31mInvalid phone number:)\033[0m\n";
            cout << "\033[36mPlease enter a valid Egyptian phone number\033[0m\n";
        }
    } while (!Egyptian_PhoneNumber(enterphone));

    for (int i = 0; i < 100; i++) {
        if (u1[numOFuser].phone != enterphone) //--> to check phone number of the user exist in array of users or not
        {
            cout << "\033[31mThis phone number is not found\033[0m\n\n";
            goto f;
        }
    }
x:
    int code = 5600 + rand() % 99;
    cout << "               _________________\n";
    cout << " \033[33m              |\t" << code << "\t|\n";                //variation code
    cout << "               |_________________\n\n\n\033[0m";
z:
    string confirm_password;
    int x;
    cout << "\033[36mPlease Enter the code shown in front of you\033[0m\n";
    cin >> x;
    if (code == x)
    {
    r:
        cout << "\033[36mEnter the New Password:\033[0m\t";
        cin >> u1[numOFuser].password;
        cout << "\033[36mEnter the Password again to confirm:\033[0m\t";
        cin >> confirm_password;
        if (u1[numOFuser].password != confirm_password)        //condition to check password
        {
            cout << "\033[31m**Password not matched**\033[0m\n";
            goto r;
        }
        remove("log.txt");
        user.open("log.txt", ios::app | ios::out);
        for (int i = 0; i < 100; i++)
        {
            if (u1[i].name == "")
                break;
            user << u1[i].id << "\t" << u1[i].name << "\t" << u1[i].phone << "\t" << u1[i].location << "\t" << u1[i].password << "\t" << endl;
        }
        user.close();
        cout << "\033[32mThe new password has been saved\033[0m\n\n";
        cout << "\033[36mNow please log in\033[0m\n\n";
        login();
    }
    else
        goto z;

}

void menu()   //--> Menu Main.
{
    string choice1, choice2, choice3, choice4, choice5, Email, pass;
    cout << "\t\t\t\t\t\t\t\t    (: Welcome to Supermarket :)   \n";
    cout << "\t\t\t\t\t\t\t\t                                    \n";
    cout << "\t\t\t\t\t\t\t\t**************************************\n\n";
    cout << "\t\t\t\t\t\t\t\t______________________________________\n";
    cout << "\t\t\t\t\t\t\t\t|                                    |\n";
    cout << "\t\t\t\t\t\t\t\t|        Supermarket Main Menu       |\n";
    cout << "\t\t\t\t\t\t\t\t|____________________________________|\n";
    cout << "\t\t\t\t\t\t\t\t|                                    |\n";
    cout << "\t\t\t\t\t\t\t\t|            \033[33m 1)\033[4m Admin\033[0m \033[0m              |\n";
    cout << "\t\t\t\t\t\t\t\t|                                    |\n";
    cout << "\t\t\t\t\t\t\t\t|            \033[36m 2)\033[4m Buyer\033[0m \033[0m              |\n";
    cout << "\t\t\t\t\t\t\t\t|                                    |\n\n";
    cout << "\n\t\t\t\t\t\t\t \033[36m Please select:) :\033[0m  ";
    cin >> choice1;
    cin.ignore();
    if (choice1 == "1")
    {
    W:
        cout << "\033[36m 1)\033[4m Log in\033[0m\033[0m    \n\n";
        cout << "\033[31m 2)\033[4m Back \033[0m\033[0m     \n\n";
        cout << "\033[36mEnter choice: \033[0m";
        cin >> choice4;
        cin.ignore();
        if (choice4 == "1") {
        E:
            cout << "\n\033[36mEnter Email:\033[0m\n";
            cin >> Email;
            cin.ignore();
            cout << "\n\033[36mEnter Password:\033[0m ";
            cout << "\t\t\t\t\t\t\t\t\t\t   \033[4m\033[31m-> Exit: Press [e]\033[0m\033[0m\n";
            cin >> pass;
            cin.ignore();
            if (Email == "mostafa" && pass == "111")
            {
                cout << "\n\t\t      \033[32m(: Login successfully :)\033[0m\n";
                cout << "\033[33m ---------------------------------------------------------------------------\033[0m \n\n";
                admin();
            }
            else if (pass == "e" || pass == "E")
            {
                menu();
            }
            else
            {
                cout << "\n\033[31mInvalid Email or Password! :(\033[0m\n";
                goto E;
            }
        }
        else if (choice4 == "2")
        {
            menu();
        }
        else
        {
            cout << "\n\033[31mInvalid Value!!\033[0m\n";
            cout << "\033[36mRe-enter your choice\033[0m\n\n";
            goto W;
        }

    }
    else if (choice1 == "2")
    {
    x:
        cout << "\n\n";
        cout << "\033[36m 1)\033[4m Log in\033[0m\033[0m  \n\n";
        cout << "\033[33m 2)\033[4m Sign up\033[0m \n\n\033[0m";
        cout << "\033[31m 3)\033[4m Exit\033[0m\033[0m    \n\n";
        cout << "\033[36mEnter choice: \033[0m";
        cin >> choice2;
        cin.ignore();
        if (choice2 == "1")
        {

            login();
        }
        else if (choice2 == "2")
        {
            sign();
            login();
        }
        else if (choice2 == "3")
        {
        U:
            cout << "\n\033[33m ---------------------------------------------------------------------------\033[0m \n\n";
            cout << "\033[31m1)\033[4m Exit this window\033[0m\033[0m\n\n";
            cout << "\033[33m2)\033[4m Homepage\033[0m\033[0m        \n\n";
            cout << "\033[36m3)\033[4m Credits\033[0m\033[0m \n\n";
            cout << "\033[36mEnter choice: \033[0m";
            cin >> choice5;
            if (choice5 == "1")
            {
                cout << "\n\033[36mPress -->\033[4m Enter\033[0m\033[0m\n";
                exit(0);
            }
            else if (choice5 == "2")
            {
                cout << "\n\t\t\t\t\033[36m  ----------------------------------------------------------------------------------------\033[0m\n\n\n";
                menu();
            }
            else if (choice5 == "3")
            {
                cout << "\n\t\t\t\t\033[36m  ----------------------------------------------------------------------------------------\033[0m\n\n\n";
                credit();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto U;
            }
        }
        else
        {
            cout << "\n\033[31mInvalid Value!!\033[0m\n";
            cout << "\033[36mRe-enter your choice\033[0m\n\n";
            goto x;
        }
        cout << "\033[33m ---------------------------------------------------------------------------\033[0m \n\n";
    p:
        cout << "\n";
        cout << "\033[36m 1)\033[4m View Profile\033[0m\033[0m    \n\n";
        cout << "\033[33m 2)\033[4m Supermarket Menu\033[0m\033[0m\n\n";
        cout << "\033[31m 3)\033[4m Back\033[0m \033[0m           \n\n";
        cout << "\033[36mEnter choice: \033[0m";
        cin >> choice3;
        cin.ignore();
        if (choice3 == "1")
        {
            cout << "\n";
            profile();
        }
        else if (choice3 == "2")
        {
            Buyer();
        }
        else if (choice3 == "3")
        {
            cout << "\033[33m -------------------------------------------------------------------------\033[0m \n";
            goto x;
        }
        else
        {
            cout << "\n\033[31mInvalid Value!!\033[0m\n";
            cout << "\033[36mRe-enter your choice\033[0m\n\n";
            goto p;
        }
    }
    else
    {
        cout << "\n\033[31mInvalid Value!!\033[0m\n";
        cout << "\033[36mRe-enter your choice\033[0m\n\n";
    }
    menu();
}
void admin()     //--> Main menu of adminstrator.
{
    string choice, choice1, choice2;
    orders.open("log2.txt", ios::in);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
            orders >> orders_a[i].code[j] >> orders_a[i].list[j] >> orders_a[i].price[j] >> orders_a[i].quantity[j] >> orders_a[i].Proddate[j] >> orders_a[i].Expiredate[j];

    }
    orders.close();

    cout << "\n1)\033[4m View the products that have been sold\033[0m\n\n";
    cout << "2)\033[4m Adding products\033[0m\n\n";
    cout << "3)\033[4m Removing products\033[0m\n\n";
    cout << "4)\033[4m Changing quantities of products\033[0m\n\n";
    cout << "5)\033[4m Changing prices of products\033[0m\n\n";
    cout << "6)\033[4m Changing production and expiry date\033[0m\n\n";
    cout << "\033[31m7)\033[4m Exit\033[0m\n\n\033[0m";
    cout << "\033[36mEnter choice: \033[0m";
    cin >> choice;
    cin.ignore();
    if (choice == "1")
    {
        cout << "\n\033[33m ---------------------------------------------------------------------------\033[0m \n\n";
        view_orders();
    }
    else if (choice == "2")
    {
        cout << "\n\033[33m ---------------------------------------------------------------------------\033[0m \n\n";
        admin_add();
    }
    else if (choice == "3")
    {
        cout << "\n\033[33m ---------------------------------------------------------------------------\033[0m \n\n";
        admin_remove();
    }
    else if (choice == "4")
    {
        cout << "\n\033[33m ---------------------------------------------------------------------------\033[0m \n\n";
        admin_change_q();
    }

    else if (choice == "5")
    {
        cout << "\n\033[33m ---------------------------------------------------------------------------\033[0m \n\n";
        admin_price();
    }

    else if (choice == "6")
    {
        cout << "\n\033[33m ---------------------------------------------------------------------------\033[0m \n\n";
        admin_date();
    }

    else if (choice == "7")
    {
        cout << "\n\033[33m ---------------------------------------------------------------------------\033[0m \n\n";
    U2:
        cout << "\033[31m1)\033[4m Exit this window\033[0m\033[0m\n\n";
        cout << "\033[33m2)\033[4m Homepage\033[0m\033[0m        \n\n";
        cout << "\033[36m3)\033[4m Credits\033[0m\033[0m \n\n";
        cout << "\033[36mEnter choice: \033[0m";
        cin >> choice1;
        if (choice1 == "1")
        {
            cout << "\n\033[36mPress -->\033[4m Enter\033[0m\033[0m\n";
            exit(0);
        }
        else if (choice1 == "2")
        {
            cout << "\n\t\t\t\t\033[36m  ----------------------------------------------------------------------------------------\033[0m\n\n\n";
            menu();
        }
        else if (choice1 == "3")
        {
            cout << "\n\t\t\t\t\033[36m  ----------------------------------------------------------------------------------------\033[0m\n\n\n";
            credit();
        }
        else
        {
            cout << "\n\033[31mInvalid Value!!\033[0m\n";
            cout << "\033[36mRe-enter your choice\033[0m\n\n";
            goto U2;
        }
    }
    else
    {
        cout << "\n\033[31mInvalid Value!!\033[0m\n";
        cout << "\033[36mRe-enter your choice\033[0m\n\n";
        admin();
    }
}
void admin_add()     //--> Adding the products to categories by administrator.
{
    string choice, check = "0";;

    cout << "\t\t\t\t\t\t\t________________________________________________\n";
    cout << "\t\t\t\t\t\t\t|        Categories of the Supermarket         |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t\t\t\t|          1) Fruits and Vegtables             |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          2) Meat [fresh,processed]           |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          3) Poultry                          |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          4) Canned Food                      |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          5) Food and Legumes                 |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          6) Drinks                           |\n";
    cout << "\t\t\t\t\t\t\t|______________________________________________|\n\n";
    cout << "\033[33m--> Choose the category to add to it :)\033[0m\n\n";
    cout << "\033[36mEnter choice: \033[0m";
    cin >> choice;
    cin.ignore();
    if (choice == "1")
    {
        while (arr_for[0] < arr_size)
        {
            cout << "Enter Code of product [" << arr_for[0] + 1 << "]\n";
            cin >> Fruits_Vegtables[arr_for[0]].Code;
            cin.ignore();
            cout << "Enter Name of product [" << arr_for[0] + 1 << "]\n";
            getline(cin, Fruits_Vegtables[arr_for[0]].Name);
            cout << "Enter Price of product [" << arr_for[0] + 1 << "]\n";
            cin >> Fruits_Vegtables[arr_for[0]].Price;
            cout << "Enter Quantity of product [" << arr_for[0] + 1 << "]\n";
            cin >> Fruits_Vegtables[arr_for[0]].Quantity;
            cout << "Enter Production Date of product [" << arr_for[0] + 1 << "]   like 00/00/2000\n";
            cin >> Fruits_Vegtables[arr_for[0]].Proddate;
            cout << "Enter Expiry date of product [" << arr_for[0] + 1 << "]   like 00/00/2000\n";
            cin >> Fruits_Vegtables[arr_for[0]].Expiredate;
            arr_for[0]++;
            cout << "\n";
            cout << " 1)\033[4m Adding another new product \033[0m\n\n";
            cout << " 2)\033[4m Adding new product in different category\033[0m    \n\n";
            cout << "\033[31m3)\033[4m Exit\033[0m\n\n\033[0m\n\n";
            cout << "\033[36mEnter choice: \033[0m";
            cin >> check;
            if (check == "2")
                admin_add();
            else if (check == "3")
                menu();
            else
                continue;
        }
    }
    else if (choice == "2")
    {
        while (arr_for[1] < arr_size)
        {
            cout << "Enter Code of product [" << arr_for[1] + 1 << "]\n";
            cin >> Meat[arr_for[1]].Code;
            cin.ignore();
            cout << "Enter Name of product [" << arr_for[1] + 1 << "]\n";
            getline(cin, Meat[arr_for[1]].Name);
            cout << "Enter Price of product [" << arr_for[1] + 1 << "]\n";
            cin >> Meat[arr_for[1]].Price;
            cout << "Enter Quantity of product [" << arr_for[1] + 1 << "]\n";
            cin >> Meat[arr_for[1]].Quantity;
            cout << "Enter Production Date of product [" << arr_for[1] + 1 << "]   like 00/00/2000\n";
            cin >> Meat[arr_for[1]].Proddate;
            cout << "Enter Expiry date of product [" << arr_for[1] + 1 << "]   like 00/00/2000\n";
            cin >> Meat[arr_for[1]].Expiredate;
            arr_for[1]++;
            cout << "\n";
            cout << " 1)\033[4m Adding another new product \033[0m\n\n";
            cout << " 2)\033[4m Adding new product in different category\033[0m    \n\n";
            cout << "\033[31m3)\033[4m Exit\033[0m\n\n\033[0m\n\n";
            cout << "\033[36mEnter choice: \033[0m";
            cin >> check;
            cin.ignore();
            cin.ignore();
            if (check == "2")
                admin_add();
            else if (check == "3")
                menu();
            else
                continue;
        }
    }
    else if (choice == "3")
    {
        while (arr_for[2] < arr_size)
        {
            cout << "Enter Code of product [" << arr_for[2] + 1 << "]\n";
            cin >> Poultry[arr_for[2]].Code;
            cin.ignore();
            cout << "Enter Name of product [" << arr_for[2] + 1 << "]\n";
            getline(cin, Poultry[arr_for[2]].Name);
            cout << "Enter Price of product [" << arr_for[2] + 1 << "]\n";
            cin >> Poultry[arr_for[2]].Price;
            cout << "Enter Quantity of product [" << arr_for[2] + 1 << "]\n";
            cin >> Poultry[arr_for[2]].Quantity;
            cout << "Enter Production Date of product [" << arr_for[2] + 1 << "]   like 00/00/2000\n";
            cin >> Poultry[arr_for[2]].Proddate;
            cout << "Enter Expiry date of product [" << arr_for[2] + 1 << "]   like 00/00/2000\n";
            cin >> Poultry[arr_for[2]].Expiredate;
            arr_for[2]++;
            cout << "\n";
            cout << " 1)\033[4m Adding another new product \033[0m\n\n";
            cout << " 2)\033[4m Adding new product in different category\033[0m    \n\n";
            cout << "\033[31m3)\033[4m Exit\033[0m\n\n\033[0m\n\n";
            cout << "\033[36mEnter choice: \033[0m";
            cin >> check;
            if (check == "2")
                admin_add();
            else if (check == "3")
                menu();
            else
                continue;

        }
    }
    else if (choice == "4")
    {
        while (arr_for[3] < arr_size)
        {
            cout << "Enter Code of product [" << arr_for[3] + 1 << "]\n";
            cin >> Canned_Food[arr_for[3]].Code;
            cin.ignore();
            cout << "Enter Name of product [" << arr_for[3] + 1 << "]\n";
            getline(cin, Canned_Food[arr_for[3]].Name);
            cout << "Enter Price of product [" << arr_for[3] + 1 << "]\n";
            cin >> Canned_Food[arr_for[3]].Price;
            cout << "Enter Quantity of product [" << arr_for[3] + 1 << "]\n";
            cin >> Canned_Food[arr_for[3]].Quantity;
            cout << "Enter Production Date of product [" << arr_for[3] + 1 << "]   like 00/00/2000\n";
            cin >> Canned_Food[arr_for[3]].Proddate;
            cout << "Enter Expiry date of product [" << arr_for[3] + 1 << "]   like 00/00/2000\n";
            cin >> Canned_Food[arr_for[3]].Expiredate;
            arr_for[3]++;
            cout << "\n";
            cout << " 1)\033[4m Adding another new product \033[0m\n\n";
            cout << " 2)\033[4m Adding new product in different category\033[0m    \n\n";
            cout << "\033[31m3)\033[4m Exit\033[0m\n\n\033[0m\n\n";
            cout << "\033[36mEnter choice: \033[0m";
            cin >> check;
            if (check == "2")
                admin_add();
            else if (check == "3")
                menu();
            else
                continue;

        }
    }
    else if (choice == "5")
    {
        while (arr_for[4] < arr_size)
        {
            cout << "Enter Code of product [" << arr_for[4] + 1 << "]\n";
            cin >> Food_Legumes[arr_for[4]].Code;
            cin.ignore();
            cout << "Enter Name of product [" << arr_for[4] + 1 << "]\n";
            getline(cin, Food_Legumes[arr_for[4]].Name);
            cout << "Enter Price of product [" << arr_for[4] + 1 << "]\n";
            cin >> Food_Legumes[arr_for[4]].Price;
            cout << "Enter Quantity of product [" << arr_for[4] + 1 << "]\n";
            cin >> Food_Legumes[arr_for[4]].Quantity;
            cout << "Enter Production Date of product [" << arr_for[4] + 1 << "]   like 00/00/2000\n";
            cin >> Food_Legumes[arr_for[4]].Proddate;
            cout << "Enter Expiry date of product [" << arr_for[4] + 1 << "]   like 00/00/2000\n";
            cin >> Food_Legumes[arr_for[4]].Expiredate;
            arr_for[4]++;
            cout << "\n";
            cout << " 1)\033[4m Adding another new product \033[0m\n\n";
            cout << " 2)\033[4m Adding new product in different category\033[0m    \n\n";
            cout << "\033[31m3)\033[4m Exit\033[0m\n\n\033[0m\n\n";
            cout << "\033[36mEnter choice: \033[0m";
            cin >> check;
            if (check == "2")
                admin_add();
            else if (check == "3")
                menu();
            else
                continue;

        }
    }
    else if (choice == "6")
    {
        while (arr_for[5] < arr_size)
        {
            cout << "Enter Code of product [" << arr_for[5] + 1 << "]\n";
            cin >> Drinks[arr_for[5]].Code;
            cin.ignore();
            cout << "Enter Name of product [" << arr_for[5] + 1 << "]\n";
            getline(cin, Drinks[arr_for[5]].Name);
            cout << "Enter Price of product [" << arr_for[5] + 1 << "]\n";
            cin >> Drinks[arr_for[5]].Price;
            cout << "Enter Quantity of product [" << arr_for[5] + 1 << "]\n";
            cin >> Drinks[arr_for[5]].Quantity;
            cout << "Enter Production Date of product [" << arr_for[5] + 1 << "]   like 00/00/2000\n";
            cin >> Drinks[arr_for[5]].Proddate;
            cout << "Enter Expiry date of product [" << arr_for[5] + 1 << "]   like 00/00/2000\n";
            cin >> Drinks[arr_for[5]].Expiredate;
            arr_for[5]++;
            cout << "\n";
            cout << " 1)\033[4m Adding another new product \033[0m\n\n";
            cout << " 2)\033[4m Adding new product in different category\033[0m    \n\n";
            cout << "\033[31m3)\033[4m Exit\033[0m\n\n\033[0m\n\n";
            cout << "\033[36mEnter choice: \033[0m";
            cin >> check;
            if (check == "2")
                admin_add();
            else if (check == "3")
                menu();
            else
                continue;
        }
    }
    else
    {
        cout << "\n\033[31mInvalid Value!!\033[0m\n";
        cout << "\033[36mRe-enter your choice\033[0m\n\n";
        admin_add();
    }
}
void admin_remove()   //-->Removing products from categories by adminstrator.

{
    string choice, choice1;
    bool test = false;
    cout << "\t\t\t\t\t\t\t________________________________________________\n";
    cout << "\t\t\t\t\t\t\t|        Categories of the Supermarket         |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t\t\t\t|          1) Fruits and Vegtables             |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          2) Meat [fresh,processed]           |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          3) Poultry                          |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          4) Canned Food                      |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          5) Food and Legumes                 |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          6) Drinks                           |\n";
    cout << "\t\t\t\t\t\t\t|______________________________________________|\n\n";
    cout << "\033[36mEnter Category number : \033[0m";
    cin >> choice;
    cin.ignore();
R:
    if (choice == "1")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[0]; i++)
        {

            cout << "|  " << Fruits_Vegtables[i].Code << " \t|\t" << Fruits_Vegtables[i].Name << "\t|\t" << Fruits_Vegtables[i].Price << "\t|\t" << Fruits_Vegtables[i].Quantity << "\t|\t" << Fruits_Vegtables[i].Proddate << "\t|\t" << Fruits_Vegtables[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[31mPlease enter the code of the product you want to remove:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[0]; i++)
        {
            if (code == Fruits_Vegtables[i].Code)
            {
                test = true;
                for (int j = i; j < arr_for[0]; j++)
                {
                    Fruits_Vegtables[j].Code = Fruits_Vegtables[j + 1].Code;
                    Fruits_Vegtables[j].Name = Fruits_Vegtables[j + 1].Name;
                    Fruits_Vegtables[j].Quantity = Fruits_Vegtables[j + 1].Quantity;
                    Fruits_Vegtables[j].Price = Fruits_Vegtables[j + 1].Price;
                    Fruits_Vegtables[j].Proddate = Fruits_Vegtables[j + 1].Proddate;
                    Fruits_Vegtables[j].Expiredate = Fruits_Vegtables[j + 1].Expiredate;
                }
                arr_for[0]--;
            }

        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[0]; i++)
            {

                cout << "|  " << Fruits_Vegtables[i].Code << " \t|\t" << Fruits_Vegtables[i].Name << "\t|\t" << Fruits_Vegtables[i].Price << "\t|\t" << Fruits_Vegtables[i].Quantity << "\t|\t" << Fruits_Vegtables[i].Proddate << "\t|\t" << Fruits_Vegtables[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mProduct removed succesfully\033[0m\n\n";
            cout << "1)\033[4m Removing another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o1:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_remove();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o1;
            }
        }
    }
    else if (choice == "2")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[1]; i++)
        {
            cout << "|  " << Meat[i].Code << " \t|\t" << Meat[i].Name << "\t|\t" << Meat[i].Price << "\t|\t" << Meat[i].Quantity << "\t|\t" << Meat[i].Proddate << "\t|\t" << Meat[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[31mPlease enter the code of the product you want to remove:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[1]; i++)
        {
            if (code == Meat[i].Code)
            {
                test = true;
                for (int j = i; j < arr_for[1]; j++)
                {
                    Meat[j].Code = Meat[j + 1].Code;
                    Meat[j].Name = Meat[j + 1].Name;
                    Meat[j].Quantity = Meat[j + 1].Quantity;
                    Meat[j].Price = Meat[j + 1].Price;
                    Meat[j].Proddate = Meat[j + 1].Proddate;
                    Meat[j].Expiredate = Meat[j + 1].Expiredate;
                }
                arr_for[1]--;
            }

        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[1]; i++)
            {
                cout << "|  " << Meat[i].Code << " \t|\t" << Meat[i].Name << "\t|\t" << Meat[i].Price << "\t|\t" << Meat[i].Quantity << "\t|\t" << Meat[i].Proddate << "\t|\t" << Meat[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mProduct removed succesfully\033[0m\n\n";
            cout << "1)\033[4m Removing another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o2:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_remove();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o2;
            }
        }
    }
    else if (choice == "3")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[2]; i++)
        {
            cout << "|  " << Poultry[i].Code << " \t|\t" << Poultry[i].Name << "\t|\t" << Poultry[i].Price << "\t|\t" << Poultry[i].Quantity << "\t|\t" << Poultry[i].Proddate << "\t|\t" << Poultry[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[31mPlease enter the code of the product you want to remove:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[2]; i++)
        {
            if (code == Poultry[i].Code)
            {
                test = true;
                for (int j = i; j < arr_for[2]; j++)
                {
                    Poultry[j].Code = Poultry[j + 1].Code;
                    Poultry[j].Name = Poultry[j + 1].Name;
                    Poultry[j].Quantity = Poultry[j + 1].Quantity;
                    Poultry[j].Price = Poultry[j + 1].Price;
                    Poultry[j].Proddate = Poultry[j + 1].Proddate;
                    Poultry[j].Expiredate = Poultry[j + 1].Expiredate;
                }
                arr_for[2]--;
            }

        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[2]; i++)
            {
                cout << "|  " << Poultry[i].Code << " \t|\t" << Poultry[i].Name << "\t|\t" << Poultry[i].Price << "\t|\t" << Poultry[i].Quantity << "\t|\t" << Poultry[i].Proddate << "\t|\t" << Poultry[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mProduct removed succesfully\033[0m\n\n";
            cout << "1)\033[4m Removing another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o3:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_remove();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o3;
            }
        }
    }
    else if (choice == "4")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[3]; i++)
        {
            cout << "|  " << Canned_Food[i].Code << " \t|\t" << Canned_Food[i].Name << "\t|\t" << Canned_Food[i].Price << "\t|\t" << Canned_Food[i].Quantity << "\t|\t" << Canned_Food[i].Proddate << "\t|\t" << Canned_Food[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[31mPlease enter the code of the product you want to remove:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[3]; i++)
        {
            if (code == Canned_Food[i].Code)
            {
                test = true;
                for (int j = i; j < arr_for[3]; j++)
                {
                    Canned_Food[j].Code = Canned_Food[j + 1].Code;
                    Canned_Food[j].Name = Canned_Food[j + 1].Name;
                    Canned_Food[j].Quantity = Canned_Food[j + 1].Quantity;
                    Canned_Food[j].Price = Canned_Food[j + 1].Price;
                    Canned_Food[j].Proddate = Canned_Food[j + 1].Proddate;
                    Canned_Food[j].Expiredate = Canned_Food[j + 1].Expiredate;
                }
                arr_for[3]--;
            }

        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[3]; i++)
            {
                cout << "|  " << Canned_Food[i].Code << " \t|\t" << Canned_Food[i].Name << "\t|\t" << Canned_Food[i].Price << "\t|\t" << Canned_Food[i].Quantity << "\t|\t" << Canned_Food[i].Proddate << "\t|\t" << Canned_Food[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mProduct removed succesfully\033[0m\n\n";
            cout << "1)\033[4m Removing another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o4:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_remove();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o4;
            }
        }
    }
    else if (choice == "5")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[4]; i++)
        {
            cout << "|  " << Food_Legumes[i].Code << " \t|\t" << Food_Legumes[i].Name << "\t|\t" << Food_Legumes[i].Price << "\t|\t" << Food_Legumes[i].Quantity << "\t|\t" << Food_Legumes[i].Proddate << "\t|\t" << Food_Legumes[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[31mPlease enter the code of the product you want to remove:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[4]; i++)
        {
            if (code == Food_Legumes[i].Code)
            {
                test = true;
                for (int j = i; j < arr_for[4]; j++)
                {
                    Food_Legumes[j].Code = Food_Legumes[j + 1].Code;
                    Food_Legumes[j].Name = Food_Legumes[j + 1].Name;
                    Food_Legumes[j].Quantity = Food_Legumes[j + 1].Quantity;
                    Food_Legumes[j].Price = Food_Legumes[j + 1].Price;
                    Food_Legumes[j].Proddate = Food_Legumes[j + 1].Proddate;
                    Food_Legumes[j].Expiredate = Food_Legumes[j + 1].Expiredate;
                }
                arr_for[4]--;
            }

        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[4]; i++)
            {
                cout << "|  " << Food_Legumes[i].Code << " \t|\t" << Food_Legumes[i].Name << "\t|\t" << Food_Legumes[i].Price << "\t|\t" << Food_Legumes[i].Quantity << "\t|\t" << Food_Legumes[i].Proddate << "\t|\t" << Food_Legumes[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mProduct removed succesfully\033[0m\n\n";
            cout << "1)\033[4m Removing another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o5:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_remove();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o5;
            }
        }
    }
    else if (choice == "6")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[5]; i++)
        {
            cout << "|  " << Drinks[i].Code << " \t|\t" << Drinks[i].Name << "\t|\t" << Drinks[i].Price << "\t|\t" << Drinks[i].Quantity << "\t|\t" << Drinks[i].Proddate << "\t|\t" << Drinks[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[31mPlease enter the code of the product you want to remove:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[5]; i++)
        {
            if (code == Drinks[i].Code)
            {
                test = true;
                for (int j = i; j < arr_for[5]; j++)
                {
                    Drinks[j].Code = Drinks[j + 1].Code;
                    Drinks[j].Name = Drinks[j + 1].Name;
                    Drinks[j].Quantity = Drinks[j + 1].Quantity;
                    Drinks[j].Price = Drinks[j + 1].Price;
                    Drinks[j].Proddate = Drinks[j + 1].Proddate;
                    Drinks[j].Expiredate = Drinks[j + 1].Expiredate;
                }
                arr_for[5]--;
            }

        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[5]; i++)
            {
                cout << "|  " << Drinks[i].Code << " \t|\t" << Drinks[i].Name << "\t|\t" << Drinks[i].Price << "\t|\t" << Drinks[i].Quantity << "\t|\t" << Drinks[i].Proddate << "\t|\t" << Drinks[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mProduct removed succesfully\033[0m\n\n";
            cout << "1)\033[4m Removing another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o6:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_remove();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o6;
            }
        }
    }
    else
    {
        cout << "\n\033[31mInvalid Value!!\033[0m\n";
        cout << "\033[36mRe-enter your choice\033[0m\n\n";
        admin_remove();
    }
}

void admin_change_q()   //--> Changing the quantity of the product by administrator.
{
    string choice, choice1;
    bool test = false;
    cout << "\t\t\t\t\t\t\t________________________________________________\n";
    cout << "\t\t\t\t\t\t\t|        Categories of the Supermarket         |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t\t\t\t|          1) Fruits and Vegtables             |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          2) Meat [fresh,processed]           |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          3) Poultry                          |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          4) Canned Food                      |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          5) Food and Legumes                 |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          6) Drinks                           |\n";
    cout << "\t\t\t\t\t\t\t|______________________________________________|\n\n";
    cout << "\033[36mEnter Category number : \033[0m";
    cin >> choice;
    cin.ignore();
R:
    if (choice == "1")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[0]; i++)
        {

            cout << "|  " << Fruits_Vegtables[i].Code << " \t|\t" << Fruits_Vegtables[i].Name << "\t|\t" << Fruits_Vegtables[i].Price << "\t|\t" << Fruits_Vegtables[i].Quantity << "\t|\t" << Fruits_Vegtables[i].Proddate << "\t|\t" << Fruits_Vegtables[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36m Please enter the code of the produc you want to change quantity :\033[0m \n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[0]; i++)
        {
            if (code == Fruits_Vegtables[i].Code)
            {
                test = true;


                cout << "\033[36m Enter the new quantity:\033[0m ";
                cin >> Fruits_Vegtables[i].Quantity;
            }

        }
        if (test == false)
        {
            cout << "\033[31m The code you want is not avalible :(\033[0m \n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[0]; i++)
            {

                cout << "|  " << Fruits_Vegtables[i].Code << " \t|\t" << Fruits_Vegtables[i].Name << "\t|\t" << Fruits_Vegtables[i].Price << "\t|\t" << Fruits_Vegtables[i].Quantity << "\t|\t" << Fruits_Vegtables[i].Proddate << "\t|\t" << Fruits_Vegtables[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32m Quantity changed succesfully\033[0m \n\n";
            cout << " 1)\033[4m Changing another quantity\033[0m \n\n";
            cout << "\033[31m 2)\033[4m Exit\033[0m\033[0m \n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o1:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_change_q();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o1;
            }
        }

    }

    if (choice == "2")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[0]; i++)
        {

            cout << "|  " << Meat[i].Code << " \t|\t" << Meat[i].Name << "\t|\t" << Meat[i].Price << "\t|\t" << Meat[i].Quantity << "\t|\t" << Meat[i].Proddate << "\t|\t" << Meat[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36m Please enter the code of the produc you want to change quantity :\033[0m \n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[0]; i++)
        {
            if (code == Meat[i].Code)
            {
                test = true;


                cout << "\033[36m Enter the new quantity:\033[0m ";
                cin >> Meat[i].Quantity;

            }

        }

        if (test == false)
        {
            cout << "\033[31m The code you want is not avalible :(\033[0m \n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[0]; i++)
            {

                cout << "|  " << Meat[i].Code << " \t|\t" << Meat[i].Name << "\t|\t" << Meat[i].Price << "\t|\t" << Meat[i].Quantity << "\t|\t" << Meat[i].Proddate << "\t|\t" << Meat[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32m Quantity changed succesfully\033[0m \n\n";
            cout << " 1)\033[4m Changing another quantity\033[0m \n\n";
            cout << "\033[31m 2)\033[4m Exit\033[0m\033[0m \n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o2:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_change_q();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o2;
            }
        }
    }
    if (choice == "3")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[0]; i++)
        {

            cout << "|  " << Poultry[i].Code << " \t|\t" << Poultry[i].Name << "\t|\t" << Meat[i].Price << "\t|\t" << Meat[i].Quantity << "\t|\t" << Meat[i].Proddate << "\t|\t" << Meat[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36m Please enter the code of the produc you want to change quantity :\033[0m \n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[0]; i++)
        {
            if (code == Poultry[i].Code)
            {
                test = true;


                cout << "\033[36m Enter the new quantity:\033[0m ";
                cin >> Poultry[i].Quantity;

            }
        }
        if (test == false)
        {
            cout << "\033[31m The code you want is not avalible :(\033[0m \n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[0]; i++)
            {

                cout << "|  " << Poultry[i].Code << " \t|\t" << Poultry[i].Name << "\t|\t" << Poultry[i].Price << "\t|\t" << Poultry[i].Quantity << "\t|\t" << Poultry[i].Proddate << "\t|\t" << Poultry[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32m Quantity changed succesfully\033[0m \n\n";
            cout << " 1)\033[4m Changing another quantity\033[0m \n\n";
            cout << "\033[31m 2)\033[4m Exit\033[0m\033[0m \n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o3:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_change_q();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o3;
            }
        }
    }
    if (choice == "4")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[0]; i++)
        {

            cout << "|  " << Canned_Food[i].Code << " \t|\t" << Canned_Food[i].Name << "\t|\t" << Canned_Food[i].Price << "\t|\t" << Canned_Food[i].Quantity << "\t|\t" << Canned_Food[i].Proddate << "\t|\t" << Canned_Food[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36m Please enter the code of the produc you want to change quantity :\033[0m \n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[0]; i++)
        {
            if (code == Canned_Food[i].Code)
            {
                test = true;


                cout << "\033[36m Enter the new quantity:\033[0m ";
                cin >> Canned_Food[i].Quantity;

            }
        }
        if (test == false)
        {
            cout << "\033[31m The code you want is not avalible :(\033[0m \n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[0]; i++)
            {

                cout << "|  " << Canned_Food[i].Code << " \t|\t" << Canned_Food[i].Name << "\t|\t" << Canned_Food[i].Price << "\t|\t" << Canned_Food[i].Quantity << "\t|\t" << Canned_Food[i].Proddate << "\t|\t" << Canned_Food[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32m Quantity changed succesfully\033[0m \n\n";
            cout << " 1)\033[4m Changing another quantity\033[0m \n\n";
            cout << "\033[31m 2)\033[4m Exit\033[0m\033[0m \n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o4:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_change_q();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o4;
            }
        }
    }
    if (choice == "5")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[0]; i++)
        {

            cout << "|  " << Food_Legumes[i].Code << " \t|\t" << Food_Legumes[i].Name << "\t|\t" << Food_Legumes[i].Price << "\t|\t" << Food_Legumes[i].Quantity << "\t|\t" << Food_Legumes[i].Proddate << "\t|\t" << Food_Legumes[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36m Please enter the code of the produc you want to change quantity :\033[0m \n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[0]; i++)
        {
            if (code == Food_Legumes[i].Code)
            {
                test = true;


                cout << "\033[36m Enter the new quantity:\033[0m ";
                cin >> Food_Legumes[i].Quantity;

            }
        }
        if (test == false)
        {
            cout << "\033[31m The code you want is not avalible :(\033[0m \n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[0]; i++)
            {

                cout << "|  " << Food_Legumes[i].Code << " \t|\t" << Food_Legumes[i].Name << "\t|\t" << Food_Legumes[i].Price << "\t|\t" << Food_Legumes[i].Quantity << "\t|\t" << Food_Legumes[i].Proddate << "\t|\t" << Food_Legumes[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32m Quantity changed succesfully\033[0m \n\n";
            cout << " 1)\033[4m Changing another quantity\033[0m \n\n";
            cout << "\033[31m 2)\033[4m Exit\033[0m\033[0m \n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o5:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_change_q();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o5;
            }
        }
    }
    if (choice == "6")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[0]; i++)
        {

            cout << "|  " << Drinks[i].Code << " \t|\t" << Drinks[i].Name << "\t|\t" << Drinks[i].Price << "\t|\t" << Drinks[i].Quantity << "\t|\t" << Drinks[i].Proddate << "\t|\t" << Drinks[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36m Please enter the code of the produc you want to change quantity :\033[0m \n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[0]; i++)
        {
            if (code == Drinks[i].Code)
            {
                test = true;


                cout << "\033[36m Enter the new quantity:\033[0m ";
                cin >> Drinks[i].Quantity;

            }
        }
        if (test == false)
        {
            cout << "\033[31m The code you want is not avalible :(\033[0m \n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[0]; i++)
            {

                cout << "|  " << Drinks[i].Code << " \t|\t" << Drinks[i].Name << "\t|\t" << Drinks[i].Price << "\t|\t" << Drinks[i].Quantity << "\t|\t" << Drinks[i].Proddate << "\t|\t" << Drinks[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32m Quantity changed succesfully\033[0m \n\n";
            cout << " 1)\033[4m Changing another quantity\033[0m \n\n";
            cout << "\033[31m 2)\033[4m Exit\033[0m\033[0m \n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o6:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_change_q();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\n\033[31mInvalid Value!!\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o6;
            }
        }
      
    }
    else
    {
        cout << "\n\033[31mInvalid Value!!\033[0m\n";
        cout << "\033[36mRe-enter your choice\033[0m\n\n";
        admin_change_q();
        
    }

}
void admin_price()     //-->Changing the price of a product by adminstrator.
{
    string choice, choice1;
    bool test = false;
    cout << "\t\t\t\t\t\t\t________________________________________________\n";
    cout << "\t\t\t\t\t\t\t|        Categories of the Supermarket         |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t\t\t\t|          1) Fruits and Vegtables             |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          2) Meat [fresh,processed]           |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          3) Poultry                          |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          4) Canned Food                      |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          5) Food and Legumes                 |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          6) Drinks                           |\n";
    cout << "\t\t\t\t\t\t\t|______________________________________________|\n\n";
    cout << "\033[36mEnter Category number :\033[0m ";
    cin >> choice;
    cin.ignore();
R:
    if (choice == "1")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[0]; i++)
        {

            cout << "|  " << Fruits_Vegtables[i].Code << " \t|\t" << Fruits_Vegtables[i].Name << "\t|\t" << Fruits_Vegtables[i].Price << "\t|\t" << Fruits_Vegtables[i].Quantity << "\t|\t" << Fruits_Vegtables[i].Proddate << "\t|\t" << Fruits_Vegtables[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36mPlease enter the code of the product you want to change its price:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[0]; i++)
        {
            if (code == Fruits_Vegtables[i].Code)
            {
                test = true;
                cout << "\n\033[36mEnter the new price:\033[0m";
                cin >> Fruits_Vegtables[i].Price;
            }
        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[0]; i++)
            {

                cout << "|  " << Fruits_Vegtables[i].Code << " \t|\t" << Fruits_Vegtables[i].Name << "\t|\t" << Fruits_Vegtables[i].Price << "\t|\t" << Fruits_Vegtables[i].Quantity << "\t|\t" << Fruits_Vegtables[i].Proddate << "\t|\t" << Fruits_Vegtables[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mThe price has changed succesfully\033[0m\n\n";
            cout << "1)\033[4m Changing price of another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36Enter Choice:\033[0m";
        o1:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_price();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o1;
            }
        }

    }
    else if (choice == "2")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[1]; i++)
        {
            cout << "|  " << Meat[i].Code << " \t|\t" << Meat[i].Name << "\t|\t" << Meat[i].Price << "\t|\t" << Meat[i].Quantity << "\t|\t" << Meat[i].Proddate << "\t|\t" << Meat[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36mPlease enter the code of the product you want to change its price:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[1]; i++)
        {
            if (code == Meat[i].Code)
            {
                test = true;
                cout << "\n\033[36mEnter the new price:\033[0m";
                cin >> Meat[i].Price;
            }
        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[1]; i++)
            {
                cout << "|  " << Meat[i].Code << " \t|\t" << Meat[i].Name << "\t|\t" << Meat[i].Price << "\t|\t" << Meat[i].Quantity << "\t|\t" << Meat[i].Proddate << "\t|\t" << Meat[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mThe price has changed succesfully\033[0m\n\n";
            cout << "1)\033[4m Changing price of another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36Enter Choice:\033[0m";
        o2:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_price();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o2;
            }
        }

    }
    else if (choice == "3")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[2]; i++)
        {
            cout << "|  " << Poultry[i].Code << " \t|\t" << Poultry[i].Name << "\t|\t" << Poultry[i].Price << "\t|\t" << Poultry[i].Quantity << "\t|\t" << Poultry[i].Proddate << "\t|\t" << Poultry[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36mPlease enter the code of the product you want to change its price:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[2]; i++)
        {
            if (code == Poultry[i].Code)
            {
                test = true;
                cout << "\n\033[36mEnter the new price:\033[0m";
                cin >> Poultry[i].Price;
            }
        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[2]; i++)
            {
                cout << "|  " << Poultry[i].Code << " \t|\t" << Poultry[i].Name << "\t|\t" << Poultry[i].Price << "\t|\t" << Poultry[i].Quantity << "\t|\t" << Poultry[i].Proddate << "\t|\t" << Poultry[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mThe price has changed succesfully\033[0m\n\n";
            cout << "1)\033[4m Changing price of another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36Enter Choice:\033[0m";
        o3:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_price();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o3;
            }
        }
    }
    else if (choice == "4")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[3]; i++)
        {
            cout << "|  " << Canned_Food[i].Code << " \t|\t" << Canned_Food[i].Name << "\t|\t" << Canned_Food[i].Price << "\t|\t" << Canned_Food[i].Quantity << "\t|\t" << Canned_Food[i].Proddate << "\t|\t" << Canned_Food[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36mPlease enter the code of the product you want to change its price:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[3]; i++)
        {
            if (code == Canned_Food[i].Code)
            {
                test = true;
                cout << "\n\033[36mEnter the new price:\033[0m";
                cin >> Canned_Food[i].Price;
            }
        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[3]; i++)
            {
                cout << "|  " << Canned_Food[i].Code << " \t|\t" << Canned_Food[i].Name << "\t|\t" << Canned_Food[i].Price << "\t|\t" << Canned_Food[i].Quantity << "\t|\t" << Canned_Food[i].Proddate << "\t|\t" << Canned_Food[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mThe price has changed succesfully\033[0m\n\n";
            cout << "1)\033[4m Changing price of another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36Enter Choice:\033[0m";
        o4:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_price();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o4;
            }
        }
    }
    else if (choice == "5")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[4]; i++)
        {
            cout << "|  " << Food_Legumes[i].Code << " \t|\t" << Food_Legumes[i].Name << "\t|\t" << Food_Legumes[i].Price << "\t|\t" << Food_Legumes[i].Quantity << "\t|\t" << Food_Legumes[i].Proddate << "\t|\t" << Food_Legumes[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36mPlease enter the code of the product you want to change its price:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[4]; i++)
        {
            if (code == Food_Legumes[i].Code)
            {
                test = true;
                cout << "\n\033[36mEnter the new price:\033[0m";
                cin >> Food_Legumes[i].Price;
            }
        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[4]; i++)
            {
                cout << "|  " << Food_Legumes[i].Code << " \t|\t" << Food_Legumes[i].Name << "\t|\t" << Food_Legumes[i].Price << "\t|\t" << Food_Legumes[i].Quantity << "\t|\t" << Food_Legumes[i].Proddate << "\t|\t" << Food_Legumes[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mThe price has changed succesfully\033[0m\n\n";
            cout << "1)\033[4m Changing price of another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36Enter Choice:\033[0m";
        o5:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_price();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o5;
            }
        }
    }
    else if (choice == "6")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[5]; i++)
        {
            cout << "|  " << Drinks[i].Code << " \t|\t" << Drinks[i].Name << "\t|\t" << Drinks[i].Price << "\t|\t" << Drinks[i].Quantity << "\t|\t" << Drinks[i].Proddate << "\t|\t" << Drinks[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36mPlease enter the code of the product you want to change its price:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[5]; i++)
        {
            if (code == Drinks[i].Code)
            {
                test = true;
                cout << "\n\033[36mEnter the new price:\033[0m";
                cin >> Drinks[i].Price;
            }
        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[5]; i++)
            {
                cout << "|  " << Drinks[i].Code << " \t|\t" << Drinks[i].Name << "\t|\t" << Drinks[i].Price << "\t|\t" << Drinks[i].Quantity << "\t|\t" << Drinks[i].Proddate << "\t|\t" << Drinks[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mThe price has changed succesfully\033[0m\n\n";
            cout << "1)\033[4m Changing price of another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36Enter Choice:\033[0m";
        o6:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_price();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o6;
            }
        }
    }
    else
    {
        cout << "\033[31m\nInvalid Value! :(\033[0m\n";
        cout << "\033[36mRe-enter your choice\033[0m\n\n";
        admin_price();
    }

}
void admin_date()
{
    string choice, choice1;
    bool test = false;
    cout << "\t\t\t\t\t\t\t________________________________________________\n";
    cout << "\t\t\t\t\t\t\t|        Categories of the Supermarket         |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t\t\t\t|          1) Fruits and Vegtables             |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          2) Meat [fresh,processed]           |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          3) Poultry                          |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          4) Canned Food                      |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          5) Food and Legumes                 |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          6) Drinks                           |\n";
    cout << "\t\t\t\t\t\t\t|______________________________________________|\n\n";
    cout << "\033[36mEnter Category number : \033[0m";
    cin >> choice;
    cin.ignore();
R:
    if (choice == "1")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[0]; i++)
        {

            cout << "|  " << Fruits_Vegtables[i].Code << " \t|\t" << Fruits_Vegtables[i].Name << "\t|\t" << Fruits_Vegtables[i].Price << "\t|\t" << Fruits_Vegtables[i].Quantity << "\t|\t" << Fruits_Vegtables[i].Proddate << "\t|\t" << Fruits_Vegtables[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36mPlease enter the code of the product you want to change its production & expiry date:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[0]; i++)
        {
            if (code == Fruits_Vegtables[i].Code)
            {
                test = true;
                cout << "\n\033[36mEnter the new production date (like 00/00/2000):\033[0m\n";
                cin >> Fruits_Vegtables[i].Proddate;
                cout << "\n\033[36mEnter the new expiry date (like 00/00/2000):\033[0m\n";
                cin >> Fruits_Vegtables[i].Expiredate;
            }
        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[0]; i++)
            {

                cout << "|  " << Fruits_Vegtables[i].Code << " \t|\t" << Fruits_Vegtables[i].Name << "\t|\t" << Fruits_Vegtables[i].Price << "\t|\t" << Fruits_Vegtables[i].Quantity << "\t|\t" << Fruits_Vegtables[i].Proddate << "\t|\t" << Fruits_Vegtables[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mThe production & expiry dates have changed succesfuly\033[0m\n\n";
            cout << "1)\033[4m Changing production & expiry dates of another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o1:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_date();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o1;
            }
        }

    }
    else if (choice == "2")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[1]; i++)
        {
            cout << "|  " << Meat[i].Code << " \t|\t" << Meat[i].Name << "\t|\t" << Meat[i].Price << "\t|\t" << Meat[i].Quantity << "\t|\t" << Meat[i].Proddate << "\t|\t" << Meat[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36mPlease enter the code of the product you want to change its production & expiry date:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[1]; i++)
        {
            if (code == Meat[i].Code)
            {
                test = true;
                cout << "\n\033[36mEnter the new production date (like 00/00/2000):\033[0m\n";
                cin >> Meat[i].Proddate;
                cout << "\n\033[36mEnter the new expiry date (like 00/00/2000):\033[0m\n";
                cin >> Meat[i].Expiredate;
            }
        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[1]; i++)
            {
                cout << "|  " << Meat[i].Code << " \t|\t" << Meat[i].Name << "\t|\t" << Meat[i].Price << "\t|\t" << Meat[i].Quantity << "\t|\t" << Meat[i].Proddate << "\t|\t" << Meat[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mThe production & expiry dates have changed succesfuly\033[0m\n\n";
            cout << "1)\033[4m Changing production & expiry dates of another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o2:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_date();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o2;
            }
        }

    }
    else if (choice == "3")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[2]; i++)
        {
            cout << "|  " << Poultry[i].Code << " \t|\t" << Poultry[i].Name << "\t|\t" << Poultry[i].Price << "\t|\t" << Poultry[i].Quantity << "\t|\t" << Poultry[i].Proddate << "\t|\t" << Poultry[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36mPlease enter the code of the product you want to change its production & expiry date:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[2]; i++)
        {
            if (code == Poultry[i].Code)
            {
                test = true;
                cout << "\n\033[36mEnter the new production date (like 00/00/2000):\033[0m\n";
                cin >> Poultry[i].Proddate;
                cout << "\n\033[36mEnter the new expiry date (like 00/00/2000):\033[0m\n";
                cin >> Poultry[i].Expiredate;
            }
        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[2]; i++)
            {
                cout << "|  " << Poultry[i].Code << " \t|\t" << Poultry[i].Name << "\t|\t" << Poultry[i].Price << "\t|\t" << Poultry[i].Quantity << "\t|\t" << Poultry[i].Proddate << "\t|\t" << Poultry[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mThe production & expiry dates have changed succesfuly\033[0m\n\n";
            cout << "1)\033[4m Changing production & expiry dates of another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o3:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_date();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o3;
            }
        }
    }
    else if (choice == "4")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[3]; i++)
        {
            cout << "|  " << Canned_Food[i].Code << " \t|\t" << Canned_Food[i].Name << "\t|\t" << Canned_Food[i].Price << "\t|\t" << Canned_Food[i].Quantity << "\t|\t" << Canned_Food[i].Proddate << "\t|\t" << Canned_Food[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36mPlease enter the code of the product you want to change its production & expiry date:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[3]; i++)
        {
            if (code == Canned_Food[i].Code)
            {
                test = true;
                cout << "\n\033[36mEnter the new production date (like 00/00/2000):\033[0m\n";
                cin >> Canned_Food[i].Proddate;
                cout << "\n\033[36mEnter the new expiry date (like 00/00/2000):\033[0m\n";
                cin >> Canned_Food[i].Expiredate;
            }
        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[3]; i++)
            {
                cout << "|  " << Canned_Food[i].Code << " \t|\t" << Canned_Food[i].Name << "\t|\t" << Canned_Food[i].Price << "\t|\t" << Canned_Food[i].Quantity << "\t|\t" << Canned_Food[i].Proddate << "\t|\t" << Canned_Food[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mThe production & expiry dates have changed succesfuly\033[0m\n\n";
            cout << "1)\033[4m Changing production & expiry dates of another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o4:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_date();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o4;
            }
        }
    }
    else if (choice == "5")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[4]; i++)
        {
            cout << "|  " << Food_Legumes[i].Code << " \t|\t" << Food_Legumes[i].Name << "\t|\t" << Food_Legumes[i].Price << "\t|\t" << Food_Legumes[i].Quantity << "\t|\t" << Food_Legumes[i].Proddate << "\t|\t" << Food_Legumes[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36mPlease enter the code of the product you want to change its production & expiry date:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[4]; i++)
        {
            if (code == Food_Legumes[i].Code)
            {
                test = true;
                cout << "\n\033[36mEnter the new production date (like 00/00/2000):\033[0m\n";
                cin >> Food_Legumes[i].Proddate;
                cout << "\n\033[36mEnter the new expiry date (like 00/00/2000):\033[0m\n";
                cin >> Food_Legumes[i].Expiredate;
            }
        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[4]; i++)
            {
                cout << "|  " << Food_Legumes[i].Code << " \t|\t" << Food_Legumes[i].Name << "\t|\t" << Food_Legumes[i].Price << "\t|\t" << Food_Legumes[i].Quantity << "\t|\t" << Food_Legumes[i].Proddate << "\t|\t" << Food_Legumes[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mThe production & expiry dates have changed succesfuly\033[0m\n\n";
            cout << "1)\033[4m Changing production & expiry dates of another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o5:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_date();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o5;
            }
        }
    }
    else if (choice == "6")
    {
        cout << "_____________________________________________________________________________________________________________ \n";
        cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
        cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
        for (int i = 0; i < arr_for[5]; i++)
        {
            cout << "|  " << Drinks[i].Code << " \t|\t" << Drinks[i].Name << "\t|\t" << Drinks[i].Price << "\t|\t" << Drinks[i].Quantity << "\t|\t" << Drinks[i].Proddate << "\t|\t" << Drinks[i].Expiredate << "   |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
        }
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        cout << "\033[36mPlease enter the code of the product you want to change its production & expiry date:\033[0m\n";
        cin >> code;
        cin.ignore();
        for (int i = 0; i < arr_for[5]; i++)
        {
            if (code == Drinks[i].Code)
            {
                test = true;
                cout << "\n\033[36mEnter the new production date (like 00/00/2000):\033[0m\n";
                cin >> Drinks[i].Proddate;
                cout << "\n\033[36mEnter the new expiry date (like 00/00/2000):\033[0m\n";
                cin >> Drinks[i].Expiredate;
            }
        }
        if (test == false)
        {
            cout << "\033[31mThe code you want is not avalible :(\033[0m\n";
            goto R;
        }
        else if (test == true)
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[5]; i++)
            {
                cout << "|  " << Drinks[i].Code << " \t|\t" << Drinks[i].Name << "\t|\t" << Drinks[i].Price << "\t|\t" << Drinks[i].Quantity << "\t|\t" << Drinks[i].Proddate << "\t|\t" << Drinks[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
            cout << "\033[32mThe production & expiry dates have changed succesfuly\033[0m\n\n";
            cout << "1)\033[4m Changing production & expiry dates of another product\033[0m\n\n";
            cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
            cout << "\033[36mEnter Choice:\033[0m";
        o6:
            cin >> choice1;
            cin.ignore();
            if (choice1 == "1")
            {
                admin_date();
            }
            else if (choice1 == "2")
            {
                admin();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto o6;
            }
        }
    }
    else
    {
        cout << "\033[31m\nInvalid Value! :(\033[0m\n";
        cout << "\033[36mRe-enter your choice\033[0m\n\n";
        admin_date();
    }
}
void Buyer()   //--> Choosing Category and display Menu of the products in this Category.
{
R:
    string choice, choice1, choice2, choice3, order;
    cout << "\t\t\t\t\033[33m*******************************************      ******************************************     \n";
    cout << "\t\t\t\t*       ##       ###         #      #     *      *      ###      ####   ######   ######   *     \n";
    cout << "\t\t\t\t*     # ##    ##     ##     ###   #       *      *    ##   #      ##    ##         ##     *     \n";
    cout << "\t\t\t\t*       ##   ##       ##     #  #   #     *      *   ##           ##    #####      ##     *     \n";
    cout << "\t\t\t\t*       ##    ##     ##       #    ###    *      *    ##   ####   ##    ##         ##     *     \n";
    cout << "\t\t\t\t*      ####      ###        #       #     *      *      ####     ####   ##         ##     *     \n";
    cout << "\t\t\t\t*    Discount on orders exceeds 2000 L.E  *      *        For order exceed 6000 L.E       *     \n";
    cout << "\t\t\t\t*******************************************      ******************************************\033[0m     \n\n";
    cout << "\t\t\t\t\t\t\t________________________________________________\n";
    cout << "\t\t\t\t\t\t\t|        Categories of the Supermarket         |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t\t\t\t|          1) Fruits and Vegtables             |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          2) Meat [fresh,processed]           |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          3) Poultry                          |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          4) Canned Food                      |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          5) Food and Legumes                 |\n";
    cout << "\t\t\t\t\t\t\t|                                              |\n";
    cout << "\t\t\t\t\t\t\t|          6) Drinks                           |\n";
    cout << "\t\t\t\t\t\t\t|______________________________________________|\n\n";
    cout << "\033[36m 1)\033[4m Choose the Category you want\033[0m\033[36m :)\033[0m\n\n";
    cout << "\033[31m 2)\033[4m Back\033[0m \033[0m                        \n\n";
    cout << "\033[36mEnter choice:\033[0m ";
    cin >> choice1;
    cin.ignore();
    if (choice1 == "1")
    {
        cout << "\n";
        cout << "\033[36mEnter Category number :\033[0m ";
        cin >> choice;
        cin.ignore();
        if (choice == "1")
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[0]; i++)
            {

                cout << "|  " << Fruits_Vegtables[i].Code << " \t|\t" << Fruits_Vegtables[i].Name << "\t|\t" << Fruits_Vegtables[i].Price << "\t|\t" << Fruits_Vegtables[i].Quantity << "\t|\t" << Fruits_Vegtables[i].Proddate << "\t|\t" << Fruits_Vegtables[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        }
        else if (choice == "2")
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[1]; i++)
            {
                cout << "|  " << Meat[i].Code << " \t|\t" << Meat[i].Name << "\t|\t" << Meat[i].Price << "\t|\t" << Meat[i].Quantity << "\t|\t" << Meat[i].Proddate << "\t|\t" << Meat[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        }
        else if (choice == "3")
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[2]; i++)
            {
                cout << "|  " << Poultry[i].Code << " \t|\t" << Poultry[i].Name << "\t|\t" << Poultry[i].Price << "\t|\t" << Poultry[i].Quantity << "\t|\t" << Poultry[i].Proddate << "\t|\t" << Poultry[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        }
        else if (choice == "4")
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[3]; i++)
            {
                cout << "|  " << Canned_Food[i].Code << " \t|\t" << Canned_Food[i].Name << "\t|\t" << Canned_Food[i].Price << "\t|\t" << Canned_Food[i].Quantity << "\t|\t" << Canned_Food[i].Proddate << "\t|\t" << Canned_Food[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        }
        else if (choice == "5")
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Kilo) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[4]; i++)
            {
                cout << "|  " << Food_Legumes[i].Code << " \t|\t" << Food_Legumes[i].Name << "\t|\t" << Food_Legumes[i].Price << "\t|\t" << Food_Legumes[i].Quantity << "\t|\t" << Food_Legumes[i].Proddate << "\t|\t" << Food_Legumes[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        }
        else if (choice == "6")
        {
            cout << "_____________________________________________________________________________________________________________ \n";
            cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   |            \n";
            cout << "|       |   \t\t\t|    (Per Can ) |               |\t  Date      \t|           Date    |                      \n";
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________| \n";
            for (int i = 0; i < arr_for[5]; i++)
            {
                cout << "|  " << Drinks[i].Code << " \t|\t" << Drinks[i].Name << "\t|\t" << Drinks[i].Price << "\t|\t" << Drinks[i].Quantity << "\t|\t" << Drinks[i].Proddate << "\t|\t" << Drinks[i].Expiredate << "   |\n";
                cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |  \n";
            }
            cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|\n\n";
        }
        else
        {
            cout << "\033[31m\nInvalid Value! :(\033[0m\n";
            cout << "\033[36mRe-enter your choice\033[0m\n\n";
            Buyer();
        }
    p:
        cout << "\n";
        cout << "1)\033[4m Buying product\033[0m   \n\n";
        cout << "2)\033[4m Different Category\033[0m \n\n";
        cout << "\033[36mEnter choice:\033[0m ";
        cin >> order;
        cin.ignore();
        if (order == "2")
        {
            Buyer();
        }
        else if (order == "1")
        {
            cout << "\n";
            buy(choice);
        x:
            cout << "\n";
            cout << " 1)\033[4m Buying another product\033[0m \n\n";
            cout << " 2)\033[4m Different Category\033[0m     \n\n";
            cout << " 3)\033[4m View your cart\033[0m         \n\n";
            cout << " 4)\033[4m Want to the invoice\033[0m    \n\n";
            cout << "\033[36mEnter choice:\033[0m ";
            cin >> choicex;
            cin.ignore();
            if (choicex == "2")
            {
                Buyer();
            }
            else if (choicex == "1")
            {
                buy(choice);
                goto x;
            }
            else if (choicex == "3")
            {
                view();
                choose();

            }
            else if (choicex == "4")
            {
                view();
                totalprice();
                logout();

            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto x;
            }
        }
        else
        {
            cout << "\033[31m\nInvalid Value! :(\033[0m\n";
            cout << "\033[36mRe-enter your choice\033[0m\n\n";
            goto p;

        }
    }
    else if (choice1 == "2")
    {
    X:
        cout << "\n";
        cout << "\033[36m1)\033[4m View Profile\033[0m\033[0m     \n\n";
        cout << "\033[33m2)\033[4m Supermarket Menu\033[0m\033[0m \n\n";
        cout << "\033[31m3)\033[4m Back\033[0m\033[0m\n\n";
        cout << "\033[36mEnter choice:\033[0m ";
        cin >> choice3;
        cin.ignore();
        if (choice3 == "1")
        {
            profile();
        }
        else if (choice3 == "2")
        {
            Buyer();
        }
        else if (choice3 == "3")
        {
        P:
            cout << "\n";
            cout << "\033[33m -------------------------------------------------------------------------\033[0m \n\n";
            cout << "\033[36m1)\033[4m Log in\033[0m\033[0m  \n\n";
            cout << "\033[33m2)\033[4m Sign up\033[0m \n\n\033[0m";
            cout << "\033[31m3)\033[4m Exit\033[0m\033[0m    \n\n";
            cout << "\033[36mEnter choice:\033[0m ";
            cin >> choice2;
            cin.ignore();
            if (choice2 == "1")
            {
                login();
            }
            else if (choice2 == "2")
            {
                sign();
                login();
            }
            else if (choice2 == "3")
            {
                menu();
            }
            else
            {
                cout << "\033[31m\nInvalid Value! :(\033[0m\n";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto P;
            }
        }
        else
        {
            cout << "\033[31m\nInvalid Value! :(\033[0m\n";
            cout << "\033[36mRe-enter your choice\033[0m\n\n";
            goto X;
        }
    }
    else
    {
        cout << "\033[31m\nInvalid Value! :(\033[0m\n";
        cout << "\033[36mRe-enter your choice\033[0m\n\n";
        goto R;
    }
}
void buy(string choice)   //--> Buying the products.
{
    bool test = false;
x:
    cout << "\n";
    cout << "\033[36mEnter code of the product you want to buy:\033[0m\n";
    cin >> code;
    cin.ignore();
    if (choice == "1")
    {
    t:
        for (int i = 0; i < arr_for[0]; i++)
        {
            if (code == Fruits_Vegtables[i].Code)
            {
                test = true;
                order.code[z] = Fruits_Vegtables[i].Code;
                order.list[z] = Fruits_Vegtables[i].Name;
                order.price[z] = Fruits_Vegtables[i].Price;
                order.Proddate[z] = Fruits_Vegtables[i].Proddate;
                order.Expiredate[z] = Fruits_Vegtables[i].Expiredate;
                cout << "\033[36mPlease enter the quantity you want:\033[0m\n";
            a:
                cin >> order.quantity[z];
                if (order.quantity[z] > Fruits_Vegtables[i].Quantity || order.quantity[z] <= 0)
                {
                    cout << "\033[31mThe quantity you want is not available :(\033[0m\n\n";
                    cout << "\033[36mEnter the quantity from the given quantities:\033[0m\n ";
                    goto a;
                }
                Fruits_Vegtables[i].Quantity -= order.quantity[z];
                z++;
            }
        }
        if (test == false)
        {
            string choice;
            cout << "\033[31mThe product you want is not available :(\033[0m\n\n";
        A:
            cout << "\n";
            cout << " 1)\033[4m Buying from this category\033[0m\n\n";
            cout << " 2)\033[4m Buying from different category\033[0m\n\n";
            cout << "\033[36mEnter choice:\033[0m ";
            cin >> choice;
            cin.ignore();
            if (choice == "1")
            {
                goto x;
            }
            else if (choice == "2")
            {
                Buyer();
            }
            else {
                cout << "\n\033[31mInvalid Value! :( \033[0m  \n";
                cout << "\033[36mRe-enter your choice\n\n\033[0m";
                goto A;

            }
        }
    }
    else if (choice == "2")
    {
        for (int i = 0; i < arr_for[1]; i++)
        {
            if (code == Meat[i].Code)
            {
                test = true;
                order.code[z] = Meat[i].Code;
                order.list[z] = Meat[i].Name;
                order.price[z] = Meat[i].Price;
                order.Proddate[z] = Meat[i].Proddate;
                order.Expiredate[z] = Meat[i].Expiredate;
                cout << "\033[36mPlease enter the quantity you want:\033[0m\n";
            b:
                cin >> order.quantity[z];
                if (order.quantity[z] > Meat[i].Quantity || order.quantity[z] <= 0)
                {
                    cout << "\033[31mThe quantity you want is not available :(\033[0m\n\n";
                    cout << "\033[36mEnter the quantity from the given quantities:\033[0m\n ";
                    goto b;
                }
                Meat[i].Quantity -= order.quantity[z];
                z++;
            }
        }
        if (test == false)
        {
            string choice;
            cout << "\033[31mThe product you want is not available :(\033[0m\n\n";
        B:
            cout << "\n";
            cout << " 1)\033[4m Buying from this category\033[0m\n\n";
            cout << " 2)\033[4m Buying from different category\033[0m\n\n";
            cout << "\033[36mEnter choice:\033[0m ";
            cin >> choice;
            cin.ignore();
            if (choice == "1")
            {
                goto x;
            }
            else if (choice == "2")
            {
                Buyer();
            }
            else
            {
                cout << "\n\033[31mInvalid Value! :( \033[0m  \n";
                cout << "\033[36mRe-enter your choice\n\n\033[0m";
                goto B;

            }
        }
    }
    else if (choice == "3")
    {
        for (int i = 0; i < arr_for[2]; i++)
        {
            if (code == Poultry[i].Code)
            {
                test = true;
                order.code[z] = Poultry[i].Code;
                order.list[z] = Poultry[i].Name;
                order.price[z] = Poultry[i].Price;
                order.Proddate[z] = Poultry[i].Proddate;
                order.Expiredate[z] = Poultry[i].Expiredate;
                cout << "\033[36mPlease enter the quantity you want:\033[0m\n";
            c:
                cin >> order.quantity[z];
                if (order.quantity[z] > Poultry[i].Quantity || order.quantity[z] <= 0)
                {
                    cout << "\033[31mThe quantity you want is not available :(\033[0m\n\n";
                    cout << "\033[36mEnter the quantity from the given quantities:\033[0m\n ";
                    goto c;
                }
                Poultry[i].Quantity -= order.quantity[z];
                z++;
            }
        }
        if (test == false)
        {
            string choice;
            cout << "\033[31mThe product you want is not available :(\033[0m\n\n";
        C:
            cout << "\n";
            cout << " 1)\033[4m Buying from this category\033[0m\n\n";
            cout << " 2)\033[4m Buying from different category\033[0m\n\n";
            cout << "\033[36mEnter choice:\033[0m ";
            cin >> choice;
            cin.ignore();
            if (choice == "1")
            {
                goto x;
            }
            else if (choice == "2")
            {
                Buyer();
            }
            else
            {
                cout << "\n\033[31mInvalid Value! :( \033[0m  \n";
                cout << "\033[36mRe-enter your choice\n\n\033[0m";
                goto C;
            }
        }
    }
    else if (choice == "4")
    {
        for (int i = 0; i < arr_for[3]; i++)
        {
            if (code == Canned_Food[i].Code)
            {
                test = true;
                order.code[z] = Canned_Food[i].Code;
                order.list[z] = Canned_Food[i].Name;
                order.price[z] = Canned_Food[i].Price;
                order.Proddate[z] = Canned_Food[i].Proddate;
                order.Expiredate[z] = Canned_Food[i].Expiredate;
                cout << "\033[36mPlease enter the quantity you want:\033[0m\n";
            d:
                cin >> order.quantity[z];
                if (order.quantity[z] > Canned_Food[i].Quantity || order.quantity[z] <= 0)
                {
                    cout << "\033[31mThe quantity you want is not available :(\033[0m\n\n";
                    cout << "\033[36mEnter the quantity from the given quantities:\033[0m\n ";
                    goto d;
                }
                Canned_Food[i].Quantity -= order.quantity[z];
                z++;
            }
        }
        if (test == false)
        {
            string choice;
            cout << "\033[31mThe product you want is not available :(\033[0m\n\n";
        D:
            cout << "\n";
            cout << " 1)\033[4m Buying from this category\033[0m\n\n";
            cout << " 2)\033[4m Buying from different category\033[0m\n\n";
            cout << "\033[36mEnter choice:\033[0m ";
            cin >> choice;
            cin.ignore();
            if (choice == "1")
            {
                goto x;
            }
            else if (choice == "2")
            {
                Buyer();
            }
            else
            {
                cout << "\n\033[31mInvalid Value! :( \033[0m  \n";
                cout << "\033[36mRe-enter your choice\n\n\033[0m";
                goto D;
            }
        }
    }
    else if (choice == "5")
    {
        for (int i = 0; i < arr_for[4]; i++)
        {
            if (code == Food_Legumes[i].Code)
            {
                test = true;
                order.code[z] = Food_Legumes[i].Code;
                order.list[z] = Food_Legumes[i].Name;
                order.price[z] = Food_Legumes[i].Price;
                order.Proddate[z] = Food_Legumes[i].Proddate;
                order.Expiredate[z] = Food_Legumes[i].Expiredate;
                cout << "\033[36mPlease enter the quantity you want:\033[0m\n";
            e:
                cin >> order.quantity[z];
                if (order.quantity[z] > Food_Legumes[i].Quantity || order.quantity[z] <= 0)
                {
                    cout << "\033[31mThe quantity you want is not available :(\033[0m\n\n";
                    cout << "\033[36mEnter the quantity from the given quantities:\033[0m\n ";
                    goto e;
                }
                Food_Legumes[i].Quantity -= order.quantity[z];
                z++;
            }
        }
        if (test == false)
        {
            string choice;
            cout << "\033[31mThe product you want is not available :(\033[0m\n\n";
        E:
            cout << "\n";
            cout << " 1)\033[4m Buying from this category\033[0m\n\n";
            cout << " 2)\033[4m Buying from different category\033[0m\n\n";
            cout << "\033[36mEnter choice:\033[0m ";
            cin >> choice;
            cin.ignore();
            if (choice == "1")
            {
                goto x;
            }
            else if (choice == "2")
            {
                Buyer();
            }
            else
            {
                cout << "\n\033[31mInvalid Value! :( \033[0m  \n";
                cout << "\033[36mRe-enter your choice\n\n\033[0m";
                goto E;
            }
        }
    }
    else if (choice == "6")
    {
        for (int i = 0; i < arr_for[5]; i++)
        {
            if (code == Drinks[i].Code)
            {
                test = true;
                order.code[z] = Drinks[i].Code;
                order.list[z] = Drinks[i].Name;
                order.price[z] = Drinks[i].Price;
                order.Proddate[z] = Drinks[i].Proddate;
                order.Expiredate[z] = Drinks[i].Expiredate;
                cout << "\033[36mPlease enter the quantity you want:\033[0m\n";
            f:
                cin >> order.quantity[z]; cout << "  Can\n";
                if (order.quantity[z] > Drinks[i].Quantity || order.quantity[z] <= 0)
                {
                    cout << "\033[31mThe quantity you want is not available :(\033[0m\n\n";
                    cout << "\033[36mEnter the quantity from the given quantities:\033[0m\n ";
                    goto f;
                }
                Drinks[i].Quantity -= order.quantity[z];
                z++;
            }
        }
        if (test == false)
        {
            string choice;
            cout << "\033[31mThe product you want is not available :(\033[0m\n\n";
        F:
            cout << "\n";
            cout << " 1)\033[4m Buying from this category\033[0m\n\n";
            cout << " 2)\033[4m Buying from different category\033[0m\n\n";
            cout << "\033[36mEnter choice:\033[0m ";
            cin >> choice;
            if (choice == "1")
            {
                goto x;
            }
            else if (choice == "2")
            {
                Buyer();
            }
            else
            {
                cout << "\n\033[31mInvalid Value! :( \033[0m  \n";
                cout << "\033[36mRe-enter your choice\n\n\033[0m";
                goto F;
            }
        }
    }
    cout << "\n\033[33m \033[4mThe products has been added to the cart :)\033[0m\033[0m \n\n";
}
void view()   //--> Displing order.
{
    order.id = u1[numOFuser].id;
    cout << "\n\t\t\t\t\033[36m****************** Your ID : " << order.id << "*****************\033[0m\n";
    cout << "_______________________________________________________________________________________________________________________________\n";
    cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   | \t  Total       |          \n";
    cout << "|       |   \t\t\t|               |               |\t  Date      \t|           Date    |      (L.E)      |                    \n";
    cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|_________________|\n";
    for (int i = 0; i < z; i++)
    {
        order.Total = order.quantity[i] * order.price[i];
        cout << "|  " << order.code[i] << " \t|\t" << order.list[i] << "\t|\t" << order.price[i] << "\t|\t" << order.quantity[i] << "\t|\t" << order.Proddate[i] << "\t|\t" << order.Expiredate[i] << "   | " << order.Total << "\t      |\n";
        cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |\t\t      |\n";
        order.Total = 0;
    }
    cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|_________________|\n\n";
}
void totalprice()  //--> Calculating total price for order.
{
    order.totalprice = 0;
    for (int i = 0; i < z; i++)
    {

        order.totalprice += order.price[i] * order.quantity[i];
    }
    cout << "\n\n";
    cout << "\033[36mThe total price of your order =  \033[0m" << order.totalprice << "  L.E" << "\n";
    cout << "\t\t\t\t\033[33m*************\033[0m\n";
    if (order.totalprice >= 2000)
    {
        if (order.totalprice >= 6000) {
            cout << "\033[33m\n****** Your order exceeds 6000 L.E , we have a gift for you ******\033[0m\n";
            gift();
        }
        else {
            discount();
        }
    }
    cout << "\033[33m-----------------------------------------------------------------------------------------\033[0m\n\n\n";
    orders.open("log2.txt", ios::app | ios::out);

    for (int i = 0; i < z; i++) {
        orders << order.code[i] << "\t" << order.list[i] << "\t" << order.price[i] << "\t" << order.quantity[i] << "\t" << order.Proddate[i] << "\t" << order.Expiredate[i] << "\n";

    }

    orders.close();
    z = 0;
    logout();
}
void remove()  //--> Removing any products in order.
{
    cout << "Enter the code of the product you want to remove:\n";
    cin >> code;
    cin.ignore();
    for (int i = 0; i < z; i++)
    {
        if (code == order.code[i])
        {
            modifycheck = true;
            for (int k = 0; k < arr_for[0]; k++)
            {
                if (code == Fruits_Vegtables[k].Code)
                    Fruits_Vegtables[k].Quantity += order.quantity[i];
            }
            for (int k = 0; k < arr_for[1]; k++)
            {
                if (code == Meat[k].Code)
                    Meat[k].Quantity += order.quantity[i];
            }
            for (int k = 0; k < arr_for[2]; k++)
            {
                if (code == Poultry[k].Code)
                    Poultry[k].Quantity += order.quantity[i];
            }
            for (int k = 0; k < arr_for[3]; k++)
            {
                if (code == Canned_Food[k].Code)
                    Canned_Food[k].Quantity += order.quantity[i];
            }
            for (int k = 0; k < arr_for[4]; k++)
            {
                if (code == Food_Legumes[k].Code)
                    Food_Legumes[k].Quantity += order.quantity[i];
            }
            for (int k = 0; k < arr_for[5]; k++)
            {
                if (code == Drinks[k].Code)
                    Drinks[k].Quantity += order.quantity[i];
            }
            for (int j = i; j < z; j++)
            {
                order.code[j] = order.code[j + 1];
                order.list[j] = order.list[j + 1];
                order.price[j] = order.price[j + 1];
                order.quantity[j] = order.quantity[j + 1];
            }
            z--;
            break;
        }
        else
        {
            modifycheck = false;
        }


    }
    if (modifycheck == false)
    {
        cout << "\nInvalid Value :(\n\n";
        remove();
    }

}
void choose()  //--> Choosing any products in order to modify it.
{
    cout << " 1)\033[4m Adding products to your cart\033[0m\n\n";
    cout << " 2)\033[4m Removing products from your cart\033[0m\n\n";
    cout << " 3)\033[4m Changing quantity of any product in your cart\033[0m\n\n";
    cout << " 4)\033[4m View total price\033[0m\n\n";
    cout << "\033[36mEnter choice:\033[0m ";
    cin >> choicey;
    cin.ignore();
    if (choicey == "1")
    {
        Buyer();
    }
    else if (choicey == "2")
    {
        remove();
        view();
        choose();
    }
    else if (choicey == "3")
    {
        change();
        view();
        choose();
    }
    else if (choicey == "4")
    {
        totalprice();

    }
    else
    {
        cout << "\n\033[31mInvalid Value! :( \033[0m  \n";
        cout << "\033[36mRe-enter your choice\n\n\033[0m";
        choose();
    }
}
void change()  //--> Changing the quantity of the products in order.
{
    cout << "Enter the code of the product you want to change its quantity:\n";
    cin >> code;
    for (int i = 0; i < z; i++)
    {
        if (code == order.code[i])
        {
            modifycheck = true;
            for (int k = 0; k < arr_for[0]; k++)
            {
                if (code == Fruits_Vegtables[k].Code)
                    Fruits_Vegtables[k].Quantity += order.quantity[i];
            }
            for (int k = 0; k < arr_for[1]; k++)
            {
                if (code == Meat[k].Code)
                    Meat[k].Quantity += order.quantity[i];
            }
            for (int k = 0; k < arr_for[2]; k++)
            {
                if (code == Poultry[k].Code)
                    Poultry[k].Quantity += order.quantity[i];
            }
            for (int k = 0; k < arr_for[3]; k++)
            {
                if (code == Canned_Food[k].Code)
                    Canned_Food[k].Quantity += order.quantity[i];
            }
            for (int k = 0; k < arr_for[4]; k++)
            {
                if (code == Food_Legumes[k].Code)
                    Food_Legumes[k].Quantity += order.quantity[i];
            }
            for (int k = 0; k < arr_for[5]; k++)
            {
                if (code == Drinks[k].Code)
                    Drinks[k].Quantity += order.quantity[i];
            }
        h:
            cout << "Enter the new quantity:\n";
            cin >> order.quantity[i];
            cin.ignore();
            for (int l = 0; l < arr_for[0]; l++)
            {
                if (code == Fruits_Vegtables[l].Code)
                {
                    if (order.quantity[i] > Fruits_Vegtables[l].Quantity || order.quantity[i] <= 0)
                    {
                        cout << "The quantity you want is not available :(\n";
                        goto h;
                    }
                    Fruits_Vegtables[l].Quantity -= order.quantity[i];
                }
            }
            for (int l = 0; l < arr_for[1]; l++)
            {
                if (code == Meat[l].Code)
                {
                    if (order.quantity[i] > Meat[l].Quantity || order.quantity[i] <= 0)
                    {
                        cout << "The quantity you want is not available :(\n";
                        goto h;
                    }
                    Meat[l].Quantity -= order.quantity[i];
                }
            }
            for (int l = 0; l < arr_for[2]; l++)
            {
                if (code == Poultry[l].Code)
                {
                    if (order.quantity[i] > Poultry[l].Quantity || order.quantity[i] <= 0)
                    {
                        cout << "The quantity you want is not available :(\n";
                        goto h;
                    }
                    Poultry[l].Quantity -= order.quantity[i];
                }
            }
            for (int l = 0; l < arr_for[3]; l++)
            {
                if (code == Canned_Food[l].Code)
                {
                    if (order.quantity[i] > Canned_Food[l].Quantity || order.quantity[i] <= 0)
                    {
                        cout << "The quantity you want is not available :(\n";
                        goto h;
                    }
                    Canned_Food[l].Quantity -= order.quantity[i];
                }
            }
            for (int l = 0; l < arr_for[4]; l++)
            {
                if (code == Food_Legumes[l].Code)
                {
                    if (order.quantity[i] > Food_Legumes[l].Quantity || order.quantity[i] <= 0)
                    {
                        cout << "The quantity you want is not available :(\n";
                        goto h;
                    }
                    Food_Legumes[l].Quantity -= order.quantity[i];
                }
            }
            for (int l = 0; l < arr_for[5]; l++)
            {
                if (code == Drinks[l].Code)
                {
                    if (order.quantity[i] > Drinks[l].Quantity || order.quantity[i] <= 0)
                    {
                        cout << "The quantity you want is not available :(\n";
                        goto h;
                    }
                    Drinks[l].Quantity -= order.quantity[i];
                }
            }
            break;
        }
        else
        {
            modifycheck = false;
        }
    }
    if (modifycheck == false)
    {
        cout << "\nInvalid Value :(\n\n";
        change();
    }

}
void logout()  //--> Log out.
{
    string choice, choice1, ans;
y:
    cout << "\n\033[36mDo you want any other process ?\033[0m (\033[32mY\033[0m/\033[31mN\033[0m)\n";
    cin >> ans;
    if (ans == "y" || ans == "Y" || ans == "Yes" || ans == "yes" || ans == "YES")
    {
    Y:
        cout << "\n-------------------------------------------------------------------------\n\n";
        cout << "\033[36m 1)\033[4m View Profile\033[0m\033[0m    \n\n";
        cout << "\033[33m 2)\033[4m Supermarket Menu\033[0m\033[0m\n\n";
        cout << "\033[31m 3)\033[4m Exit\033[0m \033[0m           \n\n";
        cout << "\033[36mEnter choice:\033[0m ";
        cin >> choice;
        cin.ignore();
        if (choice == "1")
        {
            cout << "\n";
            profile();
        }
        else if (choice == "2")
        {
            Buyer();
        }
        else if (choice == "3")
        {
            cout << "\n\n\n\n";
            cout << "\t\t\t\t\033[33m    ########  ##    ##   ######   ####    ##  ##   ##     ##    ##     ##     ##    ## \n";
            cout << "\t\t\t\t       ##     ##    ##  ##    ##  ## ##   ##  ##  ##       ##  ##    ##  ##   ##    ## \n";
            cout << "\t\t\t\t       ##     ########  ########  ##  ##  ##  ## #           ##     ##    ##  ##    ## \n";
            cout << "\t\t\t\t       ##     ##    ##  ##    ##  ##   ## ##  ##  ##         ##      ##  ##    ##  ##  \n";
            cout << "\t\t\t\t       ##     ##    ##  ##    ##  ##    ####  ##   ##        ##        ##        ##    \n";
            cout << "\n\t\t\t\t\tfor using our supermarket :)\033[0m\n\n ";
            cout << "\t\t\t\t\033[36m  ----------------------------------------------------------------------------------------\033[0m\n\n\n";
        G:
            cout << "\033[31m1) \033[4mExit this window\033[0m\033[0m\n\n";
            cout << "\033[33m2) \033[4mHomepage\033[0m\033[0m        \n\n";
            cout << "\033[36m3) \033[4mCredits\033[0m\033[0m \n\n";
            cout << "\033[36mEnter choice:\033[0m  ";
            cin >> choice1;
            if (choice1 == "1")
            {
                cout << "\n\033[36mPress --> \033[4mEnter\033[0m\033[0m\n";
                exit(0);
            }
            else if (choice1 == "2")
            {
                cout << "\n\t\t\t\t\033[36m  ----------------------------------------------------------------------------------------\033[0m\n\n\n";
                menu();
            }
            else if (choice1 == "3")
            {
                cout << "\n\t\t\t\t\033[36m  ----------------------------------------------------------------------------------------\033[0m\n\n\n";
                credit();
            }
            else
            {
                cout << "\n\033[31mInvalid Value! :( \033[0m  \n";
                cout << "\033[36mRe-enter your choice\n\n\033[0m";
                goto G;
            }

        }
        else
        {
            cout << "\n\033[31mInvalid Value! :( \033[0m  \n";
            cout << "\033[36mRe-enter your choice\n\n\033[0m";
            goto Y;
        }

    }
    else if (ans == "n" || ans == "N" || ans == "No" || ans == "no" || ans == "NO")
    {
        cout << "\n\n\n\n";
        cout << "\t\t\t\t\033[33m    ########  ##    ##   ######   ####    ##  ##   ##     ##    ##     ##     ##    ## \n";
        cout << "\t\t\t\t       ##     ##    ##  ##    ##  ## ##   ##  ##  ##       ##  ##    ##  ##   ##    ## \n";
        cout << "\t\t\t\t       ##     ########  ########  ##  ##  ##  ## #           ##     ##    ##  ##    ## \n";
        cout << "\t\t\t\t       ##     ##    ##  ##    ##  ##   ## ##  ##  ##         ##      ##  ##    ##  ##  \n";
        cout << "\t\t\t\t       ##     ##    ##  ##    ##  ##    ####  ##   ##        ##        ##        ##    \n";
        cout << "\n\t\t\t\t\tfor using our supermarket :)\033[0m\n\n ";
        cout << "\t\t\t\t\033[36m  ----------------------------------------------------------------------------------------\033[0m\n\n\n";
        cout << "\033[31m1) \033[4mExit this window\033[0m\033[0m\n\n";
        cout << "\033[33m2) \033[4mHomepage\033[0m\033[0m        \n\n";
        cout << "\033[36m3) \033[4mCredits\033[0m\033[0m \n\n";
        cout << "\033[36mEnter choice:\033[0m  ";
        cin >> choice1;
        if (choice1 == "1")
        {
            cout << "\n\033[36mPress --> \033[4mEnter\033[0m\033[0m\n";
            exit(0);
        }
        else if (choice1 == "2")
        {
            cout << "\n\t\t\t\t\033[36m  ----------------------------------------------------------------------------------------\033[0m\n\n\n";
            menu();
        }
        else if (choice1 == "3")
        {
            cout << "\n\t\t\t\t\033[36m  ----------------------------------------------------------------------------------------\033[0m\n\n\n";
            credit();
        }
        else
        {
            cout << "\n\033[31mInvalid Value! :( \033[0m  \n";
            cout << "\033[36mRe-enter your choice\n\n\033[0m";
            goto G;
        }
    }
    else
    {
        cout << "\n\033[31mInvalid Value! :( \033[0m  \n";
        cout << "\033[36mRe-enter your choice\n\n\033[0m";
        goto y;
    }


}
void discount()
{
    cout << "\n\033[33mYour order exceeds 2000 L.E \n\n \t\t*** we have a 10% discount for you ***\033[0m\n";
    order.totalprice -= order.totalprice * 0.1;      //10% discount 
    cout << "\033[36m Total price after disscount=\033[0m " << order.totalprice << "\033[36m  L.E\033[0m" << endl;
}
void gift()
{
    string n_gift;
    bool checkextra = false;
    int zgift;
    cout << "\t\033[33m    ________         _________       _________        _________       __________     \n";
    cout << "\t   |    #   |       |   ###   |     |  ###    |      |  #   #  |     |   #####  |    \n";
    cout << "\t   |  # #   |       |  #   #  |     |     #   |      |  #   #  |     |   #      |    \n";
    cout << "\t   |    #   |       |     #   |     |   ##    |      |  #####  |     |   #####  |    \n";
    cout << "\t   |    #   |       |   #     |     |     #   |      |      #  |     |       #  |    \n";
    cout << "\t   |  ##### |       |  #####  |     |  ###    |      |      #  |     |   #####  |    \n";
    cout << "\t   |________|       |_________|     |_________|      |_________|     |__________|\033[0m    \n\n";
y:
    cout << "\033[36mplease choose your gift  >>>>> enter gift number:\033[0m  ";
    cin >> n_gift;

    if (n_gift == "1")
    {
        cout << "\t\033[33m  ___________  \n    ";
        cout << "\t |           | \n    ";
        cout << "\t |   5879    |        This is your gift code >>> Keep it to recieve yor gift \n";
        cout << "\t |___________|\033[0m \n    ";
    }
    else if (n_gift == "2")
    {
        cout << "\t\033[33m  ___________  \n    ";
        cout << "\t |           | \n    ";
        cout << "\t |   2456    |        This is your gift code >>> Keep it to recieve yor gift \n";
        cout << "\t |___________|\033[0m \n    ";
    }
    else if (n_gift == "3")
    {
        cout << "\t\033[33m  ___________  \n    ";
        cout << "\t |           | \n    ";
        cout << "\t |   3274    |        This is your gift code >>> Keep it to recieve yor gift \n";
        cout << "\t |___________|\033[0m \n    ";
    }
    else if (n_gift == "4")
    {
        cout << "\t\033[33m  ___________  \n    ";
        cout << "\t |           | \n    ";
        cout << "\t |   4589    |        This is your gift code >>> Keep it to recieve yor gift \n";
        cout << "\t |___________|\033[0m \n    ";
    }
    else if (n_gift == "5")
    {
        cout << "\t \033[33m ___________  \n    ";
        cout << "\t |           | \n    ";
        cout << "\t |   8733    |        This is your gift code >>> Keep it to recieve yor gift\033[0m \n";
        cout << "\t |___________| \n\033[0m    ";
    }
    else
    {
        cout << "\033[31minvalid number!\033[0m\n";
        goto y;
    }
    string giftcode, extra;
    cout << "\033[36mNow enter your gift code to recieve your gift:\033[0m ";
z:
    cin >> giftcode;
    if (giftcode == "5879")
    {
        cout << "\n\033[33m*****************************************\n";
        cout << "\n* Your gift is 500 L.E discount coupon  *\n";
        cout << "\n*****************************************\033[0m\n";
        order.totalprice -= 500;                                            //500 LE
        view();
        cout << "\033[36m Total price after disscount=\033[0m " << order.totalprice << "  L.E" << endl;
    }
    else if (giftcode == "2456")
    {
        cout << "\n\033[33m********************************************\n";
        cout << "\n* Your gift is 30% disscount on your order *\n";
        cout << "\n********************************************\033[0m\n";
        order.totalprice -= order.totalprice * 0.3;                        //30% discount    
        view();
        cout << "\033[36m Total price after disscount=\033[0m " << order.totalprice << "  L.E" << endl;
    }
    else if (giftcode == "3274")
    {
        cout << "\n\033[33m***********************************************\n";
        cout << "\n* Your gift is 2 bottle of pepsi(1L) for free *\n";
        cout << "\n***********************************************\033[0m\n";   //2 bottle of pipse(1L)
        view();
        cout << "\033[36m\t\t\t\t     Your Gift\033[0m\n";
        cout << "\033[36m\t\t\t\t   **************\033[0m\n";
        cout << "\033[33m_______________________________________________________________________________________________________________________________\033[0m\n";
        cout << "\033[33m|  " << Drinks[8].Code << " \t|\t" << Drinks[8].Name << "\t|\t" << "Free" << "\t|\t" << "2" << "\t|\t" << Drinks[8].Proddate << "\t|\t" << Drinks[8].Expiredate << "   | " << "--------" << "\t      |\n";
        cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |\t\t      |\n";
        cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|_________________|\033[0m\n\n";
        cout << "\033[36m Total price =\033[0m " << order.totalprice << "  L.E" << endl;
    }

    
    else if (giftcode == "4589")
    {
        cout << "\n\033[33m*****************************************\n";
        cout << "\n*          Free home delivery           *\n";
        cout << "\n*****************************************\033[0m\n";       //Free home delivery
        view();
        cout << "\033[36m Total price = \033[0m" << order.totalprice << "  L.E" << endl;
    }
    else if (giftcode == "8733")
    {
        cout << "\n\033[33m*****************************************\n";
        cout << "\n* Your gift is 1000 L.E discount coupon *\n";
        cout << "\n*****************************************\033[0m\n";
        order.totalprice -= 1000;                                         //1000 L.E
        view();
        cout << "\033[36m Total price after disscount=\033[0m " << order.totalprice << "  L.E\n\n";
    }
    else
    {
        cout << "\033[31mWrong code!!\033[0m\n";
        cout << "\033[36mPlease enter code again : \033[0m\n\n";
        goto z;
    }
}
void view_orders()
{
    string choice;
    double total = 0,Totalf;

    cout << "_______________________________________________________________________________________________________________________________\n";
    cout << "| Code\t|\t Name\t\t|    Price(L.E)\t|    Quantity\t|    Production\t        |         Expired   | \t  Total       |          \n";
    cout << "|       |   \t\t\t|               |               |\t  Date      \t|           Date    |      (L.E)      |                    \n";
    cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|_________________|\n";
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            Totalf = orders_a[i].price[j] * orders_a[i].quantity[j];
            if (orders_a[i].price[j] == 0)
                break;
            cout << "|  " << orders_a[i].code[j] << " \t|\t" << orders_a[i].list[j] << "\t|\t" << orders_a[i].price[j] << "\t|\t" << orders_a[i].quantity[j] << "\t|\t" << orders_a[i].Proddate[j] << "\t|\t" << orders_a[i].Expiredate[j] << "   | " << Totalf << "\t      |\n";
            cout << "|\t|  \t\t\t|\t\t|\t\t|\t\t\t|\t\t    |\t\t      |\n";
            
            total += order.totalprice;
            Totalf = 0;
            
        }

        if (orders_a[i].totalprice == 0)
            break;
    }
    cout << "|_______|_______________________|_______________|_______________|_______________________|___________________|_________________|\n\n";
t1:
    cout << "\033[36m1)\033[4m Total Price\033[0m\033[0m\n\n";
    cout << "\033[31m2)\033[4m Exit\033[0m\033[0m\n\n";
    cout << "\033[36mEnter Choice:\033[0m";
    cin >> choice;
    if (choice == "1")
    {
        cout << "\n\033[36mTotal price of all orders that have been sold =  \033[0m" << total << "  L.E\n\n";
        cout << "\033[33m-----------------------------------------------------------------------------------------\033[0m\n\n";
        admin();
    }
    else if (choice == "2")
    {
        cout << "\033[33m-----------------------------------------------------------------------------------------\033[0m\n\n";
        admin();
    }
    else
    {
        cout << "\n\033[31mInvalid Value!!\033[0m\n";
        cout << "\033[36mRe-enter your choice\033[0m\n\n";
        goto t1;
    }


}
void credit()
{
    string ch;
    vector<string> developerNames = { "\n\n\t\t\033[42mMostafa Ahmed\033[0m\n\n", "\t\t\033[42mMostafa Amr\033[0m\n\n", "\t\t\033[42mMostafa Al-Sharkawy\033[0m\n\n", "\t\t\033[42mMostafa Adel\033[0m\n\n","\t\t\033[42mMenna Hassaneen\033[0m\n\n","\t\t\033[42mMenna khaled\033[0m\n\n","\t\t\033[42mhussien El-shahat\033[0m\n\n" };

    while (true)
    {
        for (const auto& name : developerNames)
        {
            cout << name;
            this_thread::sleep_for(chrono::milliseconds(1000));

            if (name == developerNames.back())
            {
                break;
            }
        }

        cout << "\033[36m Press\n1)\033[31m\033[4m Back\033[0m\033[0m\033[0m\n\n";
    kk:
        cin >> ch;
        if (ch == "1")
        {
        cc:
            char choice1;
            cout << "\n\033[31m1) \033[4mExit this window\033[0m\033[0m\n\n";
            cout << "\033[33m2) \033[4mHomepage\033[0m\033[0m        \n\n";
            cout << "\033[36m3) \033[4mCredits\033[0m\033[0m \n\n";
            cout << "\033[36mEnter choice: \033[0m";
            cin >> choice1;
            if (choice1 == '1')
            {
                cout << "\n\033[36mPress -->\033[4m Enter\033[0m\033[0m\n";
                exit(0);
            }
            else if (choice1 == '2')
            {
                cout << "\n\t\t\t\t\033[36m  ----------------------------------------------------------------------------------------\033[0m\n\n\n";
                menu();
            }
            else if (choice1 == '3')
            {

                cout << "\n\t\t\t\t\033[36m  ----------------------------------------------------------------------------------------\033[0m\n\n\n";
                credit();
            }
            else
            {
                cout << "\033[31m\nInvalid Value!!\n\033[0m";
                cout << "\033[36mRe-enter your choice\033[0m\n\n";
                goto cc;
            }
        }
        else
        {
            cout << "\033[31minvaild number\033[0m\n\n";
            cout << "\033[36m Press\n1)\033[31m\033[4m Back\033[0m\033[0m\033[0m\n\n";
            goto kk;
        }
    }
}