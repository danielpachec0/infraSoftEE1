using namespace std;

struct Music{
    double duration;
    string name;
    string album;
    string artist;
//    Music(string name, string album, string artist){
//        name = name;
//        album = album;
//        artist = artist;
//    }
};

struct Album{
    string name;
    string artist;
    vector<Music> musics;
//    Album(string name, string artist){
//        name = name;
//        artist = artist;
//        musics = vector<Music>(0);
//    }
};

struct Artist{
    string name;
    vector<Album> albuns;
//    Artist(string name){
//        name = name;
//        albuns = vector<Album>(0);
//    }
};