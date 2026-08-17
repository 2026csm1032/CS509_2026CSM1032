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

        if(choice==0){
            return;
        }

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

    vector<string> mstTests={
        "mst_10.txt",
        "mst_100_a.txt",
        "mst_100_b.txt",
        "mst_10000_a.txt",
        "mst_10000_b.txt",
        "mst_50000_a.txt",
        "mst_50000_b.txt",
        "mst_100000_a.txt",
        "mst_100000_b.txt",
    };

    while(true){

        cout<<"\n";
        cout<<"========== ASSIGNMENT 3 ==========\n";
        cout<<"1. Kruskal MST\n";
        cout<<"2. Prim MST\n";
        cout<<"0. Exit\n\n";

        int choice;
        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice==0){
            break;
        }

        if(choice==1){

            compileIfNeeded(
                "kruskal.exe",
                "g++ "
                "driver/kruskal_driver.cpp "
                "src/kruskal.cpp "
                "../assignment_1/src/csr.cpp "
                "-o kruskal.exe"
            );

            showTests(
                mstTests,
                ".\\kruskal.exe"
            );
        }

        else if(choice==2){

            compileIfNeeded(
                "prim.exe",
                "g++ "
                "driver/prim_driver.cpp "
                "src/prim.cpp "
                "../assignment_1/src/csr.cpp "
                "-o prim.exe"
            );

            showTests(
                mstTests,
                ".\\prim.exe"
            );
        }

        else{
            cout<<"Invalid Choice\n";
        }
    }

    return 0;
}