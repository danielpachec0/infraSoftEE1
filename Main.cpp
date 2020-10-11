#include <iostream>
#include <vector>
#include "dataTypes.h"
#include "Library.h"

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

int main(){
    Library library;
    addMusic(library);
    addMusic(library);
    addMusic(library);
    library.printMusics("ar1", "al1");
    library.printArtists();
    library.printAlbuns("ar1");
}