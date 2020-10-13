class Player{
    vector<Music> playerQueue;
    Music* playingMusic;
    int playPos;
//  bool playing;
//  double trackTime;
//  double stateTime;
public:
    Player(){
        playerQueue = vector<Music>(0);
//      playing = false;
        playPos = -1;
        playingMusic = nullptr;
//      trackTime = 0;
//      stateTime = 0;
    }
    vector<Music> getQueue(){
        return playerQueue;
    };
    void addToQueueEnd(Music music){
        playerQueue.push_back(music);
    }
    void resetQueue(){
        playerQueue.clear();
    }
    bool removeFromQueueEnd(){
        if (playerQueue.size() > 0){
            playerQueue.pop_back();
            return true;
        }
        return false;
    }
    void SkipTrack(){
        playPos = playPos+1;
    }
    void previousTrack(){
        playPos = playPos-1;
    }
    bool emptyQueue(){
        return playerQueue.empty();
    }
};