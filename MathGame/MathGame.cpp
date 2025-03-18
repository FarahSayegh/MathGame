#include <iostream>
#include <cstdlib>
#include<ctime>

enum questionLevel { Easy = 1 , Mid = 2, Hard = 3, Mix = 4 };
enum operationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };

struct Question
{
    int number1 = 0;
    int number2 = 0;
    questionLevel level;
    operationType opType;
    int userAnswer = 0;
    int correctAnswer = 0;
    bool answerResult = false;
};

struct Quiz
{
    Question questionList[100];
    int numberOfQuestions = 0;
    questionLevel level;
    operationType opType;
    int numberOfRightAnswers = 0;
    int numberOfWrongAnswers = 0;
    bool isPass = false;
};

int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}

int chooseNumberOfQuestions()
{
    int number = 0;
    do
    {
        std::cout << "How many questions do you want to answer? ";
        std::cin >> number;
    } while (number<=0 || number > 100);

    return number;
}

questionLevel chooseQuestionsLevel()
{
    int level = 0;

    do
    {
        std::cout << "\nEnter questions level [1]Easy, [2]Mid, [3]Hard, [4]Mix :";
        std::cin >> level;
    } while (level < 1 || level > 4);

    return questionLevel(level);
}

operationType chooseOperationType()
{
    int operation = 0;

    do
    {
        std::cout << "\nEnter operation type [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix : ";
        std::cin >> operation;
    } while (operation < 1 || operation > 5);

    return operationType(operation);
}

std::string getLevelName(questionLevel level)
{
    std::string levels[4] = { "Easy","Mid","Hard","Mix" };

    return levels[level - 1];
}

std::string getOperationTypeName(operationType opType)
{
    std::string types[5] = { "Add","Sub","Mul","Div","MixOp" };

    return types[opType - 1];
}

std::string getOperationSymbol(operationType opType)
{
    switch (opType)
    {
    case operationType::Add:
        return "+";
        break;
    case operationType::Sub:
        return "-";
        break;
    case operationType::Mul:
        return "x";
        break;
    case operationType::Div:
        return "/";
        break;
    }
}

int readUserInput()
{
    int userInput = 0;
    std::cin >> userInput;

    return userInput;
}

int simpleCalculator(int number1, int number2, operationType opType)
{
    switch (opType)
    {
    case operationType::Add:
        return number1 + number2;
        break;
    case operationType::Sub:
        return number1 - number2;
        break;
    case operationType::Mul:
        return number1 * number2;
        break;
    case operationType::Div:
        return  number1 / number2;
        break;
    }
}

Question makeQuestion(questionLevel level, operationType opType)
{
    Question question;
    
    if (level == questionLevel::Mix)
        level = (questionLevel)randomNumber(1, 3);

    if (opType == operationType::MixOp)
        opType = (operationType)randomNumber(1, 4);

    question.level = level;
    question.opType = opType;
    
    switch (level)
    {
    case questionLevel::Easy:
        question.number1 = randomNumber(1, 10);
        question.number2 = randomNumber(1, 10);
        break;
    case questionLevel::Mid:
        question.number1 = randomNumber(10, 50);
        question.number2 = randomNumber(10, 50);
        break;
    case questionLevel::Hard:
        question.number1 = randomNumber(50, 100);
        question.number2 = randomNumber(50, 100);
        break;
    }

    question.correctAnswer = simpleCalculator(question.number1, question.number2, question.opType);

    return question;
}

void resetConsole()
{
    system("cls");
    system("color 0F");

    return;
}

void consoleTheme(bool answer)
{
    switch (answer)
    {
    case true:
        system("color 2F");
        break;
    case false:
        system("color 4F");
        std::cout << '\a';
        break;
    }

    return;
}

void displayHeader(bool answer)
{
    std::string dicision = answer ? "PASS :-)" : "FAIL :-(";

    std::cout << "____________________________\n" << std::endl;
    std::cout << "Final Result is " << dicision << std::endl;
    std::cout << "____________________________\n" << std::endl;
}

void displayFinalResult(Quiz quiz)
{
    std::cout << "Number of Questions    : " << quiz.numberOfQuestions << std::endl;
    std::cout << "Questions Level        : " << getLevelName( quiz.level) << std::endl;
    std::cout << "Operation Type         : " << getOperationTypeName(quiz.opType) << std::endl;
    std::cout << "Number of Right Answers: " << quiz.numberOfRightAnswers << std::endl;
    std::cout << "Number of Wrong Answers: " << quiz.numberOfWrongAnswers << std::endl;
    std::cout << "____________________________\n" << std::endl;
    consoleTheme(quiz.isPass);

    return;
}

void startQuiz(Quiz& quiz)
{
    for (int questionNumber = 1; questionNumber <= quiz.numberOfQuestions; questionNumber++)
    {
        std::cout << "\nQuestion [" << questionNumber << "/" << quiz.numberOfQuestions << "]\n" << std::endl;

        std::cout << quiz.questionList[questionNumber].number1 << std::endl;
        std::cout << quiz.questionList[questionNumber].number2 << " " << getOperationSymbol(quiz.questionList[questionNumber].opType) << std::endl;
        std::cout << "__________________" << std::endl;;

        quiz.questionList[questionNumber].userAnswer = readUserInput();

        quiz.questionList[questionNumber].answerResult = quiz.questionList[questionNumber].userAnswer == quiz.questionList[questionNumber].correctAnswer;

        if (quiz.questionList[questionNumber].answerResult)
        {
            std::cout << "Right Answer :-)" << std::endl;
            quiz.numberOfRightAnswers++;
            consoleTheme(quiz.questionList[questionNumber].answerResult);
        }
        else
        {
            std::cout << "Wrond Answer :-(" << std::endl;
            std::cout << "The right answer is: " << quiz.questionList[questionNumber].correctAnswer << std::endl;
            quiz.numberOfWrongAnswers++;
            consoleTheme(quiz.questionList[questionNumber].answerResult);
        }
    }

    quiz.isPass = quiz.numberOfRightAnswers >= quiz.numberOfWrongAnswers;
}

void playMathGame()
{
    Quiz quiz;
    quiz.numberOfQuestions = chooseNumberOfQuestions();
    quiz.level = chooseQuestionsLevel();
    quiz.opType = chooseOperationType();

    for (int questionNumber = 1; questionNumber <= quiz.numberOfQuestions; questionNumber++)
    {
        quiz.questionList[questionNumber] = makeQuestion(quiz.level, quiz.opType);
    }
    startQuiz(quiz);

    displayHeader(quiz.isPass);
    displayFinalResult(quiz);

    return;
}

void startGame()
{
    char playAgain = 'Y';
    do
    {
        resetConsole();
        playMathGame();

        std::cout << "Do you want to play again (Y/N): " << std::endl;
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return;
}

int main()
{
    srand((unsigned)time(NULL));

    startGame();

    return 0;
}