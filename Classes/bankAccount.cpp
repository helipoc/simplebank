
#pragma once

class  bankAccount{
public:
double solde;
std::string name;
std::string password;
int id;
bankAccount();
bankAccount(std::string,std::string,int);
void addSolde(int);
void removeSolde(int);
void sendMoney(bankAccount*,int);
void showInfo();

};



// implementation 
bankAccount::bankAccount(){}

bankAccount::bankAccount(std::string nm,std::string pass,int id){
this->name=nm;
this->password=pass;
this->id=id;
this->solde=0;
}

void bankAccount::addSolde(int m){
    this->solde+=std::abs(m);
}
void bankAccount::removeSolde(int m){
    this->solde-=std::abs(m);
}

void bankAccount::showInfo(){
    std::cout<<"########################"<<std::endl;
    std::cout<<"# Numero:  "<<this->id<<std::endl;
    std::cout<<"# Name:    "<<this->name<<std::endl;
    std::cout<<"# Solde:   "<<this->solde<<std::endl;
    std::cout<<"########################"<<std::endl;
    std::cout<<std::endl;
}

void bankAccount::sendMoney(bankAccount* ptr,int m){
    if(this->solde>=m ){
        ptr->addSolde(m);
        this->removeSolde(m);
        std::cout<<"Transaction successd to "<<ptr->name<<std::endl;
    }else {
        std::cout<<"Solde isn't enough"<<std::endl;
        return;
    }
}
