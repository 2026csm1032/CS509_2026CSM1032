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

    vector<string> gemmTests={
        "test_01.txt",
        "test_02.txt",
        "test_03.txt",
        "test_04.txt",
        "test_05.txt",
        "test_06.txt"
    };

    vector<string> csrTests={
        "csr_test_01.txt",
        "csr_test_02.txt",
        "csr_test_03.txt",
        "csr_test_04.txt",
        "csr_test_05.txt",
        "csr_test_06.txt",
        "csr_test_07.txt",
        "csr_test_08.txt",
        "csr_test_09.txt",
        "csr_test_10.txt"
    };

    while(true){

        cout<<"\n";
        cout<<"========== ASSIGNMENT 1 ==========\n";
        cout<<"1. GEMM\n";
        cout<<"2. CSR\n";
        cout<<"0. Exit\n\n";

        int choice;
        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice==0){
            break;
        }

        if(choice==1){

            compileIfNeeded(
                "gemm.exe",
                "g++ "
                "driver/gemm_driver.cpp "
                "src/gemm_simple.cpp "
                "src/gemm_blocking.cpp "
                "-o gemm.exe"
            );

            showTests(gemmTests,".\\gemm.exe");
        }

        else if(choice==2){

            compileIfNeeded(
                "csr.exe",
                "g++ "
                "driver/csr_driver.cpp "
                "src/csr.cpp "
                "-o csr.exe"
            );

            showTests(csrTests,".\\csr.exe");
        }

        else{

            cout<<"Invalid Choice\n";
        }
    }

    return 0;
}