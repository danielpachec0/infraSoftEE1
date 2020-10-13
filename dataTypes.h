using namespace std;

struct Music{
    double duration;
    string name;
    string album;
    string artist;
};

struct Album{
    string name;
    string artist;
    vector<Music> musics;
};

struct Artist{
    string name;
    vector<Album> albuns;
};