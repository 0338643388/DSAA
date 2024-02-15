#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct Product{
    string name;
    int quanlity;
    int price;
    friend istream& operator >> (istream &in, Product &product){
        cout << "NHAP TEN: ";
        in.ignore();
        getline(in, product.name);
        cout << "NHAP SO LUONG: ";
        in >> product.quanlity;
        cout << "NHAP GIA: ";
        in >> product.price;
        
        return in;
    }
    friend ostream& operator << (ostream &out, Product &product){
        out << "TEN: " << product.name<<endl;
        out << "SO LUONG: "<< product.quanlity<<endl;
        out << "GIA: "<< product.price;

        return out;
    }
};


int showMenu();
void print_product(Product *products, int size);
void add_product(Product *&products, int &size);
void remove_product(Product *&products, int &size);

int main() {
    int size =0;
    Product *products = new Product[size];
    while(true){
        int choose = showMenu();
        system("cls");
        switch (choose)
        {
        case 1:
            print_product(products, size);
            break;
        case 2:
            add_product(products, size);
            break;
        case 3:
            remove_product(products, size);
            break;
        case 0:
            cout << "BYE BYE!!!";
            return 0;
        default:
            cout <<"LUA CHON KHONG HOP LE.";
        }
        cout<<"BAN CO MUON TIEP TUC KHONG?(1/0)";
        bool is_continue;
        cin >> is_continue;
        if(is_continue == false){
            cout << "BYE BYE!!!"<<endl;
            break;
        }
    }

    


    return 0;
}


int showMenu(){
    system ("cls");
    int choose;
    cout <<"-------MENU------"<<endl;
    cout << "1. XEM SAN PHAM"<<endl;
    cout << "2. THEM SAN PHAM"<<endl;
    cout << "3. XOA SAN PHAM"<<endl;
    cout << "0. THOAT"<<endl;
    cout << "LUA CHON CUA BAN LA: ";
    cin>> choose;
    return choose;
}

void print_product(Product *products, int size){
    if(size == 0){
        cout <<"K CO SAN PHAM NAO."<<endl;
    } else{
        cout << "DANH SACH SAN PHAM: "<<endl;
        for(int i =0; i<size; i++){
            cout << products[i] <<endl;
        }
    }
}


void add_product(Product *&products, int &size){
    Product new_product;
    cout <<"NHAP SAN PHAM MOI:"<<endl;
    cin >> new_product;
    int new_size = size +1;
    Product *tmp_product = new Product[new_size];
    for(int i =0; i<size ; i++){
        tmp_product[i] = products[i];
    }
    tmp_product[new_size-1] = new_product;
    delete[] products;
    products = tmp_product;
    size = new_size;

    cout << "THEM SAP PHAM THANH CONG."<<endl;
}


void remove_product(Product *&products, int &size){
    string name_product;
    cout << "NHAP TEN SAN PHAM CAN XOA: ";
    cin.ignore();
    getline(cin , name_product);
    
    int del_index = -1;
    for(int i =0; i<size; i++){
        if(name_product.compare(products[i].name)==0){
            del_index = i;
            break;
        }
    }
    if(del_index==-1){
        cout << "KHONG TIM THAY SAN PHAM."<<endl;
        return;
    }

    for(int i = del_index; i<size-1; i++){
        products[i] = products[i+1];
    }
    size--;

    Product *tmp_product = new Product[size];
    for(int i =0; i<size; i++){
        tmp_product[i] = products[i];
    }
    delete[] products;
    products = tmp_product;
    cout <<"XOA THANH CONG."<<endl;

}



 
