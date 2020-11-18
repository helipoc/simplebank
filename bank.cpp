#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "./Classes/bankAccount.cpp"
#include "./Classes/accountList.cpp"


void addAccount();
void LoadAccounts();
void SaveData();
void searchAcc();
std::vector<std::string> split(std::string,std::string);
void removeAcc();
void login(int,std::string);
void userArea();
void SendMoney();
void Menu();
using namespace std;



accountList lista;
bankAccount* User;
int main(){


LoadAccounts();
Menu();

return 0;
}


void Menu(){
    int c;
    cout<<"1- Add a new account"<<endl;
    cout<<"2- Show all accounts"<<endl;
    cout<<"3- Search an account"<<endl;
    cout<<"4- delete an account"<<endl;
    cout<<"5- User Area"<<endl;
    cout<<"0- Save and exit"<<endl;

    do {
        cin>>c;
        switch(c){
            case 1:
            addAccount();
            break;
            case 2:
            lista.showAll();
            break;
            case 3:
            searchAcc();
            break;
            case 4:
            removeAcc();
            break;
            case 5:
            userArea();
            break;
            default:
            break;
        }
        if(c!=0)Menu();
    }while(c!=0);
    cout<<"Bye";
    SaveData();
    exit(1);
    
}


void addAccount(){
    bankAccount* b = new bankAccount;
    cout<<"ID: ";
    cin>>b->id;
    cout<<"Name: ";
    cin>>b->name;
    cout<<"Password: ";
    cin>>b->password;
    cout<<"Solde: ";
    cin>>b->solde;
    lista.addAccount(b);
}



void searchAcc(){
    int id;
    cout<<"User ID : ";
    cin>>id;
    bankAccount* acc = lista.findAcc(id);
    if(acc==NULL){
        cout<<"User not found !"<<endl;
        return;
    }
    acc->showInfo();
}


void removeAcc(){
    int d;
    cout<<"User ID :";
    cin>>d;
    lista.deleteAcc(d);
}


void login(int d,string p){
    User=lista.login(d,p);
}


void userArea(){
    
int id;
string pass;
int c;

system("cls");
do{
    cout<<"ID :";
    cin>>id;
    cout<<"password :";
    cin>>pass;
    login(id,pass);
}while(User==NULL);

do{

cout<<"1- show you info"<<endl;
cout<<"2- send money"<<endl;
cout<<"3- delete my account"<<endl;
cout<<"0- go back"<<endl;
cin>>c;
switch(c){
case 1:
User->showInfo();
break;
case 2:
SendMoney();
break;
case 3:
lista.deleteAcc(User->id);
break;
case 0:
Menu();
break;

}

}while(1);


}


void SendMoney(){
    int d,p;
    cout<<"Client Id :";
    cin>>d;
    cout<<"Amount to send :";
    cin>>p;
    bankAccount* client = lista.findAcc(d);
    if(client!=NULL){
        User->sendMoney(client,p);
        return;
    }
    cout<<"Client not found"<<endl;
    
}

void LoadAccounts(){
    string line;
    int ctr=0;
    vector<string> s;
    ifstream f("data");
    if(!f.is_open()){
        cout<<"Filenot found"<<endl;
        return;
    }


    while(getline(f,line)){
        bankAccount *b = new bankAccount;
        s=split(line," ");
        
        
        b->id=atoi(s.at(0).data());
        b->name=s.at(1);
        b->password=s.at(2);
        b->solde=(double)atoi(s.at(3).data());
        lista.addAccount(b);
        ctr++;

    }
    cout<<"[+] Loaded "<<ctr<<" Accounts !"<<endl;
}



void SaveData(){

    ofstream f;
    f.open("data");
    if(!f.is_open()){
        cout<<"Error opening file"<<endl;
        return;
    }
    for(map<int,bankAccount*>::iterator b=lista.Users.begin();b!=lista.Users.end();++b){
        bankAccount * tmp = b->second;
        f<<tmp->id<<" "<<tmp->name<<" "<<tmp->password<<" "<<tmp->solde<<endl;  
    }
    f.close();
    cout<<"[+] Saved successfuly"<<endl;
}

vector<string> split (string ss,string sp){
    size_t start = 0,end,splen=sp.length();
    string token;
    vector<string> last;

    while((end=ss.find(sp,start))!=string::npos){
        token=ss.substr(start,end-start);
        start=end+splen;
        last.push_back(token);
    }
    last.push_back(ss.substr(start));
    return last;
}