// mask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


using namespace std;


struct items
{
    string name;
    string desc;
    string option;
};

struct locs
{
    string name;
    string desc;
    int id;
    vector<items>loot;
};

struct hero
{
    string name;
    string desc;
    int hp;
    int damage;
    int current_loc;
    vector<items>inventory;
};

struct enemy
{
    string name;
    string desc;
    int hp;
    int damage;
    int current_loc;
};

vector<locs>location;
items Rusty_dagger;
items Forest_berry;
items Leather_armor;
items Gold_coin;
hero character;
enemy monster;

void locas()
{
    location.push_back({ "Honeywood", "Small village on bonderland of Kingdom", 1});
    location.push_back({ "Lightwood forest", "Forest near with Honeywood", 2 , {{Forest_berry.name, Forest_berry.desc, Forest_berry.option}} });
    location.push_back({ "Honeywood's lake", "Lake near with Honeywood", 3, {{Gold_coin.name, Gold_coin.desc, Gold_coin.option}} });
    location.push_back({ "Darkwood forest", "Wrong forest near with Honeywood", 4});
};

void Items()
{
    Rusty_dagger.name = "Rusty_dagger";
    Rusty_dagger.desc = "Iron rusty dagger";
    Rusty_dagger.option = "Increas damage on 5";

    Forest_berry.name = "Forest_berry";
    Forest_berry.desc = "Yammy red berry";
    Forest_berry.option = "Restores HP on 15";

    Leather_armor.name = "Leather_armor";
    Leather_armor.desc = "Armor made of wolf skin";
    Leather_armor.option = "Reduces taken damage on 1";

    Gold_coin.name = "Gold_coin";
    Gold_coin.desc = "MONEY!";
    Gold_coin.option = "Just a money";
};


void heroes()
{
    character.name = "Cloud";
    character.desc = "Main character";
    character.current_loc = 0;
    character.hp = 50;
    character.damage = 10;
    character.inventory.push_back({ Rusty_dagger.name, Rusty_dagger.desc, Rusty_dagger.option });
    character.inventory.push_back({ Leather_armor.name, Leather_armor.desc, Leather_armor.option });
    character.inventory.push_back({ Gold_coin.name, Gold_coin.desc, Gold_coin.option });
};

void enemie1()
{
    monster.name = "Wolf";
    monster.desc = "Wild animal";
    monster.hp = 30;
    monster.damage = 10;
    monster.current_loc = 1;
}

void enemie2()
{
    monster.name = "Crab";
    monster.desc = "Giant crab";
    monster.hp = 20;
    monster.damage = 3;
    monster.current_loc = 2;
}

void enemie3()
{
    monster.name = "Rogue";
    monster.desc = "Criminal person";
    monster.hp = 40;
    monster.damage = 10;
    monster.current_loc = 3;
}

int main()
{
    Items();
    locas();
    heroes();
    enemie1();
    enemie2();
    enemie3();

    int way;
    
    while (true)
    {
        /*отображение инвентаря*/
        string operation;
        cout << "Open Inventory? y/n \n";
        cin >> operation;
        if (operation == "y")
        {
            cout << "Inventory\n" << "\n";
            for (int i = 0; i < character.inventory.size(); i++)
            {
                cout << character.inventory[i].name << "\n" << character.inventory[i].desc << "\n" << character.inventory[i].option << "\n" << "\n";
            }
        }

        /*перемещение между локациями*/
        cout << "0 - Honeywood\n" << "1 - Lightwood forest\n" << "2 - Honeywood's lake\n" << "3 - Darkwood forest\n";
        cout << character.current_loc << " You in " << location[character.current_loc].name << "\n";
        cin >> way;
        if (way!= character.current_loc)
        {
            character.current_loc = way;
            cout << location[character.current_loc].name << "\n" << location[character.current_loc].desc << "\n";
        }
        else
        {
            cout << "You is here\n";
        }

        /*лут локации*/
        cout << "Loot it? y/n \n";
        cin >> operation;
        if (operation == "y")
        {
            /*cout << "You found\n";
            for (int i = 0; i < location[character.current_loc].loot.size(); i++)
            {
                cout << location[character.current_loc].loot[i].name << "\n";
            }
            character.inventory.push_back({ Gold_coin.name, Gold_coin.desc, Gold_coin.option });*/

                /* if (location[character.current_loc].loot.empty())
                   {
                      cout << "You didn't find anything\n";
                   }
            
                   else
                   {
                      cout << "You found\n";
                      for (int i = 0; i < location[character.current_loc].loot.size(); i++)
                      {
                         cout << location[character.current_loc].loot[i].name << "\n";
                      }
                      character.inventory.push_back({ Gold_coin.name, Gold_coin.desc, Gold_coin.option });
                    }*/
            if (location[character.current_loc].loot.empty())
            {
                cout << "You didn't find anything\n";
            }
            else
            {
                cout << "You found:\n";
                for (int i = 0; i < location[character.current_loc].loot.size(); i++)
                {
                    cout << location[character.current_loc].loot[i].name << "\n";
                    character.inventory.push_back({location[character.current_loc].loot[i].name,location[character.current_loc].loot[i].desc,location[character.current_loc].loot[i].option });
                }
            }
        }
                                                                                                            /*почитать про вектора и их функции, про структуры*/
                                                                                                            /*почитать про swich и case*/
        /*фаза боя*/
        if (character.current_loc == monster.current_loc)
        {
            while (character.hp > 0 && monster.hp > 0)
            {
                cout << monster.name << " is appeared\n";
                string action;
                cout << "Chose action " << "Attack (a) || Defence (d) || Use item (i) || Wait\n";
                cin >> action;
                if (action == "a")
                {
                    monster.hp -= character.damage;
                    cout << monster.name << " Hp = " << monster.hp << "\n";
                }
                cout << monster.name << " is attack\n";
                character.hp -= monster.damage;
                cout << character.name << " HP = " << character.hp << "\n";

                /*if (action == "d")
                {

                }*/

                /*if (action == "i")
                {

                }*/

                if (monster.hp <= 0)
                {
                    cout << monster.name << " is defead\n";
                }
                
                if (character.hp <= 0)
                {
                    cout << character.name << " is defead\n";
                    cout << "You lost \n";
                    /*character.inventory.erase(character.inventory.begin() + 4);*/
                                                                                                                  /*через if сделать сравнение названий и удаление одинаковых*/
                    for (auto i = character.inventory.begin(); i != character.inventory.end();)
                    {
                        if (i->name == Gold_coin.name)
                        {
                            cout << i->name << "\n";
                            i = character.inventory.erase(i);
                        }

                        else
                        {
                        i++;
                        }
                    }
                }
            }
        }
    }

























    


//struct Product_ {
//
//    string name;
//    int count;
//    int price;
//
//};
//
//
//void magaz() {
//
//    cout << "name\t" << "count\t" << "price\n";
//    string text[3]{ "melon", "berry", "cherry" };
//    int count[3]{ 3, 50, 30 };
//    int price[3]{ 140, 15, 10 };
//    int wallet = 1000;
//    string chose;
//    int number;
//    int basket[3]{ 0, 0, 0 };
//    int SPEND = 0;
//
//    while (true)
//    {
//        for (int i = 0; i < 3; i++)
//        {
//            cout << text[i] << "\t" << count[i] << "\t" << price[i] << "\n";
//        }
//        cout << "wallet\t" << wallet << "\n";
//
//        cout << "enter chose\n";
//        cin >> chose;
//
//        if (chose == "basket")
//        {
//            for (int i = 0; i < 3; i++)
//            {
//                cout << text[i] << "\t" << basket[i] << "\n";
//            }
//            cout << "SPEND:\t" << SPEND << endl;
//        }
//
//        for (int i = 0; i < 3; i++)
//        {
//            if (chose == text[i])
//            {
//                cout << "enter count\n";
//                cin >> number;
//                if (number > 0 && number <= count[i])
//                {
//                    if (wallet >= number * price[i])
//                    {
//                        count[i] -= number;
//                        basket[i] += number;
//                        wallet -= number * price[i];
//                        SPEND += number * price[i];
//                    }
//                    else
//                    {
//                        cout << "need " << number * price[i] << "\n";
//                    }
//                }
//                else
//                {
//                    cout << "not found\n";
//                }
//            }
//        }
//    }
//
//}
//
// ???????? in t main()
//{
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

    //vector<Product_> shop;

    //shop.push_back({ "melon", 3, 140 });
    //shop.push_back({ "berry", 50, 15 });
    //shop.push_back({ "cherry", 30, 10 });
    //int wallet = 1000;
    //string chose;
    //int number;
    //int basket[3]{ 0, 0, 0 };
    //vector<Product_> bas;
    //int spend = 0;

    //while (true)
    //{
    //    for (int i = 0; i < shop.size(); i++)
    //    {
    //        cout << shop[i].name << "\t" << shop[i].count << "\t" << shop[i].price << endl;
    //    }
    //    cout << "wallet\t" << wallet << "\n";

    //    cout << "enter chose\n";
    //    cin >> chose;

    //    if (chose == "basket")
    //    {
    //        for (int i = 0; i < bas.size(); i++)
    //        {
    //            cout << bas[i].name << "\t" << bas[i].count << "\t" <<bas[i].price <<  "\n";
    //        }
    //        cout << "spend:\t" << spend << endl;
    //    }

    //    for (int i = 0; i < shop.size(); i++)
    //    {
    //        if (chose == shop[i].name)
    //        {
    //            cout << "enter count\n";
    //            cin >> number;
    //            if (number > 0 && number <= shop[i].count)
    //            {
    //                if (wallet >= number * shop[i].price)
    //                {
    //                    shop[i].count -= number;
    //                    //basket[i] += number;
    //                    bas.push_back({ shop[i].name, number, number * shop[i].price });
    //                    wallet -= number * shop[i].price;
    //                    spend += number * shop[i].price;
    //                }
    //                else
    //                {
    //                    cout << "need " << number * shop[i].price << "\n";
    //                }
    //            }
    //            else
    //            {
    //                cout << "not found\n";
    //            }
    //        }
    //    }
    //}
    //
    
    
    
    
    
    
    
    















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
};


