#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
class shopping
{
private:
    int product_code;
    float product_price;
    float discount;
    string product_name;

public:
    void menu();
    void administration();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void reciept();
};

void shopping::menu()
{
m:
    int choice;
    string email, password;
    cout << "\t\t\t\t_______________________________________________\n";
    cout << "\t\t\t\t                                               \n";
    cout << "\t\t\t\t          Supermarket main menu                \n";
    cout << "\t\t\t\t                                               \n";
    cout << "\t\t\t\t _______________________________________________\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|            1). Admistration                   |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|            2). Buyer                          |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|            3). Exit                           |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|            Plesase select                     |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t _______________________________________________\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\t\t\t\t              Please login                       \n";
        cout << "\t\t\t\t              Enter Email :\n";
        cout << "\t\t\t\t              Enter Password :\n";
        cin >> email >> password;
        if (email == "bhupendra@gmail.com" && password == "password")
        {
            administration();
        }
        else
        {
            cout << "\t\t\t\t         Invalid email/password              \n";
            break;
        }
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout << "\t\t\t\t        Please select a given option          \n";
    }
    }
    goto m;
}

void shopping::administration()
{
m:
    int choice;
    cout << "\t\t\t\t_______________________________________________\n";
    cout << "\t\t\t\t                                               \n";
    cout << "\t\t\t\t          Administration menu                  \n";
    cout << "\t\t\t\t                                               \n";
    cout << "\t\t\t\t _______________________________________________\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|            1). Add the product                |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|            2). Modify the product             |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|            3). Delete the product             |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|            4). Babk to Main Menu              |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t|            Plesase Enter your choice          |\n";
    cout << "\t\t\t\t|                                               |\n";
    cout << "\t\t\t\t _______________________________________________\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "\t\t\t\t             Invalid Choice                      \n";
    }
    goto m;
}
void shopping ::buyer()
{
m:
    int choice;

    cout << "\t\t\t\t                                                  \n";
    cout << "\t\t\t\t                                                  \n";
    cout << "\t\t\t\t             1). Buyer                            \n";
    cout << "                                                           ";
    cout << "\t\t\t\t                Buy product                       \n";
    cout << "\t\t\t\t             2). Go back                          \n";
    cout << "\t\t\t\t             Enter your choice                    \n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        reciept();
        break;
    case 2:
        menu();
    default:
        cout << "\t\t\t\tInvalid Choice!";
    }
    goto m;
}
void shopping ::add()
{
m:
    fstream data;
    int c, token = 0;
    float p, d;
    string n;
    cout << "\n\n\n\t\t Add new product";
    cout << "\n\n\t Product code of the product";
    cin >> product_code;
    cout << "\n\n\t Name of the product ";
    cin >> product_name;
    cout << "\n\n\t Price of the product ";
    cin >> product_price;
    cout << "\n\n\t Discount on product ";
    cin >> discount;
    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << product_code << " " << product_name << " " << product_price << " " << discount << "\n\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == product_code)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
        if (token == 1)
            goto m;
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << product_code << " " << product_name << " " << product_price << " " << discount << "\n\n";
            data.close();
        }
    }
    cout << "\t\tRecord inserted\n";
}

void shopping ::edit()
{
    fstream data, data1;
    int product_key, token = 0, c;
    float p, d;
    string n;
    cout << "\n\n\t\t\t\t Modify the record";
    cout << "\n\t\t\t\t Product code : ";
    cin >> product_key;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t\t\t File does not exist!";
    }
    else
    {
        data1.open("database.txt", ios::app | ios::out);
        data >> product_code >> product_name >> product_price >> discount;
        while (!data.eof())
        {
            if (product_key == product_code)
            {
                cout << "\n\t\t\t\t Product new code :";
                cin >> c;
                cout << "\n\t\t\t\t Name of the product :";
                cin >> product_name;
                cout << "\n\t\t\t\t Price of the product :";
                cin >> p;
                cout << "\n\t\t\t\t Discount on the product:";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << endl;
                cout << "\n\t\t\t\t Record edited ";
                token++;
            }
            else
            {
                data1 << " " << product_code << " " << product_name << " " << product_price << " " << discount << endl;
            }
        }
        data >> product_code >> product_name >> product_price >> discount;
        data.close();
        data1.close();
    }
    remove("database.txt");
    rename("database1.txt", "database.txt");
    if (token == 0)
    {
        cout << "\n\n\t\t\t\t Record not found";
    }
}
void shopping ::rem()
{
    fstream data, data1;
    int pkey, token = 0;
    cout << "\n\n\t\t\t\t Delelte Product ";
    cout << "\n\n\t\t\t\t Product code : ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\t\t\t\tFile does not exist!";
    }
    else
    {
        data1.open("database.txt", ios::app | ios::out);
        data >> product_code >> product_name >> product_price >> discount;
        while (!data.eof())
        {
            if (product_code == pkey)
            {
                cout << "\n\n\t\t\t\t Product delelted sucessfully!";
                token++;
            }
            else
            {
                data1 << " " << product_code << " " << product_name << " " << product_price << " " << discount << endl;
            }
            data >> product_code >> product_name >> product_price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n\t\t\t\t Record not found";
        }
    }
}
void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|_______________________________________________________|";
    cout << "\nProduct Number\t\tName\t\tPrice\n";
    data >> product_code >> product_name >> product_price >> discount;
    while (!data.eof())
    {
        cout << product_code << "\t\t" << product_name << "\t\t" << product_price << endl;
        data >> product_code >> product_name >> product_price >> discount;
    }
    data.close();
}
void shopping ::reciept()
{
    fstream data;
    int arrc[100], arrq[100];
    char choice;
    int c = 0;
    float amount = 0, dis = 0, total = 0;
    cout << "\n\n\t\t\t\t RECIEPT ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t Empty database";
    }

    else
    {
        data.close();
        list();
        cout << "___________________________________________________________";
        cout<<"\n|                                                          |\n";
        cout<<"\n|                Place your order                          |\n";
        cout<<"\n|                                                          |\n";
        cout << "___________________________________________________________";
        do
        {
        m:
        cout<<"\n\n\t\t Enter the Product code : ";
        cin>>arrc[c];
        cout<<"\n\n\t\t Enter the Product quantity : ";
        cin>>arrq[c];
        for (int i = 0; i < c; i++)
        {
            if(arrc[c]==arrc[i]){
                cout<<"\n\n Duplicate Product Code. Please try again";
                goto m;
            }
        }
        c++;
        cout<<"\n\n Do you want to buy another product? If yes then press Y else no ";
        cin>>choice;
        } while (choice=='Y');
      cout<<"\n\n\t\t_______________RECIEPT________________________________\n";
      cout<<"\nProduct number\t Product name\t Product quantity\t Product Price\t Amount with discount\n";
      for (int i = 0; i < c; i++)
      {
        data.open("database.txt",ios::in);
      data>>product_code>>product_name>>product_price>>discount;
      while (!data.eof())
      {
        if(product_code==arrc[i]){
            amount = product_price*arrq[i];
            dis = amount - ((amount)* discount/100);
            total += dis;
            cout<<"\n"<<product_code<<"\t"<<product_name<<"\t"<<arrq[i]<<"\t"<<product_price<<"\t"<<amount<<"\t"<<discount;
        }
        data>>product_code>>product_name>>product_price>>discount;
      }
      data.close();
      }
      cout<<"\n\n_________________________________________________________";
      cout<<"\n Toatal amount : "<<total;
    }
}
int main()
{
    shopping bhup;
    bhup.menu();
    return 0;
}