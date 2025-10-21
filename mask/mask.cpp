// mask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    cout << "name\t" << "count\t" << "price\n";
    string text[3]{ "melon", "berry", "cherry" };
    int count[3]{ 3, 50, 30 };
    int price[3]{ 40, 150, 100 };
    int wallet = 2000;
    string chose;

    for (int i = 0; i < 3; i++)
    {
        cout << text[i] << "\t" << count[i] << "\t" << price[i] << "\n";
    }

    cout << "enter chose\n";
    cin >> chose;
    for (int i = 0; i < 3; i++)
    {
        if (chose == text[i])
        {
            cout << "enter count\n";







        }
    }



    /*  if (chose == "melon")
        {
            cout << text[0] << "\t" << count[0] << "\t" << price[0] << "\n" << endl;
        }
        else if (chose == "berry")
        {
            cout << text[1] << "\t" << count[1] << "\t" << price[1] << "\n" << endl;
        }
        else if (chose == "cherry")
        {
            cout << text[2] << "\t" << count[2] << "\t" << price[2] << "\n" << endl;
        }
        else
        {
            
        }*/




















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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
