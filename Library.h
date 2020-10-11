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
    int addAlbum(Album album){
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
//    string teste2(){
//        return library[1].name;
//    }
//    string teste(){
//        return "testeLib";
//    }
    int deleteMusic(string music, string album, string artist){
        //return 0 -> done;
        //return 1 -> Music not found;
        //return 2 -> Album not found;
        //return 3 -> Artist not found;
        for (int i = 0; i < library.size(); ++i) {
            if (artist == library[i].name){
                for (int j = 0; j < library[i].albuns.size(); ++j) {
                    if(album == library[i].albuns[j].name){
                        for (int k = 0; k < library[i].albuns[j].musics.size(); ++k) {
                            if(music == library[i].albuns[j].musics[i].name){
                                //remove
                                library[i].albuns[j].musics.erase(library[i].albuns[j].musics.begin()+k);
                                return 0;
                            }
                        }
                        //music not found
                        return 1;
                    }
                }
                //album not found
                return 2;
            }
        }
        //artist not found
        return 3;
    };
    int deleteAlbum(string album, string artist){
        //return 0 -> done;
        //return 1 -> album not found;
        //return 2 -> artist not found;
        for (int i = 0; i < library.size(); ++i) {
            if (artist == library[i].name){
                for (int j = 0; j < library[i].albuns.size(); ++j) {
                    if(album == library[i].albuns[j].name){
                        //delete
                        library[i].albuns.erase(library[i].albuns.begin()+j);
                        return 0;
                    }
                }
                //album not found;
                return 1;
            }
        }
        //artist not found;
        return 2;
    }
    bool deleteArtist(Artist artist){
        //return true -> done;
        //return false -> artist not found
        for (int i = 0; i < library.size(); ++i) {
            if (artist.name == library[i].name){
                //delete
                library.erase(library.begin()+i);
                return true;
            }
        }
        //artist not found;
        return false;
    }
    bool checkForEmptyAlbum(string artist, string album){
        for (int i = 0; i < library.size(); ++i) {
            if(artist == library[i].name){
                for (int j = 0; j < library[i].albuns.size(); ++j) {
                    if (album == library[i].albuns[j].name){
                        if (library[i].albuns[j].musics.empty()){
                            //empty so delete
                            library[i].albuns.erase(library[i].albuns.begin()+j);
                            return true;
                        }else{
                            return false;
                        }
                    }
                }
            }
        }
        return false;
    }
    void checkForEmptyArtist(string artist){
        for (int i = 0; i < library.size(); ++i) {
            if(artist == library[i].name){
                if (library[i].albuns.empty()){
                    //empty so delete
                    library.erase(library.begin()+i);
                    return;
                }else{
                    return;
                }
            }
        }
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