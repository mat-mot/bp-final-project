#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
using namespace std;
int uniq_vote (int *x , int y)
{
    int max = *x , z=0 , p=0 ;
    for (int i=0 ; i<y ; i++)
    {
        if (*(x+i) > max)
            max = *(x+i) ;
    }
    for (int i=0 ; i<y ; i++)
    {
        if (max == *(x+i))
        {
            z++ ;
            p = i ;
        }
    }
    if (z == 1)
    {
        return p;
    }
    return -1;
}
//int condition ()
int rolknown (string x , string y[8])
{;
    for (int q=0 ; q < 8 ; q++)
        if (x == y[q])
            return q;
    return -1 ;
}
int whoer (string x , string y[20][2] , int a , int z )
{
    for (int i=0 ; i < a ; i++)
    {
        if ( x == y[i][z])
        {
            return i;
        }
    }
    return -1;
}
int main (void)
{
    int number_of_players , i=0 , day_counter=1 , p=0 , night_counter=1 , lover [2] , tempp=0 , tempp1=0 ;
    //getting number of player
    cout << "please enter number of players : ";
    cin >> number_of_players ;
    while (number_of_players < 10)
    {
        cout << "the min of player in this game is 10 try again : " ;
        cin >> number_of_players ;
    }
    string player [number_of_players][2] , roles [8] , temp , temp1 , temp_roles[8];
    int vote [number_of_players] , num_roles[8] , hunter_bullets = 0  , num_alive = number_of_players ;
    bool player_with_role [number_of_players] , player_in_game [number_of_players] ;
    bool first_day = true , first_night = true , oil[number_of_players] , burn = false , first = true ;
    //getting player name
    for (int k=0 ; k < number_of_players ; k++)
    {
        cout << "please enter your name player " << k+1 << " : " ;
        cin >> player [k][0] ;
    }
    for (int i=0 ; i < number_of_players ; i++)
        player_with_role[i] = 0 ;
    for (int i=0 ; i < number_of_players ; i++)
        player_in_game [i] = 1 ;
    for (int i=0 ; i < number_of_players ; i++)
        vote [i] = 0 ;
    for (int i=0 ; i < number_of_players ; i++)
        oil [i] = 0 ;
    for (int i=0 ; i < 8 ; i++)
        num_roles[i] = 0 ;
    //game roles
    {
        roles[0]="hunter" ;
        roles[1]="serial killer" ;
        roles[2]="cult" ;
        roles[3]="fireman" ;
        roles[4]="gurdian angel" ;
        roles[5]="goddess of love" ;
        roles[6]="villager" ;
        roles[7]="werewolf" ;
        //--------------end game role
    }
    // asigning roles between players
    {
        i=0 ;
        while (i != 6)
        {
            p = (rand()  %  number_of_players) ;
            if (player_with_role[p] == 0 )
            {
                player_with_role[p] = 1 ;
                player [p][1] = roles[i] ;
                num_roles[i] ++ ;
                i++ ;
            }
        }
        i=0 ;
        while (floor ((number_of_players - 6)/4) != i)
        {
            p = (rand()  %  number_of_players) ;
            if (player_with_role[p] == 0 )
            {
                player_with_role[p] = 1 ;
                player [p][1] = roles[7] ;
                i++ ;
                num_roles[7] ++ ;
            }
        }
        i=0 ;
        while (i < number_of_players )
        {
            if (player_with_role[i] == 0 )
            {
                player_with_role[i] = 1 ;
                player [i][1] = roles[6] ;
                num_roles[6] ++ ;
            }
            i++ ;
        }
        // list of player with role
        cout << " Show role segmentation " << endl ;
        for (int i=0 ; i < number_of_players ; i++)
            cout << "name of player :  " << player[i][0] << "  =>>  name of role :  " << player[i][1] << endl ;
        system("pause") ;
        //----------------end asigning role
    }
    while (true)
    {
        // day process

        system ("cls") ;//clear blackboard
        if (num_roles[1]+ num_roles[7] + num_roles[3] + num_roles[0] + num_roles[4] + num_roles[5] + num_roles[6] < 2 )
        {
            cout << "the cults is winner " << endl ;
            cout << "tanks for playing see you soon " << endl ;
            return 0;
        }
        if (num_roles[7] == num_alive && num_roles[3] + num_roles[1] == 0)
        {
            cout << "the werewolfs is winner " << endl ;
            cout << "tanks for playing see you soon " << endl ;
            return 0;
        }
        if (num_roles[1] + num_roles[2] + num_roles[3] + num_roles[7] == 0)
        {
            cout << "the villager is winner " << endl ;
            cout << "tanks for playing see you soon " << endl ;
            return 0;
        }
        if (num_roles[3] == 0 && num_alive + num_roles[1] < 3)
        {
            cout << "the serial killer is winner " << endl ;
            cout << "tanks for playing see you soon " << endl ;
            return 0;
        }
        if (num_roles[3] + num_alive < 3)
        {
            cout << "the fireman is winner " << endl ;
            cout << "tanks for playing see you soon " << endl ;
            return 0;
        }
        for (int i=0 ; i<50 ; i++)
            cout << char (178) ;
        cout << endl ;
        for (int i=0 ; i<8 ; i++)
        {
            cout << char (178) ;
            for (int j=0 ; j<48 ; j++)
                cout << " " ;
            cout << char (178) << endl ;
            if (i==3)
            {
                cout << char (178) << "          day number is : " << day_counter << "                     " << char (178) << endl ;
            }
        }
        for (int i=0 ; i<50 ; i++)
            cout << char (178) ;
        cout << endl ;
        cout << endl ;
        cout << endl ;
        cout << endl ;
        day_counter++ ;
        if (first_day == false)
        {


            cout << "                            <<  *list of player*  >>" << endl ;
            for (int l=0 ; l < number_of_players ; l++)
            {
                cout << player[l][0] ;
                if (player_in_game[l] == true)
                    cout << "  :  alive :)" ;
                else
                    cout << "  :  is dead :(" ;
                cout << endl ;
            }
            // talking part
            cout << "now is time to talk" << endl ;
            for (int i=0 ; i < number_of_players ; i++)
            {
                if (player_in_game[i] == 1 )
                {
                    cout << player[i][0] << " please talk and give me feedback with done or next : " ;
                    cin >> temp ;
                    while (temp != "done" && temp != "next")
                    {
                        cout << "please write the corect word : " ;
                        cin >> temp ;
                    }
                }
            }
            //------------end talking part
            // voting part
            for (int i=0 ; i < number_of_players ; i++)// clearing past vote
                vote[i] = 0 ;
            cout << "now is time to vote" << endl ;
            for (int i=0 ; i < number_of_players ; i++)
            {
                if (player_in_game[i] == 1 )
                {
                    cout << player[i][0] << " what is your vote please enter his/her name : " ;
                    cin >> temp ;
                    tempp = whoer (temp , player , number_of_players , 0 ) ;
                    //                tempp1 = whoer (player[i][0] , player , number_of_players , 0 ) ;
                    while (player_in_game[tempp] == 0 || tempp == -1)
                    {
                        cout << player[i][0] << " you type name of player that is'n in the game or is dead vote again : " ;
                        cin >> temp ;
                        tempp = whoer (temp , player , number_of_players , 0) ;
                    }
                    vote [tempp] ++ ;
                }
            }
            if (uniq_vote(vote , number_of_players) != -1)
            {
                cout << "player " << player[uniq_vote(vote , number_of_players)][0] << "  was removed from gmae by people vote" << endl ;
                player_in_game[uniq_vote(vote , number_of_players)] = false ;
                tempp = rolknown(player[uniq_vote(vote , number_of_players)][1] , roles) ;
                num_roles[tempp] -- ;
            }
            else
            {
                cout << "in this day non player removed from game " << endl ;
            }
            while (player_in_game[lover[0]] == false || player_in_game[lover[1]] == false )
            {
                if (player_in_game[lover[0]] == false && first == true)
                {
                    player_in_game[lover[1]] = false ;
                    cout << player[lover[1]][0] << " from the sadness of love died O_O " << endl ;
                    tempp1 = rolknown (player[lover[1]][1] , roles) ;
                    num_roles[tempp1] -- ;
                    first = false ;
                    break ;
                }
                if (player_in_game[lover[1]] == false && first == true)
                {
                    player_in_game[lover[0]] = false ;
                    cout << player[lover[0]][0] << " from the sadness of love died O_O " << endl ;
                    tempp = rolknown (player[lover[0]][1] , roles) ;
                    num_roles[tempp] -- ;
                    first = false ;
                    break ;
                }
                break;
            }
        }
        first_day = false ;
        //------------------end voting part
        system("pause") ;
        num_alive = number_of_players ;
        for (int i=0 ; i < number_of_players ; i++)
            if (player_in_game[i] == false)
                num_alive -- ;
        //-----------------------------------end day process


        // night process

        if (num_roles[1]+ num_roles[7] + num_roles[3] + num_roles[0] + num_roles[4] + num_roles[5] + num_roles[6] < 2 )
        {
            system("cls") ;
            cout << "the cults is winner " << endl ;
            cout << "tanks for playing see you soon " << endl ;
            return 0;
        }
        if (num_roles[7] == num_alive && num_roles[3] + num_roles[1] == 0)
        {
            system("cls") ;
            cout << "the werewolfs is winner " << endl ;
            cout << "tanks for playing see you soon " << endl ;
            return 0;
        }
        if (num_roles[1] + num_roles[2] + num_roles[3] + num_roles[7] == 0)
        {
            system("cls") ;
            cout << "the villager is winner " << endl ;
            cout << "tanks for playing see you soon " << endl ;
            return 0;
        }
        if (num_roles[3] == 0 && num_alive + num_roles[1] < 3)
        {
            system("cls") ;
            cout << "the serial killer is winner " << endl ;
            cout << "tanks for playing see you soon " << endl ;
            return 0;
        }
        if (num_roles[3] + num_alive < 3)
        {
            system("cls") ;
            cout << "the fireman is winner " << endl ;
            cout << "tanks for playing see you soon " << endl ;
            return 0;
        }
        system ("cls") ;//clear blackboard
        for (int i=0 ; i<50 ; i++)
            cout << char (178) ;
        cout << endl ;
        for (int i=0 ; i<8 ; i++)
        {
            cout << char (178) ;
            for (int j=0 ; j<48 ; j++)
                cout << " " ;
            cout << char (178) << endl ;
            if (i==3)
            {
                cout << char (178) << "          night number is : " << night_counter << "                   " << char (178) << endl ;
            }
        }
        for (int i=0 ; i<50 ; i++)
            cout << char (178) ;
        cout << endl ;
        cout << endl ;
        cout << endl ;
        cout << endl ;
        night_counter++ ;
        // goddess of love choice
        if (first_night == true)
        {
            cout << roles[5] << " enter name of two lovers right now \n lover 1 : " ;
            cin >> temp  ;
            cout << " lover 2 : " ;
            cin >> temp1 ;
            tempp = whoer (temp , player , number_of_players , 0) ;
            tempp1 = whoer (temp1 , player , number_of_players , 0) ;
            while (tempp1 == -1 || tempp == -1)
            {
                cout << roles[5] << " you type name of player that is'n in the game \n lover 1 : " ;
                cin >> temp ;
                cout << "lover 2 : " ;
                cin >> temp1 ;
                tempp = whoer (temp , player , number_of_players , 0) ;
                tempp1 = whoer (temp1 , player, number_of_players , 0) ;
            }
            lover[0] = tempp ;
            lover[1] = tempp1 ;
        }
        first_night = false ;
        // ---------------------- end goddess of love choice
        // hunter shoot
        //tempp = whoer( "hunter" , &player[0][0] , number_of_players , 1 ) ;
        while ( num_roles[0] > 0  && hunter_bullets < 2)//player_in_game[tempp] != 0 && hunter_bullets < 2  )
        {
            cout << roles[0] << " choose name to shoot or if you want to skip just type skip : " ;
            cin >> temp_roles[0] ;
            if (temp_roles[0] == "skip" )
                break ;
            tempp = whoer (temp_roles[0] , player , number_of_players , 0 ) ;
            while (player_in_game[tempp] != 1 && tempp == -1)
            {
                cout << roles[0] << " you type name of player that is'n in the game or is dead vote again : " ;
                cin >> temp_roles[0] ;
                tempp = whoer (temp_roles[0] , player , number_of_players , 0) ;
            }
            hunter_bullets ++ ;
            break ;
        }
        //-----------------end hunter shoot
        // gurdian angel save
        //tempp = whoer( "gurdian angel" , &player[0][0] , number_of_players , 1 ) ;
        while ( num_roles[4] > 0  )//player_in_game[tempp] != 0
        {
            cout << roles[4] << " choose name to save or if you want to skip just type skip : " ;
            cin >> temp_roles[4] ;
            if (temp_roles[4] == "skip" )
                break ;
            tempp = whoer (temp_roles[4] , player , number_of_players , 0 ) ;
            while (player_in_game[tempp] != 1 && tempp == -1)
            {
                cout << player[i][0] << " you type name of player that is'n in the game or is dead vote again : " ;
                cin >> temp_roles[4] ;
                tempp = whoer (temp_roles[4] , player , number_of_players , 0) ;
            }
            break ;
        }
        // -----------------------end gurdian angel save
        // fireman process
        //tempp = whoer( "fireman" , &player[0][0] , number_of_players , 1 ) ;
        while ( num_roles[3] > 0  )//player_in_game[tempp] != 0
        {
            cout << roles[3] << " choose what you want to do between burn or oil : " ;
            cin >> temp ;
            while (temp != "oil" && temp != "burn")
            {
                cout << "please write the corect word : " ;
                cin >> temp ;
            }
            if (temp == "oil")
            {
                cout << "now type his / her name : " ;
                cin >> temp_roles[3] ;
                tempp = whoer (temp_roles[3] , player , number_of_players , 0 ) ;
                while (player_in_game[tempp] != 1 && tempp == -1)
                {
                    cout << roles[3] << " you type name of player that is'n in the game or is dead vote again : " ;
                    cin >> temp_roles[3] ;
                    tempp = whoer (temp_roles[3] , player , number_of_players , 0) ;
                }
                oil[tempp] = true ;
                break ;
            }
            burn = true ;
            break ;
        }
        //---------------end fireman process
        // sreial killer merdering
        //tempp = whoer( "serial killer" , &player[0][0] , number_of_players , 1 ) ;
        while ( num_roles[1] > 0  )//player_in_game[tempp] != 0
        {
            cout << roles[1] << " choose name to kill or if you want to skip just type skip : " ;
            cin >> temp_roles[1] ;
            if (temp_roles[1] == "skip" )
                break ;
            tempp = whoer (temp_roles[1] , player , number_of_players , 0 ) ;
            while (player_in_game[tempp] != 1 && tempp == -1)
            {
                cout << roles[1] << " you type name of player that is'n in the game or is dead vote again : " ;
                cin >> temp_roles[1] ;
                tempp = whoer (temp_roles[1] , player , number_of_players , 0) ;
            }
            break ;
        }
        //----------------end sreial killer merdering
        // werewolf eating
        while ( num_roles[7] > 0  )
        {
            cout << roles[7] << " choose name to eat or if you want to skip just type skip : " ;
            cin >> temp_roles[7] ;
            if (temp_roles[7] == "skip" )
                break ;
            tempp = whoer (temp_roles[7] , player , number_of_players , 0 ) ;
            while (player_in_game[tempp] != 1 && tempp == -1)
            {
                cout << roles[7] << " you type name of player that is'n in the game or is dead vote again : " ;
                cin >> temp_roles[7] ;
                tempp = whoer (temp_roles[7] , player , number_of_players , 0) ;
            }
            break ;
        }
        //----------------werewolf eating
        // cult invite
        while ( num_roles[2] > 0   )
        {
            cout << roles[2] << " choose name to invite or if you want to skip just type skip : " ;
            cin >> temp_roles[2] ;
            if (temp_roles[2] == "skip" )
                break ;
            tempp = whoer (temp_roles[2] , player , number_of_players , 0 ) ;
            while (player_in_game[tempp] != 1 && tempp == -1)
            {
                cout << roles[2] << " you type name of player that is'n in the game or is dead vote again : " ;
                cin >> temp_roles[2] ;
                tempp = whoer (temp_roles[2] , player , number_of_players , 0) ;
            }
            break ;
        }
        system("pause") ;
        //------------- end cult invite
        // doing order
        system("cls") ;
        while (temp_roles[0] != "skip" )//hunter
        {
            tempp = whoer (temp_roles[0] , player , number_of_players , 0 ) ;
            if (player[tempp][0] == temp_roles[4] && num_roles[4] > 0)
            {
                cout << " hunter shoot its useless bcuz doc is here o_o " << endl ;
                break ;
            }
            if (player[tempp][1] == roles[2])
            {
                cout << "hunter have grest mind and shoot the target very well /o\\/o\\ " << player[tempp][0] << " remove the game" << endl ;
                player_in_game[tempp] = false ;
                tempp1 = rolknown (player[tempp][1] , roles) ;
                num_roles[tempp1] -- ;
                break ;
            }
            cout << " our hunter has facked up its better to sleep insted of play game o_o " << endl ;
            break ;
        }
        while (temp_roles[1] != "skip" )//serial killer
        {
            tempp = whoer (temp_roles[1] , player , number_of_players , 0 ) ;
            tempp1 = rolknown (player[tempp][1] , roles) ;
            if (player[tempp][0] == temp_roles[4] && num_roles[4] > 0)
            {
                cout << " serial killer its popy bcuz doc is here o_o " << endl ;
                break ;
            }
            cout << " our serial killer has fucked enemy its better to known him as king o_o " << player[tempp][0] << " remove the game" << endl ;
            player_in_game[tempp] = false ;
            num_roles[tempp1] -- ;
            break ;
        }
        while (temp_roles[2] != "skip" )//cult
        {
            tempp = whoer (temp_roles[2] , player , number_of_players , 0 ) ;
            tempp1 = rolknown(player[tempp][1] , roles) ;
            if (player[tempp][1] == roles[0])
            {
                cout << " our cult have un accepted invite O_O " << endl ;
                break ;
            }
            cout << " our cult have sent a invite to our choose o_o " << endl ;
            player[tempp][1] = roles[2] ;
            num_roles[2] ++ ;
            num_roles[tempp1] -- ;
            break ;
        }
        while (temp_roles[7] != "skip" )//werewolf
        {
            tempp = whoer (temp_roles[7] , player , number_of_players , 0 ) ;
            tempp1 = rolknown (player[tempp][1] , roles) ;
            if (player[tempp][0] == temp_roles[4] && num_roles[4] > 0)
            {
                cout << " werewolfs want to eat some one but doc is here o_o " << endl ;
                break ;
            }
            cout << " werewolf eat innocent people it is a shame o_o " << player[tempp][0] << " remove the game" << endl ;
            player_in_game[tempp] = false ;
            num_roles[tempp1] -- ;
            break ;
        }
        while (temp_roles[3] != "skip" )//fireman
        {
            if (burn == false)
            {
                cout << "some one took an oil bath with help of fireman o_o " << endl ;
                break ;
            }
            else
            {
                cout << "fireman was an angry and kill every one that he want O_O such : " << endl  ;
                for (int i=0 ; i<number_of_players ; i++)
                {
                    if (oil [i] == true)
                    {
                        cout << player[i][0] << " remove the game" << endl ;
                        player_in_game[i] = false ;
                        tempp1 = rolknown(player[i][1] , roles) ;
                        num_roles[tempp1] -- ;
                        oil [i] = false ;
                    }
                }
                break ;
            }
        }
        while (player_in_game[lover[0]] == false || player_in_game[lover[1]] == false )
        {
            if (player_in_game[lover[0]] == false && first == true)
            {
                player_in_game[lover[1]] = false ;
                cout << player[lover[1]][0] << " from the sadness of love died O_O " << endl ;
                tempp1 = rolknown (player[lover[1]][1] , roles) ;
                num_roles[tempp1] -- ;
                first = false ;
                break ;
            }
            if (player_in_game[lover[1]] == false && first == true)
            {
                player_in_game[lover[0]] = false ;
                cout << player[lover[0]][0] << " from the sadness of love died O_O " << endl ;
                tempp = rolknown (player[lover[0]][1] , roles) ;
                num_roles[tempp] -- ;
                first = false ;
                break ;
            }
            break ;
        }
        system("pause") ;
        cout << endl ;
        cout << " Show role segmentation " << endl ;
        for (int i=0 ; i < number_of_players ; i++)
        {
            cout << "name of player :  " << player[i][0] << "  =>>  name of role :  " << player[i][1] ;
            if (player_in_game[i] == true)
                cout << " =>> alive :) " << endl ;
            else
                cout << " =>> dead :(  " << endl ;
        }
        system("pause") ;
        tempp = 0 , tempp1 = 0 , temp = '\0' , temp1 = '\0' ;
        for (int i=0 ; i < 8 ; i++)
            temp_roles[i] = "skip" ;
        num_alive = number_of_players ;
        for (int i=0 ; i < number_of_players ; i++)
            if (player_in_game[i] == false)
                num_alive -- ;
        //---------------------------end night process


    }
    return 0;
}
