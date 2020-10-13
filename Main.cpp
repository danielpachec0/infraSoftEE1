#include <iostream>
#include <vector>
#include "dataTypes.h"
#include "Library.h"
#include "Player.h"

using namespace std;

void addMusic(Library& library){
    string musicIn, albumIn, artistIn;
    Music music;
    Album album;
    Artist artist;
    double duration;
    cout << "Digite o nome da Musica:" << endl;
    cin >> musicIn;
    cout << "Digite o nome Do album:" << endl;
    cin >> albumIn;
    cout << "Digite o nome do Artista:" << endl;
    cin >> artistIn;
    cout << "Digite a duracao da musica:" << endl;
    cin >> duration;
    //--
    music.name = musicIn;
    music.album = albumIn;
    music.artist = artistIn;
    music.duration = duration;
    //--
    album.name = albumIn;
    album.artist = artistIn;
    album.musics = vector<Music>(0);
    album.musics.push_back(music);
    //--
    artist.name = artistIn;
    artist.albuns = vector<Album>(0);
    artist.albuns.push_back(album);
    //--
    int aux;
    aux = library.addMusic(music);
    switch(aux) {
        case 0:
            cout << "done1" << endl;
            break;
        case 1:
            cout << "Musica ja estava no programa!" << endl;
            break;
        case 2:
            //creat album and add;
            library.addAlbum(album);
            cout << "done2" << endl;
            break;
        default:
            //create from artist;
            library.addArtist(artist);
            cout << "done3" << endl;
            break;
    }
}

void deleteMusic(Library& library){
    string musicIn, albumIn, artistIn;
    cout << "Digite o nome da Musica:" << endl;
    cin >> musicIn;
    cout << "Digite o nome Do album:" << endl;
    cin >> albumIn;
    cout << "Digite o nome do Artista:" << endl;
    cin >> artistIn;
    int aux = library.deleteMusic(musicIn, albumIn, artistIn);
    if(aux == 0){
        aux = library.checkForEmptyAlbum(artistIn, albumIn);
        if (aux == true){
            library.checkForEmptyArtist(artistIn);
        }else{
            //album not empty
            return;
        }
    }else if (aux == 1){
        cout << "A musica nao foi encontrada" << endl;
        return;
    }else if(aux == 2){
        cout << "O album nao foi encontrado" << endl;
        return;
    }else{
        cout << "O artista nao foi encontrado" << endl;
        return;
    }
}

void Interface(Library library, Player& player){
    vector<Artist> artists;
    vector<Album> albuns;
    vector<Music> musics;
    int estado = 0;
    //--------------------------------
    while(true){
        for (int i = 0; i < 30; ++i) {
            cout << endl;
        }
        switch (estado) {
            case 0:
                cout << "Player Home" << endl;
                cout << "Para vizualizar os Artistas Digte 1" << endl;
                cout << "Para vizualizar a lista de reproducao digite 2" << endl;
                cout << "para adcionar uma musica na biblioteca digite 3" << endl;
                cout << "para remover a ultima musica adcionada na fila de reporducao digite 4" << endl;
                cin >> estado;
                break;
            case 1:
                artists = library.getArtists();
                cout << "Artists" << endl;
                cout << "Digite 0 para voltar atela inicial" << endl;
                cout << "Digite o numero do artistas para ver seus albuns" << endl;
                for (int i = 0; i < artists.size(); ++i) {
                    cout << i+1 << " - " << artists[i].name << endl;
                }
                cin >> estado;
                if(estado == 0){
                    break;
                }else{
                    albuns = library.getAlbuns(artists[estado-1].name);
                    cout << artists[estado-1].name << " Albuns:" << endl;
                    cout << "Digite 0 para voltar atela inicial" << endl;
                    cout << "Digite o numero do album para ver as musicas" << endl;
                    for (int i = 0; i < albuns.size(); ++i) {
                        cout << i+1 << " - " << albuns[i].name << endl;
                    }
                    cin >> estado;
                    if(estado == 0){
                        break;
                    }else{
                        musics = library.getMusics(albuns[estado-1].artist, albuns[estado-1].name);
                        cout << albuns[estado-1].artist << " " << albuns[estado-1].name << " musics:" << endl;
                        cout << "Digite 0 para voltar atela inicial" << endl;
                        cout << "Digite o numero da musica para adcionar a fila de reproducao" << endl;
                        for (int i = 0; i < musics.size(); ++i) {
                            cout << i+1 << " - " << musics[i].name << endl;
                        }
                        cin >> estado;
                        if(estado == 0){
                            break;
                        }else{
                            player.addToQueueEnd(musics[estado-1]);
                        }
                    }
                }
                estado = 0;
                break;
            case 2:
                musics = player.getQueue();
                if(musics.size() == 0){
                    cout << "a Fila esta vazia" << endl;
                }else{
                    for (int i = 0; i < musics.size(); ++i) {
                        if(i != 0){
                            cout << "  ->  ";
                        }
                        cout << musics[i].name;
                        if(i%10 == 0 && i != 0){
                            cout << endl;
                        }
                    }
                }

                cout << endl;
                do{
                    cout << "Digite 0 para continuar" <<endl;
                    cin >> estado;
                }while (estado !=0);
                break;
            case 3:
                addMusic(library);
                do{
                    cout << "Digite 0 para continuar" <<endl;
                    cin >> estado;
                }while (estado !=0);
                estado = 0;
                break;
            case 4:
                if(player.removeFromQueueEnd()){
                    cout<< "Removida!" << endl;
                }else{
                    cout << "a Fila esta vazia" << endl;
                }
                do{
                    cout << "Digite 0 para continuar" <<endl;
                    cin >> estado;
                }while (estado !=0);
                break;
            default:
                return;
        }
    }

}


int main(){
    Library library;
    Player player;
    //estado == 0 -> home
    //estado == 1 -> artistas
    //estado == 2 -> albuns - todo
    //estado == 3 -> musicas - todo
    //player == 4 -> Lista de reproducao
    addMusic(library);
    addMusic(library);
    addMusic(library);
    Interface( library, player);
}