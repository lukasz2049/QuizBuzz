int i;
int currentMode;
int selectedPlayer;

int pinButtonConfirm;
int pinButtonCancel;
int pinHostLight;
int pinButtonCenter;


int startingLives = 3;
int scoreToWin = 11;

const int maxPlayerBoxes = 5; 

int questionNumber = 0;

bool silent = false;
int connectedPlayerBoxes = 0;

int activePlayers = 0;
int totalPlayers = 0;

int countdown = 0;

enum Modes { PREGAME = 0, HOST = 1, QUESTION = 2, ANSWER = 3, END = 9, TEST = 10, LOADING = 11};
// enum Players { RED = 0, GREEN = 1, BLUE = 2, YELLOW = 3, WHITE = 4};
int playerSelect[maxPlayerBoxes];


