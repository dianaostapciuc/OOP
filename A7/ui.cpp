#include "ui.h"
#include <iostream>
#include <windows.h>
#include <shellapi.h>
#include <crtdbg.h>
#define EXIT 0
#define ADMINISTRATOR 1
#define ADD 1
#define DELETING 2
#define UPDATE 3
#define DISPLAY 4
#define DISPLAY_HTML_CSV 5
#define USER 2
#define DOG_LIST 1
#define FILTER 2
#define ADOPTION_LIST 3
using namespace std;

string read_listing_mode()
{
    string buffer;
    cout<<"Choose a listing mode: ";
    cin>>buffer;
    cout<<endl;
    bool is_valid = 0;
    while(!is_valid)
    {
        try {
            is_valid = 1;
            validators::validate_listing(buffer);
        }
        catch(exception_validator)
        {
            cout<<"Try inputting html or csv.\n";
            cin>>buffer;
            is_valid = 0;
        }
    }
    return buffer;
}

ui::ui(services service1, string list_mode): service(service1)
{
    this->listing_mode = list_mode;
}

bool ui::validate_input_command(string input) {
    for (int i = 0; i <input.length(); i++)
        if (isdigit(input[i]) == false)
            return false;
    return true;
}
void ui::menu()
{
    cout<<"The Keep calm and adopt a pet shelter has 2 ways of being accessed: \n";
    cout<<"1. Administrator mode. \n"<<"2. User mode. \n"<<"0. Exit.\n";
    cout<<"Which one would you like to access?\n";

    while(true)
    {
        string command1;
        cin>>command1;

        int checking_command = validate_input_command(command1);
        while (checking_command == false)
        {
            cout<<"Try inputting an integer.\n";
            cin>>command1;
            checking_command = validate_input_command(command1);
        }
        int command;
        command = stoi(command1);

        switch(command)
        {
            case EXIT:
            {
                exit(0);
            }
            case ADMINISTRATOR:
            {
                cout<<"You are now in ADMINISTRATOR mode! What do you want to do?\n";
                cout<<"1. Adding a dog.\n";
                cout<<"2. Deleting a dog.\n";
                cout<<"3. Update the information of a dog.\n";
                cout<<"4. Display all dogs.\n";
                cout<<"5. Display in a HTML/CSV file.\n";
                cout<<"What's the mode you wanna access?\n";
                string choice1;
                cin>>choice1;

                int check_command = validate_input_command(choice1);
                while (check_command == false)
                {
                    cout<<"Try inputting an integer.\n";
                    cin>>choice1;
                    check_command = validate_input_command(choice1);
                }
                int choice;
                choice = stoi(choice1);
                while (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5)
                {
                    cout<<"Invalid integer... try again!\n";
                    cin>>choice;
                }
                switch(choice)
                {
                    case ADD:
                    {
                        bool check;
                        string breed, name, photo;
                        int age;
                        cout<<"Breed:\n";
                        cin>>breed;
                        cout<<"Name:\n";
                        cin>>name;
                        cout<<"Age:\n";
                        cin>>age;
                        cout<<"Photo:\n";
                        cin>>photo;
                        try
                        {
                            validators::validate_breed(breed);
                            validators::validate_name(name);
                            validators::validate_age(age);
                            validators::validate_link(photo);
                        }
                        catch(exception_validator)
                        {
                            cout<<"The input for the dog is wrong.\n";
                            cout<<"What's the mode you wanna access?\n";
                            break;
                        }
                        try{
                            check = this->service.add_service(breed, name, age, photo);
                        }
                        catch(exception_repository)
                        {
                            cout<<"Couldn't be added.\n";
                        }
                        if(check == false)
                            cout<<"It has been added.\n";
                        cout<<"What's the mode you wanna access?\n";
                        break;
                    }
                    case DELETING:
                    {
                        int check;
                        string name;
                        cout<<"Name:\n";
                        cin>>name;
                        try
                        {
                            validators::validate_name(name);
                        }
                        catch(exception_validator)
                        {
                            cout<<"The input for the dog is wrong.\n";
                            cout<<"What's the mode you wanna access?\n";
                            break;
                        }
                        try
                        {
                            check = this->service.delete_service(name);
                        }
                        catch(exception_repository)
                        {
                            cout<<"Couldn't be deleted\n";
                        }
                        if (check == true)
                            cout<<"It has been deleted!\n";
                        cout<<"What's the mode you wanna access?\n";
                        break;
                    }
                    case UPDATE:
                    {
                        int check;
                        string old_name, new_name, breed, photo;
                        int age;
                        cout<<"Who's info do you wanna update?\n";
                        cin>>old_name;
                        cout<<"Update it with name:\n";
                        cin>>new_name;
                        cout<<"Breed:\n";
                        cin>>breed;
                        cout<<"Age:\n";
                        cin>>age;
                        cout<<"Photo:\n";
                        cin>>photo;
                        try
                        {
                            validators::validate_breed(breed);
                            validators::validate_name(old_name);
                            validators::validate_name(new_name);
                            validators::validate_age(age);
                            validators::validate_link(photo);
                        }
                        catch(exception_validator)
                        {
                            cout<<"The input for the dog is wrong.\n";
                            cout<<"What's the mode you wanna access?\n";
                            break;
                        }
                        try {
                            check = this->service.updating_service(old_name, new_name, breed, age, photo);
                        }
                        catch(exception_repository)
                        {
                            cout<<"Couldn't be updated.\n";
                        }
                        if (check == true)
                            cout<<"It has been updated!\n";
                        cout<<"What's the mode you wanna access?\n";
                        break;
                    }
                    case DISPLAY:
                    {
                        for (int index=0; index<this->service.get_number_of_dogs(); index++)
                            cout<<this->service.display_each_dog(index);
                        cout<<"What's the mode you wanna access?\n";
                        break;
                    }
                    case DISPLAY_HTML_CSV:
                    {
                        this->service.load_listing();
                        if(this->listing_mode == "html"){
                            std::string url = R"(D:\Git\OOP-GIT\a7-xdianaost-1\cmake-build-debug\dogs.html)";
                            std::string comm = "start chrome " + url;
                            system(comm.c_str());
                        }
                        else{
                            std::string file_path = "D:\\Git\\OOP-GIT\\a7-xdianaost-1\\cmake-build-debug\\dogs.csv";
                            std::string comm = "start excel.exe " + file_path;
                            system(comm.c_str());
                        }
                        cout<<"What's the mode you wanna access?\n";
                        break;
                    }
                    default:
                    {
                        cout<<"There is no such command.\n";
                        cout<<"What's the mode you wanna access?\n";
                        break;
                    }
                }
                break;
            }
            case USER:
            {
                cout<<"You are now in USER mode! What do you want to do?\n";
                cout<<"1. See the dogs in the database one by one (and possibly adopt).\n";
                cout<<"2. See all dogs of a given breed.\n";
                cout<<"3. See adoption list.\n";
                cout<<"What's the mode you wanna access?\n";
                string choice2;
                cin >> choice2;

                int check_command = validate_input_command(choice2);
                while (check_command == false)
                {
                    cout<<"Try inputting an integer.\n";
                    cin >> choice2;
                    check_command = validate_input_command(choice2);
                }
                int choice;
                choice = stoi(choice2);
                while (choice!=1 && choice!=2 && choice!=3)
                {
                    cout<<"Invalid integer... try again!\n";
                    cin>>choice;
                }
                switch(choice)
                {
                    case DOG_LIST: {
                        for (auto i = this->service.get_services().begin(); i!=this->service.get_services().end(); i++) {
                            cout << i->turn_into_string() << "\n";
                            string string = i->get_photo();
                            char* result = const_cast<char *>(string.c_str());
                            ShellExecuteA(NULL, NULL, "chrome.exe", result, NULL, SW_SHOWMAXIMIZED);
                            cout << "Would you wish to adopt this beautiful dog?\n" << "Enter 1 for YES, 0 for NO.\n";
                            int adopt;
                            cin >> adopt;
                            while (choice != 1 && choice != 0) {
                                cout << "Try another integer..\n";
                                cin >> adopt;
                            }
                            if (adopt == 1) {
                                this->service.adding_to_adoption_list(*i);
                                this->service.delete_service(i->get_name());
                                cout << "What's the mode you wanna access?\n";
                                break;
                            }
                            if (i->get_name() == (this->service.get_services().end()-1)->get_name()) {
                                cout << "All the dogs have been displayed! Would you like to see them again?\n";
                                cout << "Input 1 for next, 0 for exiting.\n";
                                int next;
                                cin >> next;
                                while (next != 1 && next != 0) {
                                    cout << "Try another integer..\n";
                                    cin >> next;
                                }
                                if (next == 1)
                                    i = this->service.get_services().begin()-1;
                                else cout << "What's the mode you wanna access?\n";

                            }
                        }
                        break;
                    }
                    case FILTER: {
                        string breed;
                        int age;
                        cout << "Breed:\n";
                        cin >> breed;
                        cout << "Age:\n";
                        cin >> age;
                        this->service.sorting_the_array_of_dogs(breed, age);
                        for(auto i = this->service.get_sorted_services().begin(); i!=this->service.get_sorted_services().end(); i++) {
                            cout << i->turn_into_string() << "\n";
                            string string = i->get_photo();
                            char* result = const_cast<char *>(string.c_str());
                            ShellExecuteA(NULL, NULL, "chrome.exe", result, NULL, SW_SHOWMAXIMIZED);
                            cout << "Would you wish to adopt this beautiful dog?\n" << "Enter 1 for YES, 0 for NO.\n";
                            int adopt;
                            cin >> adopt;
                            while (adopt != 1 && adopt != 0) {
                                cout << "Try another integer..\n";
                                cin >> adopt;
                            }
                            if (adopt == 1) {
                                this->service.adding_to_adoption_list(*i);
                                this->service.delete_service(i->get_name());
                                this->service.delete_dog_from_sorted_list(i->get_name());
                                cout << "What's the mode you wanna access?\n";
                                break;
                            }
                            if (i->get_name() == (this->service.get_sorted_services().end()-1)->get_name()) {
                                cout << "All the dogs have been displayed! Would you like to see them again?\n";
                                cout << "Input 1 for next, 0 for exiting.\n";
                                int next;
                                cin >> next;
                                while (next != 1 && next != 0) {
                                    cout << "Try another integer..\n";
                                    cin >> next;
                                }
                                if (next == 1)
                                    i = this->service.get_sorted_services().begin()-1;
                                else cout << "What's the mode you wanna access?\n";
                            }
                        }
                            break;
                        }
                    case ADOPTION_LIST:
                    {
                        cout << this->service.displaying_adoption_list();
                        cout<<"What's the mode you wanna access?\n";
                        break;
                    }
                }
                break;
            }
            default:
            {
                cout<<"Please entry a valid input!\n";
                break;
            }
        }

    }

}

int main()
{
    file_repo fr("startup_entries.txt");
    file_repo fr2("startup_entries.txt");
    string listing_mode = read_listing_mode();
    services service(fr, &fr2, listing_mode);
    ui uis(service, listing_mode);
    uis.menu();
    cout<<"\nResult of memory dumps: "<<_CrtDumpMemoryLeaks()<<"\n";
    return 0;
}
