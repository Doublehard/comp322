//
// Created by Wendy Wu on 2022-02-23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


using namespace std;

enum class Rank{
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
    EIGHT, NINE, TEN, JACK, QUEEN, KING
};

enum class Type{
    CLUBS='C', DIAMONDS='D', HEARTS='H', SPADES='S'
};

const std::vector<Type> v_type {Type::CLUBS, Type::DIAMONDS, Type::HEARTS, Type::SPADES};

const std::vector<Rank> v_rank {Rank::ACE, Rank::TWO, Rank::THREE, Rank::FOUR, Rank::FIVE,
                                Rank::SIX, Rank::SEVEN, Rank::EIGHT, Rank::NINE, Rank::TEN, Rank::JACK,
                                Rank::QUEEN, Rank::KING};

class Card{
public:
    Card(Rank r, Type t):rank(r),type(t){}
    int getValue();
    void displayCard();
    Rank getRank(){return rank;}
private:
    Rank rank;
    Type type;
};

void Card::displayCard() {
    string s1 = "";
    if(rank==Rank::JACK){
        s1 = "J";
    }else if(rank==Rank::QUEEN){
        s1 = "Q";
    }else if(rank==Rank::KING){
        s1 = "K";
    }else{
        s1 = to_string(static_cast<int>(rank));
    }
    s1.push_back(static_cast<char>(type));
    cout << s1 << " ";
}

int Card::getValue() {
    if(rank!=Rank::JACK&&rank!=Rank::QUEEN&&rank!=Rank::KING){
        return static_cast<int>(rank);
    }
    return 10;
}

class Hand{
public:
    void add(Card c);
    void clear();
    pair<int,int> getTotal() const; // first number is normal sum, second number is # of Ace
    vector<Card> peekHands();
private:
    vector<Card> cards;
};

void Hand::add(Card c) {
    cards.push_back(c);
}

void Hand::clear() {
    cards.clear();
}

pair<int,int> Hand::getTotal() const {
    int sum = 0;
    int numOfAce = 0;
    for(auto c:cards){
        if(c.getRank()==Rank::ACE){
            numOfAce+=1;
        }
        sum+=c.getValue();
    }
    return make_pair(sum,numOfAce);
}

vector<Card> Hand::peekHands() {
    return cards;
}

class Deck{
public:
    void Populate(); //  create a standard deck of 52 cards
    void shuffle();
    void deal(Hand &hand); //  deal one card to a hand
private:
    vector<Card> cards;
};

void Deck::Populate() {
    for(auto t:v_type){
        for(auto r: v_rank){
            Card c = Card(r,t);
            cards.push_back(c);
        }
    }
}

void Deck::shuffle() {
    random_device rd;
    auto rd_eng = default_random_engine{rd()};
    std::shuffle(begin(cards), end(cards),rd_eng);
}

void Deck::deal(Hand &hand) {
    if(cards.size()>0){
        Card c = cards.back();
        cards.pop_back();
        hand.add(c);
    }
}


class AbstractPlayer{
public:
    virtual bool isDrawing() const = 0;
    bool isBusted();
    Hand hand;
};

bool AbstractPlayer::isBusted() {
    if(hand.getTotal().first>21){
        return true;
    }
    return false;
}

class ComputerPlayer: public AbstractPlayer{
public:
    bool isDrawing() const{
        int num_of_ace = hand.getTotal().second;
        int sum1 = hand.getTotal().first;
        int sum2;
        if(num_of_ace>0){
            sum2 = sum1-1+11;
            if(sum2>21){
                sum2 = 0;
            }
        }
        if(max(sum1,sum2)>=16){
            return false;
        }
        return true;
    }
};

class HumanPlayer: public AbstractPlayer{
public:
    bool isDrawing() const; //  implements the inherited method that indicates whether a player wants to draw another card
    friend void announce(HumanPlayer &player1, ComputerPlayer &player2); //  prints information about whether the player wins, loses or had a push situation
};

bool HumanPlayer::isDrawing() const{
    string msg = "Do you want to draw? (y/n):";
    cout << msg;
    char playerAns;
    cin >> playerAns;
    if(playerAns=='y'){
        return true;
    }
    return false;
}

void comparePlayers(int play_sum, int casino_sum, string &msg, int player_num_ace, int casino_num_ace){
    if(player_num_ace>0&&play_sum<=11){
        play_sum = play_sum-1+11;
    }
    if(casino_sum>0&&casino_num_ace<=11){
        casino_sum = casino_sum-1+11;
    }
    if(play_sum>casino_sum){
        msg = "Player wins.";
    }else if(play_sum<casino_sum){
        msg = "Casino wins.";
    }else{
        msg = "Push: No one wins.";
    }
}

void announce(HumanPlayer &player1, ComputerPlayer &player2) {
    string msg;
    if (player1.isBusted()){
        msg = "Player lose";
    }else if(player2.isBusted()){
        msg = "Player win";
    }else{
        pair<int,int> p1 = player1.hand.getTotal();
        pair<int,int> p2 = player2.hand.getTotal();
        comparePlayers(p1.first,p2.first,msg,p1.second,p2.second);
    }
    cout << msg << endl;
    cout << endl;
}

class BustedException: public exception{
public:
    virtual const char* what() const throw() = 0;
};

class PlayerBustedException: public BustedException{
public:
    virtual const char* what() const throw(){
        return "Player busts.";
    }
};

class ComputerBustedException: public BustedException{
public:
    virtual const char* what() const throw(){
        return "Casino busts.";
    }
};

PlayerBustedException playerBustedException;
ComputerBustedException computerBustedException;

class BlackJackGame{
public:
    void play();
    Deck m_deck;
    ComputerPlayer m_casino;
    HumanPlayer m_player;
private:
    void printPlayerCards();
    void printCasinoCards();
    void printValue(pair<int,int> pair);
};

void BlackJackGame::play() {
    m_player.hand.clear();
    m_casino.hand.clear();
    m_deck.Populate();
    m_deck.shuffle();
    // player two cards
    m_deck.deal(m_player.hand);
    m_deck.deal(m_player.hand);
    // casino one card
    m_deck.deal(m_casino.hand);

    printCasinoCards();
    printPlayerCards();
    try{
        // player's turn
        while(m_player.isDrawing()){
            m_deck.deal(m_player.hand);
            printPlayerCards();
            if(m_player.isBusted()){
                throw playerBustedException;
            }
        }
        // casino's turn
        while(m_casino.isDrawing()){
            m_deck.deal(m_casino.hand);
            printCasinoCards();
            if(m_casino.isBusted()){
                throw computerBustedException;
            }
        }
    } catch (PlayerBustedException &e1){
        cout << e1.what() << endl;
    } catch (ComputerBustedException &e2){
        cout << e2.what() << endl;
    }

    announce(m_player,m_casino);
}

void BlackJackGame::printCasinoCards() {
    cout << "Casino: ";
    for(auto c: m_casino.hand.peekHands()){
        c.displayCard();
    }
    pair<int,int> p = m_casino.hand.getTotal();
    printValue(p);
}

void BlackJackGame::printPlayerCards() {
    cout << "Player: ";
    for(auto c:m_player.hand.peekHands()){
        c.displayCard();
    }
    pair<int,int> p = m_player.hand.getTotal();
    printValue(p);
}

void BlackJackGame::printValue(pair<int,int> p) {
    cout << "[" << p.first << "]";
    int num_of_ace = p.second;
    if(num_of_ace>0&&p.first<=11){
        cout << "/[" << p.first-1+11 << "]";
    }
    cout << endl;
}

int main(){
    cout << "Welcome to the Comp322 Blackjack game!" << endl << endl;
    BlackJackGame game;
// The main loop of the game
    bool playAgain = true;
    char answer = 'y';
    while (playAgain)
    {
        game.play();
// Check whether the player would like to play another round
        cout << "Would you like another round? (y/n): ";
        cin >> answer;
//        cout << endl << endl;
        playAgain = (answer == 'y' ? true : false);
    }
    cout <<"Gave over!";
    return 0;
}



