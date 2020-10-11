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
        for (int i = 0; i < library.size(); ++i) {
            if(artist == library[i].name){
                for (int j = 0; j < library[i].albuns.size(); ++j) {
                    if (album == library[i].albuns[j].name){
                        for (int k = 0; k < library[i].albuns[j].musics.size(); ++k) {
                            if (music == library[i].albuns[j].musics[k].name){
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
};