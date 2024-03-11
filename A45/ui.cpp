#include "ui.h"
#include <iostream>
#include <windows.h>
#include <shellapi.h>
#include <stdlib.h>
#include <crtdbg.h>


using namespace std;

ui::ui(services service1): service(service1)
{
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

    while(1)
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
            case 0:
            {
                exit(0);
            }
            case 1:
            {
                cout<<"You are now in ADMINISTRATOR mode! What do you want to do?\n";
                cout<<"1. Adding a dog.\n";
                cout<<"2. Deleting a dog.\n";
                cout<<"3. Update the information of a dog.\n";
                cout<<"4. Display all dogs.\n";
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
                while (choice!=1 && choice!=2 && choice!=3 && choice!=4)
                {
                    cout<<"Invalid integer... try again!\n";
                    cin>>choice;
                }
                switch(choice)
                {
                    case 1:
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
                        check = this->service.add_service(breed, name, age, photo);
                        if (check == true)
                            cout<<"It has NOT been added!\n";
                        else cout<<"It has been added!\n";
                        cout<<"What's the mode you wanna access?\n";
                        break;
                    }
                    case 2:
                    {
                        int check;
                        string name;
                        cout<<"Name:\n";
                        cin>>name;
                        check = this->service.delete_service(name);
                        if (check == false)
                            cout<<"The dog doesn't exist!\n";
                        else cout<<"It has been deleted!\n";
                        cout<<"What's the mode you wanna access?\n";
                        break;
                    }
                    case 3:
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
                        check = this->service.updating_service(old_name, new_name, breed, age, photo);
                        if (check == false)
                            cout<<"The dog doesn't exist!\n";
                        else cout<<"It has been updated!\n";
                        cout<<"What's the mode you wanna access?\n";
                        break;
                    }
                    case 4:
                    {
                        for (int index=0; index<this->service.get_number_of_dogs(); index++)
                            cout<<this->service.display_each_dog(index);
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
            case 2:
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
                    case 1: {
                        int i;
                        for (i = 0; i < this->service.get_number_of_dogs(); i++) {
                            cout << this->service.get_services()[i].turn_into_string() << "\n";
                            string string = this->service.get_services()[i].get_photo();
                            char *result = const_cast<char *>(string.c_str());
                            ShellExecuteA(NULL, NULL, "chrome.exe", result, NULL, SW_SHOWMAXIMIZED);
                            cout << "Would you wish to adopt this beautiful dog?\n" << "Enter 1 for YES, 0 for NO.\n";
                            int adopt;
                            cin >> adopt;
                            while (choice != 1 && choice != 0) {
                                cout << "Try another integer..\n";
                                cin >> adopt;
                            }
                            if (adopt == 1) {
                                this->service.adding_to_adoption_list(this->service.get_services()[i]);
                                this->service.delete_service(this->service.get_services()[i].get_name());
                                cout << "What's the mode you wanna access?\n";
                                break;
                            }
                            if (i == this->service.get_number_of_dogs() - 1) {
                                cout << "All the dogs have been displayed! Would you like to see them again?\n";
                                cout << "Input 1 for next, 0 for exiting.\n";
                                int next;
                                cin >> next;
                                while (next != 1 && next != 0) {
                                    cout << "Try another integer..\n";
                                    cin >> next;
                                }
                                if (next == 1)
                                    i = -1;
                                else cout << "What's the mode you wanna access?\n";

                            }
                        }
                        break;
                    }
                    case 2: {
                        string breed;
                        int age;
                        cout << "Breed:\n";
                        cin >> breed;
                        cout << "Age:\n";
                        cin >> age;
                        this->service.sorting_the_array_of_dogs(breed, age);
                        int i;
                        for (i = 0; i < this->service.get_number_of_sorted_dogs(); i++) {
                            cout << this->service.get_sorted_services()[i].turn_into_string() << "\n";
                            string string = this->service.get_sorted_services()[i].get_photo();
                            char *result = const_cast<char *>(string.c_str());
                            ShellExecuteA(NULL, NULL, "chrome.exe", result, NULL, SW_SHOWMAXIMIZED);
                            cout << "Would you wish to adopt this beautiful dog?\n" << "Enter 1 for YES, 0 for NO.\n";
                            int adopt;
                            cin >> adopt;
                            while (adopt != 1 && adopt != 0) {
                                cout << "Try another integer..\n";
                                cin >> adopt;
                            }
                            if (adopt == 1) {
                                this->service.adding_to_adoption_list(this->service.get_sorted_services()[i]);
                                this->service.delete_service(this->service.get_sorted_services()[i].get_name());
                                this->service.delete_dog_from_sorted_list(this->service.get_sorted_services()[i].get_name());
                                cout << "What's the mode you wanna access?\n";
                                break;
                            }
                            if (i == this->service.get_number_of_sorted_dogs() - 1) {
                                cout << "All the dogs have been displayed! Would you like to see them again?\n";
                                cout << "Input 1 for next, 0 for exiting.\n";
                                int next;
                                cin >> next;
                                while (next != 1 && next != 0) {
                                    cout << "Try another integer..\n";
                                    cin >> next;
                                }
                                if (next == 1)
                                    i = -1;
                                else cout << "What's the mode you wanna access?\n";
                            }
                        }
                            break;
                        }
                    case 3:
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
    testing_domain();
    testing_dynamic_array();
    testing_repo();
    testing_services();
    _CrtDumpMemoryLeaks();
    DynamicArray<Dog> dynamic_array;
    DynamicArray<Dog> dynamic_array_dogs;
    DynamicArray<Dog> sorted_array_dogs;
    dynamic_array.creating_dynamic_array(20);
    dynamic_array_dogs.creating_dynamic_array(20);
    sorted_array_dogs.creating_dynamic_array(20);
    repository repo(dynamic_array, dynamic_array_dogs, sorted_array_dogs);
    repo.generating_startup_entries();
    services service(repo);
    ui uis(service);
    uis.menu();
}
