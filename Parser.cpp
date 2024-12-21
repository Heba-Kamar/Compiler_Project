#include <iostream>
#include <string>

using namespace std;

struct Rule
{
    string Prod ;
};

bool isSimpleGrammer (Rule rules[4])
{
    if(rules[0].Prod[0] ==rules[1].Prod[0] || (rules[0].Prod[0]>='A'&&rules[0].Prod[0]<='Z') || (rules[1].Prod[0]>='A'&&rules[1].Prod[0]<='Z'))
        return false;
    if(rules[2].Prod[0] ==rules[3].Prod[0] || (rules[2].Prod[0]>='A'&&rules[2].Prod[0]<='Z') || (rules[3].Prod[0]>='A'&&rules[3].Prod[0]<='Z'))
        return false;

    return true;
}

string checkString(string word, Rule rules[4])
{
    string stack="S";
    int stackindex =1;
    int index =0;
    bool match=false;

    while(stackindex > 0 && index < word.size())
    {
       char top =stack[stackindex-1];
       stackindex--;

       for(int i=0; i<4;i++)
       {
           if(top==rules[i].Prod[0])
           {
               for(int j=0; j<rules[i].Prod.size(); j++)
               {
                   stack+=rules[i].Prod[j];
                   stackindex++;
               }
               match = true;
               break;
           }
       }
       if(match=false)
        return "your input string is Reject";
    }

    return "your input string is accept";
}

int main()
{
    Rule rules[4];
    int num=0;
    while(true)
    {
        cout<<"\n Enter rule number 1 for non-terminal 'S': ";
        cin>>rules[0].Prod;
        cout<<"\n Enter rule number 2 for non-terminal 'S': ";
        cin>>rules[1].Prod;
        cout<<"\n Enter rule number 1 for non-terminal 'B': ";
        cin>>rules[2].Prod;
        cout<<"\n Enter rule number 2 for non-terminal 'B': ";
        cin>>rules[3].Prod;

        if(isSimpleGrammer(rules) == false)
        {
            cout<<"\n The Grammer isn't simple.";
            cout<<"\n try again";
            continue;
        }
        else
        {
test_word:  string word;
            cout<<"\n Enter the string want to be checked : ";
            cin>>word;
            cout<<"\n the input string: [";
            for(int i=0;i<word.size();i++)
            {
                cout<<"\'"<<word[i]<<"\'";
                if (i!=word.size()-1)
                    cout<<", ";
            }
            cout<<"] \n ";
            cout<<checkString(word,rules)<<endl;
            cout<<"=============================================\n";
            cout<<"1. Another Grammar\n";
            cout<<"2. Another String\n";
            cout<<"3. Exit\n";
            cin>>num;
            if(num==1)
                continue;
            else if(num==2)
                goto test_word;
            else if(num==3)
                break;

        }
    }
    return 0;
}
