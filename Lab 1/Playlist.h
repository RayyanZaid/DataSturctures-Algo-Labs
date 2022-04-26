#include <iostream>
using namespace std;

class PlaylistNode {
    public:
    PlaylistNode();
    PlaylistNode(string uniqueID, string songName, string artistName, int songLength);
    

    string GetID() {
        return this->uniqueID;
    }
    string GetSongName() {
        return this->songName;
    }
    string GetArtistName() {
        return this->artistName;
    }
    int GetSongLength() {
        return this->songLength;
    }

    PlaylistNode* GetNext();
    void PrintPlaylistNode();
    void InsertAfter(PlaylistNode* nextSong);  
    void SetNext(PlaylistNode* nextSong);

    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;

        
};

class Playlist {
    private:
        PlaylistNode* head;
        PlaylistNode* tail;

    public:
        Playlist();
        void AddSong(string uniqueID, string songName, string artistName, int songLength);
        bool RemoveSong(string uniqueID);
        bool ChangePosition(int currentPosition, int newPosition);
        void SongsByArtist(string artistName);
        int TotalTime();
        void PrintList();
};

