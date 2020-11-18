#include <map>
#include "bankAccount.cpp"

class accountList {
    public:
    std::map<int,bankAccount*> Users;
    accountList();
    void addAccount(bankAccount*);
    void showAll();
    bankAccount* findAcc(int);
    void deleteAcc(int);
    bankAccount* login(int,std::string);


};


//implemetation


accountList::accountList(){}

void accountList::addAccount(bankAccount *b){
    if(this->Users.find(b->id)==this->Users.end()){
        this->Users[b->id]=b;
        return;
    }
    std::cout<<"ID already exists !"<<std::endl;
}


void accountList::showAll(){
    std::map<int,bankAccount*>::iterator it;
    for(it=this->Users.begin();it!=this->Users.end();++it){
        it->second->showInfo();
    }
}


bankAccount* accountList::findAcc(int d){
    std::map<int,bankAccount*>::iterator b = this->Users.find(d);
    if(b==this->Users.end()){
        return NULL;
    }
    return b->second;
}


void accountList::deleteAcc(int d){
    std::map<int,bankAccount*>::iterator acc = this->Users.find(d);
    if(acc==this->Users.end()){
        std::cout<<"Account not Found"<<std::endl;
        return;
    }
    this->Users.erase(d);
    delete acc->second;
}


bankAccount* accountList::login(int d,std::string p){

bankAccount* b = findAcc(d);

if(b->id==d && b->password==p){
std::cout<<"[*] Success login "<<std::endl;
return b;
}

std::cout<<"Invalid ID OR Password"<<std::endl;
return NULL;
}