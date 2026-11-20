#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD configuration
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Voting buttons
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;

// Result button
const int resultButton = 6;

// Vote counters
int votes1 = 0;
int votes2 = 0;
int votes3 = 0;
int votes4 = 0;

// Previous button states
int lastState1 = HIGH;
int lastState2 = HIGH;
int lastState3 = HIGH;
int lastState4 = HIGH;
int lastResultState = HIGH;

bool resultDisplayed = false;

void setup()
{
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button3, INPUT_PULLUP);
    pinMode(button4, INPUT_PULLUP);
    pinMode(resultButton, INPUT_PULLUP);

    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("Digital Voting");

    lcd.setCursor(0, 1);
    lcd.print("Machine Ready");

    delay(2000);
    lcd.clear();

    displayVotes();
}

void loop()
{
    if (resultDisplayed)
    {
        return;
    }

    int state1 = digitalRead(button1);

    if (state1 == LOW && lastState1 == HIGH)
    {
        votes1++;
        displayVotes();
        delay(200);
    }
    lastState1 = state1;

    int state2 = digitalRead(button2);

    if (state2 == LOW && lastState2 == HIGH)
    {
        votes2++;
        displayVotes();
        delay(200);
    }
    lastState2 = state2;

    int state3 = digitalRead(button3);

    if (state3 == LOW && lastState3 == HIGH)
    {
        votes3++;
        displayVotes();
        delay(200);
    }
    lastState3 = state3;

    int state4 = digitalRead(button4);

    if (state4 == LOW && lastState4 == HIGH)
    {
        votes4++;
        displayVotes();
        delay(200);
    }
    lastState4 = state4;

    int resultState = digitalRead(resultButton);

    if (resultState == LOW && lastResultState == HIGH)
    {
        resultDisplayed = true;
        displayResult();
    }

    lastResultState = resultState;
}

// Display candidate vote counts
void displayVotes()
{
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("C1:");
    lcd.print(votes1);

    lcd.setCursor(8, 0);
    lcd.print("C2:");
    lcd.print(votes2);

    lcd.setCursor(0, 1);
    lcd.print("C3:");
    lcd.print(votes3);

    lcd.setCursor(8, 1);
    lcd.print("C4:");
    lcd.print(votes4);
}

// Calculate winner and majority
void displayResult()
{
    int votes[4] = {votes1, votes2, votes3, votes4};

    int maxVotes = votes[0];
    int winner = 0;

    // Find highest votes
    for (int i = 1; i < 4; i++)
    {
        if (votes[i] > maxVotes)
        {
            maxVotes = votes[i];
            winner = i;
        }
    }

    // Check for a tie
    int topCount = 0;

    for (int i = 0; i < 4; i++)
    {
        if (votes[i] == maxVotes)
        {
            topCount++;
        }
    }

    lcd.clear();

    if (topCount > 1)
    {
        lcd.setCursor(0, 0);
        lcd.print("Election Tie!");

        lcd.setCursor(0, 1);
        lcd.print("Top votes:");
        lcd.print(maxVotes);
        return;
    }

    // Find second-highest votes
    int secondMax = -1;

    for (int i = 0; i < 4; i++)
    {
        if (i != winner && votes[i] > secondMax)
        {
            secondMax = votes[i];
        }
    }

    // Calculate winning margin
    int majority = maxVotes - secondMax;

    lcd.setCursor(0, 0);
    lcd.print("Winner: C");
    lcd.print(winner + 1);

    lcd.setCursor(0, 1);
    lcd.print("Majority:");
    lcd.print(majority);
}
