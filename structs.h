using namespace std;

struct music{
    double duration;
    string name;
    string album;
    string artist; 
};

struct album{
    double duration;
    int tracks;
    string name;
    vector<music> musics;
};

struct artist{
    string name;
    int albumNumber;
    vector<album> albuns;
};