#include <iostream>
#include <vector>
#include <string>
#include <map>
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

    while (true) {
        cout << "   =======[MENU]======\n\n";
        cout << " [1] => Registrar Dados\n";
        cout << " [2] => Listar Dados\n";
        cout << " [0] => Sair do Programa\n";
        cout << " [Selecionado]: ";
        cin >> opcao;

        if (opcao == 1) {
            data_registration(artistas);
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

    cout << " => Inserir nome do artista\n";
    cin >> artista;

    // Check if the artist already exists in the map
    if (artistas.find(artista) == artistas.end()) {
        // If not, create a new entry
        AlbumData novo_album;
        cout << " => Inserir a quantidade das faixas no album\n";
        cin >> novo_album.qt_faixas;
        cout << " => Inserir os nomes das faixas do album\n";

        for (int i = 0; i < novo_album.qt_faixas; i++) {
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
    for (const auto& entry : artistas) {
        cout << "Artista: " << entry.first << "\n";
        cout << "Quantidade de faixas: " << entry.second.qt_faixas << "\n";
        cout << "Nomes das faixas:\n";

        for (const string& faixa : entry.second.nome_faixas) {
            cout << "- " << faixa << "\n";
        }

        cout << "\n";
    }
}

