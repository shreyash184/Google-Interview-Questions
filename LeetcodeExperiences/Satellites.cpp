You are given a 2d matrix with the co-ordinates of the satelite and given a source and destination coordinates of satelite
each saltelite can cover upto 10 unit radius and if 2 satelite are covering any same part they can be consider as satelite a can reach 
satelite b. so is it possible to reach from source to destination ?

ex -

0, 0, 10
5, 4, 10
3, 7, 10
10, 8, 10

source - 0, 0
destination - 10, 8


void spreadReach(int source, vector<bool>& visited, vector<int>sateliteConnections[]){
    visited[source] = true;

    for(auto neighbourSatelite : sateliteConnections[source]){
        if(!visited[neighbourSatelite]){
            spreadReach(neighbourSatelite, visited, spreadConnections);
        }
    }
}

bool checkReability(vector<vector<int>>& satelites, int source, int destination){
    int totalSatelites = satelites.size();


    vector<int>sateliteConnections[];

    for(int satelitei = 0; satelitei < totalSatelites; satelitei++){
        int xCoordinate = satelites[satelitei][0];
        int yCoordinate = satelites[satelitei][1];
        int radius = 10*10;

        for(int satelitej = 0; satelitej < totalStatelies; satelitej++){
            if(satelitei == satelitej){
                continue;
            }
            int diffInX = abs(xCoordinate - satelites[satelitej][0]);
            int diffInY = abs(yCoordinate - satelites[satelitej][1]);

            int distance = (diffInX * diffInX) + (diffInY * diffInY);

            if(distance <= radius){
                sateliteConnections[satelitei].push_back(satelitej);
            }
        }
    }

    vector<bool> visited(totalSatelites, false);

    spreadReach(source, visited, sateliteConnections);

    if(visited[destination]){
        return true;
    }

    return false;
}

Time complexity - O(n^3) where n is no Of satelite 
Space complexity - O(n^2) to store the satelites.

Now the follow up question is 

If one satelite is capture by multiple satelite then it can't propagate further from that satelite.
then we have to whether we can reach the destination.

solution - during dfs if we encountered if the satelite is already visited then return false else return true
and return final answer true if(visited[destination] == true and dfs call returns true)