#include "Playlist.h"
#include <iostream>
using namespace std;

// Constructor
PlaylistNode::PlaylistNode() {
    this->uniqueID = "";
    this->songName = "";
    this->artistName = "";
    this->songLength = 0;
    this->nextNodePtr = nullptr;

    

}
PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) {
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
    this->nextNodePtr = nullptr;

}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << this->uniqueID << endl;
    cout << "Song Name: " << this->songName << endl;
    cout << "Artist Name: " << this->artistName << endl;
    cout << "Song Length (in seconds): " << this->songLength << endl;
}

PlaylistNode* PlaylistNode::GetNext() {
    return this->nextNodePtr;
}



Playlist::Playlist() {
    head = nullptr;
    tail = nullptr;
}

void Playlist::PrintList() {
    PlaylistNode* currentSong = this->head;


    if(currentSong == nullptr) {
        cout << "Playlist is empty" << endl;
    }
    unsigned i = 1;
    while(currentSong != nullptr) {
        cout << i << "." << endl;
        currentSong->PrintPlaylistNode();
        currentSong = currentSong->GetNext();
        i++;
    }

    cout << endl;
}


// to add songs

void PlaylistNode::SetNext(PlaylistNode* nextSong) {    // setting the next song pointer to what the user puts in
    nextNodePtr = nextSong;
}

void PlaylistNode::InsertAfter(PlaylistNode* ptr) {
    PlaylistNode* temp = this;
    this->SetNext(ptr->GetNext());
    ptr->SetNext(temp);

//     this->SetNext(ptr->GetNext());
//    ptr->SetNext(this);
}
void Playlist::AddSong(string uniqueID, string songName, string artistName, int length) {
    PlaylistNode* newSong = new PlaylistNode(uniqueID,songName, artistName, length);

    if(head == nullptr) { // if there are no other songs in the list
        head = newSong;
        tail = newSong;
    }
    else {
    newSong->InsertAfter(this->tail); // inserting the new song after the tail
    tail = newSong; // setting the tail to the new song
    }
}

bool Playlist::RemoveSong(string id)
{
    if (head ==nullptr)
        {
            cout << "Playlist is empty" << endl;
            return false;
        }

PlaylistNode* curr = head;
PlaylistNode* prev =nullptr;
    while (curr !=nullptr)
        {
            if (curr->GetID() == id) {
            break;
        }
prev = curr;
curr = curr->GetNext();
}

if (curr ==nullptr) //not found
{
cout << "\"" << curr->GetSongName() << "\" is not found" << endl;
return false;
}
else
{
if (prev !=nullptr)
prev->SetNext(curr->GetNext());
else
head = curr->GetNext();

if (tail == curr)
tail = prev;
cout << "\"" << curr->GetSongName() << "\" removed." << endl;
delete curr;
return true;
}
}




bool Playlist::ChangePosition(int oldPosition, int newPosition)
{
    // 1. Get position
    // 2. Skip over position
    // 3. Find newPosition and insert the song there


    // checking if the position 
   if (this->head == nullptr)
   {
       cout << "Playlist is empty." << endl;
       return false;
   }

   if(oldPosition < 1) {
       cout << "Input a number that is within the range of the Playlist" << endl;
       return false;
   }

   PlaylistNode* prev = nullptr;
   PlaylistNode* curr = this->head;

   int position;
   

   
   for (position = 1; curr != nullptr && position < oldPosition; position++)    // finding the song at the position the user inputted
   {
       prev = curr;
       curr = curr->GetNext();
   }
   if (curr != nullptr) // current position actually exists (user did not put a number outside of the length of list)
   {
       
       // these first logic statements are to basically take out the oldPosition

       if (prev == nullptr) // if the oldPosition is at the head
           head = curr->GetNext();  // we make the head point to the next node (basically skipping over the oldPosition)
       else // if the oldPosition is NOT at the head
       {
           prev->SetNext(curr->GetNext());  // point previous's next pointer to skip the current song
            // if this was the tail, this would set the next pointer to nullptr
       }

       if (curr == tail) // if old position is at the tail (if we remove the tail)
           tail = prev; // put the previous song into tail

       PlaylistNode* oldPositionNode = curr; // store oldPosition song before changing curr to head again for new position
       prev = nullptr;
       curr = head;

       // get the new location node the number the user put in
       for (position = 1; curr != nullptr && position < newPosition; position++)
       {
           prev = curr;
           curr = curr->GetNext();
       }

       

       if (curr == this->head)  // if the new position is at the head, then we: (moving a node to the head)
       {
           oldPositionNode->SetNext(head);    // set the next pointer of the old position to head
           head = oldPositionNode;          // set head to the oldPosition node
       }
       else
           oldPositionNode->InsertAfter(prev);  // if new position is not at the head

       if (prev == this->tail)     
           tail = oldPositionNode;


        if(newPosition < 1) {
            newPosition = 1;
        }

        PlaylistNode* currentSongNode = this->head;
        unsigned songCounter = 0;
        while(currentSongNode != nullptr) {
            currentSongNode = currentSongNode->GetNext();
            songCounter++;
        }
        if(newPosition > songCounter) {
            newPosition = songCounter;
        }
        string currentSong = oldPositionNode->GetSongName(); // storing the song name
       cout << "\"" << currentSong << "\" moved to position " << newPosition << endl;
       return true;

   }
   else // current position does not exist
   {
       cout << "Input a number that is within the range of the Playlist" << endl;
       return false;
   }
}


void Playlist::SongsByArtist(string artistName) {
    PlaylistNode* currentSong = this->head;

    if(currentSong == nullptr) {
        cout << "Empty" << endl;
    }
    unsigned i = 1;
    while(currentSong != nullptr) {
        string currentArtistName = currentSong->GetArtistName();
        if(currentArtistName == artistName) {
            cout << endl << i << "." << endl;
            currentSong->PrintPlaylistNode();
        }
        currentSong = currentSong->GetNext();
        i++;
    }
}

int Playlist::TotalTime() {
    PlaylistNode* currentSong = this->head;
    int totalTime = 0;

    if(currentSong == nullptr) {
        cout << "Empty" << endl;
    }

    while(currentSong != nullptr) {
        totalTime+=currentSong->GetSongLength();
        currentSong = currentSong->GetNext();
    }

    return totalTime;
}