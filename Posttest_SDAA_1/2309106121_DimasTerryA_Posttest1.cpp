#include <iostream>
using namespace std;

void pindahkanPiringan(int jumlahPiringan, string menaraAsal, string menaraTujuan, string menaraSementara) {
   
    if (jumlahPiringan == 1) {
        cout << "Pindahkan piringan 1 dari " << menaraAsal << " ke " << menaraTujuan << endl;
        return;
    }
    
    pindahkanPiringan(jumlahPiringan - 1, menaraAsal, menaraSementara, menaraTujuan);
    
    cout << "Pindahkan piringan " << jumlahPiringan << " dari " << menaraAsal << " ke " << menaraTujuan << endl;
    
    pindahkanPiringan(jumlahPiringan - 1, menaraSementara, menaraTujuan, menaraAsal);
}

int main() {
    int jumlahPiringan = 3; 
    pindahkanPiringan(jumlahPiringan, "Menara A", "Menara B", "Menara C"); // 
    return 0;
}
