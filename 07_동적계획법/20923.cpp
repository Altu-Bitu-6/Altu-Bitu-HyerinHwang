#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define xx first
#define yy second
#define all(v) (v).begin(), (v).end()

int num_players, num_rounds;
deque<int> player_cards[2], ground_cards[2];

int check_winner() {
    // Player 0 wins if there's a 5
    for(int i : {0, 1})
        if(!ground_cards[i].empty() && ground_cards[i].front() == 5) return 0;

    // Player 1 wins if the sum is 5
    if(!ground_cards[0].empty() && !ground_cards[1].empty() && ground_cards[0].front() + ground_cards[1].front() == 5) return 1;

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_players >> num_rounds;
    for(int i=0; i<num_players; ++i){
        int card1, card2;
        cin >> card1 >> card2;
        player_cards[0].push_front(card1);
        player_cards[1].push_front(card2);
    }

    int current_player = 0;
    while(num_rounds--){
        // Move cards from player to ground
        ground_cards[current_player].push_front(player_cards[current_player].front());
        player_cards[current_player].pop_front();

        // Check if player's cards are empty
        if(player_cards[current_player].empty()) break;

        // Check result
        int winner = check_winner();
        if(winner != -1){
            int loser = !winner;
            for(int i : {loser, winner})
                while(!ground_cards[i].empty()){
                    player_cards[winner].push_back(ground_cards[i].back());
                    ground_cards[i].pop_back();
                }
        }

        current_player ^= 1;
    }

    if(player_cards[0].size() > player_cards[1].size()) cout << "do";
    else if(player_cards[0].size() < player_cards[1].size()) cout << "su";
    else cout << "dosu";
}
