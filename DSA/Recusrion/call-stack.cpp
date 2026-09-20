void A(){
    cout<<"A"<<endl;
    B();
    cout<<"A"<<endl;
}
void B(){
    cout<<"B"<<endl;
}

int main(){
    cout<<"Calling A"<<endl;
    A();
    cout<<"Back in main"<<endl;

    cout<<"Calling B"<<endl;
    B();
    cout<<"Back in main"<<endl;
}