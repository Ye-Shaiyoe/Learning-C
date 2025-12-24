#include <stdio.h>
int main () {

//===== MAIN =====//
    int playerHealt = 100;
    int playerLife = 3;
    int playerScore = 0;
    float playerSpeed = 2.5;
    int playerLevel = 1; 
    int isPlayerLife=  1 ;

//===== ENEMY =====//
    int enemyHelat = 1;
    int enemyDamage= 5;
    float enemySpeed= 1.5;
    int enemyCount= 2;

//===== ITEM =====//
    int cointCount = 0;
    int ammoCOunt =  10; 
    int shieldActive = 0;
    int powerUpTime = 0;

//===== GAME SATE =====//
    int curretLevel = 1;
    int maxLevel = 10;
    int isGameOver = 0;
    int isPaused = 0;

//==== SImulasi Game ====//

printf("==== GAME DIMULAI ====\n");

playerHealt -= enemyDamage;
ammoCOunt --; 
playerScore += 100;
cointCount += 5;

if (playerHealt <=0) { 
    playerLife-- ;
    playerHealt= 100 ;
    
    if (playerLife <= 0) { 
        isPlayerLife = 0;
        isGameOver = 1;
    }
}
printf("HP Player: %d\n", playerHealt);
printf("Life Player: %d\n", playerLife);
printf("Score: %d\n", playerScore);
printf("Coin: %d\n", cointCount);
printf("Ammo: %d\n", ammoCOunt);
printf("Level: %d\n", playerLevel);
printf("Game Over: %d\n", isGameOver);

return 0;
}