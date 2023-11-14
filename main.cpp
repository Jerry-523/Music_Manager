#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct AlbumData {
    int qt_faixas;
    string artista;
    vector<string> nome_faixas;
};

void data_registration(AlbumData&);
void display_data(const AlbumData&);

int main(){
    int opcao;
    AlbumData album;

    while(true) {
        cout << "   =======[MENU]======\n\n";
        cout << " [1] => Registrar Dados\n";
        cout << " [2] => Listar Dados\n";
        cout << " [0] => Sair do Programa\n";
        cout << " [Selecionado]: ";
        cin >> opcao;

        if (opcao == 1) {
            data_registration(album);
        } else if (opcao == 2){
            display_data(album);
        } else if (opcao == 0) break;
    }
}

void data_registration(AlbumData& album) {
    string faixas;

    cout << " => Inserir nome do artista\n";
    cin >> album.artista;
    cout << " => Inserir a quantidade das faixas no album\n";
    cin >> album.qt_faixas;
    cout << " => Inserir os nomes das faixas do album\n";

    for(int i = 0; i < album.qt_faixas; i++) {
        cin >> faixas;
        album.nome_faixas.push_back(faixas);
    }
}

void display_data(const AlbumData& album) {
    cout << "Artista: " << album.artista << "\n";
    cout << "Quantidade de faixas: " << album.qt_faixas << "\n";
    cout << "Nomes das faixas:\n";

    for (const string& faixa : album.nome_faixas) {
        cout << "- " << faixa << "\n";
    }
}
