# include <iostream>
# include <fstream>
# include <string>
using namespace std;


// admin features

class Admin {
    protected:
    int id,age,marks;
    string name;
    string line;
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
            cout<<"Do you want to add more?\nPress Y if YES or N if NO : ";
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
        while (true)
        {
            cout<<"Do you want to delete more?\nPress Y if YES or N if NO : ";
            char choice;
            cin>>choice;
            if (choice == 'y' || choice == 'Y'){
                del();
            }
            else{
                //main_menu();
            }
        }
        
    }

};

class Student : virtual protected Admin {
    public:
    void details(){
        ifstream detail("Records.csv");
        cout<<"Enter your ID : ";
        cin >>id;
        int currentLine=0;
        while (getline(detail,line))
        {
            currentLine++;
            if (currentLine==id){
                cout<<line;
                break;
            }
        }
        
        
    }
    void comment(){
        string comment;
        try
        {
            ofstream feadback ("Studentfeadback.txt",ios::app);
            if (!feadback.is_open())
            {
                throw runtime_error ("Error Occured...");
            }
            cout << "Enter your Feadback : ";
            cin.ignore();
            getline(cin,comment);
            feadback<<comment;
            cout<<"Your feedback is :"<<comment<<endl;
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }

};

class display : virtual Admin,Student{
 public:
    void main_menu(){
        cout<<"\t\t|----------WELCOME USER--------------|"<<endl;
        cout<<"\t\t|                                    |"<<endl;
        cout<<"\t\t|        1. Admin                    |"<<endl;
        cout<<"\t\t|                                    |"<<endl;
        cout<<"\t\t|        2. Student                  |"<<endl;
        cout<<"\t\t|                                    |"<<endl;
        cout<<"\t\t|                                    |"<<endl;
        cout<<"\t\t|------------------------------------|"<<endl;
    
        int choice;
        cout<<"Select 1 or 2 : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            Admin_display();
            break;
            case 2:
            Student_display();
            break;
        
        default:
            cout<<"Not a valid command Enter 1 or 2";
            break;
        }
    }

    void Admin_display(){
        cout<<"\t\t|----------WELCOME Admin-------------|"<<endl;
        cout<<"\t\t|                                    |"<<endl;
        cout<<"\t\t|        1. View Student details     |"<<endl;
        cout<<"\t\t|        2. Add Student              |"<<endl;
        cout<<"\t\t|        3. Delete Student           |"<<endl;
        cout<<"\t\t|        4.Back to main menu         |"<<endl;
        cout<<"\t\t|                                    |"<<endl;
        cout<<"\t\t|------------------------------------|"<<endl;
    
        int choice;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            show();
            break;
            case 2: 
            add();
            break;
            case 3:
            del();
            break;
            case 4:
            main_menu();
            break;
        default:
        cout<<"Enter valid command";
            break;
        }
    }
    
    void Student_display(){
        cout<<"\t\t|----------WELCOME STUDENT-------------|"<<endl;
        cout<<"\t\t|                                      |"<<endl;
        cout<<"\t\t|                                      |"<<endl;
        cout<<"\t\t|        1. View YOUR DETAILS          |"<<endl;
        cout<<"\t\t|        2. Give your comment          |"<<endl;
        cout<<"\t\t|        3. Back to main menu          |"<<endl;
        cout<<"\t\t|                                      |"<<endl;
        cout<<"\t\t|--------------------------------------|"<<endl;

        int choice;
        cout<<"Enter your Choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            details();
            break;
            case 2:
            comment();
            break;
            case 3:
            main_menu();
            break;
            default:
            cout<<"Not a valid command";
            break;
        }
    }
    
};


int main(){
    display d1;
    d1.main_menu();
    d1.Admin_display();
    d1.Student_display();
    return 0;
}