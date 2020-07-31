#include <chrono>
#include "Dictionary.h"
#include "Node.h"

int main()
{
    ifstream RawFile;
    Dictionary* Dic = new Dictionary;
    Dic->Init();
    InitList();
    string InputName;
    cout << "What is the name of the txt file that you would like to process?" << "\n";
    cout << "Case sensitive; do not include filename's extension" << "\n";

    cin >> InputName;
    RawFile.open("RawFile/" + InputName + ".txt");
    OutFileAlpha.open("ProcessedFile/" + InputName + " Alphabetically.txt");
    OutFileNumer.open("ProcessedFile/" + InputName + " Numerically.txt");
    
    auto start = chrono::steady_clock::now();

    ReadFile(Dic, RawFile);
    RawFile.close();
    PrintDic(Dic);
    PrintAllList();
    PrintNode();
    OutFileAlpha.close();
    OutFileNumer.close();

    auto end = chrono::steady_clock::now();
    cout << "File processed" << "\n";
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << "\n";
    system("pause");
}