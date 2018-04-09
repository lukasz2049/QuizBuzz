int i;
int currentMode;
int selectedPlayer;

int pinButtonConfirm;
int pinButtonCancel;
int pinHostLight;
int pinButtonCenter;

bool silent = false;

int startingLives = 3;
int questionNumber = 0;
const int maxPlayerBoxes = 5;
int connectedPlayerBoxes = 0;
int activePlayers = 0;
int countdown = 0;

enum Modes { PREGAME = 0, HOST = 1, QUESTION = 2, ANSWER = 3, END = 9, TEST = 10};
// enum Players { RED = 0, GREEN = 1, BLUE = 2, YELLOW = 3, WHITE = 4};
int playerSelect[maxPlayerBoxes];


