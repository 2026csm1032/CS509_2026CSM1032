#include<bits/stdc++.h>
using namespace std;

bool fileExists(string fileName){

    ifstream fin(fileName);

    return fin.good();
}

void compileIfNeeded(string exeName,string compileCommand){

    if(!fileExists(exeName)){

        cout<<"Compiling "<<exeName<<"...\n";

        system(compileCommand.c_str());
    }
}

void runVertexColoring(){

    compileIfNeeded("vertex_coloring.exe","g++ driver/vertex_coloring_driver.cpp src/vertex_coloring.cpp ../assignment_1/src/csr.cpp -o vertex_coloring.exe");

    vector<string> tests={
        "color_10.txt",
        "color_100.txt",
        "color_10000.txt",
        "color_50000.txt",
        "color_100000.txt"
    };

    cout<<"\nAvailable Test Files\n\n";

    for(int i=0;i<tests.size();i++){

        cout<<i+1<<". "<<tests[i]<<"\n";
    }

    cout<<tests.size()+1<<". Run All\n";

    int choice;

    cout<<"\nEnter choice: ";
    cin>>choice;

    if(choice==tests.size()+1){

        for(int i=0;i<tests.size();i++){

            string command="vertex_coloring.exe "+tests[i];

            system(command.c_str());
        }
    }

    else if(choice>=1 && choice<=tests.size()){

        string command="vertex_coloring.exe "+tests[choice-1];

        system(command.c_str());
    }

    else{

        cout<<"Invalid Choice\n";
    }
}

void runPageRank(){

    compileIfNeeded("pagerank.exe","g++ driver/pagerank_driver.cpp src/pagerank.cpp ../assignment_1/src/csr.cpp -o pagerank.exe");

    vector<string> tests={
        "pagerank_10.txt",
        "pagerank_100.txt",
        "pagerank_1000.txt",
        "pagerank_10000.txt",
        "pagerank_50000.txt"
    };

    cout<<"\nAvailable Test Files\n\n";

    for(int i=0;i<tests.size();i++){

        cout<<i+1<<". "<<tests[i]<<"\n";
    }

    cout<<tests.size()+1<<". Run All\n";

    int choice;

    cout<<"\nEnter choice: ";
    cin>>choice;

    if(choice==tests.size()+1){

        for(int i=0;i<tests.size();i++){

            string command="pagerank.exe "+tests[i];

            system(command.c_str());
        }
    }

    else if(choice>=1 && choice<=tests.size()){

        string command="pagerank.exe "+tests[choice-1];

        system(command.c_str());
    }

    else{

        cout<<"Invalid Choice\n";
    }
}

int main(){

    while(true){

        cout<<"\n========== ASSIGNMENT 4 ==========\n";
        cout<<"1. Vertex Coloring\n";
        cout<<"2. PageRank\n";
        cout<<"0. Exit\n";

        int choice;

        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice==0){

            break;
        }

        else if(choice==1){

            runVertexColoring();
        }

        else if(choice==2){

            runPageRank();
        }

        else{

            cout<<"Invalid Choice\n";
        }
    }

    return 0;
}