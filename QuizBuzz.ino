int i;
int currentMode;
int selectedPlayer;

int pinButtonConfirm;
int pinButtonCancel;
int pinHostLight = LED_BUILTIN;

bool silent = false;

int questionNumber = 0;
const int maxPlayerBoxes = 4;
int connectedPlayerBoxes = 0;
int activePlayers = 0;
int countdown = 0;

enum Modes { TEST = 10, PREGAME = 0, HOST = 1, QUESTION = 2, ANSWER = 3};
