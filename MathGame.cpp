#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib> // for generate random numbers
using namespace std;

struct UserInfo
{
    short numOfQuestions = 0;
    short questionCounter = 0;
    short rightAnswer = 0;
    short rongAnswer = 0; 
    int level = 0;
    int operationType = 0;
};


UserInfo user;


// Who many Question number
short askForQuestionNumbers(){
    short number;
cout << "Who Many Question You Want ... ?" << endl;
    cin >> number;
    return number;
}

int getRandomNum(int from, int to){
   return rand() % (to-from+from) + from;
}


enum EnOperatinoType {Add = 1 , Sub = 2 , Mult = 3 , Div = 4  , MixOp = 5 };

EnOperatinoType operationType (){
    cout << "Enter Operation Type [1] Add, [2] Sub [3] Mul [4] Div [5] Mix " << endl;
    int operation;
    cin >> operation;
    return operation == 1 ? Add : operation == 2 ? Sub : operation == 3 ? Mult : operation == 4 ? Div : MixOp;
}


char getRandomOperatino (){
    char mathOperators[4] = {'+', '-', '*', '/'};
     int random = getRandomNum(1,4);
    return mathOperators[random-1];
}


enum EnQuestionLevel { Easy = 1, Mid = 2, Hard = 3, MixQes = 4 };

EnQuestionLevel askForLevel(){
   cout << "Enter Question Level [1] Easy, [2] Mid [3] Hard [4] Mix" << endl;
    short level;
    cin >> level;
    return level == 1 ? Easy : level == 2 ? Mid : level == 3 ? Hard : MixQes;
}

short getRandNumForQuestion(int level){
    switch  (level){
        case 1 : return getRandomNum(1,10); break;
        case 2 : return getRandomNum(10,20); break;
        case 3 : return getRandomNum(30,100); break;
        case 4 : return getRandomNum(1,100); break;
    }
}

short userAnswer(){
    short answer;
    cin >> answer;
    return answer ;
}

void checkUserAnswer(short answer, short result){
    if(answer == result) {
        cout<<"Right answer"<<endl;
        user.rightAnswer ++;
    }
    else {
        cout<<"\a";
        cout<< "Rong answer"<<endl;
         cout<< "The Right answer = " << result << endl;
        user.rongAnswer ++;
    }

}

void checkUserMark(short rightAnswer , short rongAnswer){

    if (rightAnswer > rongAnswer) {
    cout<< "\x1b[32m"; // Green color
    cout<< "\n--------------*** Congratulation, you are passed ***--------------\n\n";
    }else{
        cout<< "\x1b[31m"; // Red Color
        cout<< "\n--------------*** Sorry, you are failed ***--------------\n\n";
    }
}
    

short preformOperation (int op, char mixOper ,int num1, int num2){
    switch (op)
    {
    case 1: return num1 + num2; break;
    case 2: return num1 - num2; break;
    case 3: return num1 * num2; break;
    case 4: return num1 / num2; break;
    case 5: 
   // cout << "operation type is: " << mixOper << endl;
    if (mixOper == '+') return num1 + num2;
    if (mixOper == '-') return num1 - num2;
    if (mixOper == '*') return num1 * num2;
    if (mixOper == '/') return num1 / num2; break;
}
}

string operationTypeString(EnOperatinoType opType , char mixOper){
    switch(opType){
        case Add: return "+"; break;
        case Sub: return "-"; break;
        case Mult: return "*"; break;
        case Div: return "/"; break;
        case MixOp: 
    if (mixOper == '+') return "+";
    if (mixOper == '-') return "-";
    if (mixOper == '*') return "*";
    if (mixOper == '/') return "/";
    }
}
void printQustion (int op, char mixOper ,int num1, int num2){
    cout<< "\n\n--------- Question Number ["<<user.questionCounter << "] ---------\n\n";
    switch (op)
    {
    case 1: cout<< num1 << " + " << num2 << " = "; break;
    case 2: cout<< num1 << " - " << num2 << " = "; break;
    case 3: cout<< num1 << " * " << num2 << " = "; break;
    case 4: cout<< num1 << " / " << num2 << " = "; break;
    case 5: 
    if (mixOper == '+') cout<< num1 << " + " << num2 << " = "; 
    if (mixOper == '-') cout<< num1 << " - " << num2 << " = "; 
    if (mixOper == '*') cout<< num1 << " * " << num2 << " = "; 
    if (mixOper == '/') cout<< num1 << " / " << num2 << " = "; 
}
cout << "\n---------\n";
}


void printFinalResult(UserInfo userInfo){
    cout << "\n||-------------------- *** G a m e  O v e r *** ---------------------||\n\n";
    cout << "||------------------------- Game Result ---------------------------||\n\n";
    cout<< "                      Qustions Counts  :[" << userInfo.numOfQuestions << "]\n";
    cout<< "                      Right Answers    :[" << userInfo.rightAnswer << "]\n";
    cout<< "                      Rong Answers     :[" << userInfo.rongAnswer << "]\n";
    //cout<< "                      Computer Score   :[" << userInfo. << "]\n";
    checkUserMark(userInfo.rightAnswer, userInfo.rongAnswer);
}

void setScreenColor(short answer, short result){
    if(answer == result) cout<< "\x1b[32m"; // Green color
    else cout<< "\x1b[31m"; // Red Color
}

void resetScreen(){
     cout<< "\x1b[0m"; // reset all color attributes back to normal
     system("clear");  // clear terminal
}

void resetCounters(){
  user.numOfQuestions = 0 ;
   user.questionCounter = 0;
   user.rightAnswer = 0;
  user.rongAnswer = 0;  
  user.level = 0;
  user.operationType = 0;
}

void startRound(){
    cout<<"----------------------||| Math Game Start |||----------------------" << endl;
  user.numOfQuestions = askForQuestionNumbers();
     user.level = askForLevel();
     user.operationType = operationType();
}

void resetGame (){
    cout<< "\x1b[0m"; // reset all color attributes back to normal
    char userAnswer;
    cout<< "do you want to play agine [Y] Yes , [Any Key] No : ";
    cin >> userAnswer;
    if (userAnswer == 'Y' || userAnswer == 'y') {
        resetCounters();
        resetScreen();
         startRound();
         
        cout<<"\n---------------- Now You Can Play Again ----------------\n" << endl;
    }else{
        resetCounters();
        resetScreen();
        cout<<"----------------------||| Game Ended |||----------------------" << endl;
    }
}



void startGame(){

  startRound();

    do{
    user.questionCounter ++;
    int num1 = getRandNumForQuestion(user.level);
    int num2 = getRandNumForQuestion(user.level);
    char mixOperation = getRandomOperatino();

    printQustion(user.operationType,mixOperation,num1,num2);

    short result = preformOperation(user.operationType,mixOperation, num1, num2);
    // user input answer
    short answer = userAnswer();
    checkUserAnswer(answer, result);
    setScreenColor(answer,result);
    

    if (user.numOfQuestions == user.questionCounter){
        printFinalResult(user);
        resetGame();
    }
    
    } while(user.numOfQuestions > user.questionCounter);
    
}


int main()
{
    srand((unsigned)time(NULL));
    startGame();

    return 0;
}

