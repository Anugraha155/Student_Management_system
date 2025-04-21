# include <iostream>
# include <fstream>
# include <string>
using namespace std;


// admin features

class Admin {
    public:
    void show(){
        try
        {
            ifstream file ("student_details.csv");

            if (!file.is_open()){
                throw runtime_error("Failed to open file");
            }
            string line;
            while(getline(file,line)){
                cout<<line<<endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr<<"Error" << e.what() << '\n';
        }
        
    }

    void add(){
        int id,age,marks;
        string name;
        try
        {
            ofstream file1("student_details.csv",ios::app);
            
            if(!file1.is_open()){
                throw runtime_error("Failled to Load");
            }
            
            cout<<"Enter ID: ";
            cin>>id;
            cin.ignore(); // flust leftover newline
            cout<<"Enter name: ";
            getline(cin,name); // gives full name including spaces
            cout<<"Enter age: ";
            cin>>age;
            cout<<"Enter marks: ";
            cin>>marks;
            file1<<id<<","<<name<<","<<age<<","<<marks<<"\n";
            
            file1.close();
            cout<<"Record added"<<endl;
        }
        catch(const std::exception& e)
        {
            std::cerr<<"Error" << e.what() << '\n';
        }
        
    }

    void add_more(){
        while (true){
            cout<<"Do you want to add more?\n Press Y if YES or N if NO : ";
            char choice;
            cin>>choice;
            if (choice == 'y' || choice == 'Y'){
                add();
            }
            else{
                //main_menu();
            }
        }

    }

    void del(){
        int id;
        string line;
        cout <<"Enter the ID to remove ";
        cin>>id;
        ifstream delin("student_details.csv");
        ofstream delout("student.csv");

        while (getline(delin,line)){
            int currentid =stoi(line.substr(0,line.find(",")));
            if (currentid!=id){
                delout<<line<<endl;
            }
        }
        delin.close();
        delout.close();
        remove("student_details.csv");
        rename("student.csv","student_details.csv");
        cout<<"Delleted sucessfully"<<endl;
    }
    void del_more(){
        cout<<"Do you want to delete more?\n Press Y if YES or N if NO : ";
        char choice;
        cin>>choice;
        while (true)
        {
            if (choice == 'y' || choice == 'Y'){
                del();
            }
            else{
                //main_menu();
            }
        }
        
    }

};


int main(){

    return 0;
}