//NAME : Semicolon

//ASSIGNMENT : Game Complete

//COURSE : CS120

//TERM & YEAR : Fall 2021

# core

## Made good use of exceptions

player.h (191~205)

~~~
        if (playerHP_width > 200.0)
        {
            try
            {
                if (playerHP_width < 300)
                {
                    throw playerHP_width + 300.0;
                }
                cout << "Players can still fight!!" << endl;
            }
            catch (double e)
            {
                cout << e << "player will die!!" << endl;
            }
        }

~~~

##  Made good use of File IO with the ifstream and ofstream types

player.h (207 ~ 225)

~~~
        string  name;
        fstream myFile;
        if (playerHP_width > 50.0)
        {
            if (playerHP_width < 100.0)
            {

                myFile.open("asset/game.txt");
                    if (myFile.is_open())
                    {
                        string line;
                        while (getline(myFile, line))
                        {
                            cout << line << endl;
                        }
                        myFile.close();
                    }
            }
        }
~~~

## Made good use of std::map and/or std::unordered_map

player.h(228 ~ 243)

~~~
        if (playerHP_width > 0.0)
        {
            if (playerHP_width < 50.0)
            {
                unordered_map<double, string> HP;
                HP.emplace(1, "HP danger");
                HP.emplace(2, "HP very dagner");
                HP.emplace(3, "soon die...");

                for (const auto& hp : HP)
                {
                    cout << hp.first << " " << hp.second << " " << endl;
                }
            }
        }
    }

~~~

# Section describing something you're proud of about the assignment

Of course it should be done, but I'm proud to have done this core.
When I did the cs120 exercise, I did not understand what it was and coded it.
But through this task, I started to understand little by little.
