#include<bits/stdc++.h>
using namespace std;

bool fileExists(string fileName){
    ifstream fin(fileName);
    return fin.good();
}

void compileIfNeeded(string executable,string compileCommand){

    if(fileExists(executable)){
        return;
    }

    cout<<"\nCompiling "<<executable<<"...\n";

    int status=system(compileCommand.c_str());

    if(status!=0){
        cout<<"Compilation Failed\n";
        return;
    }

    cout<<"Compilation Successful\n";
}

void showTests(vector<string>& tests,string executable){

    while(true){

        cout<<"\nAvailable Test Files\n\n";

        for(int i=0;i<tests.size();i++){
            cout<<i+1<<". "<<tests[i]<<"\n";
        }

        cout<<tests.size()+1<<". Run All Tests\n";
        cout<<"0. Back\n\n";

        int choice;
        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice==0)return;
        
        if(choice==tests.size()+1){

            for(auto file:tests){

                cout<<"\n====================================\n";
                cout<<"Running "<<file<<"\n";
                cout<<"====================================\n";

                string command=executable+" "+file;

                system(command.c_str());

                cout<<"\n";
            }

            continue;
        }

        if(choice<1 || choice>tests.size()){
            cout<<"Invalid Choice\n";
            continue;
        }

        string command=executable+" "+tests[choice-1];

        system(command.c_str());
    }
}

int main(){

    vector<string> bellmanTests={
        "test_01.txt",
        "test_02.txt",
        "test_03.txt",
        "test_04.txt",
        "test_05.txt",
        "test_06.txt",
        "test_07.txt",
        "test_08.txt",
        "test_09.txt",
        "test_10.txt"
    };

    vector<string> floydTests={
        "test_01.txt",
        "test_02.txt",
        "test_03.txt",
        "test_04.txt",
        "test_05.txt",
        "test_06.txt",
        "test_07.txt",
        "test_08.txt"
    };

    while(true){

        cout<<"\n";
        cout<<"========== ASSIGNMENT 2 ==========\n";
        cout<<"1. Bellman Ford\n";
        cout<<"2. Floyd Warshall\n";
        cout<<"0. Exit\n\n";

        int choice;
        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice==0)break;
        

        if(choice==1){

            compileIfNeeded(
                "bellman_ford",
                "g++ "
                "driver/bellman_ford_driver.cpp "
                "src/bellman_ford.cpp "
                "../assignment_1/src/csr.cpp "
                "-o bellman_ford"
            );

            showTests(bellmanTests,"./bellman_ford");
        }

        else if(choice==2){

            compileIfNeeded(
                "floyd_warshall",
                "g++ "
                "driver/floyd_warshall_driver.cpp "
                "src/floyd_warshall.cpp "
                "-o floyd_warshall"
            );

            showTests(floydTests,"./floyd_warshall");
        }

        else{
             cout<<"Invalid Choice\n";
        }
    }

    return 0;
}