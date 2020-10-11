using namespace std;

struct music{
    double duration;
    string name;
    string album;
    string artist; 
};

struct album{
    string name;
    vector<music> musics;
};

struct artist{
    string name;
    vector<album> albuns;
};

