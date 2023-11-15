#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <map>
#include<unistd.h>
using namespace std;

struct AlbumData {
    int qt_faixas;
    vector<string> nome_faixas;
};

void data_registration(map<string, AlbumData>&);
void display_data(const map<string, AlbumData>&);

int main() {
    int opcao;
    map<string, AlbumData> artistas; // Map to associate artists with their data
    system("clear");
    while (true) {
        cout << "_____________________________________"<<endl;
        cout << "|---------[ GESTOR DE ALBUM ]-------|" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "|       [1] => Registrar Dados      |"<<endl;
        cout << "|       [2] => Listar Dados         |"<<endl;
        cout << "|_______[0] => Sair do Programa_____|"<<endl<<endl;
        cout << "[Selecionado]: ";
        cin >> opcao;
        system("clear");

        if (opcao == 1) {
            data_registration(artistas);
            system("clear");
        } else if (opcao == 2) {
            display_data(artistas);
        } else if (opcao == 0) {
            break;
        }
    }

    return 0;
}

void data_registration(map<string, AlbumData>& artistas) {
    string artista, faixa;
    cout << "_____________________________________"<<endl;
    cout << "|--------[ 1. Registrar Dados]------|" << endl;
    cout << "-------------------------------------"<<endl;
    cout << " => Inserir nome do artista: ";
    cin >> artista;

    // Check if the artist already exists in the map
    if (artistas.find(artista) == artistas.end()) {
        // If not, create a new entry
        AlbumData novo_album;
        cout << " => Inserir a quantidade das faixas no album: ";
        cin >> novo_album.qt_faixas;

        for (int i = 0; i < novo_album.qt_faixas; i++) {
            cout << " => Inserir o nome da faixa [#"<< i+1 <<"] do album: ";
            cin >> faixa;
            novo_album.nome_faixas.push_back(faixa);
        }

        // Add the new entry to the map
        artistas[artista] = novo_album;
    } else {
        cout << "Artista ja existe. Use outra opcao para modificar.\n";
    }
    
}

void display_data(const map<string, AlbumData>& artistas) {
    cout << "_____________________________________"<<endl;
    cout << "|---------[ 2. Listar Dados]--------|" << endl;
    cout << "-------------------------------------"<<endl;
    for (const auto& entry : artistas) {
        cout << "  Artista: " << entry.first << "\n";
        cout << "  Quantidade de faixas: " << entry.second.qt_faixas << "\n";
        cout << "  Nomes das faixas:\n";

        for (const string& faixa : entry.second.nome_faixas) {
            cout << "   -> " << faixa << "\n";
        }

        cout << "\n";
        sleep(3);
        system("clear");
    }
}

