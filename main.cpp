#include <iostream>
#include <fstream>
#include <Windows.h>
                            ////  Âàðèàíò 6  ////
using namespace std;           

class Date
{
    public:

    struct Node
    {
        int second;
        int minute;
        int hour;
        int day;
        int month;
        int year;

        Node* next;
        Node* prev;

        unsigned int n;   // Íîìåð
    };

    Node* first;
    
    void DisplayNode(Node* temp);
    void Show_all();
 
    void Push(Node* temp);
    void GetFail();
    void Task_6();

    void GetSystemDate();

    void Clear();
    
};


Date datetime;
//Date timedelta;




void Date::Push(Node* temp)
{
    if(!first)
    {
        first = temp;
        first->next = NULL;
        first->prev = NULL;

        temp->n=1;
    }

    else
    {
        Node* temp1 = first;

        while ( temp1->next != NULL)
        {
            temp1 = temp1->next;
        }

        temp1->next = temp;
        temp1->next->next = NULL;
        temp->prev = temp1;

        temp->n = (temp->prev->n)+1;
    }
}

void Date::GetFail()
{
    ifstream fin("INPUT.txt");

    Node* temp;

    while(!fin.eof())
    {
        temp = new Node;
        fin >> temp->second;
        fin >> temp->minute;
        fin >> temp->hour;
        fin >> temp->day;
        fin >> temp->month;
        fin >> temp->year;

        datetime.Push(temp);  // ? 
    }

    fin.close();
}

void Date::Show_all()
{
    if(!first) 
    {
        cout<<"\n *  Ñïèñîê ïóñò   * \n";
        return;
    }

    Node* temp = first;

    cout<<"\n------------------------------------------------------------------------------------";
    cout<<"\n          äàòà             |       ñëåäóþùàÿ äàòà       |       ïðåäûäóùàÿ äàòà     |\n";
    cout<<"-------------------------------------------------------------------------------------\n";

    do
    {

        DisplayNode(temp);
        temp = temp->next;

    } while(temp);

    cout<<endl;

}

void Date::DisplayNode(Node* temp)
{

    cout<<temp->n<<".   "<<temp->second<<":"<<temp->minute<<":"<<temp->hour
        <<"  "<<temp->day<<"."<<temp->month<<"."<<temp->year<<"       ";     // Äàòà


        if(temp->next != NULL)                          // Ñëå. Äàòà
        {   
         cout<<temp->next->second<<":"<<temp->next->minute<<":"<<temp->next->hour      // Ñëå. Äàòà
         <<"  "<<temp->next->day<<"."<<temp->next->month<<"."<<temp->next->year;
        }
        else
        {
            cout<<"__"<<":"<<"__"<<":"<<"__"
         <<"  "<<"__"<<"."<<"__"<<"."<<"__";
        }
        cout<<"               ";

            if(temp->prev != NULL)                     // Ïðåä. Äàòà
            {
                cout<<temp->prev->second<<":"<<temp->prev->minute<<":"<<temp->prev->hour   
                <<"  "<<temp->prev->day<<"."<<temp->prev->month<<"."<<temp->prev->year;
            }
            else
            {
                    cout<<"__"<<":"<<"__"<<":"<<"__"
                <<"  "<<"__"<<"."<<"__"<<"."<<"__";
            }
        
        cout<<endl;
}

void Date::Task_6()
{
    if(!first)
    {
        cout<<"\n * Íè÷åãî íå íàéäåíî. ";
        return;
    }

    Node* temp = first;
    bool flag = 0;

    do
    {
       if(temp->next != NULL && temp->day%2 != 0  && temp->next->day%2 != 0)
       {
           if(!flag)
           {
            cout<<"\n------------------------------------------------------------------------------------";
            cout<<"\n          äàòà             |       ñëåäóþùàÿ äàòà       |       ïðåäûäóùàÿ äàòà     |\n";
            cout<<"-------------------------------------------------------------------------------------\n";
           }

            DisplayNode(temp);

            flag = 1;
       }

        temp = temp->next;

    } while (temp);
    
    if(!flag) cout<<"\n * Íè÷åãî íå íàéäåíî. ";

}

void Date::GetSystemDate()
{
    SYSTEMTIME st;  // áóôåð õðàíåíèÿ ñèñòåìíîãî âðåìåíè

    Node* temp;
    temp = new Node;
    GetLocalTime(&st);  // Çàïèñü âðåìåíè
  
    temp->second = int(st.wSecond);  // Ðàñïåðåäåëåíèå äàííûõ
    temp->minute = int(st.wMinute);
    temp->hour = int(st.wHour);
    temp->day = int(st.wDay);
    temp->month = int(st.wMonth);
    temp->year = int(st.wYear);
    
    Push(temp);

    cout<<"\n\n * Äàòà "<<temp->second<<":"<<temp->minute<<":"<<temp->hour
        <<"  "<<temp->day<<"."<<temp->month<<"."<<temp->year<<" óñïåøíî äîáàâëåíà.\n";
}

void Date::Clear()
{

    if(!first)
    {
        cout<<"\n * Î÷åðåäü óæå ïóñòàÿ.";
        return; 
    }

    Node* temp = first;

    while (first)
    {
        temp = first;
        first = temp->next;
    
        free(temp);
    }
    
}


void MENU()
{

    cout<<"\n  ________________________________________"
        <<"\n |                                        ||"
        <<"\n |        ** Âûáèðèòå îïåðàöèþ **         ||"
        <<"\n |  1.) Âûãðóçèòü äàííûå èç ôàéëà         ||"
        <<"\n |  2.) Âàðèàíò 6                        ||"
        <<"\n |  3.) Îòîáðàçèòü ñïèñîê                 ||"
        <<"\n |  4.) Î÷èñòèòü ñïèñîê                   ||"
        <<"\n |  5.) Çàïèñàòü ñèñòåìíîå âðåìÿ è äàòó   ||"
        <<"\n |  0.) Âûéòè                             ||"
        <<"\n |________________________________________||"
        <<"\n  > ";

    int point;  cin>>point;

    switch(point) {
        case 1:
        {
            system("cls");
            datetime.GetFail();
            cout<<"\n * Äàííûå óñïåøíî çàãðóæåíû.";
            datetime.Show_all();
            MENU();

              break;
        }      

         case 2:
        {
            datetime.Task_6();
            MENU();

              break;
        }  

        case 3:
        {
            datetime.Show_all();
            MENU();

              break;
        } 

        case 4:
        {
            datetime.Clear();
            cout<<"\n\n * Ñïèñîê óñïåøíî î÷èùåí.\n";
            MENU();

              break;
        }     

        case 5:
        {
            datetime.GetSystemDate();
            cout<<"\n\n * Âðåìÿ çàïèñàíî.\n";
            MENU();

              break;
        }              

       

        case 0:
        {
            exit(1);
            break;
        }
        
        default:
        {
            cout<<"\n * Îøèáêà";
            system("cls");
            MENU();
            break;
        }

    }

}

int main()
{
    setlocale(LC_ALL,"Russian"):
    system ("chcp 1251");
    
    MENU();
   


    return 0;
}

