#include <iostream>
#include<unistd.h>
using namespace std;
void game();
void game2();
int g1, g2;
string teamchoose(int x)
{
    string T1;
    switch (x)
    {
    case 1:
        T1 = "Batch15";
        break;
    case 2:
        T1 = "Batch16";
        break;
    case 3:
        T1 = "Batch17";
        break;
    case 4:
        T1 = "Batch18";
        break;
    case 5:
        T1 = "Batch19";
        break;
    case 6:
        T1 = "Batch20";
        break;
    }
    return T1;
}

int main()
{
    system("cls");
    cout << "                           *********    *****    ***********  **********  ***            *****         ***" << endl;
    cout << "                           *********   *******   ***********  **********  ***          ********      *** ***" << endl;
    cout << "                              ***     ***   ***      ***      ***     **  ***         ***    ***    ***  ***" << endl;
    cout << "                              ***     ***            ***      ***     **  ***              ***     ***   ***" << endl;
    cout << "                              ***     ***            ***      **********  ***             ***     ***    ***" << endl;
    cout << "                              ***     ***            ***      **********  ***            ***      **********" << endl;
    cout << "                              ***     ***   ***      ***      ***         ***          ****       **********" << endl;
    cout << "                           *********   *******       ***      ***         **********  **********         ***" << endl;
    cout << "                           *********    *****        ***      ***         **********  **********         ***" << endl;
    cout << "                                     Information and Communication Technology Premier League 2024" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                                                      ---Instructions:---" << endl;
    cout << "                                                   # At first choose 2 teams" << endl;
    cout << "                                                # Each team has 5 wickets to play" << endl;
    cout << "                                                          # 5 Overs" << endl;
    cout << "                                            # You can input every ball by using a character" << endl;
    cout << "                   # Runs are : 0, 1, 2, 3, 4, 6, w (Wide Ball)=1 run + 1 extra Ball ,n (No Ball)=1 run + 1 extra Ball" << endl;
    cout << "                                      #There is no free hit if No Ball Occurs(Update Will Come Soon)" << endl;
    cout << "                                                   # W will be denoted as Wicket" << endl;
    cout<<"                                   # There is 1/50 chance where a Batsman can be injured in the game"<<endl;
    cout << endl;
    cout << endl;
    cout << endl;
    string S;
    do
    {
        cout << "                                                    Start a New Board (Press S)" << endl;
        cout << "                                                     Press Q to Quit the Game" << endl;
        cin >> S;
        if (S[0] == 'Q' || S[0] == 'q')
        {
            cout << "                                                  Thank you for Using this console" << endl;
            sleep(1);
            break;
        }
        cout << "                                                     Press 1 to select Batch 15" << endl;
        cout << "                                                     Press 2 to select Batch 16" << endl;
        cout << "                                                     Press 3 to select Batch 17" << endl;
        cout << "                                                     Press 4 to select Batch 18" << endl;
        cout << "                                                     Press 5 to select Batch 19" << endl;
        cout << "                                                     Press 6 to select Batch 20" << endl;
        int t1, t2;
        cout << "Choose Team 1:" << endl;
        cin >> t1;
        string T1 = teamchoose(t1);
        cout << "Choose Team 2:" << endl;
        cin >> t2;
        string T2 = teamchoose(t2);
        cout << "                                                 " << T1 << "(Team 1) vs " << T2 << "(Team 2)" << endl;
        cout << "\n\n                                   It's Time for Toss....Team 1 choose H for Head or T for Tail" << endl;
        string ht;
        int HT = rand(), hT = 0;
        cin >> ht;
        if (HT % 2 == 0)
        {
            cout << "It's Tail" << endl;
            if (ht[0] == 't' || ht[0] == 'T')
            {
                cout << T1 << " Won the Toss" << endl;
                cout << T1 << " press 1 to bat or press 0 to field " << endl;
                cin >> HT;
                if (HT == 1)
                    hT++;
            }
            else
            {
                cout << T1 << " lost the Toss" << endl;
                cout << T2 << " press 1 to bat or press 0 to field " << endl;
                cin >> HT;
                if (HT == 0)
                    hT++;
            }
        }
        else
        {
            cout << "It's Head" << endl;
            if (ht[0] == 'h' || ht[0] == 'H')
            {
                cout << T1 << " Won the Toss" << endl;
                cout << T1 << " press 1 to bat or press 0 to field " << endl;
                cin >> HT;
                if (HT == 1)
                    hT++;
            }
            else
            {
                cout << T1 << " lost the Toss" << endl;
                cout << T2 << " press 1 to bat or press 0 to field " << endl;
                cin >> HT;
                if (HT == 0)
                    hT++;
            }
        }
        if (hT == 1)
        {
            int S1, S2;
            cout << T1 << " will Bat now" << endl;
            game();
            S1 = g1;
            cout << T2 << " will Bat now" << endl;
            game2();
            S2 = g2;
            if (S1 < S2)
            {
                S2 = S2 - S1;
                cout << T2 << " Won the match by " << S2 << " Runs" << endl;
            }
            else if (S1 > S2)
            {
                S1 = S1 - S2;
                cout << T1 << " Won the match by " << S1 << " Runs" << endl;
            }
            else
            {
                cout << "The match is TIE..... Well Played " << T1 << " and " << T2 << endl;
            }
        }
        else
        {
            cout << T2 << " will Bat now" << endl;
            game();
            int S1, S2;
            S1 = g1;
            cout << T1 << " will Bat now" << endl;
            game2();
            S2 = g2;
            if (S1 < S2)
            {
                S2 = S2 - S1;
                cout << T1 << " Won the match by " << S2 << " Runs" << endl;
            }
            else if (S1 > S2)
            {
                S1 = S1 - S2;
                cout << T2 << " Won the match by " << S1 << " Runs" << endl;
            }
            else
            {
                cout << "The match is TIE..... Well Played " << T1 << " and " << T2 << endl;
            }
        }
    } while (S[0] == 'S' || S[0] == 's');
}

void game()
{
    char x;
    int b = 0, sum = 0, W = 0, O,ww,i;
    while (W < 5 && b < 30)
    {
        ww=rand()%6;
        i==rand()%50;
        if(b==0)
        {
            cout<<"Here goes the first ball...."<<endl;
        }
        else if(b<30)
        {
            cout<<"Here goes the next ball...."<<endl;
        }
        else
        {
            cout<<"And the last ball...."<<endl;
        }
        cin >> x;
        if (x == 'W')
        {
            W++;
            b++;
            if(sum==0)
                cout<<"The Batsman has gone for a DUCK"<<endl;
            else if(ww%5==0)
                cout<<"It's a clean Bold"<<endl;
            else if(ww%5==1)
                cout<<"A great Catch by the fielder"<<endl;
            else if(ww%5==2)
                cout<<"Oh no!! It's LBW"<<endl;
            else if(ww%5==3)
                cout<<"The Batsmen are unable to make the quick run and lost the Wicket\\Its a Run Out"<<endl;
            else if(ww%5==4)
                cout<<"Stamps are flying in the air!!!!"<<endl;
        }
        else if (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '6')
        {
            sum = sum + (x - '0');
            b++;
        }
        else if (x == 'w')
        {
            sum++;
            cout<<"Wide Ball!!"<<endl;
        }
        else if (x == 'n')
        {
            cout<<"NO BALL"<<endl;
            sum++;
            cout << "Did any run happened?\nPress y to input the run\nPress n to skip" << endl;
            string nr;
            cin >> nr;
            if (nr[0] == 'y')
            {
                cout << "Enter the run:" << endl;
                cin >> x;
                if (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '6')
                {
                    sum = sum + (x - '0');
                    if(x=='6')
                    {
                        cout<<"It's a huge SIXER in No Ball"<<endl;
                    }
                    else if(x=='4')
                        cout<<"There goes Four run in a No Ball"<<endl;
                }
            }
        }
        else
        {
            cout<<"     404"<<endl;
            cout<<"Invalid Character\nPlease Try again with Valid Character given in the Instruction"<<endl;
        }
        if(i==18)
        {
            cout<<"                         \n\nOh No!!! The Ball hits the Batsman........"<<endl;
            cout<<"                         He seemed to be injured...//Lifemen are coming to rescue him"<<endl;
            cout<<"                         Today this is end for him_____New Batsman is coming as a substitute"<<endl;
            cout<<"                         The Game should be continued....................\n\n"<<endl;
        }
    }
    cout << "After the 1st innings The final Scoreboard is: ";
    O = b / 6;
    b = b - (O * 6);
    cout << O << "." << b;
    if (O == 1)
    {
        if (b == 0)
        {
            cout << " Over ";
        }
        else
        {
            cout << " Overs ";
        }
    }
    else if (O == 0)
    {
        cout << " Over ";
    }
    else if (O > 1)
    {
        cout << " Overs ";
    }
    cout << sum;
    if (sum == 1 || sum == 0)
    {
        cout << " Run ";
    }
    else
    {
        cout << " Runs ";
    }
    cout << W;
    if (W < 2)
        cout << " Wicket." << endl;
    else
        cout << " Wickets." << endl;

    cout << "\nNow The opponent team will need " << sum + 1 << " runs in 30 balls and the required run rate is " << (float)(sum + 1) / 5 << endl;
    g1 = sum;
}


void game2()
{
    char x;
    int s = g1;
    int b = 0, sum = 0, W = 0, O,ww,i;
        while (W < 5 && b < 30)
    {
        ww=rand()%6;
        i==rand()%50;
        if(sum>(s))
        {
            break;
        }
        if(b==0)
        {
            cout<<"Here goes the first ball...."<<endl;
        }
        else if(b<30)
        {
            cout<<"Here goes the next ball...."<<endl;
        }
        else
        {
            cout<<"And the last ball...."<<endl;
        }
        cin >> x;
        if (x == 'W')
        {
            W++;
            b++;
            if(sum==0)
                cout<<"The Batsman has gone for a DUCK"<<endl;
            else if(ww%5==0)
                cout<<"It's a clean Bold"<<endl;
            else if(ww%5==1)
                cout<<"A great Catch by the fielder"<<endl;
            else if(ww%5==2)
                cout<<"Oh no!! It's LBW"<<endl;
            else if(ww%5==3)
                cout<<"The Batsmen are unable to make the Quick run and lost the Wicket\\Its a Run Out"<<endl;
            else if(ww%5==4)
                cout<<"Stamps are flying in the air!!!!"<<endl;
        }
        else if (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '6')
        {
            sum = sum + (x - '0');
            b++;
        }
        else if (x == 'w')
        {
            sum++;
            cout<<"Wide Ball"<<endl;
        }
        else if (x == 'n')
        {
            cout<<"NO BALL"<<endl;
            sum++;
            cout << "Did any run happened?\nPress y to input the run\nPress n to skip" << endl;
            string nr;
            cin >> nr;
            if (nr[0] == 'y')
            {
                cout << "Enter the run:" << endl;
                cin >> x;
                if (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '6')
                {
                    sum = sum + (x - '0');
                    if(x=='6')
                    {
                        cout<<"It's a huge SIXER in No Ball"<<endl;
                    }
                    else if(x=='4')
                        cout<<"There goes Four run in a No Ball"<<endl;
                }
            }
        }
        else
        {
            cout<<"     404"<<endl;
            cout<<"Invalid Character\nPlease Try again with Valid Character given in the Instruction"<<endl;
        }
         if(i==18)
        {
            cout<<"                         \n\nOh No!!! The Ball hits the Batsman........"<<endl;
            cout<<"                         He seemed to be injured...//Lifemen are coming to rescue him"<<endl;
            cout<<"                         Today this is end for him_____New Batsman is coming as a substitute"<<endl;
            cout<<"                         The Game should be continued....................\n\n"<<endl;
        }
    }


    cout << "After the 2nd innings The final Scoreboard is: ";
    O = b / 6;
    b = b - (O * 6);
    cout << O << "." << b;
    if (O == 1)
    {
        if (b == 0)
        {
            cout << " Over ";
        }
        else
        {
            cout << " Overs ";
        }
    }
    else if (O == 0)
    {
        cout << " Over ";
    }
    else if (O > 1)
    {
        cout << " Overs ";
    }
    cout << sum;
    if (sum == 1 || sum == 0)
    {
        cout << " Run ";
    }
    else
    {
        cout << " Runs ";
    }
    cout << W;
    if (W < 2)
        cout << " Wicket." << endl;
    else
        cout << " Wickets." << endl;

    g2 = sum;
}

