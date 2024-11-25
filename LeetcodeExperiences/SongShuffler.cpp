Given a playlist of songs, you have to design a song shuffler.
This song shuffler is not like the normal song shuffler that shuffles the complete playlist at the start and returns a shuffled list, but instead when asked for a next song to be played, returns a random song from the list of songs.
The next random song to be played should satisfy a condition that the song was not played in the last 'k' turns.
You have to make sure, that at each call, all the eligible (not played during last k turns) songs have equal probability of being played next.

For example:
if songs = [A, B, C, D], k = 2,
then a possible random sequence of songs can be:

playNext: [ A , B , C , D ] ->  return C
playNext: [ A , B , _ , D ] ->  return A
playNext: [ _ , B , _ , D ] ->  return B
playNext: [ _ , _ , C , D ] ->  return C (as C was not played in the last two turns, it has an equal probability with D to be played).

timer = 0;

A - 2
B - 3
C - 4
D - 


Are there contraints on the size of array and k ??
because k can equal to size of array, our playNext function c


Clarifying questions I asked:

Songs datatype? -> decided to be String
Can k = 0 be possible? -> Yes
Can n = 0 be possible? -> No, n >= 1
What will happen when k >= n? -> Considered this as an invalid case, i.e., k will always be < n.



class SongShuffler{

    queue<string> songsQueue;
    vector<int> songs;
    int limit;


    SongShuffler(vector<string> songs, int limit){
        this.songs = songs;
        this.limit = limit;
    }

    string playNext(){
        int randomIndex = rand(0, songs.size());
        string song = songs[randomIndex];
        songsQueue.push(songs[randomIndex]);

        if(songsQueue.size() > limit){
            string song = songsQueue.front();
            songsQueue.pop();

            songs.push_back(song);
        }

        return song;
    }
}
            0   1   2   3
playNext: [ A , B , C , D ] ->  return C
playNext: [ A , B , _ , D ] ->  return A
playNext: [ _ , B , _ , D ] ->  return B
playNext: [ _ , _ , C , D ] ->  return C (as C was not played in the last two turns, it has an equal probability with D to be played).

time complexit - O(1)
space complexity - O(n) where is total songs
