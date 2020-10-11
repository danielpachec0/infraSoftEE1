class Library{
    vector<Artist> library;
public:
    Library(){
        library = vector<Artist>(0);
    }
    int checkMusic(string music, string album, string artist){
    //return 0 --> music exist;
    //return 1 --> no music;
    //return 2 --> no album;
    //return 3 --> no artist;
        for (auto & i : library) {
            if(artist == i.name){
                for (auto & j : i.albuns) {
                    if (album == j.name){
                        for (auto & k : j.musics) {
                            if (music == k.name){
                                return 0;
                            }
                        }
                        return 1;
                    }
                }
                return 2;
            }
        }
        return 3;
    }

    int addMusic(Music music){
    //return 0 -> done;
    //return 1 -> music alredy exist;
    //return 2 -> album not found;
    //return 3 -> Artist not found;
        for (int i = 0; i < library.size(); ++i) {
            if (music.artist == library[i].name){
                for (int j = 0; j < library[i].albuns.size(); ++j) {
                    if(music.album == library[i].albuns[j].name){
                        for (int k = 0; k < library[i].albuns[j].musics.size(); ++k) {
                            if(music.name == library[i].albuns[j].musics[i].name){
                                return 1;
                            }
                        }
                        library[i].albuns[j].musics.push_back(music);
                        return 0;
                    }
                }
                return 2;
            }
        }
        return 3;
    }
    bool addAlbum(Album album){
    //return 0 -> done;
    //return 1 -> album alredy found;
    //return 2 -> artist not found;
        for (int i = 0; i < library.size(); ++i) {
            if (album.artist == library[i].name){
                for (int j = 0; j < library[i].albuns.size(); ++j) {
                    if(album.name == library[i].albuns[j].name){
                        return 1;
                    }
                }
                library[i].albuns.push_back(album);
                return 0;
            }
        }
        return 2;
    }
    bool addArtist(Artist artist){
    //return true -> done;
    //return false -> artist alredy exist
        for (int i = 0; i < library.size(); ++i) {
            if (artist.name == library[i].name){
                return false;
            }
        }
        library.push_back(artist);
        return true;
    }
    string teste2(){
        return library[1].name;
    }
    string teste(){
        return "testeLib";
    }

    bool printMusics(string artist, string album){
        for (int i = 0; i < library.size(); ++i) {
            if(artist == library[i].name){
                for (int j = 0; j < library[i].albuns.size(); ++j) {
                    if (album == library[i].albuns[j].name){
                        for (int k = 0; k < library[i].albuns[j].musics.size(); ++k) {
                            cout << library[i].albuns[j].musics[k].name << endl;
                        }
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }

    bool printAlbuns(string artist){
        for (int i = 0; i < library.size(); ++i) {
            if(artist == library[i].name){
                for (int j = 0; j < library[i].albuns.size(); ++j) {
                    cout << library[i].albuns[j].name << endl;
                }
                return true;
            }
        }
        return false;
    }

    void printArtists(){
        for (int i = 0; i < library.size(); ++i) {
            cout << library[i].name <<endl;
        }
    }
};