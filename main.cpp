#include "reader.h"
#include "file_functions.h"

int main(){
    char filename[] = "offFile.off";
    char txtfile[] = "txtFile.txt";

    std::string filetxt(txtfile);
    std::string txt_local = find_path("../../", txtfile); // Procura o arquivo txt
    const char* txt_local_ = txt_local.c_str();

    Reader r(txt_local_);
    Sculptor s(r.getDimX(), r.getDimY(), r.getDimZ());
    r.draw(s);
    s.writeOFF(filename);

    win_open_file(filename);

    return 0;
}

