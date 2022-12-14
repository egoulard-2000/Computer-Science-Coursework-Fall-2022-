#include <iostream>
using namespace std;

class Cat {
    private:
        int lives;

    /// Add a public member reportLives that reports to cout an informative message about the Cat's lives.
///Add another public member loseLife that decrements the life by 1.
///Add code to main to exercise those functions and print out some results.
    public: 
        Cat(int _lives) {
            lives = _lives;
        }

    public:
        int reportLives() {
            return lives;
        }

    public:
        void loseLife() {
            lives -= 1;
        }

    public:
        void operator+=(int extraLives) {
            
        }
};

int main() {
    Cat myCat(9); //my cat has 9 lives
    myCat.loseLife();
    myCat.loseLife();
    int numOfLives = myCat.reportLives();

    cout << "My Cat has: " << numOfLives << " lives" << endl;
}