// mask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


using namespace std;

struct Product_ {

    string name;
    int count;
    int price;

};


void magaz() {

    cout << "name\t" << "count\t" << "price\n";
    string text[3]{ "melon", "berry", "cherry" };
    int count[3]{ 3, 50, 30 };
    int price[3]{ 140, 15, 10 };
    int wallet = 1000;
    string chose;
    int number;
    int basket[3]{ 0, 0, 0 };
    int SPEND = 0;

    while (true)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << text[i] << "\t" << count[i] << "\t" << price[i] << "\n";
        }
        cout << "wallet\t" << wallet << "\n";

        cout << "enter chose\n";
        cin >> chose;

        if (chose == "basket")
        {
            for (int i = 0; i < 3; i++)
            {
                cout << text[i] << "\t" << basket[i] << "\n";
            }
            cout << "SPEND:\t" << SPEND << endl;
        }

        for (int i = 0; i < 3; i++)
        {
            if (chose == text[i])
            {
                cout << "enter count\n";
                cin >> number;
                if (number > 0 && number <= count[i])
                {
                    if (wallet >= number * price[i])
                    {
                        count[i] -= number;
                        basket[i] += number;
                        wallet -= number * price[i];
                        SPEND += number * price[i];
                    }
                    else
                    {
                        cout << "need " << number * price[i] << "\n";
                    }
                }
                else
                {
                    cout << "not found\n";
                }
            }
        }
    }


int main()
{
    /*Product_ s[2]{ {"Aboba", 4, 900},
                   {"Biba", 1, 10} };
    vector<Product_> shop;

    shop.push_back({ "tom", 4, 1 });
    shop.push_back({ "cat", 1, 5 });
    shop.push_back({ "bob", 3, 2 });

    for (int i = 0; i < shop.size(); i++)
    {
        cout << shop[i].name << "\t" << shop[i].count << endl;
    }*/

    vector<Product_> shop;

    shop.push_back({ "melon", 3, 140 });
    shop.push_back({ "berry", 50, 15 });
    shop.push_back({ "cherry", 30, 10 });
    int wallet = 1000;
    string chose;
    int number;
    int basket[3]{ 0, 0, 0 };
    vector<Product_> bas;
    int spend = 0;

    while (true)
    {
        for (int i = 0; i < shop.size(); i++)
        {
            cout << shop[i].name << "\t" << shop[i].count << "\t" << shop[i].price << endl;
        }
        cout << "wallet\t" << wallet << "\n";

        cout << "enter chose\n";
        cin >> chose;

        if (chose == "basket")
        {
            for (int i = 0; i < bas.size(); i++)
            {
                cout << bas[i].name << "\t" << bas[i].count << "\t" <<bas[i].price <<  "\n";
            }
            cout << "spend:\t" << spend << endl;
        }

        for (int i = 0; i < shop.size(); i++)
        {
            if (chose == shop[i].name)
            {
                cout << "enter count\n";
                cin >> number;
                if (number > 0 && number <= shop[i].count)
                {
                    if (wallet >= number * shop[i].price)
                    {
                        shop[i].count -= number;
                        //basket[i] += number;
                        bas.push_back({ shop[i].name, number, number * shop[i].price });
                        wallet -= number * shop[i].price;
                        spend += number * shop[i].price;
                    }
                    else
                    {
                        cout << "need " << number * shop[i].price << "\n";
                    }
                }
                else
                {
                    cout << "not found\n";
                }
            }
        }
    }
    
    
    
    
    
    
    
    
    















        //int a[5] { 7,5,-1,3,-7 };

        //for (int i = 0; i < 5; i++)
        //{
        //     for (int j = 0; j < 4; j++)
        //         if (a[j] > a[j + 1])
        //         {
        //             int n = a[j];
        //             a[j] = a[j + 1];
        //             a[j + 1] = n;
        //         }
        //}


        ////igijuiy
        // for (int i = 0; i < 5; i++) 
        // {
        //     std::cout << a[i] << std::endl;
        // }






        /*srand(time(NULL));

        int a;
        int q = 0;
        while (q < 3)
        {
            int i = 1 + rand() % 3;
            std::cout << i << std::endl;
            std::cin >> a;

            if (a == 1 && i == 2 ||
                a == 2 && i == 3 ||
                a == 3 && i == 1)
            {
                std::cout << "u win\n";
            }
            else if (a == i)
            {
                std::cout << "NN\n";
            }
            else
            {
                std::cout << "u lose\n";
            }
            q++;
        }*/
}


