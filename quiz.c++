#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Question {
public:
    string questionText;
    vector<string> options;
    char correctOption;

    Question(const string& qText, const vector<string>& opts, char correctOpt)
        : questionText(qText), options(opts), correctOption(correctOpt) {}

    bool isCorrect(char userChoice) const {
        return toupper(userChoice) == toupper(correctOption);
    }
};

class Quiz {
private:
    vector<Question> questions;
    int score;

public:
    Quiz() : score(0) {
        loadQuestions();
    }

    void startQuiz() {
        cout << "Welcome to the Awesome Quiz!\n\n";
        shuffleQuestions();
        for (const auto& question : questions) {
            displayQuestion(question);
        }
        cout << "Quiz Completed! Your Score: " << score << " out of " << questions.size() << endl;
    }

private:
    void loadQuestions() {
        ifstream file("quiz_questions.txt");
        if (file.is_open()) {
            string qText, optA, optB, optC, optD;
            char correctOpt;

            while (getline(file, qText)) {
                file >> optA >> optB >> optC >> optD >> correctOpt;
                file.ignore();  // Consume the newline character

                vector<string> options = {optA, optB, optC, optD};
                Question newQuestion(qText, options, correctOpt);
                questions.push_back(newQuestion);
            }

            file.close();
        }
    }

    void shuffleQuestions() {
        srand(static_cast<unsigned int>(time(nullptr)));
        random_shuffle(questions.begin(), questions.end());
    }

    void displayQuestion(const Question& question) {
        cout << question.questionText << endl;
        for (char i = 'A'; i <= 'D'; ++i) {
            cout << i << ". " << question.options[i - 'A'] << endl;
        }

        char userChoice;
        cout << "Your choice: ";
        cin >> userChoice;

        if (question.isCorrect(userChoice)) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect! The correct answer is " << question.correctOption << ".\n";
        }

        cout << "------------------------\n";
    }
};

int main() {
    Quiz quiz;
    quiz.startQuiz();

    return 0;
}
