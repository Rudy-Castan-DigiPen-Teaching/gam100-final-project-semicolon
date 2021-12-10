// Name: semicolon
// Assignment: Game Complete
// Course : cs120
// term : 2021

##  Made good use of exceptions

player.h (191 ~ 205)

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

## Made good use of File IO with the ifstream and ofstream types

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

player.h (228 ~ 242)

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
~~~

#  Section describing anything incomplete about the assignment, Section describing something you’re proud of about the assignment
Failed to code file io several times. So, I completed the coding by studying through a lot of Googling. Although it may seem simple coding to others, it is a code that I am proud of.
Also, I felt that map and unordered_map needed more study. I coded it, but like a vector, it is a difficult code for me. So, after this final exam, I thought I should study with vector. For me, the map code is unstable and difficult due to lack of understanding.
